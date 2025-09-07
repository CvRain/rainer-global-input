#ifndef GLOBAL_INPUT_HPP
#define GLOBAL_INPUT_HPP

#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/signal.hpp"

namespace godot {
class GlobalInput : public Node {
  GDCLASS(GlobalInput, Node)

public:
  explicit GlobalInput();
  ~GlobalInput() override;
  void _ready() override;

  void start_hook();
  void stop_hook();

protected:


private:
  static void _bind_methods();
};
} // namespace godot

#endif // GLOBAL_INPUT_HPP