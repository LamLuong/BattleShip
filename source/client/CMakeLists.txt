cmake_minimum_required(VERSION 3.5)
project(ballteShipClient)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

# Create your game executable target as usual
file(GLOB SRC *.cpp)
file(GLOB UTILS_SRC utils/*.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRC} ${UTILS_SRC})

# Link to the actual SDL3 library.
target_link_libraries(${CMAKE_PROJECT_NAME}
                      ${SDL2_LIBRARIES}
                      ${SDL2IMAGE_LIBRARIES}
                     )