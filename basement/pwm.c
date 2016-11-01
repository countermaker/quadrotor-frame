#include <stdbool.h>

#include <stdint.h>

#include "inc/hw_ints.h"

#include "inc/hw_memmap.h"

#include "driverlib/gpio.h"

#include "driverlib/interrupt.h"

#include "driverlib/pin_map.h"

#include "driverlib/pwm.h"

#include "driverlib/sysctl.h"

#include "driverlib/uart.h"

#include "utils/uartstdio.h"

//*****************************************************************************
//
// Misc macros for manipulating the encoded generator and output defines used
// by the API.
//
//*****************************************************************************
#define PWM_GEN_BADDR(_mod_, _gen_)                                           \
                                ((_mod_) + (_gen_))
#define PWM_GEN_EXT_BADDR(_mod_, _gen_)                                       \
                                ((_mod_) + PWM_GEN_EXT_0 +                    \
                                 ((_gen_) - PWM_GEN_0) * 2)
#define PWM_OUT_BADDR(_mod_, _out_)                                           \
                                ((_mod_) + ((_out_) & 0xFFFFFFC0))
#define PWM_IS_OUTPUT_ODD(_out_)                                              \
                                ((_out_) & 0x00000001)

//*****************************************************************************
//
//! \internal
//! Checks a PWM generator number.
//!
//! \param ui32Gen is the generator number.
//!
//! This function determines if a PWM generator number is valid.
//!
//! \return Returnes \b true if the generator number is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_PWMGenValid(uint32_t ui32Gen)
{
    return((ui32Gen == PWM_GEN_0) || (ui32Gen == PWM_GEN_1) ||
           (ui32Gen == PWM_GEN_2) || (ui32Gen == PWM_GEN_3));
}
#endif

//*****************************************************************************
//
//! \internal
//! Checks a PWM output number.
//!
//! \param ui32PWMOut is the output number.
//!
//! This function determines if a PWM output number is valid.
//!
//! \return Returns \b true if the output number is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_PWMOutValid(uint32_t ui32PWMOut)
{
    return((ui32PWMOut == PWM_OUT_0) || (ui32PWMOut == PWM_OUT_1) ||
           (ui32PWMOut == PWM_OUT_2) || (ui32PWMOut == PWM_OUT_3) ||
           (ui32PWMOut == PWM_OUT_4) || (ui32PWMOut == PWM_OUT_5) ||
           (ui32PWMOut == PWM_OUT_6) || (ui32PWMOut == PWM_OUT_7));
}
#endif

//*****************************************************************************
//
//! Configures a PWM generator.
//!
//! \param ui32Base is the base address of the PWM module.
//! \param ui32Gen is the PWM generator to configure.  This parameter must be
//! one of \b PWM_GEN_0, \b PWM_GEN_1, \b PWM_GEN_2, or \b PWM_GEN_3.
//! \param ui32Config is the configuration for the PWM generator.
//!
//! This function is used to set the mode of operation for a PWM generator.
//! The counting mode, synchronization mode, and debug behavior are all
//! configured.  After configuration, the generator is left in the disabled
//! state.
//!
//! A PWM generator can count in two different modes:  count down mode or count
//! up/down mode.  In count down mode, it counts from a value down to zero,
//! and then resets to the preset value, producing left-aligned PWM
//! signals (that is, the rising edge of the two PWM signals produced by the
//! generator occur at the same time).  In count up/down mode, it counts up
//! from zero to the preset value, counts back down to zero, and then repeats
//! the process, producing center-aligned PWM signals (that is,
//! the middle of the high/low period of the PWM signals produced by the
//! generator occurs at the same time).
//!
//! When the PWM generator parameters (period and pulse width) are modified,
//! their effect on the output PWM signals can be delayed.  In synchronous
//! mode, the parameter updates are not applied until a synchronization event
//! occurs.  This mode allows multiple parameters to be modified and take
//! effect simultaneously, instead of one at a time.  Additionally, parameters
//! to multiple PWM generators in synchronous mode can be updated
//! simultaneously, allowing them to be treated as if they were a unified
//! generator.  In non-synchronous mode, the parameter updates are not delayed
//! until a synchronization event.  In either mode, the parameter updates only
//! occur when the counter is at zero to help prevent oddly formed PWM signals
//! during the update (that is, a PWM pulse that is too short or too long).
//!
//! The PWM generator can either pause or continue running when the processor
//! is stopped via the debugger.  If configured to pause, it continues to
//! count until it reaches zero, at which point it pauses until the
//! processor is restarted.  If configured to continue running, it keeps
//! counting as if nothing had happened.
//!
//! The \e ui32Config parameter contains the desired configuration.  It is the
//! logical OR of the following:
//!
//! - \b PWM_GEN_MODE_DOWN or \b PWM_GEN_MODE_UP_DOWN to specify the counting
//!   mode
//! - \b PWM_GEN_MODE_SYNC or \b PWM_GEN_MODE_NO_SYNC to specify the counter
//!   load and comparator update synchronization mode
//! - \b PWM_GEN_MODE_DBG_RUN or \b PWM_GEN_MODE_DBG_STOP to specify the debug
//!   behavior
//! - \b PWM_GEN_MODE_GEN_NO_SYNC, \b PWM_GEN_MODE_GEN_SYNC_LOCAL, or
//!   \b PWM_GEN_MODE_GEN_SYNC_GLOBAL to specify the update synchronization
//!   mode for generator counting mode changes
//! - \b PWM_GEN_MODE_DB_NO_SYNC, \b PWM_GEN_MODE_DB_SYNC_LOCAL, or
//!   \b PWM_GEN_MODE_DB_SYNC_GLOBAL to specify the deadband parameter
//!   synchronization mode
//! - \b PWM_GEN_MODE_FAULT_LATCHED or \b PWM_GEN_MODE_FAULT_UNLATCHED to
//!   specify whether fault conditions are latched or not
//! - \b PWM_GEN_MODE_FAULT_MINPER or \b PWM_GEN_MODE_FAULT_NO_MINPER to
//!   specify whether minimum fault period support is required
//! - \b PWM_GEN_MODE_FAULT_EXT or \b PWM_GEN_MODE_FAULT_LEGACY to specify
//!   whether extended fault source selection support is enabled or not
//!
//! Setting \b PWM_GEN_MODE_FAULT_MINPER allows an application to set the
//! minimum duration of a PWM fault signal.  Faults are signaled for at
//! least this time even if the external fault pin deasserts earlier.  Care
//! should be taken when using this mode because during the fault signal
//! period, the fault interrupt from the PWM generator remains asserted.  The
//! fault interrupt handler may, therefore, reenter immediately if it exits
//! prior to expiration of the fault timer.
//!
//! \note Changes to the counter mode affect the period of the PWM signals
//! produced.  PWMGenPeriodSet() and PWMPulseWidthSet() should be called after
//! any changes to the counter mode of a generator.
//!
//! \return None.
//
//*****************************************************************************

void Pwm_init(void)
{

	SysCtlPWMClockSet(SYSCTL_PWMDIV_32);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    //Configure GPIO
    GPIOPinConfigure(GPIO_PB7_M0PWM1);
    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    GPIOPinConfigure(GPIO_PB5_M0PWM3);
    GPIOPinConfigure(GPIO_PB4_M0PWM2);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);

    PWMGenConfigure(PWM0_BASE, PWM_GEN_0,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1,PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 5208);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 5208);

    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, 2083);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, 2083);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 2083);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, 2083);

    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
    //Output
    PWMOutputState(PWM0_BASE, (PWM_OUT_0_BIT), true);
    PWMOutputState(PWM0_BASE, (PWM_OUT_1_BIT), true);
    PWMOutputState(PWM0_BASE, (PWM_OUT_2_BIT), true);
    PWMOutputState(PWM0_BASE, (PWM_OUT_3_BIT), true);
}

/**
  * @brief  Set the PWM1
  * @param  cnt
  * @retval None
  * @cnt:1ms__1250    2ms__2500
  */
void Pwm_Set1(uint32_t cnt)
{
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, cnt);
}
/**
  * @brief  Set the PWM1
  * @param  cnt
  * @retval None
  * @cnt:1ms__1250    2ms__2500
  */
void Pwm_Set2(uint32_t cnt)
{
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, cnt);
}
/**
  * @brief  Set the PWM1
  * @param  cnt
  * @retval None
  * @cnt:1ms__1250    2ms__2500
  */
void Pwm_Set3(uint32_t cnt)
{
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, cnt);
}
/**
  * @brief  Set the PWM1
  * @param  cnt
  * @retval None
  * @cnt:1ms__1250    2ms__2500
  */
void Pwm_Set4(uint32_t cnt)
{
	PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, cnt);
}
