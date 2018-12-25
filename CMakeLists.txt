cmake_minimum_required(VERSION 3.13)
project(BasicShell)

set(CMAKE_CXX_STANDARD 14)

# --- Section for adding the library dependencies --- #
# --------------------------------------------------- #
# --- Static library linking --- #
set(PROJECT_LINK_LIBS libSDL2.a)
set(PROJECT_LINK_LIBS libSDL2_test.a)
set(PROJECT_LINK_LIBS libSDL2main.a)
link_directories("/usr/local/lib")

# --- Dynamic library linking --- #
set(PROJECT_LINK_LIBS libSDL2-2.0.0.dylib)
set(PROJECT_LINK_LIBS libSDL2.dylib)
link_directories("/usr/local/lib")
# --------------------------------------------------- #
# --- Header files linking --- #
include_directories("/usr/local/include/SDL2")
include_directories("include")

# --------------------------------------------------- #
# --- Source file linking --- #
file(GLOB SOURCES "src/*.cpp")

add_executable(BasicShell ${SOURCES})
target_link_libraries(BasicShell ${PROJECT_LINK_LIBS})