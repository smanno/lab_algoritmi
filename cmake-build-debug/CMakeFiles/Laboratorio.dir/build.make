# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\stefano\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5233.103\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\stefano\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\193.5233.103\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Laboratorio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Laboratorio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laboratorio.dir/flags.make

CMakeFiles/Laboratorio.dir/main.cpp.obj: CMakeFiles/Laboratorio.dir/flags.make
CMakeFiles/Laboratorio.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Laboratorio.dir/main.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Laboratorio.dir\main.cpp.obj -c "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\main.cpp"

CMakeFiles/Laboratorio.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Laboratorio.dir/main.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\main.cpp" > CMakeFiles\Laboratorio.dir\main.cpp.i

CMakeFiles/Laboratorio.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Laboratorio.dir/main.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\main.cpp" -o CMakeFiles\Laboratorio.dir\main.cpp.s

# Object files for target Laboratorio
Laboratorio_OBJECTS = \
"CMakeFiles/Laboratorio.dir/main.cpp.obj"

# External object files for target Laboratorio
Laboratorio_EXTERNAL_OBJECTS =

Laboratorio.exe: CMakeFiles/Laboratorio.dir/main.cpp.obj
Laboratorio.exe: CMakeFiles/Laboratorio.dir/build.make
Laboratorio.exe: CMakeFiles/Laboratorio.dir/linklibs.rsp
Laboratorio.exe: CMakeFiles/Laboratorio.dir/objects1.rsp
Laboratorio.exe: CMakeFiles/Laboratorio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Laboratorio.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Laboratorio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laboratorio.dir/build: Laboratorio.exe

.PHONY : CMakeFiles/Laboratorio.dir/build

CMakeFiles/Laboratorio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Laboratorio.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Laboratorio.dir/clean

CMakeFiles/Laboratorio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio" "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio" "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug" "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug" "C:\Users\stefano\Dropbox\INFORMATICA\2 anno\Algoritmi e Strutture Dati\Laboratorio\cmake-build-debug\CMakeFiles\Laboratorio.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Laboratorio.dir/depend

