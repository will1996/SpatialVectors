add_subdirectory(Catch2)
add_executable(alltests tests.cpp)
target_link_libraries(alltests Catch2)
target_link_libraries(alltests FeatherStone)


