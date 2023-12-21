#include <nvs_flash.h>
#include <esp_log.h>

#include "sdkconfig.h"
#include "fs_init.h"

#include <furi_hal.h>
#include <desktop/desktop.h>
#include <dialogs/dialogs.h>
#include <assets_icons.h>

static const char* TAG = "application";

extern Canvas* canvas_init();

extern int32_t gui_srv(void* p);
extern int32_t desktop_srv(void* p);
extern int32_t loader_srv(void* p);
extern int32_t dialogs_srv(void* p);
extern int32_t dolphin_srv(void* p);
extern int32_t input_srv(void* p);
extern int32_t notification_srv(void* p);
extern int32_t storage_srv(void* p);

#include <services/gui/scene_manager.h>
#include <desktop/views/desktop_events.h>
extern Desktop* shared_desktop;
extern bool desktop_scene_main_on_event(void* context, SceneManagerEvent event);
SceneManagerEvent event = {
    .event = DesktopMainEventOpenMenu,
    .type = SceneManagerEventTypeCustom
};

int32_t main_task(void* param) {
    FuriString* error_message = furi_string_alloc();
    furi_string_set(error_message, "Hello, world!");
    DialogsApp* dialogs = furi_record_open(RECORD_DIALOGS);
    DialogMessage* message = dialog_message_alloc();
    dialog_message_set_header(message, "Error", 64, 0, AlignCenter, AlignTop);
    dialog_message_set_buttons(message, NULL, NULL, NULL);
    dialog_message_set_text(
        message,
        furi_string_get_cstr(error_message),
        64, 35,
        AlignCenter, AlignCenter
    );

    while (1) {
        furi_delay_ms(1000L);
        dialog_message_show(dialogs, message);
    }

    dialog_message_free(message);
    furi_record_close(RECORD_DIALOGS);
    furi_string_free(error_message);
    return 0;
}

void furi_start_service(const char* name, FuriThreadCallback callback) {
    FuriThread* thread = furi_thread_alloc_ex(name, 2048, callback, NULL);
    furi_thread_mark_as_service(thread);
    furi_thread_set_appid(thread, name);
    furi_thread_start(thread);
}

void app_main(void) {
    ESP_LOGD(TAG, "init complete");

    furi_log_set_level(FuriLogLevelDebug);
    furi_hal_init();
    furi_init();

//    Canvas* canvas = canvas_init();
//    canvas_draw_icon(canvas, 0, 0, &I_DolphinReadingSuccess_59x63);
//    canvas_commit(canvas);

    furi_start_service("desktop", &desktop_srv);
    furi_start_service("dialogs", &dialogs_srv);
    furi_start_service("dolphin", &dolphin_srv);
    furi_start_service("gui", &gui_srv);
    furi_start_service("input", &input_srv);
    furi_start_service("loader", &loader_srv);
    furi_start_service("notification", &notification_srv);
//    furi_start_service("storage", &storage_srv);

//    furi_start_service("custom", &main_task);
}
