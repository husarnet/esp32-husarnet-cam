# Husarnet ESP32 Webcam Example

This example demonstrates how to use the Husarnet library to stream video. Stream performance highly depends on a selected ESP microcontroller and camera resolution.

To use Arduino libraries in your project and still have access to extended features of ESP-IDF, you can use the ESP-IDF framework in a [Arduino as a component](https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html) configuration. As stated by the Espressif documentation, this setup is recommended for advanced users and has some limitations.

For more details, refer to the [official Espressif documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html).

## Quickstart

Clone the repository and submodules (used for external Arduino libraries):

```bash
git clone --recurse-submodules https://github.com/husarnet/esp32-husarnet-cam
cd esp32-husarnet-cam
```

Set your Husarnet join code and Wi-Fi credentials in the `main/main.cpp` file.

```cpp
#define HOSTNAME  "husarnet-esp32-cam"
#define JOIN_CODE "XXXXXXXXXXXXXXXXXX"

#define WIFI_SSID "your_ssid"
#define WIFI_PASS "your_password"
```

Flash the project to your ESP32 device:
```bash
idf.py build && idf.py flash
```

For more details on how to use Arduino libraries in ESP-IDF projects, refer to the [official documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html).
