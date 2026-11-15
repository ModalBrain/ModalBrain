cmake_minimum_required(VERSION 3.20)
project(ModalBrainDSP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only core DSP interface library
add_library(modalbrain_dsp INTERFACE)
target_include_directories(modalbrain_dsp INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Test executable
enable_testing()
add_executable(test_modal_resonator tests/test_modal_resonator.cpp)
target_link_libraries(test_modal_resonator PRIVATE modalbrain_dsp)
add_test(NAME test_modal_resonator COMMAND test_modal_resonator)
