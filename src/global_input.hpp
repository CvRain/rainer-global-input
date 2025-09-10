#ifndef GLOBAL_INPUT_HPP
#define GLOBAL_INPUT_HPP

#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/signal.hpp"

#include "key_event.hpp"

#if defined(_WIN32)
#include "hook_windows.hpp"
#elif defined(__linux__) || defined(__unix__)
#include "hook_linux.hpp"
#endif

namespace godot {
class GlobalInput : public Node {
  GDCLASS(GlobalInput, Node)

public:
  explicit GlobalInput();
  ~GlobalInput() override;
  
  void _ready() override;
  void _process(double delta) override;

protected:
  static void _bind_methods();

private:
  bool hookInitialized = false;
};
} // namespace godot

#endif // GLOBAL_INPUT_HPP