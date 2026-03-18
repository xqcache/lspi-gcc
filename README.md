# 梁山派使用vscode+arm-none-eabi-gcc+cmake构建


settings.json中配置：
```json
{
    "cortex-debug.armToolchainPath.windows": "D:\\Install\\msys64\\ucrt64\\bin",
    "cortex-debug.gdbPath.windows": "D:\\Install\\msys64\\ucrt64\\bin\\gdb-multiarch.exe",
    "cortex-debug.openocdPath.windows": "D:\\Install\\msys64\\ucrt64\\bin\\openocd.exe",
    "cmake.environment": {
        "PATH": "D:\\Install\\msys64\\ucrt64\\bin;${env:PATH}"
    }
}
```