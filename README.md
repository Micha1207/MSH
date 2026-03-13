# MSH
Simple shell program with bundled-in commands for GNU/Linux distributions.

---

## Getting started
This project is written in **C (compatible with C89)**.

### Features
- Bundled-in commands: MSH comes with minimal: cat, cd, clear, echo, help, ls, mkdir, pwd, rm, run, touch.
- Run any command from $PATH,
- Saving entered commands to `~/.msh_history` (can be changed in src/main.c).
---

### Command usage:
cat <file>            - show contents of file
cd <path/to/dir>      - change directory
cls, clear            - clear terminal
echo <text>           - echo text or any system variable (starting with $ sign)
ls, dir               - list objects in current directory
mkdir <dir>           - make directory
pwd                   - print working directory
rm <name>             - remove file or directory
run <command>         - run command from $PATH
touch <file>          - create file or update it's time
<command>             - run any command from $PATH

### Requirements
Make sure to have `gcc`, `make` and `git` programs installed on your system.
You can use your package manager (e.g. apt, dnf).

---

1. **Download sources**
   Clone project's repo with `git`:
   ```bash
   git clone https://github.com/Micha1207/MSH.git
   cd MSH
   ```

   Or download ZIP file directly from [project's GitHub page](https://github.com/Micha1207/MSH) and extract it.

2. **Compilation**:
   To compile this project, run `make` in project directory.

3. **Usage**:
   - To run directly: `./msh`
   - To install system-wide: `make install`. Make sure, to run as root.
   - Clean: `make clean` removes object files and binary.
