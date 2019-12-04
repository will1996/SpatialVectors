find_package(glm REQUIRED)
add_library(spatialVector spatialVector.cpp spatialVector.hpp)
target_link_libraries(spatialVector PUBLIC glm)
