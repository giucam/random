
add_library(lib SHARED lib.cpp)

add_executable(exe main.cpp)
target_link_libraries(exe lib)
