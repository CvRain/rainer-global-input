/**
 * @file hook_linux.hpp
 * @author cvraindays@outlook.com
 * @brief 
 * @version 1.0
 * @date 2025-09-08
 * 
 * 在研究如何在linux上实现全局按键监听的时候想了很多的方法，最大的阻力是如何在wayland上实现此功能。
 * 在 Wayland 中，出于安全设计，没有提供像 X11 那样允许应用程序随意监听全局输入的 API。任何全局操作都必须依赖 Wayland 组合器（如 Hyprland, GNOME, KDE）暴露的扩展协议。
 * 在 Wayland 上实现像 X11 那样"任意按键全局监听"是非常困难的，因为它直接违背了 Wayland 的安全模型。
 * 因此，目前的解决方案只能在 X11 上实现全局按键监听，而在 Wayland 上则无法实现这一功能。
 * 作为一个长期在hyprland下使用的用户，这对我来说是一个遗憾，但也是对隐私和安全的妥协。开发这个软件的初衷便是想在linux下也实现一款桌宠软件，而全局按键监听是桌宠软件的核心功能之一。
 * 因此便诞生了这个项目，说来也有意思，最轻松最简单完成全局输入监听的系统反而是windows，而因为手里没有mac设备，所以macos的计划暂时搁置。
 * 这里只能指望xwayland能提供不错的兼容，让程序在wayland下也能有不错的表现了。
 * 
 */
#ifndef HOOK_LINK_H
#define HOOK_LINK_H

// 添加链接库指令
#ifdef __GNUC__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-variable"
    #pragma GCC diagnostic ignored "-Wunused-function"
#endif

#if defined (__linux__) || defined (__unix__)

#include <godot_cpp/templates/vector.hpp>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/extensions/XInput.h>
#include "key_event.hpp"

// 声明一个函数用于获取按键事件Vector
godot::Vector<godot::KeyEvent>& get_key_event_vector();

// 声明初始化和处理函数
void initKeyboardHook();
void processKeyEvents();

bool is_running_on_wayland();

#endif

#ifdef __GNUC__
    #pragma GCC diagnostic pop
#endif

#endif