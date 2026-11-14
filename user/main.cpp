#include <cstdio>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

namespace {
constexpr uint32_t BLINK_INTERVAL_MS = 500;
}

int main() {
    stdio_init_all();

    // Initialize CYW43 driver in 'none' mode
    if (cyw43_arch_init() != 0) {
        printf("Failed to initialize CYW43 for onboard LED\n");
        return 1;
    }

    bool led_state = false;

    while (true) {
        led_state = !led_state;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_state);

        printf("led %s\n", led_state ? "on" : "off");

        sleep_ms(BLINK_INTERVAL_MS);
    }

    return 0;
}
