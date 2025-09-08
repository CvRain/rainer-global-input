#ifndef KEY_EVENT_HPP
#define KEY_EVENT_HPP

#include <godot_cpp/templates/vector.hpp>
#include <godot_cpp/variant/string.hpp>

#if defined(_WIN32)
    #pragma comment(lib, "user32.lib")
#endif

namespace godot {

// 通用按键事件结构
struct KeyEvent {
    int keycode = 0;          // 键码
    String keyname;           // 键名
    
    KeyEvent() {}
    
    KeyEvent(int p_keycode, const String& p_keyname) :
        keycode(p_keycode),
        keyname(p_keyname) {
    }
};

// 键码到键名的映射接口
class KeyMapping {
public:
    virtual ~KeyMapping() {}
    virtual String get_key_name(int keycode) const = 0;
};

// Windows键码映射
class WindowsKeyMapping : public KeyMapping {
public:
    String get_key_name(int keycode) const override;
};

// Linux键码映射
class LinuxKeyMapping : public KeyMapping {
public:
    String get_key_name(int keycode) const override;
};

// macOS键码映射
class MacOSKeyMapping : public KeyMapping {
public:
    String get_key_name(int keycode) const override;
};

// 获取当前平台的键码映射实例
KeyMapping* get_platform_key_mapping();

} // namespace godot

#endif // KEY_EVENT_HPP