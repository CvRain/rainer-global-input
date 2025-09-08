#ifndef HOOK_WINDOWS_HPP
#define HOOK_WINDOWS_HPP
#if _WIN32

#include <Windows.h>
#include <conio.h>
#include <godot_cpp/templates/vector.hpp>
#include "key_event.hpp"

// 声明一个Vector用于存储按键事件
extern godot::Vector<godot::KeyEvent> keyEventVector;

// 声明初始化和处理函数
void initKeyboardHook();
void processKeyEvents();

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

#endif
#endif