#include <stdio.h>
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#define TAG "SHIFT_SPI"

// Pin definitions
#define PIN_NUM_MISO   27   // QH -> ESP32 MISO
#define PIN_NUM_CLK    33   // Clock pin
#define PIN_NUM_SHLD   32   // SH/LD pin (active low)

// SPI host to use
#define SPI_HOST_USED  SPI2_HOST   // VSPI_HOST or SPI2_HOST

spi_device_handle_t shift_dev;

// Initialize SH/LD pin as GPIO
static void shld_pin_init(void) {
    gpio_config_t io_conf = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << PIN_NUM_SHLD),
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);
    gpio_set_level(PIN_NUM_SHLD, 1); // Keep high (shift mode) by default
}

// Load parallel data into 74HC165
static void load_parallel_data(void) {
    gpio_set_level(PIN_NUM_SHLD, 0); // Load mode (parallel load)
    esp_rom_delay_us(5);             // Wait for data to latch
    gpio_set_level(PIN_NUM_SHLD, 1); // Back to shift mode
}

// Initialize SPI for reading shift register
static void spi_shiftreg_init(void) {
    spi_bus_config_t buscfg = {
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = -1,   // Not used
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1
    };
    ESP_ERROR_CHECK(spi_bus_initialize(SPI_HOST_USED, &buscfg, SPI_DMA_CH_AUTO));

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1 * 1000 * 1000, // 1 MHz
        .mode = 0,                         // SPI mode 0
        .spics_io_num = -1,                // No CS (we use SH/LD separately)
        .queue_size = 1
    };
    ESP_ERROR_CHECK(spi_bus_add_device(SPI_HOST_USED, &devcfg, &shift_dev));
}

// Read 8 bits from shift register
static uint8_t spi_read_shiftreg(void) {
    uint8_t rx_data = 0;
    spi_transaction_t t = {
        .length = 8,        // 8 bits
        .rx_buffer = &rx_data,
        .tx_buffer = NULL
    };
    load_parallel_data(); // Capture the sensor states
    ESP_ERROR_CHECK(spi_device_transmit(shift_dev, &t));
    return rx_data;
}

void app_main(void) {
    ESP_LOGI(TAG, "Initializing SPI shift register reader...");
    shld_pin_init();
    spi_shiftreg_init();

    while (1) {
        uint8_t val = spi_read_shiftreg();

        printf("Sensors: ");
        for (int i = 0; i < 8; i++) {
            printf("%d ", (val >> i) & 1);
        }
        printf("\n");

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

