include(CTest)

add_executable(TestSystemDetect SystemDetect.cpp)
target_link_libraries(TestSystemDetect PRIVATE SystemDetect)
