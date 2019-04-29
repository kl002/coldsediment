#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/hardware/led.c ../src/hardware/mcu_adc.c ../src/hardware/motor.c ../src/hardware/LCD.c ../src/hardware/touch.c ../src/hardware/NVRAM.c ../src/hardware/Uart.c ../src/hardware/scale.c ../src/system/actived.c ../src/system/AES.c ../src/system/alarm.c ../src/system/cmdProc.c ../src/system/log.c ../src/system/system.c ../src/system/user.c ../src/ui/ui.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1479262/led.o ${OBJECTDIR}/_ext/1479262/mcu_adc.o ${OBJECTDIR}/_ext/1479262/motor.o ${OBJECTDIR}/_ext/1479262/LCD.o ${OBJECTDIR}/_ext/1479262/touch.o ${OBJECTDIR}/_ext/1479262/NVRAM.o ${OBJECTDIR}/_ext/1479262/Uart.o ${OBJECTDIR}/_ext/1479262/scale.o ${OBJECTDIR}/_ext/73441385/actived.o ${OBJECTDIR}/_ext/73441385/AES.o ${OBJECTDIR}/_ext/73441385/alarm.o ${OBJECTDIR}/_ext/73441385/cmdProc.o ${OBJECTDIR}/_ext/73441385/log.o ${OBJECTDIR}/_ext/73441385/system.o ${OBJECTDIR}/_ext/73441385/user.o ${OBJECTDIR}/_ext/809997874/ui.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1479262/led.o.d ${OBJECTDIR}/_ext/1479262/mcu_adc.o.d ${OBJECTDIR}/_ext/1479262/motor.o.d ${OBJECTDIR}/_ext/1479262/LCD.o.d ${OBJECTDIR}/_ext/1479262/touch.o.d ${OBJECTDIR}/_ext/1479262/NVRAM.o.d ${OBJECTDIR}/_ext/1479262/Uart.o.d ${OBJECTDIR}/_ext/1479262/scale.o.d ${OBJECTDIR}/_ext/73441385/actived.o.d ${OBJECTDIR}/_ext/73441385/AES.o.d ${OBJECTDIR}/_ext/73441385/alarm.o.d ${OBJECTDIR}/_ext/73441385/cmdProc.o.d ${OBJECTDIR}/_ext/73441385/log.o.d ${OBJECTDIR}/_ext/73441385/system.o.d ${OBJECTDIR}/_ext/73441385/user.o.d ${OBJECTDIR}/_ext/809997874/ui.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1479262/led.o ${OBJECTDIR}/_ext/1479262/mcu_adc.o ${OBJECTDIR}/_ext/1479262/motor.o ${OBJECTDIR}/_ext/1479262/LCD.o ${OBJECTDIR}/_ext/1479262/touch.o ${OBJECTDIR}/_ext/1479262/NVRAM.o ${OBJECTDIR}/_ext/1479262/Uart.o ${OBJECTDIR}/_ext/1479262/scale.o ${OBJECTDIR}/_ext/73441385/actived.o ${OBJECTDIR}/_ext/73441385/AES.o ${OBJECTDIR}/_ext/73441385/alarm.o ${OBJECTDIR}/_ext/73441385/cmdProc.o ${OBJECTDIR}/_ext/73441385/log.o ${OBJECTDIR}/_ext/73441385/system.o ${OBJECTDIR}/_ext/73441385/user.o ${OBJECTDIR}/_ext/809997874/ui.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/hardware/led.c ../src/hardware/mcu_adc.c ../src/hardware/motor.c ../src/hardware/LCD.c ../src/hardware/touch.c ../src/hardware/NVRAM.c ../src/hardware/Uart.c ../src/hardware/scale.c ../src/system/actived.c ../src/system/AES.c ../src/system/alarm.c ../src/system/cmdProc.c ../src/system/log.c ../src/system/system.c ../src/system/user.c ../src/ui/ui.c ../src/main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1479262/led.o: ../src/hardware/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/led.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/led.o.d" -o ${OBJECTDIR}/_ext/1479262/led.o ../src/hardware/led.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/mcu_adc.o: ../src/hardware/mcu_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/mcu_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/mcu_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/mcu_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/mcu_adc.o.d" -o ${OBJECTDIR}/_ext/1479262/mcu_adc.o ../src/hardware/mcu_adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/motor.o: ../src/hardware/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/motor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/motor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/motor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/motor.o.d" -o ${OBJECTDIR}/_ext/1479262/motor.o ../src/hardware/motor.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/LCD.o: ../src/hardware/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/LCD.o.d" -o ${OBJECTDIR}/_ext/1479262/LCD.o ../src/hardware/LCD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/touch.o: ../src/hardware/touch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/touch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/touch.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/touch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/touch.o.d" -o ${OBJECTDIR}/_ext/1479262/touch.o ../src/hardware/touch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/NVRAM.o: ../src/hardware/NVRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/NVRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/NVRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/NVRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/NVRAM.o.d" -o ${OBJECTDIR}/_ext/1479262/NVRAM.o ../src/hardware/NVRAM.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/Uart.o: ../src/hardware/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/Uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/Uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/Uart.o.d" -o ${OBJECTDIR}/_ext/1479262/Uart.o ../src/hardware/Uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/scale.o: ../src/hardware/scale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/scale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/scale.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/scale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/scale.o.d" -o ${OBJECTDIR}/_ext/1479262/scale.o ../src/hardware/scale.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/actived.o: ../src/system/actived.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/actived.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/actived.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/actived.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/actived.o.d" -o ${OBJECTDIR}/_ext/73441385/actived.o ../src/system/actived.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/AES.o: ../src/system/AES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/AES.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/AES.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/AES.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/AES.o.d" -o ${OBJECTDIR}/_ext/73441385/AES.o ../src/system/AES.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/alarm.o: ../src/system/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/alarm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/alarm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/alarm.o.d" -o ${OBJECTDIR}/_ext/73441385/alarm.o ../src/system/alarm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/cmdProc.o: ../src/system/cmdProc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/cmdProc.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/cmdProc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/cmdProc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/cmdProc.o.d" -o ${OBJECTDIR}/_ext/73441385/cmdProc.o ../src/system/cmdProc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/log.o: ../src/system/log.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/log.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/log.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/log.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/log.o.d" -o ${OBJECTDIR}/_ext/73441385/log.o ../src/system/log.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/system.o: ../src/system/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/system.o.d" -o ${OBJECTDIR}/_ext/73441385/system.o ../src/system/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/user.o: ../src/system/user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/user.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/user.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/user.o.d" -o ${OBJECTDIR}/_ext/73441385/user.o ../src/system/user.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/809997874/ui.o: ../src/ui/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809997874" 
	@${RM} ${OBJECTDIR}/_ext/809997874/ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/809997874/ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809997874/ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/809997874/ui.o.d" -o ${OBJECTDIR}/_ext/809997874/ui.o ../src/ui/ui.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1479262/led.o: ../src/hardware/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/led.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/led.o.d" -o ${OBJECTDIR}/_ext/1479262/led.o ../src/hardware/led.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/mcu_adc.o: ../src/hardware/mcu_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/mcu_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/mcu_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/mcu_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/mcu_adc.o.d" -o ${OBJECTDIR}/_ext/1479262/mcu_adc.o ../src/hardware/mcu_adc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/motor.o: ../src/hardware/motor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/motor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/motor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/motor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/motor.o.d" -o ${OBJECTDIR}/_ext/1479262/motor.o ../src/hardware/motor.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/LCD.o: ../src/hardware/LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/LCD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/LCD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/LCD.o.d" -o ${OBJECTDIR}/_ext/1479262/LCD.o ../src/hardware/LCD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/touch.o: ../src/hardware/touch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/touch.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/touch.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/touch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/touch.o.d" -o ${OBJECTDIR}/_ext/1479262/touch.o ../src/hardware/touch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/NVRAM.o: ../src/hardware/NVRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/NVRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/NVRAM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/NVRAM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/NVRAM.o.d" -o ${OBJECTDIR}/_ext/1479262/NVRAM.o ../src/hardware/NVRAM.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/Uart.o: ../src/hardware/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/Uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/Uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/Uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/Uart.o.d" -o ${OBJECTDIR}/_ext/1479262/Uart.o ../src/hardware/Uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1479262/scale.o: ../src/hardware/scale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1479262" 
	@${RM} ${OBJECTDIR}/_ext/1479262/scale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1479262/scale.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1479262/scale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1479262/scale.o.d" -o ${OBJECTDIR}/_ext/1479262/scale.o ../src/hardware/scale.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/actived.o: ../src/system/actived.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/actived.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/actived.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/actived.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/actived.o.d" -o ${OBJECTDIR}/_ext/73441385/actived.o ../src/system/actived.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/AES.o: ../src/system/AES.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/AES.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/AES.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/AES.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/AES.o.d" -o ${OBJECTDIR}/_ext/73441385/AES.o ../src/system/AES.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/alarm.o: ../src/system/alarm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/alarm.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/alarm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/alarm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/alarm.o.d" -o ${OBJECTDIR}/_ext/73441385/alarm.o ../src/system/alarm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/cmdProc.o: ../src/system/cmdProc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/cmdProc.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/cmdProc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/cmdProc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/cmdProc.o.d" -o ${OBJECTDIR}/_ext/73441385/cmdProc.o ../src/system/cmdProc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/log.o: ../src/system/log.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/log.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/log.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/log.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/log.o.d" -o ${OBJECTDIR}/_ext/73441385/log.o ../src/system/log.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/system.o: ../src/system/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/system.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/system.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/system.o.d" -o ${OBJECTDIR}/_ext/73441385/system.o ../src/system/system.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/73441385/user.o: ../src/system/user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/73441385" 
	@${RM} ${OBJECTDIR}/_ext/73441385/user.o.d 
	@${RM} ${OBJECTDIR}/_ext/73441385/user.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/73441385/user.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/73441385/user.o.d" -o ${OBJECTDIR}/_ext/73441385/user.o ../src/system/user.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/809997874/ui.o: ../src/ui/ui.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/809997874" 
	@${RM} ${OBJECTDIR}/_ext/809997874/ui.o.d 
	@${RM} ${OBJECTDIR}/_ext/809997874/ui.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/809997874/ui.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/809997874/ui.o.d" -o ${OBJECTDIR}/_ext/809997874/ui.o ../src/ui/ui.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -D_SUPPRESS_PLIB_WARNING -D_DISABLE_OPENADC10_CONFIGPORT_WARNING -I"../src/system" -I"../src/hardware" -I"../src/transport" -I"../src/ui" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPICkit3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PICkit3PlatformTool=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/LCD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
