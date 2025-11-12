# CMakeList.txt : CMake project for SpaceInvader_Main, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (SpaceInvader_Main "SpaceInvader_Main.cpp" "SpaceInvader_Main.h" "SpaceShip.hpp" "Game.cpp" "BarrierBlocks.cpp" "alienAI.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpaceInvader_Main PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
