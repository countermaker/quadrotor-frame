################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
basement/bsp.obj: ../basement/bsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/bsp.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/delay.obj: ../basement/delay.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/delay.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/exti.obj: ../basement/exti.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/exti.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/ii2c.obj: ../basement/ii2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/ii2c.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/led.obj: ../basement/led.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/led.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/mpu6050.obj: ../basement/mpu6050.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/mpu6050.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/pll.obj: ../basement/pll.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/pll.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/pwm.obj: ../basement/pwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/pwm.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/sonar.obj: ../basement/sonar.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/sonar.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/timer.obj: ../basement/timer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/timer.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/uart.obj: ../basement/uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/uart.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

basement/uartstdio.obj: C:/Users/home/Desktop/TI/TI\ Code/TivaWare_C_Series-2.1.2.111/utils/uartstdio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="basement/uartstdio.pp" --obj_directory="basement" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


