extends Node2D


func _on_global_input_key_pressed(key_code: int) -> void:
	pass


func _on_global_input_key_pressed_named(key_code: int, key_name: String) -> void:
	print("key code: ", key_code)
	print("key name: ", key_name)
