project(atomic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# for thread
find_package(Threads)

include_directories(${PROJECT_SOURCE_DIR}/../../include)

set(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# link thread libraries
target_link_libraries (${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})