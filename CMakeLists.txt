cmake_minimum_required(VERSION 3.14)

find_program(CCACH_PROGRAM ccach)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

project(PLang C)

add_executable(
	plang
	src/main.c
  src/token.c
  src/errors.c
)
