# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/encrypt_data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/encrypt_data/build

# Include any dependencies generated for this target.
include CMakeFiles/enc_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/enc_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/enc_test.dir/flags.make

CMakeFiles/enc_test.dir/src/main.c.o: CMakeFiles/enc_test.dir/flags.make
CMakeFiles/enc_test.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/encrypt_data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/enc_test.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/enc_test.dir/src/main.c.o   -c /home/ubuntu/encrypt_data/src/main.c

CMakeFiles/enc_test.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/enc_test.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/encrypt_data/src/main.c > CMakeFiles/enc_test.dir/src/main.c.i

CMakeFiles/enc_test.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/enc_test.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/encrypt_data/src/main.c -o CMakeFiles/enc_test.dir/src/main.c.s

# Object files for target enc_test
enc_test_OBJECTS = \
"CMakeFiles/enc_test.dir/src/main.c.o"

# External object files for target enc_test
enc_test_EXTERNAL_OBJECTS =

enc_test: CMakeFiles/enc_test.dir/src/main.c.o
enc_test: CMakeFiles/enc_test.dir/build.make
enc_test: libenc_data.a
enc_test: CMakeFiles/enc_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/encrypt_data/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable enc_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/enc_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/enc_test.dir/build: enc_test

.PHONY : CMakeFiles/enc_test.dir/build

CMakeFiles/enc_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/enc_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/enc_test.dir/clean

CMakeFiles/enc_test.dir/depend:
	cd /home/ubuntu/encrypt_data/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/encrypt_data /home/ubuntu/encrypt_data /home/ubuntu/encrypt_data/build /home/ubuntu/encrypt_data/build /home/ubuntu/encrypt_data/build/CMakeFiles/enc_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/enc_test.dir/depend

