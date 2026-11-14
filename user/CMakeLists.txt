add_executable(user
    main.cpp
)

target_link_libraries(user PRIVATE
    pico_stdlib
    pico_cyw43_arch_none
    shared_core
)

target_compile_options(user PRIVATE -Wall -Wextra)

pico_enable_stdio_usb(user 1)
pico_enable_stdio_uart(user 0)

pico_add_extra_outputs(user)
