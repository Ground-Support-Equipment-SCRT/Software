# GSE Firmware
Tree:
- Shared code (like securing of RF link) is in `common/`. Currently headers only.
- RF Enclosure firmware under `rfbox/`.
- User enclosure firmware under `user/`.
- Pad enclosure application under `pad`.

Primary link is ESRA supplied networking (private VLAN). Pad sends continuous telemetry
at its own volition. User enclosure sends ignition commands over networking. On failure,
the RF path is used: user enclosure sends commands and telemetry request to pad every
2500ms, pad responds over RF.

Control flow: `User enclosure & Pico -> LoRa -> RF Enclosure -> RS485 -> Pad enclosure & Pi 5 `

## Pico firmware
To build the RF and user side enclosure firmware, run `cmake --preset pico-debug && cmake --build --preset pico-debug`,
or `cmake --preset pico-release && cmake --build --preset pico-release` for the final build. Copy the .uf2 firmware
files from `build/{rfbox,user}` to the Picos in BOOTSEL mode, or flash them with picotool.
