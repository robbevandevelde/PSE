# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pse.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pse.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pse.dir/flags.make

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o: ../Parsers/AirplaneParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirplaneParser.cpp

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirplaneParser.cpp > CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.i

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirplaneParser.cpp -o CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.s

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.requires

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.provides: CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.provides

CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.provides.build: CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o


CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o: ../Parsers/AirportParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirportParser.cpp

CMakeFiles/pse.dir/Parsers/AirportParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Parsers/AirportParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirportParser.cpp > CMakeFiles/pse.dir/Parsers/AirportParser.cpp.i

CMakeFiles/pse.dir/Parsers/AirportParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Parsers/AirportParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/AirportParser.cpp -o CMakeFiles/pse.dir/Parsers/AirportParser.cpp.s

CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.requires

CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.provides: CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.provides

CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.provides.build: CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o


CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o: ../Parsers/LuchthavenParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/LuchthavenParser.cpp

CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/LuchthavenParser.cpp > CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.i

CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/LuchthavenParser.cpp -o CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.s

CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.requires

CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.provides: CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.provides

CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.provides.build: CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o


CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o: ../Parsers/RunwayParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/RunwayParser.cpp

CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/RunwayParser.cpp > CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.i

CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/RunwayParser.cpp -o CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.s

CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.requires

CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.provides: CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.provides

CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.provides.build: CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o


CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o: ../TinyXML/tinystr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinystr.cpp

CMakeFiles/pse.dir/TinyXML/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/TinyXML/tinystr.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinystr.cpp > CMakeFiles/pse.dir/TinyXML/tinystr.cpp.i

CMakeFiles/pse.dir/TinyXML/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/TinyXML/tinystr.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinystr.cpp -o CMakeFiles/pse.dir/TinyXML/tinystr.cpp.s

CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.requires

CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.provides: CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.provides

CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.provides.build: CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o


CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o: ../TinyXML/tinyxml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxml.cpp

CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxml.cpp > CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.i

CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxml.cpp -o CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.s

CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.requires

CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.provides: CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.provides

CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.provides.build: CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o


CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o: ../TinyXML/tinyxmlerror.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlerror.cpp

CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlerror.cpp > CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.i

CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlerror.cpp -o CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.s

CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.requires

CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.provides: CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.provides

CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.provides.build: CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o


CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o: ../TinyXML/tinyxmlparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlparser.cpp

CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlparser.cpp > CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.i

CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/TinyXML/tinyxmlparser.cpp -o CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.s

CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.requires

CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.provides: CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.provides

CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.provides.build: CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o


CMakeFiles/pse.dir/Airplane.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Airplane.cpp.o: ../Airplane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pse.dir/Airplane.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Airplane.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airplane.cpp

CMakeFiles/pse.dir/Airplane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Airplane.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airplane.cpp > CMakeFiles/pse.dir/Airplane.cpp.i

CMakeFiles/pse.dir/Airplane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Airplane.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airplane.cpp -o CMakeFiles/pse.dir/Airplane.cpp.s

CMakeFiles/pse.dir/Airplane.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Airplane.cpp.o.requires

CMakeFiles/pse.dir/Airplane.cpp.o.provides: CMakeFiles/pse.dir/Airplane.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Airplane.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Airplane.cpp.o.provides

CMakeFiles/pse.dir/Airplane.cpp.o.provides.build: CMakeFiles/pse.dir/Airplane.cpp.o


CMakeFiles/pse.dir/Airport.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Airport.cpp.o: ../Airport.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/pse.dir/Airport.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Airport.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airport.cpp

CMakeFiles/pse.dir/Airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Airport.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airport.cpp > CMakeFiles/pse.dir/Airport.cpp.i

CMakeFiles/pse.dir/Airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Airport.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Airport.cpp -o CMakeFiles/pse.dir/Airport.cpp.s

CMakeFiles/pse.dir/Airport.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Airport.cpp.o.requires

CMakeFiles/pse.dir/Airport.cpp.o.provides: CMakeFiles/pse.dir/Airport.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Airport.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Airport.cpp.o.provides

CMakeFiles/pse.dir/Airport.cpp.o.provides.build: CMakeFiles/pse.dir/Airport.cpp.o


CMakeFiles/pse.dir/Gate.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Gate.cpp.o: ../Gate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/pse.dir/Gate.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Gate.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Gate.cpp

CMakeFiles/pse.dir/Gate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Gate.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Gate.cpp > CMakeFiles/pse.dir/Gate.cpp.i

CMakeFiles/pse.dir/Gate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Gate.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Gate.cpp -o CMakeFiles/pse.dir/Gate.cpp.s

CMakeFiles/pse.dir/Gate.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Gate.cpp.o.requires

CMakeFiles/pse.dir/Gate.cpp.o.provides: CMakeFiles/pse.dir/Gate.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Gate.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Gate.cpp.o.provides

CMakeFiles/pse.dir/Gate.cpp.o.provides.build: CMakeFiles/pse.dir/Gate.cpp.o


CMakeFiles/pse.dir/main.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/pse.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/main.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/main.cpp

CMakeFiles/pse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/main.cpp > CMakeFiles/pse.dir/main.cpp.i

CMakeFiles/pse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/main.cpp -o CMakeFiles/pse.dir/main.cpp.s

CMakeFiles/pse.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/main.cpp.o.requires

CMakeFiles/pse.dir/main.cpp.o.provides: CMakeFiles/pse.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/main.cpp.o.provides

CMakeFiles/pse.dir/main.cpp.o.provides.build: CMakeFiles/pse.dir/main.cpp.o


CMakeFiles/pse.dir/Runway.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Runway.cpp.o: ../Runway.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/pse.dir/Runway.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Runway.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Runway.cpp

CMakeFiles/pse.dir/Runway.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Runway.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Runway.cpp > CMakeFiles/pse.dir/Runway.cpp.i

CMakeFiles/pse.dir/Runway.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Runway.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Runway.cpp -o CMakeFiles/pse.dir/Runway.cpp.s

CMakeFiles/pse.dir/Runway.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Runway.cpp.o.requires

CMakeFiles/pse.dir/Runway.cpp.o.provides: CMakeFiles/pse.dir/Runway.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Runway.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Runway.cpp.o.provides

CMakeFiles/pse.dir/Runway.cpp.o.provides.build: CMakeFiles/pse.dir/Runway.cpp.o


CMakeFiles/pse.dir/Flightplan.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Flightplan.cpp.o: ../Flightplan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/pse.dir/Flightplan.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Flightplan.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Flightplan.cpp

CMakeFiles/pse.dir/Flightplan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Flightplan.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Flightplan.cpp > CMakeFiles/pse.dir/Flightplan.cpp.i

CMakeFiles/pse.dir/Flightplan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Flightplan.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Flightplan.cpp -o CMakeFiles/pse.dir/Flightplan.cpp.s

CMakeFiles/pse.dir/Flightplan.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Flightplan.cpp.o.requires

CMakeFiles/pse.dir/Flightplan.cpp.o.provides: CMakeFiles/pse.dir/Flightplan.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Flightplan.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Flightplan.cpp.o.provides

CMakeFiles/pse.dir/Flightplan.cpp.o.provides.build: CMakeFiles/pse.dir/Flightplan.cpp.o


CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o: ../Parsers/FlightplanParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/FlightplanParser.cpp

CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/FlightplanParser.cpp > CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.i

CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Parsers/FlightplanParser.cpp -o CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.s

CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.requires

CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.provides: CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.provides

CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.provides.build: CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o


CMakeFiles/pse.dir/AirTrafficController.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/AirTrafficController.cpp.o: ../AirTrafficController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/pse.dir/AirTrafficController.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/AirTrafficController.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/AirTrafficController.cpp

CMakeFiles/pse.dir/AirTrafficController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/AirTrafficController.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/AirTrafficController.cpp > CMakeFiles/pse.dir/AirTrafficController.cpp.i

CMakeFiles/pse.dir/AirTrafficController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/AirTrafficController.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/AirTrafficController.cpp -o CMakeFiles/pse.dir/AirTrafficController.cpp.s

CMakeFiles/pse.dir/AirTrafficController.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/AirTrafficController.cpp.o.requires

CMakeFiles/pse.dir/AirTrafficController.cpp.o.provides: CMakeFiles/pse.dir/AirTrafficController.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/AirTrafficController.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/AirTrafficController.cpp.o.provides

CMakeFiles/pse.dir/AirTrafficController.cpp.o.provides.build: CMakeFiles/pse.dir/AirTrafficController.cpp.o


CMakeFiles/pse.dir/Simulator.cpp.o: CMakeFiles/pse.dir/flags.make
CMakeFiles/pse.dir/Simulator.cpp.o: ../Simulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/pse.dir/Simulator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pse.dir/Simulator.cpp.o -c /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Simulator.cpp

CMakeFiles/pse.dir/Simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pse.dir/Simulator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Simulator.cpp > CMakeFiles/pse.dir/Simulator.cpp.i

CMakeFiles/pse.dir/Simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pse.dir/Simulator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/Simulator.cpp -o CMakeFiles/pse.dir/Simulator.cpp.s

CMakeFiles/pse.dir/Simulator.cpp.o.requires:

.PHONY : CMakeFiles/pse.dir/Simulator.cpp.o.requires

CMakeFiles/pse.dir/Simulator.cpp.o.provides: CMakeFiles/pse.dir/Simulator.cpp.o.requires
	$(MAKE) -f CMakeFiles/pse.dir/build.make CMakeFiles/pse.dir/Simulator.cpp.o.provides.build
.PHONY : CMakeFiles/pse.dir/Simulator.cpp.o.provides

CMakeFiles/pse.dir/Simulator.cpp.o.provides.build: CMakeFiles/pse.dir/Simulator.cpp.o


# Object files for target pse
pse_OBJECTS = \
"CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o" \
"CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o" \
"CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o" \
"CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o" \
"CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o" \
"CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o" \
"CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o" \
"CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o" \
"CMakeFiles/pse.dir/Airplane.cpp.o" \
"CMakeFiles/pse.dir/Airport.cpp.o" \
"CMakeFiles/pse.dir/Gate.cpp.o" \
"CMakeFiles/pse.dir/main.cpp.o" \
"CMakeFiles/pse.dir/Runway.cpp.o" \
"CMakeFiles/pse.dir/Flightplan.cpp.o" \
"CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o" \
"CMakeFiles/pse.dir/AirTrafficController.cpp.o" \
"CMakeFiles/pse.dir/Simulator.cpp.o"

# External object files for target pse
pse_EXTERNAL_OBJECTS =

pse: CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o
pse: CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o
pse: CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o
pse: CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o
pse: CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o
pse: CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o
pse: CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o
pse: CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o
pse: CMakeFiles/pse.dir/Airplane.cpp.o
pse: CMakeFiles/pse.dir/Airport.cpp.o
pse: CMakeFiles/pse.dir/Gate.cpp.o
pse: CMakeFiles/pse.dir/main.cpp.o
pse: CMakeFiles/pse.dir/Runway.cpp.o
pse: CMakeFiles/pse.dir/Flightplan.cpp.o
pse: CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o
pse: CMakeFiles/pse.dir/AirTrafficController.cpp.o
pse: CMakeFiles/pse.dir/Simulator.cpp.o
pse: CMakeFiles/pse.dir/build.make
pse: CMakeFiles/pse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable pse"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pse.dir/build: pse

.PHONY : CMakeFiles/pse.dir/build

CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Parsers/AirplaneParser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Parsers/AirportParser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Parsers/LuchthavenParser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Parsers/RunwayParser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/TinyXML/tinystr.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/TinyXML/tinyxml.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/TinyXML/tinyxmlerror.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/TinyXML/tinyxmlparser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Airplane.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Airport.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Gate.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/main.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Runway.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Flightplan.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Parsers/FlightplanParser.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/AirTrafficController.cpp.o.requires
CMakeFiles/pse.dir/requires: CMakeFiles/pse.dir/Simulator.cpp.o.requires

.PHONY : CMakeFiles/pse.dir/requires

CMakeFiles/pse.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pse.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pse.dir/clean

CMakeFiles/pse.dir/depend:
	cd /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug /Users/robbe/Desktop/Projecten_semester_2/PSE/PSE/cmake-build-debug/CMakeFiles/pse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pse.dir/depend

