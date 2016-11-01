################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
global.obj: ../global.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="global.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

quad_math.obj: ../quad_math.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="quad_math.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="D:/git_code/quad_tm4c123" --include_path="D:/git_code/quad_tm4c123/basement" --include_path="D:/git_code/quad_tm4c123/interface" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111" --include_path="C:/Users/home/Desktop/TI/TI Code/TivaWare_C_Series-2.1.2.111/utils" --include_path="D:/CCS/ccsv6/tools/compiler/ti-cgt-arm_5.2.2/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


