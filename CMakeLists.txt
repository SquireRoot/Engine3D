# Set the minimum cmake version
cmake_minimum_required(VERSION 3.10.0)

# set the project name and version
project(Engine3D VERSION 0.1.0)

# set the source directory environment variable
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# set the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# find all source and header files in the src directory
file(GLOB_RECURSE SOURCE_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.c)
file(GLOB_RECURSE HEADER_FILES ${SRC_DIR}/*.h)

# setup the cmake module path, used for the FindGLFW3 cmake thing
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# create the CMakeConfig.h file
configure_file(${PROJECT_SOURCE_DIR}/cmake/CMakeConfig.h.in ${SRC_DIR}/CMakeConfig.h)

# find and add the GLFW3 package
find_package(GLFW3 REQUIRED)
set(LIBS ${LIBS} ${GLFW3_LIBRARY})
set(INCLUDES ${INCLUDES} ${GLFW3_INCLUDE_DIR})

# find and add vulkan
find_package(Vulkan REQUIRED)
set(LIBS ${LIBS} ${Vulkan_LIBRARIES})
set(INCLUDES ${INCLUDES} ${Vulkan_INCLUDE_DIRS})

# add the ext folder to the includes
set(INCLUDES ${INCLUDES} ${PROJECT_SOURCE_DIR}/ext)

# Add other platform dependent stuff
if (WIN32) # if we are on windows
    message("Windows detected")
    set(LIBS ${LIBS} ) # add the needed libraries to the LIBS variable

elseif(UNIX AND NOT APPLE) # if we are on unix
    message("Unix detected")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    
    set(LIBS ${LIBS} )
    
else()
    set(LIBS ${LIBS} )
    
endif(WIN32)

# generate the executable for the project
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# set the include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

# link the libraries set in the libs variable
target_link_libraries(${PROJECT_NAME} ${LIBS})