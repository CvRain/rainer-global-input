#ifndef HOOK_WINDOWS_HPP
#define HOOK_WINDOWS_HPP
#if _WIN32

#include <Windows.h>
#include <conio.h>
#include <godot_cpp/templates/vector.hpp>
#include "key_event.hpp"

// 声明一个函数用于获取按键事件Vector
godot::Vector<godot::KeyEvent>& get_key_event_vector();

// 声明初始化和处理函数
void initKeyboardHook();
void processKeyEvents();

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

#endif
#endif