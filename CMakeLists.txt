message("Processing CMakeLists.txt")

cmake_minimum_required(VERSION 3.27.1) # the currently stable version of CMake is required
project(elen3009-lab-4)

# ====================== Declare Variables ======================

set(SRC_PATH "${CMAKE_SOURCE_DIR}/src/game-plotter") # path to  source code folder
set(MAIN_CPP "main.cpp") # your cpp file that runs your game and contains the entry point main() function
set(GAME_EXE_NAME "graph-plotter") # name of the game executable
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin") # the output directory for the executables
set(WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}) # working directory for exe's so relative paths are correct when running from within VS Code

# ====================== Select Files for Compilation ======================

# CONFIGURE_DEPENDS is used to make sure that the globbing is re-run when a new source or test file is added
file(GLOB GAME_SRC CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/graph-plotter/*.cpp)

# ====================== Download Dependencies ======================

include(FetchContent)

# SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    # corresponds to SFML 2.6.0 - good practice to specify a commit hash, tags can be moved
    GIT_TAG "11b73743c42cf7ecd7c596ba83fdbf1150ffa96c" )

# make the dependencies available to the build system and populate dependency variables like doctest_SOURCE_DIR
FetchContent_MakeAvailable(SFML)

# ====================== Setup Targets ======================

# Game executable target
add_executable(${GAME_EXE_NAME} ${GAME_SRC})
target_compile_features(${GAME_EXE_NAME} PRIVATE cxx_std_17) # enable C++17 features for the target
target_link_libraries(${GAME_EXE_NAME} PRIVATE sfml-audio sfml-graphics) # link privately to hide SFML internal headers




