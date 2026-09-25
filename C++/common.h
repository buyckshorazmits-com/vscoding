#pragma once
#include <windows.h>

// 全局静态对象，在 main() 之前自动设置控制台编码
// 注意：只设置"输出"为 UTF-8（解决中文显示），
// 不设置"输入"代码页——否则在 UTF-8 输入模式下，
// 控制台输入不回显（看不到自己敲的数字），且 cin 读中文会乱码。
namespace {
    struct __ConsoleInit {
        __ConsoleInit() {
            SetConsoleOutputCP(CP_UTF8);
        }
    };
    static __ConsoleInit __console_init_instance__;
}
