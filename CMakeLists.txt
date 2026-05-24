cmake_minimum_required(VERSION 3.15)
project(PomodoroWin32 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(PomodoroWin32 WIN32 src/main.c)

target_link_libraries(PomodoroWin32 PRIVATE user32 gdi32)
