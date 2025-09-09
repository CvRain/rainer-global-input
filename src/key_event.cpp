#include "key_event.hpp"

namespace godot {

// Windows键码映射实现
String WindowsKeyMapping::get_key_name(int keycode) const {
    switch (keycode) {
        case 0x08: return "BACKSPACE";
        case 0x09: return "TAB";
        case 0x0C: return "CLEAR";
        case 0x0D: return "ENTER";
        case 0x10: return "SHIFT";
        case 0x11: return "CTRL";
        case 0x12: return "ALT";
        case 0x13: return "PAUSE";
        case 0x14: return "CAPS_LOCK";
        case 0x1B: return "ESCAPE";
        case 0x20: return "SPACE";
        case 0x21: return "PAGE_UP";
        case 0x22: return "PAGE_DOWN";
        case 0x23: return "END";
        case 0x24: return "HOME";
        case 0x25: return "LEFT_ARROW";
        case 0x26: return "UP_ARROW";
        case 0x27: return "RIGHT_ARROW";
        case 0x28: return "DOWN_ARROW";
        case 0x2C: return "PRINT_SCREEN";
        case 0x2D: return "INSERT";
        case 0x2E: return "DELETE";
        case 0x30: return "0";
        case 0x31: return "1";
        case 0x32: return "2";
        case 0x33: return "3";
        case 0x34: return "4";
        case 0x35: return "5";
        case 0x36: return "6";
        case 0x37: return "7";
        case 0x38: return "8";
        case 0x39: return "9";
        case 0x41: return "A";
        case 0x42: return "B";
        case 0x43: return "C";
        case 0x44: return "D";
        case 0x45: return "E";
        case 0x46: return "F";
        case 0x47: return "G";
        case 0x48: return "H";
        case 0x49: return "I";
        case 0x4A: return "J";
        case 0x4B: return "K";
        case 0x4C: return "L";
        case 0x4D: return "M";
        case 0x4E: return "N";
        case 0x4F: return "O";
        case 0x50: return "P";
        case 0x51: return "Q";
        case 0x52: return "R";
        case 0x53: return "S";
        case 0x54: return "T";
        case 0x55: return "U";
        case 0x56: return "V";
        case 0x57: return "W";
        case 0x58: return "X";
        case 0x59: return "Y";
        case 0x5A: return "Z";
        case 0x5B: return "LEFT_META";
        case 0x5C: return "RIGHT_META";
        case 0x5D: return "CONTEXT_MENU";
        case 0x60: return "NUMPAD_0";
        case 0x61: return "NUMPAD_1";
        case 0x62: return "NUMPAD_2";
        case 0x63: return "NUMPAD_3";
        case 0x64: return "NUMPAD_4";
        case 0x65: return "NUMPAD_5";
        case 0x66: return "NUMPAD_6";
        case 0x67: return "NUMPAD_7";
        case 0x68: return "NUMPAD_8";
        case 0x69: return "NUMPAD_9";
        case 0x6A: return "MULTIPLY";
        case 0x6B: return "ADD";
        case 0x6C: return "SEPARATOR";
        case 0x6D: return "SUBTRACT";
        case 0x6E: return "DECIMAL";
        case 0x6F: return "DIVIDE";
        case 0x70: return "F1";
        case 0x71: return "F2";
        case 0x72: return "F3";
        case 0x73: return "F4";
        case 0x74: return "F5";
        case 0x75: return "F6";
        case 0x76: return "F7";
        case 0x77: return "F8";
        case 0x78: return "F9";
        case 0x79: return "F10";
        case 0x7A: return "F11";
        case 0x7B: return "F12";
        case 0x7C: return "F13";
        case 0x7D: return "F14";
        case 0x7E: return "F15";
        case 0x7F: return "F16";
        case 0x80: return "F17";
        case 0x81: return "F18";
        case 0x82: return "F19";
        case 0x83: return "F20";
        case 0x84: return "F21";
        case 0x85: return "F22";
        case 0x86: return "F23";
        case 0x87: return "F24";
        case 0x90: return "NUM_LOCK";
        case 0x91: return "SCROLL_LOCK";
        case 0xA0: return "LEFT_SHIFT";
        case 0xA1: return "RIGHT_SHIFT";
        case 0xA2: return "LEFT_CONTROL";
        case 0xA3: return "RIGHT_CONTROL";
        case 0xA4: return "LEFT_ALT";
        case 0xA5: return "RIGHT_ALT";
        default: 
            if (keycode >= 0x30 && keycode <= 0x39) {
                return String::chr('0' + (keycode - 0x30));
            } else if (keycode >= 0x41 && keycode <= 0x5A) {
                return String::chr('A' + (keycode - 0x41));
            }
            return "UNKNOWN";
    }
}

// Linux键码映射实现 (基于X11键码定义)
String LinuxKeyMapping::get_key_name(int keycode) const {
    switch (keycode) {
        case 0xff08: return "BACKSPACE";
        case 0xff09: return "TAB";
        case 0xff0d: return "ENTER";
        case 0xff13: return "PAUSE";
        case 0xff14: return "SCROLL_LOCK";
        case 0xff1b: return "ESCAPE";
        case 0xff50: return "HOME";
        case 0xff51: return "LEFT_ARROW";
        case 0xff52: return "UP_ARROW";
        case 0xff53: return "RIGHT_ARROW";
        case 0xff54: return "DOWN_ARROW";
        case 0xff55: return "PAGE_UP";
        case 0xff56: return "PAGE_DOWN";
        case 0xff57: return "END";
        case 0xff61: return "PRINT_SCREEN";
        case 0xff63: return "INSERT";
        case 0xff7f: return "NUM_LOCK";
        case 0xff8d: return "KP_ENTER";
        case 0xff95: return "KP_7";
        case 0xff96: return "KP_4";
        case 0xff97: return "KP_1";
        case 0xff98: return "KP_8";
        case 0xff99: return "KP_5";
        case 0xff9a: return "KP_2";
        case 0xff9b: return "KP_9";
        case 0xff9c: return "KP_6";
        case 0xff9d: return "KP_3";
        case 0xff9e: return "KP_0";
        case 0xffaa: return "MULTIPLY";
        case 0xffab: return "ADD";
        case 0xffad: return "SUBTRACT";
        case 0xffae: return "DECIMAL";
        case 0xffaf: return "DIVIDE";
        case 0xffbe: return "F1";
        case 0xffbf: return "F2";
        case 0xffc0: return "F3";
        case 0xffc1: return "F4";
        case 0xffc2: return "F5";
        case 0xffc3: return "F6";
        case 0xffc4: return "F7";
        case 0xffc5: return "F8";
        case 0xffc6: return "F9";
        case 0xffc7: return "F10";
        case 0xffc8: return "F11";
        case 0xffc9: return "F12";
        case 0xffe1: return "LEFT_SHIFT";
        case 0xffe2: return "RIGHT_SHIFT";
        case 0xffe3: return "LEFT_CONTROL";
        case 0xffe4: return "RIGHT_CONTROL";
        case 0xffe5: return "CAPS_LOCK";
        case 0xffe9: return "LEFT_ALT";
        case 0xffea: return "RIGHT_ALT";
        case 0xffeb: return "LEFT_META";
        case 0xffec: return "RIGHT_META";
        case 0xffed: return "CONTEXT_MENU";
        case 0xffff: return "DELETE";
        case 0x0020: return "SPACE";
        default:
            if (keycode >= 0x30 && keycode <= 0x39) {
                return String::chr('0' + (keycode - 0x30));
            } else if (keycode >= 0x41 && keycode <= 0x5a) {
                return String::chr('A' + (keycode - 0x41));
            } else if (keycode >= 0x61 && keycode <= 0x7a) {
                return String::chr('A' + (keycode - 0x61));
            }
            return "UNKNOWN";
    }
}

// macOS键码映射实现 (简化示例)
String MacOSKeyMapping::get_key_name(int keycode) const {
    // 这里应该根据macOS的键码定义实现
    // 当前为简化实现
    // QAQ手里没有mac设备，应该是实现不了了
    switch (keycode) {
        case 0x33: return "BACKSPACE";
        case 0x30: return "TAB";
        case 0x4C: return "ENTER";
        case 0x38: return "SHIFT";
        case 0x3B: return "CONTROL";
        case 0x3A: return "ALT";
        case 0x35: return "ESCAPE";
        case 0x31: return "SPACE";
        case 0x75: return "DELETE";
        default:
            // 简化处理
            if (keycode >= 0x12 && keycode <= 0x1D) {
                return String::chr('0' + (keycode - 0x12));
            } else if (keycode >= 0x00 && keycode <= 0x0B) {
                return String::chr('A' + keycode);
            }
            return "UNKNOWN";
    }
}

// 获取当前平台的键码映射实例
KeyMapping* get_platform_key_mapping() {
#if defined(_WIN32)
    static WindowsKeyMapping win_mapping;
    return &win_mapping;
#elif defined(__linux__)
    static LinuxKeyMapping linux_mapping;
    return &linux_mapping;
#elif defined(__APPLE__)
    static MacOSKeyMapping macos_mapping;
    return &macos_mapping;
#else
    return nullptr;
#endif
}

} // namespace godot