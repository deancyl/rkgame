# TreeFrog-UI R36SX v2.7 Jailbreak

## 自动编译方法

### 使用 GitHub Actions（推荐）

1. 将此仓库推送到 GitHub:
   git add .
   git commit -m "Add jailbreak source"
   git push

2. 在 GitHub 网页上:
   - 进入 Actions 标签页
   - 点击 "Compile MIPS Jailbreak" 工作流
   - 点击 "Run workflow" 按钮
   - 等待编译完成（约 2 分钟）

3. 下载编译好的 .so 文件:
   - 在工作流页面点击 Artifacts
   - 下载 jailbreak-so.zip
   - 解压得到 libemu_jailbreak.so

4. 部署到 TF 卡（参见 部署指南.txt）

---

## 手动编译方法

如果 GitHub Actions 不可用，可以使用 Docker:

docker run --rm -v D:\opencode\rootfs2:/work ubuntu:22.04 bash -c "apt-get update && apt-get install -y gcc-mipsel-linux-gnu libc6-dev-mipsel-cross && mipsel-linux-gnu-gcc -shared -fPIC -march=mips32r2 -O2 -o /work/libemu_jailbreak.so /work/jailbreak.c"

---

## 文件说明

- jailbreak.c - Libretro 核心源码
- jailbreak.sh - 越狱脚本
- 部署指南.txt - 详细部署步骤
