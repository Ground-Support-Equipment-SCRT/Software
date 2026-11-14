add_library(shared_core INTERFACE)

target_include_directories(shared_core INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_compile_features(shared_core INTERFACE cxx_std_17)
