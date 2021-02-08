## Project Setup

1. Put all the code files into a `src` folder.
2. Create a `CMakeLists.txt` file.
3. In the cmake file, define the following:
    a) minimum version of CMAKE to use: `cmake_minimum_required(VERSION 3.5.1)`
    b) version of C++ to use: `set(CMAKE_CXX_STANDARD 17)`
    c) project name: `project(<your_project_name>)`
4. Once the above steps are done then, add an executable to project as follows:
`add_executable(your_executable_name  path_to_file_1  path_to_file_2 ...)`


## Build and Run the Project

To build this project, do the following:

1. Create a `build` folder outside the `src` folder.
2. Go inside the `build` folder.
3. Direct the `cmake` to `CMakeLists.txt` file using: `cmake ..`
4. This command uses the `CMakeLists.txt` to configure the project and create a `Makefile` in the `build` directory.
5. The above steps will create your `executable` file as specified in the `CMakeLists.txt` file.
6. Run the executable as: `./your_executable_name`

If after these steps, you make any changes to the files, then you only need to run the `make` command. Make will be able to keep track of which files have changed and compile only those that need to be compiled before building.