add_executable(rfbox
    main.cpp
)

target_link_libraries(rfbox PRIVATE
    pico_stdlib
    pico_cyw43_arch_none
    shared_core
)

target_compile_options(rfbox PRIVATE -Wall -Wextra)

pico_enable_stdio_usb(rfbox 1)
pico_enable_stdio_uart(rfbox 0)

pico_add_extra_outputs(rfbox)
