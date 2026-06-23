#!/bin/sh
# ===================================================
# TreeFrog-UI 越狱脚本 - R36SX v2.7 专用
# ===================================================

# 记录执行开始
echo "=== JAILBREAK START ===" > /mnt/sdcard/jailbreak.log
echo "Time: 06/23/2026 22:03:48" >> /mnt/sdcard/jailbreak.log

# 第一步：解除 noexec 封印 - 将 TF 卡重新挂载为可执行
echo "Remounting TF card..." >> /mnt/sdcard/jailbreak.log
mount -o remount,exec /mnt/sdcard 2>> /mnt/sdcard/jailbreak.log

# 第二步：杀死宿主 rkgame 进程，释放硬件控制权
echo "Killing rkgame..." >> /mnt/sdcard/jailbreak.log
killall -9 rkgame 2>> /mnt/sdcard/jailbreak.log

# 短暂延迟，确保进程完全退出
sleep 1

# 第三步：启动 TreeFrog-UI (picoarch)
echo "Launching TreeFrog-UI..." >> /mnt/sdcard/jailbreak.log
cd /mnt/sdcard/cubegm
./picoarch ./cores/frogui_libretro.so >> /mnt/sdcard/jailbreak.log 2>&1 &

echo "=== JAILBREAK COMPLETE ===" >> /mnt/sdcard/jailbreak.log