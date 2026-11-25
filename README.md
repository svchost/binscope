# binscope

A learning project in C++ building toward a **binary & memory inspector**.

Right now it reads any file, loads the bytes into memory, and prints a hex dump
to the terminal and to a text file. The long-term goal is a GUI inspector
(ImGui or Qt) that can parse executable structure and read live process memory.

## Current features

- Open any file passed as an argument (drag-and-drop onto the exe works too)
- Read the whole file into memory
- Print the size in bytes
- Hex dump in rows of 16 bytes
- Export the dump to a text file

## Roadmap

- [x] Milestone 1: binary file reader with hex output
- [ ] Offset column + ASCII column (proper hex-editor layout)
- [ ] File type detection from magic numbers (MZ, PK, %PDF, ...)
- [ ] PE header parsing (sections, imports, entry point)
- [ ] Split core logic from output so a GUI can reuse it
- [ ] ImGui hex view
- [ ] Live process memory reading (ReadProcessMemory)

## Build

Requires CMake, Ninja and a C++20 compiler (MinGW/LLVM).

```sh
cmake --preset debug
cmake --build --preset debug
```

The executable lands in `build/debug/binscope.exe`.

## Run

```sh
binscope.exe <path-to-file>
```

Or drag a file onto `binscope.exe` in Explorer.

## License

MIT. See [LICENSE](LICENSE).
