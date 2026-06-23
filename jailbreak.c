#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h> /* 显式引入布尔支持，修复 bool/true/false 编译报错 */

/* 前置声明 Libretro 依赖的未知结构体指针，防止编译器因找不到类型而报错 */
struct retro_system_info;
struct retro_system_av_info;
struct retro_game_info;

/* 越狱核心：当原厂前端加载并初始化此核心时，立刻执行你的脚本 */
void retro_init(void) {
    system("/bin/sh /mnt/sdcard/cubegm/jailbreak.sh");
}

/* =======================================================
   完美对齐的空壳 Libretro API（确保 dlopen() 完美欺骗 rkgame）
   ======================================================= */
unsigned retro_api_version(void) { return 1; }
void retro_deinit(void) {}
void retro_set_environment(void *cb) {}
void retro_set_video_refresh(void *cb) {}
void retro_set_audio_sample(void *cb) {}
void retro_set_audio_sample_batch(void *cb) {}
void retro_set_input_poll(void *cb) {}
void retro_set_input_state(void *cb) {}
void retro_get_system_info(struct retro_system_info *info) {}
void retro_get_system_av_info(struct retro_system_av_info *info) {}
void retro_set_controller_port_device(unsigned port, unsigned device) {}
void retro_reset(void) {}
void retro_run(void) {}
size_t retro_serialize_size(void) { return 0; }
bool retro_serialize(void *data, size_t size) { return false; }
bool retro_unserialize(const void *data, size_t size) { return false; }
void retro_cheat_reset(void) {}
void retro_cheat_set(unsigned index, bool enabled, const char *code) {}
bool retro_load_game(const struct retro_game_info *game) { return true; }
bool retro_load_game_special(unsigned game_type, const struct retro_game_info *info, size_t num_info) { return true; }
void retro_unload_game(void) {}
unsigned retro_get_region(void) { return 0; }
void *retro_get_memory_data(unsigned id) { return NULL; }
size_t retro_get_memory_size(unsigned id) { return 0; }
