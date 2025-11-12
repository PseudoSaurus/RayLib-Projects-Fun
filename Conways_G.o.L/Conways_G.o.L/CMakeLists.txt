# CMakeList.txt : CMake project for Conways_G.o.L, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Conways_G.o.L "Conways_G.o.L.cpp" "Conways_G.o.L.h" "GameGrid.h" "GameGrid.h" "GameGrid.cpp" "simulation.h" "simulation.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Conways_G.o.L PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
