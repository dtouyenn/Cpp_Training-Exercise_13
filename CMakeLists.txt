cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

project(app)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(HDR_DIR ${CMAKE_SOURCE_DIR}/hdr)
# include_directories(${HDR})
aux_source_directory(${SRC_DIR} SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${HDR_DIR})



