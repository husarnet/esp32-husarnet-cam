# Husarnet ESP32 Webcam Example

This example demonstrates how to use the Husarnet library to stream video. Stream performance highly depends on a selected ESP microcontroller and camera resolution.

This repo also serves as a demonstration on how to include Arduino libraries in your project and still have access to extended features of ESP-IDF. Arduino Core is used as [an ES{-IDF component](https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html).

## Quickstart

Clone the repository, set your Husarnet join code and Wi-Fi credentials in the `main/husarnet_web_server.c` file and build the project using `idf.py` tool.

```bash
git clone https://github.com/miloszlagan/esp32-husarnet-cam
cd esp32-husarnet-cam
```

Flash the project to your ESP32 device:
```bash
idf.py build && idf.py flash
```

For more details on how to use Arduino libraries in ESP-IDF projects, refer to the [official documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/esp-idf_component.html).
