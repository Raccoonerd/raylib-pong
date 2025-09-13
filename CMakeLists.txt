cmake_minimum_required(VERSION 3.10)

project(playground)

set(CMAKE_CXX_STANDARD 17)

# === Szukanie raylib ===
find_package(raylib 4.5 QUIET)

if (NOT raylib_FOUND)
    # Jeśli raylib nie jest zainstalowany systemowo, pobierzemy go przez FetchContent
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0   # wersja raylib
    )
    FetchContent_MakeAvailable(raylib)
endif()

# === Katalogi z nagłówkami ===
include_directories(include)

# === Pliki źródłowe ===
file(GLOB SOURCES src/*.cpp)

# === Tworzenie pliku wykonywalnego ===
add_executable(${PROJECT_NAME} ${SOURCES})

# === Linkowanie ===
target_link_libraries(${PROJECT_NAME} raylib)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} m pthread dl)
endif()

# === Kopiowanie assets/ do build/ ===
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

