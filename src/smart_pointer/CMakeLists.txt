project(smart_pointer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(${PROJECT_SOURCE_DIR}/../../include)

set(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})