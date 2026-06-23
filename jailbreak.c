#include <stdlib.h>
#include <stdio.h>

// 核心触发点：当 rkgame 加载并初始化这个核心时，立刻执行你的越狱脚本
void retro_init(void) {
    // 调用你在 TF 卡里写好的完美脚本
    system("/bin/sh /mnt/sdcard/cubegm/jailbreak.sh");
}

// ==========================================
// 下面是欺骗 rkgame 的"空壳 Libretro API"
// 确保 rkgame 的 dlopen() 不会因为找不到符号而崩溃
// ==========================================
unsigned retro_api_version(void) { return 1; }
void retro_deinit(void) {}
void retro_set_environment(void *cb) {}
void retro_set_video_refresh(void *cb) {}
void retro_set_audio_sample(void *cb) {}
void retro_set_audio_sample_batch(void *cb) {}
void retro_set_input_poll(void *cb) {}
void retro_set_input_state(void *cb) {}
void retro_get_system_info(void *info) {}
void retro_get_system_av_info(void *info) {}
void retro_set_controller_port_device(unsigned port, unsigned device) {}
void retro_reset(void) {}
void retro_run(void) {}
size_t retro_serialize_size(void) { return 0; }
bool retro_serialize(void *data, size_t size) { return 0; }
bool retro_unserialize(const void *data, size_t size) { return 0; }
void retro_cheat_reset(void) {}
void retro_cheat_set(unsigned index, bool enabled, const char *code) {}
bool retro_load_game(const void *game) { return 1; }
bool retro_load_game_special(unsigned game_type, const void *info, size_t num_info) { return 1; }
void retro_unload_game(void) {}
unsigned retro_get_region(void) { return 0; }
void *retro_get_memory_data(unsigned id) { return 0; }
size_t retro_get_memory_size(unsigned id) { return 0; }