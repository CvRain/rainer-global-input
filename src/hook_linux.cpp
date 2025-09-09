#include "hook_linux.hpp"

using namespace godot;

bool is_running_on_wayland() {
    const char* wayland_display = getenv("WAYLAND_DISPLAY");
    return wayland_display != nullptr;
}