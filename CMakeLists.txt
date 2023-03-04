cmake_minimum_required(VERSION 3.15)

project(Sajf++ VERSION 1.0 DESCRIPTION "Sajf written in C++.")

add_subdirectory(lib/DPP)
add_subdirectory(lib/sajf)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/commands.cpp
)

target_link_libraries(${PROJECT_NAME}
    dpp
    sajf
)

target_include_directories(${PROJECT_NAME} PRIVATE
    lib/DPP/include
    lib/sajf/include
    include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)