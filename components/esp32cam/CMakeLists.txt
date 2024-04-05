file(GLOB_RECURSE SOURCES "esp32cam/src/*.cpp")

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "esp32cam/src"
                    REQUIRES arduino-esp32 esp32-camera)