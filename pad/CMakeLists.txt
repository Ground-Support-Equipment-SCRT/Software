add_executable(pad
    main.cpp
)

target_link_libraries(pad PRIVATE
    shared_core
)

if(UNIX)
    find_package(Threads REQUIRED)
    target_link_libraries(pad PRIVATE Threads::Threads)
    target_compile_options(pad PRIVATE -Wall -Wextra -Wpedantic)

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GPIOD REQUIRED libgpiodcxx)
    target_link_libraries(pad PRIVATE ${GPIOD_LIBRARIES})
    target_include_directories(pad PRIVATE ${GPIOD_INCLUDE_DIRS})
elseif(MSVC)
    target_compile_options(pad PRIVATE /W4)
endif()
