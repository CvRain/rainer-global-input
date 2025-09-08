#include "global_input.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

#if _WIN32
#include "hook_windows.hpp"
#include <godot_cpp/templates/vector.hpp>
#include "key_event.hpp"
extern godot::Vector<godot::KeyEvent> keyEventVector;
#endif

namespace godot
{
    GlobalInput::GlobalInput() : 
#if _WIN32
    hookInitialized(false)
#endif
    {
    }

    GlobalInput::~GlobalInput()
    {
    }

    void GlobalInput::_bind_methods()
    {
        ADD_SIGNAL(MethodInfo("key_pressed", PropertyInfo(Variant::INT, "key_code")));
        ADD_SIGNAL(MethodInfo("key_pressed_named", PropertyInfo(Variant::INT, "key_code"), PropertyInfo(Variant::STRING, "key_name")));
    }

    void GlobalInput::_ready()
    {
#if _WIN32
        // 初始化键盘钩子
        initKeyboardHook();
        hookInitialized = true;
#endif
    }

    void GlobalInput::_process(double delta){
#if _WIN32
        // 处理所有排队的按键事件并发送信号
        for (int i = 0; i < keyEventVector.size(); i++) {
            KeyEvent keyEvent = keyEventVector.get(i);
            
            // 发送按键信号（仅键码）
            emit_signal("key_pressed", keyEvent.keycode);
            
            // 发送按键信号（键码和键名）
            emit_signal("key_pressed_named", keyEvent.keycode, keyEvent.keyname);
        }
        
        // 清空事件Vector
        keyEventVector.clear();
#endif
    }
}