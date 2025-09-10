#include "hook_windows.hpp"
#include <godot_cpp/core/print_string.hpp>
#include "key_event.hpp"

#if defined(_WIN32)

using namespace godot;

// 定义并获取按键事件Vector
godot::Vector<godot::KeyEvent>& get_key_event_vector() {
    static Vector<KeyEvent> key_event_vector;
    return key_event_vector;
}
HHOOK keyboardHook = nullptr;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT *)lParam;
        
        // 获取键名
        KeyMapping* mapping = get_platform_key_mapping();
        String keyname = mapping->get_key_name(ks->vkCode);
        
        // 将按键码和键名添加到Vector中
        get_key_event_vector().push_back(KeyEvent(ks->vkCode, keyname));
        
        // 输出调试信息
        print_line("Key pressed: " + itos(ks->vkCode) + " (" + keyname + ")");
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

void initKeyboardHook() {
    if (keyboardHook == nullptr) {
        keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(nullptr), 0);
    }
}

void processKeyEvents() {
    // 清空Vector
    get_key_event_vector().clear();
}

#endif // defined(_WIN32)