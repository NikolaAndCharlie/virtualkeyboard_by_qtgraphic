cmake_minimum_required(VERSION 3.24)
set(project_name "virtual_keyboard")
project(${project_name})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS
 Core
 Gui
 Widgets
)

file(GLOB SRC src/*.cpp)
file(GLOB HDR src/*.h)

add_executable(${project_name} WIN32)

target_link_libraries(${project_name}
  PRIVATE
  Qt6::Core
  Qt6::Widgets
  Qt6::Gui
)

target_sources(${project_name}
  PRIVATE
  ${SRC}
  ${HDR}
)
