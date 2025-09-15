cmake_minimum_required(VERSION 3.10)

project(pong
  VERSION 0.0.1
  DESCRIPTION "Simple pong implemented with raylib"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib 4.5 REQUIRED)

set(SOURCES
    src/main.cpp
    src/ball.cpp
    src/bat.cpp
    src/game.cpp
    src/logic.cpp
    src/object.cpp
    src/render.cpp
    src/update.cpp
    src/menu.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  raylib
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

