cmake_minimum_required(VERSION 3.4)

project(QSnake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets Core)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_executable(QSnake
    main.cpp mainwindow.cpp snake.cpp res.qrc
    block.cpp fruit.cpp
)
target_link_libraries(QSnake Qt5::Widgets Qt5::Core)
