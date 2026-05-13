cmake_minimum_required(VERSION 3.10)

project(lab07_solver VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(lab07_solver STATIC
  src/quadratic.cpp
)

add_library(lab07_solver::lab07_solver ALIAS lab07_solver)

target_compile_features(lab07_solver PUBLIC cxx_std_11)

target_include_directories(lab07_solver
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(lab07_solver PROPERTIES
  EXPORT_NAME lab07_solver
)

install(
  TARGETS lab07_solver
  EXPORT lab07_solverTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/lab07_solverConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/lab07_solverConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/lab07_solverConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab07_solver
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/lab07_solverConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/lab07_solverConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab07_solver
)

install(
  EXPORT lab07_solverTargets
  NAMESPACE lab07_solver::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/lab07_solver
)
