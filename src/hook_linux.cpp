#include "hook_linux.hpp"
#include <godot_cpp/core/print_string.hpp>
#include <cstring>
#include <thread>

#if defined (__linux__) || defined (__unix__)

using namespace godot;

// 定义并获取按键事件Vector
godot::Vector<godot::KeyEvent>& get_key_event_vector() {
    static Vector<KeyEvent> key_event_vector;
    return key_event_vector;
}

// X11相关变量
static Display* display = nullptr;
static std::thread event_thread;
static bool hook_active = false;

// X11事件处理函数
static void x11_event_handler() {
    // 为当前线程打开一个新的显示连接
    Display* local_display = XOpenDisplay(nullptr);
    if (!local_display) {
        print_line("无法打开X11显示连接");
        return;
    }
    
    // 获取根窗口
    Window root = DefaultRootWindow(local_display);
    
    // 设置键盘事件捕获
    XSelectInput(local_display, root, KeyPressMask);
    
    // 获取键盘映射表
    KeyMapping* mapping = get_platform_key_mapping();
    
    XEvent ev;
    while (hook_active) {
        // 检查是否有事件
        if (XCheckMaskEvent(local_display, KeyPressMask, &ev)) {
            if (ev.type == KeyPress) {
                // 获取键码
                KeyCode keycode = ev.xkey.keycode;
                
                // 获取键名
                String keyname = mapping->get_key_name(keycode);
                
                // 添加到事件Vector
                get_key_event_vector().push_back(KeyEvent(keycode, keyname));
                
                // 输出调试信息
                print_line("Key pressed: " + itos(keycode) + " (" + keyname + ")");
            }
        }
        
        // 避免过度占用CPU
        usleep(1000); // 1毫秒
    }
    
    XCloseDisplay(local_display);
}

bool is_running_on_wayland() {
    const char* wayland_display = getenv("WAYLAND_DISPLAY");
    return wayland_display != nullptr;
}

void initKeyboardHook() {
    // 如果运行在Wayland上则不初始化
    if (is_running_on_wayland()) {
        print_line("检测到Wayland环境，无法初始化X11键盘钩子");
        return;
    }
    
    if (!hook_active) {
        // 打开X11显示连接
        display = XOpenDisplay(nullptr);
        if (!display) {
            print_line("无法打开X11显示连接");
            return;
        }
        
        hook_active = true;
        event_thread = std::thread(x11_event_handler);
        print_line("X11键盘钩子初始化成功");
    }
}

void processKeyEvents() {
    // 清空Vector
    get_key_event_vector().clear();
}

#endif