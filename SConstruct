#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Create build directory if it doesn't exist
build_dir = "build"
if not os.path.exists(build_dir):
    os.makedirs(build_dir)

# Determine output path and filename
output_subdir = ""
if env["platform"] == "macos":
    library_name = "librainer_global_input.{}.{}".format(env["platform"], env["target"])
    if env["target"] == "debug":
        output_subdir = "template_debug"
    else:
        output_subdir = "template_release"
    library = env.SharedLibrary(
        "{}/bin/{}/{}.framework/{}".format(build_dir, output_subdir, library_name, library_name),
        source=sources,
    )
elif env["platform"] == "ios":
    library_name = "librainer_global_input.{}.{}".format(env["platform"], env["target"])
    if env["ios_simulator"]:
        library_name += ".simulator"
    library_name += ".a"
    library = env.StaticLibrary(
        "{}/bin/{}/{}".format(build_dir, output_subdir, library_name),
        source=sources,
    )
else:
    # For other platforms
    library_name = "librainer_global_input{}{}".format(env["suffix"], env["SHLIBSUFFIX"])
    if env["target"] == "debug":
        output_subdir = "template_debug"
    else:
        output_subdir = "template_release"
    library = env.SharedLibrary(
        "{}/bin/{}/{}".format(build_dir, output_subdir, library_name),
        source=sources,
    )

# Copy the gdextension file to the build directory
gdextension_source = "demo/bin/gdexample.gdextension"
gdextension_target = "{}/rainer_global_input.gdextension".format(build_dir)
if os.path.exists(gdextension_source):
    # Just make sure the target directory exists
    target_dir = os.path.dirname(gdextension_target)
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
    
    # Copy the file
    if os.path.exists(gdextension_target):
        os.remove(gdextension_target)
    with open(gdextension_source, "r") as src, open(gdextension_target, "w") as dst:
        content = src.read()
        # Replace references to gdexample with rainer_global_input
        content = content.replace("gdexample", "rainer_global_input")
        content = content.replace("libgdexample", "librainer_global_input")
        # Fix the paths to point to the correct build directory structure
        content = content.replace("res://bin/", "res://bin/{}/".format(output_subdir))
        dst.write(content)

Default(library)