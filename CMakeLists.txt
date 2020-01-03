find_package(glm REQUIRED)
add_library(FeatherStone globalOperators.cpp planarVector.cpp spatialVector.cpp spatial.hpp)
target_link_libraries(FeatherStone PUBLIC glm)
add_subdirectory(tests)
