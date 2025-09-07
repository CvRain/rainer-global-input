#include "global_input.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/print_string.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

GlobalInput::GlobalInput() {

}

GlobalInput::~GlobalInput() {

}

void GlobalInput::_bind_methods() {
    ADD_SIGNAL(MethodInfo("key_pressed", PropertyInfo(Variant::INT, "key_code")));
}

void GlobalInput::_ready() {
    print_line("GlobalInput ready");
}