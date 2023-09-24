cmake_minimum_required(VERSION 3.10)

project("singly_linked_dynamic_list")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
  thisapp 
  PRIVATE
  ${PROJECT_SOURCE_DIR}/Core/Inc/Menu
  ${PROJECT_SOURCE_DIR}/Core/Inc/List
  ${PROJECT_SOURCE_DIR}/Core/Inc/Log
)

add_executable(
  app.out
  main.cpp
  Core/Src/Menu/Menu.cpp
  Core/Src/Menu/MenuItem.cpp
  Core/Src/Menu/MenuItemFactory.cpp
  Core/Src/List/ListItem.cpp
  Core/Src/List/List.cpp
  Core/Src/Log/Log.cpp
)
