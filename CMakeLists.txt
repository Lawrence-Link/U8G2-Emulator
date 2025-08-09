cmake_minimum_required(VERSION 3.16)
project(U8g2Emulator LANGUAGES CXX)

# ==============================
# 1. 基础配置
# ==============================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WITH_QT "Enable Qt GUI mode" OFF)

# ==============================
# 2. U8g2 submodule
# ==============================
add_subdirectory(third_party/u8g2 EXCLUDE_FROM_ALL)

# ==============================
# 3. 源码文件
# ==============================
set(SOURCES
    src/main.cpp
    src/emulator_backend.cpp
    src/emulator_headless.cpp
    src/emulator_arg_parser.cpp
    src/emulator_qt.cpp
    src/u8g2_wrapper.cpp
    src/u8x8_null.cpp
)

set(HEADERS
    include/emulator_backend.h
    include/emulator_headless.h
    include/emulator_arg_parser.h
    include/u8g2_wrapper.h
)

# ==============================
# 4. 如果启用 Qt 模式
# ==============================
if(WITH_QT)
    find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

    list(APPEND SOURCES src/emulator_qt.cpp)
    list(APPEND HEADERS include/emulator_qt.h)

    qt_wrap_cpp(MOC_SOURCES ${HEADERS})
    add_executable(u8g2_emulator ${SOURCES} ${MOC_SOURCES})
    add_definitions(-DUSE_QT_GUI)

    target_link_libraries(u8g2_emulator
        PRIVATE
        u8g2
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
    )
else()
    add_executable(u8g2_emulator ${SOURCES})
    target_link_libraries(u8g2_emulator PRIVATE u8g2)
endif()

# ==============================
# 5. 头文件路径
# ==============================
target_include_directories(u8g2_emulator PRIVATE
    include
    third_party/u8g2/csrc
)
