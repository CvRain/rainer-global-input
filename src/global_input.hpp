#ifndef GLOBAL_INPUT_HPP
#define GLOBAL_INPUT_HPP

#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/signal.hpp"

#if _WIN32
#include "hook_windows.hpp"
#elif defined (__linux__) || defined (__unix__)
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


private:
  static void _bind_methods();
  
#if _WIN32
  bool hookInitialized = false;
#endif
};
} // namespace godot

#endif // GLOBAL_INPUT_HPP