# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\super\c\c++\goofy-ahh-calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\super\c\c++\goofy-ahh-calculator\build

# Include any dependencies generated for this target.
include CMakeFiles/goofy-ahh-calculator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/goofy-ahh-calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/goofy-ahh-calculator.dir/flags.make

CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_C.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/glad.c
CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\glad.c.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\glad.c.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\glad.c

CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.i"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\glad.c > CMakeFiles\goofy-ahh-calculator.dir\src\glad.c.i

CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.s"
	C:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\glad.c -o CMakeFiles\goofy-ahh-calculator.dir\src\glad.c.s

CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_CXX.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/main.cpp
CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\main.cpp.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\main.cpp.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\main.cpp

CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\main.cpp > CMakeFiles\goofy-ahh-calculator.dir\src\main.cpp.i

CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\main.cpp -o CMakeFiles\goofy-ahh-calculator.dir\src\main.cpp.s

CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_CXX.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/config.cpp
CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\config.cpp.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\config.cpp.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\config.cpp

CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\config.cpp > CMakeFiles\goofy-ahh-calculator.dir\src\config.cpp.i

CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\config.cpp -o CMakeFiles\goofy-ahh-calculator.dir\src\config.cpp.s

CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_CXX.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/sprite.cpp
CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\sprite.cpp.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\sprite.cpp.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\sprite.cpp

CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\sprite.cpp > CMakeFiles\goofy-ahh-calculator.dir\src\sprite.cpp.i

CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\sprite.cpp -o CMakeFiles\goofy-ahh-calculator.dir\src\sprite.cpp.s

CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_CXX.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/maintenance.cpp
CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\maintenance.cpp.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\maintenance.cpp.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\maintenance.cpp

CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\maintenance.cpp > CMakeFiles\goofy-ahh-calculator.dir\src\maintenance.cpp.i

CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\maintenance.cpp -o CMakeFiles\goofy-ahh-calculator.dir\src\maintenance.cpp.s

CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/flags.make
CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/includes_CXX.rsp
CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj: C:/Users/super/c/c++/goofy-ahh-calculator/src/text.cpp
CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj: CMakeFiles/goofy-ahh-calculator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj -MF CMakeFiles\goofy-ahh-calculator.dir\src\text.cpp.obj.d -o CMakeFiles\goofy-ahh-calculator.dir\src\text.cpp.obj -c C:\Users\super\c\c++\goofy-ahh-calculator\src\text.cpp

CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\super\c\c++\goofy-ahh-calculator\src\text.cpp > CMakeFiles\goofy-ahh-calculator.dir\src\text.cpp.i

CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\super\c\c++\goofy-ahh-calculator\src\text.cpp -o CMakeFiles\goofy-ahh-calculator.dir\src\text.cpp.s

# Object files for target goofy-ahh-calculator
goofy__ahh__calculator_OBJECTS = \
"CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj" \
"CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj" \
"CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj" \
"CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj" \
"CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj" \
"CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj"

# External object files for target goofy-ahh-calculator
goofy__ahh__calculator_EXTERNAL_OBJECTS =

goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/glad.c.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/main.cpp.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/config.cpp.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/sprite.cpp.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/maintenance.cpp.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/src/text.cpp.obj
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/build.make
goofy-ahh-calculator.exe: C:/Users/super/c/c++/goofy-ahh-calculator/dependencies/libglfw3.a
goofy-ahh-calculator.exe: C:/Users/super/c/c++/goofy-ahh-calculator/dependencies/freetype.lib
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/linkLibs.rsp
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/objects1.rsp
goofy-ahh-calculator.exe: CMakeFiles/goofy-ahh-calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable goofy-ahh-calculator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\goofy-ahh-calculator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/goofy-ahh-calculator.dir/build: goofy-ahh-calculator.exe
.PHONY : CMakeFiles/goofy-ahh-calculator.dir/build

CMakeFiles/goofy-ahh-calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\goofy-ahh-calculator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/goofy-ahh-calculator.dir/clean

CMakeFiles/goofy-ahh-calculator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\super\c\c++\goofy-ahh-calculator C:\Users\super\c\c++\goofy-ahh-calculator C:\Users\super\c\c++\goofy-ahh-calculator\build C:\Users\super\c\c++\goofy-ahh-calculator\build C:\Users\super\c\c++\goofy-ahh-calculator\build\CMakeFiles\goofy-ahh-calculator.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/goofy-ahh-calculator.dir/depend
