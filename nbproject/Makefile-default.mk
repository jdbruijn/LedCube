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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=source/CubeControl/src/CubeData.c source/CubeControl/src/LayerControl.c source/CubeControl/src/LedCube.c source/CubeControl/src/LedDriver.c source/CubeControl/src/PanelControl.c source/LibraryFiles/src/Uart.c source/LibraryFiles/src/BitOperations.c source/LibraryFiles/src/Buzzer.c source/LibraryFiles/src/IOPorts.c source/LibraryFiles/src/SwFifoBuffer.c source/LibraryFiles/src/System.c source/src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/source/CubeControl/src/CubeData.o ${OBJECTDIR}/source/CubeControl/src/LayerControl.o ${OBJECTDIR}/source/CubeControl/src/LedCube.o ${OBJECTDIR}/source/CubeControl/src/LedDriver.o ${OBJECTDIR}/source/CubeControl/src/PanelControl.o ${OBJECTDIR}/source/LibraryFiles/src/Uart.o ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o ${OBJECTDIR}/source/LibraryFiles/src/System.o ${OBJECTDIR}/source/src/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/source/CubeControl/src/CubeData.o.d ${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d ${OBJECTDIR}/source/CubeControl/src/LedCube.o.d ${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d ${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d ${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d ${OBJECTDIR}/source/LibraryFiles/src/System.o.d ${OBJECTDIR}/source/src/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/source/CubeControl/src/CubeData.o ${OBJECTDIR}/source/CubeControl/src/LayerControl.o ${OBJECTDIR}/source/CubeControl/src/LedCube.o ${OBJECTDIR}/source/CubeControl/src/LedDriver.o ${OBJECTDIR}/source/CubeControl/src/PanelControl.o ${OBJECTDIR}/source/LibraryFiles/src/Uart.o ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o ${OBJECTDIR}/source/LibraryFiles/src/System.o ${OBJECTDIR}/source/src/main.o

# Source Files
SOURCEFILES=source/CubeControl/src/CubeData.c source/CubeControl/src/LayerControl.c source/CubeControl/src/LedCube.c source/CubeControl/src/LedDriver.c source/CubeControl/src/PanelControl.c source/LibraryFiles/src/Uart.c source/LibraryFiles/src/BitOperations.c source/LibraryFiles/src/Buzzer.c source/LibraryFiles/src/IOPorts.c source/LibraryFiles/src/SwFifoBuffer.c source/LibraryFiles/src/System.c source/src/main.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA004
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA004.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/source/CubeControl/src/CubeData.o: source/CubeControl/src/CubeData.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/CubeData.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/CubeData.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/CubeData.c  -o ${OBJECTDIR}/source/CubeControl/src/CubeData.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/CubeData.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/CubeData.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LayerControl.o: source/CubeControl/src/LayerControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LayerControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LayerControl.c  -o ${OBJECTDIR}/source/CubeControl/src/LayerControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LedCube.o: source/CubeControl/src/LedCube.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedCube.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedCube.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LedCube.c  -o ${OBJECTDIR}/source/CubeControl/src/LedCube.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LedCube.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LedCube.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LedDriver.o: source/CubeControl/src/LedDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedDriver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LedDriver.c  -o ${OBJECTDIR}/source/CubeControl/src/LedDriver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/PanelControl.o: source/CubeControl/src/PanelControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/PanelControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/PanelControl.c  -o ${OBJECTDIR}/source/CubeControl/src/PanelControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/Uart.o: source/LibraryFiles/src/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/Uart.c  -o ${OBJECTDIR}/source/LibraryFiles/src/Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o: source/LibraryFiles/src/BitOperations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/BitOperations.c  -o ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o: source/LibraryFiles/src/Buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/Buzzer.c  -o ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o: source/LibraryFiles/src/IOPorts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/IOPorts.c  -o ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o: source/LibraryFiles/src/SwFifoBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/SwFifoBuffer.c  -o ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/System.o: source/LibraryFiles/src/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/System.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/System.c  -o ${OBJECTDIR}/source/LibraryFiles/src/System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/System.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/src/main.o: source/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/src" 
	@${RM} ${OBJECTDIR}/source/src/main.o.d 
	@${RM} ${OBJECTDIR}/source/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/src/main.c  -o ${OBJECTDIR}/source/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/src/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/source/CubeControl/src/CubeData.o: source/CubeControl/src/CubeData.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/CubeData.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/CubeData.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/CubeData.c  -o ${OBJECTDIR}/source/CubeControl/src/CubeData.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/CubeData.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/CubeData.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LayerControl.o: source/CubeControl/src/LayerControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LayerControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LayerControl.c  -o ${OBJECTDIR}/source/CubeControl/src/LayerControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LayerControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LedCube.o: source/CubeControl/src/LedCube.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedCube.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedCube.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LedCube.c  -o ${OBJECTDIR}/source/CubeControl/src/LedCube.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LedCube.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LedCube.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/LedDriver.o: source/CubeControl/src/LedDriver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/LedDriver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/LedDriver.c  -o ${OBJECTDIR}/source/CubeControl/src/LedDriver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/LedDriver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/CubeControl/src/PanelControl.o: source/CubeControl/src/PanelControl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/CubeControl/src" 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d 
	@${RM} ${OBJECTDIR}/source/CubeControl/src/PanelControl.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/CubeControl/src/PanelControl.c  -o ${OBJECTDIR}/source/CubeControl/src/PanelControl.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/CubeControl/src/PanelControl.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/Uart.o: source/LibraryFiles/src/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/Uart.c  -o ${OBJECTDIR}/source/LibraryFiles/src/Uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/Uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o: source/LibraryFiles/src/BitOperations.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/BitOperations.c  -o ${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/BitOperations.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o: source/LibraryFiles/src/Buzzer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/Buzzer.c  -o ${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/Buzzer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o: source/LibraryFiles/src/IOPorts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/IOPorts.c  -o ${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/IOPorts.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o: source/LibraryFiles/src/SwFifoBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/SwFifoBuffer.c  -o ${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/SwFifoBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/LibraryFiles/src/System.o: source/LibraryFiles/src/System.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/LibraryFiles/src" 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/System.o.d 
	@${RM} ${OBJECTDIR}/source/LibraryFiles/src/System.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/LibraryFiles/src/System.c  -o ${OBJECTDIR}/source/LibraryFiles/src/System.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/LibraryFiles/src/System.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/LibraryFiles/src/System.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/source/src/main.o: source/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/source/src" 
	@${RM} ${OBJECTDIR}/source/src/main.o.d 
	@${RM} ${OBJECTDIR}/source/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  source/src/main.c  -o ${OBJECTDIR}/source/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/source/src/main.o.d"        -g -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/source/src/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -I"source/CubeControl" -I"source/LibraryFiles"  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -I"source/CubeControl" -I"source/LibraryFiles" -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/LedCube.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
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
