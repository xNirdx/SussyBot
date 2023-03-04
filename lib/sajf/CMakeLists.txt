cmake_minimum_required(VERSION 3.15)

project(sajf VERSION 1.0 DESCRIPTION "Sajf Discord bot library")

add_library(${PROJECT_NAME} 
    src/bot.cpp
    src/command.cpp
)

target_link_libraries(${PROJECT_NAME} dpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    lib/DPP/include
    include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)