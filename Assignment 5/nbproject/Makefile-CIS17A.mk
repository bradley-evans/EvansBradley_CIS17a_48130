#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=CIS17A
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/classes.o \
	${OBJECTDIR}/evans_std.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/solutions.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11 -Wall -Wextra -errors
CXXFLAGS=-std=c++11 -Wall -Wextra -errors

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../../../../../../../cygwin/bin ../../../../../../../../../cygwin/bin/cygboost_regex-mt-1_53.dll ../../../../../../../../../cygwin/bin/cygboost_program_options-mt-1_53.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5.exe: ../../../../../../../../../cygwin/bin/cygboost_regex-mt-1_53.dll

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5.exe: ../../../../../../../../../cygwin/bin/cygboost_program_options-mt-1_53.dll

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/classes.o: classes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../../../cygwin/usr/include/boost -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/classes.o classes.cpp

${OBJECTDIR}/evans_std.o: evans_std.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../../../cygwin/usr/include/boost -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/evans_std.o evans_std.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../../../cygwin/usr/include/boost -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/solutions.o: solutions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../../../cygwin/usr/include/boost -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/solutions.o solutions.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/assignment_5.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
