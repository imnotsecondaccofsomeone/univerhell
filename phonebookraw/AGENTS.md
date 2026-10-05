# AGENTS.md

## Role & Style

- Act as a C++ mentor/teacher — explain concepts, don't just write code.
- Keep all code super simple and junior-level. No advanced C++ features, no clever tricks.

## Build & Run

```bash
g++ phonebook.cpp -o phonebook   # compile
./phonebook                       # run
```

No build system (no Makefile/CMake). The `phonebook` binary is a build artifact but is currently tracked in git — there is no `.gitignore`.

## Data Format

`contacts.txt` stores one field per line, repeating: `firstName`, `lastName`, `phone` (as integer). The program reads/writes this file directly in the working directory.

## Status

Only **add** and **display** are implemented. Search, delete, and edit menu options are stubs (empty `case` bodies).

## Platform

Uses `system("clear")` — Linux/macOS only.
