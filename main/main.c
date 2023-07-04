#include <stdio.h>  // Added to include printf function

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_wifi.h>
#include <esp_log.h>
#include <esp_event_loop.h>
#include <nvs_flash.h>

#define MAX_APs 20

static esp_err_t event_handler(void* arg, esp_event_base_t event_base, int32_t event_id) {
    // Handle events here
    return ESP_OK;
}

void wifiInit() {
    ESP_ERROR_CHECK(nvs_flash_init());

//   int i =   tcpip_adapter_init(); // Initialize the TCP/IP adapter
    

    ESP_ERROR_CHECK(esp_event_loop_create_default());  // Updated to esp_event_loop_create_default

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());
}

void app_main() {
    wifiInit();
    wifi_scan_config_t scanConf = {
        .ssid = NULL,
        .bssid = NULL,
        .channel = 0,
        .show_hidden = true
    };
    
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scanConf, true));
    uint16_t apCount = 0;
    esp_wifi_scan_get_ap_num(&apCount);
    printf("Found %d access points\n", apCount);
    if (apCount == 0) {
        printf("Nothing to do now\n");
        return;
    }
    wifi_ap_record_t apRecords[MAX_APs];
    ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&apCount, apRecords));
    for (int i = 0; i < apCount; i++) {
        printf("SSID \t\t%s\n", apRecords[i].ssid);
        printf("RSSI \t\t%d\n", apRecords[i].rssi);
        printf("Channel \t%d\n", apRecords[i].primary);
        printf("Authmode \t%d\n", apRecords[i].authmode);
        printf("MAC \t\t");
        for (int j = 0; j < 6; j++) {
            printf("%02x ", apRecords[i].bssid[j]);
        }
        printf("\n\n");
    }
}
