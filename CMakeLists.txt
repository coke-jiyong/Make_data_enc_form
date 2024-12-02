cmake_minimum_required(VERSION 3.16.0)
project(enc_data)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
add_library(${PROJECT_NAME} STATIC src/aes.c src/dec.c src/enc.c src/genRandom.c src/utils.c)
target_link_libraries(${PROJECT_NAME} crypto)
target_include_directories(${PROJECT_NAME} PUBLIC src/include)


add_executable(enc_test src/main.c)
target_link_libraries(enc_test ${PROJECT_NAME})