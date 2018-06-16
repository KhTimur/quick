cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(quick)
set(QUICK_VERSION_MAJOR 0)
set(QUICK_VERSION_MINOR 1)
set(QUICK_VERSION_PATCH 0)
set(QUICK_VERSION_TWEAK 0)
set(QUICK_VERSION 
${QUICK_VERSION_MAJOR}.${QUICK_VERSION_MINOR}.${QUICK_VERSION_PATCH}.${QUICK_VERSION_TWEAK})
set(QUICK_VERSION_STRING "v${QUICK_VERSION}")

add_library(quick ${CMAKE_CURRENT_SOURCE_DIR}/sources/quick.cpp)


target_include_directories(quick PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)


install(TARGETS quick
    EXPORT quick-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT quick-config DESTINATION cmake)

if(BUILD_TESTS)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
endif()

include(CPackConfig.cmake)