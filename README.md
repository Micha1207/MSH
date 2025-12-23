# MSH
Micha1207's shell
Tested on Fedora GNU/Linux.

This program comes with NO WARRANTY; to the extent permitted by law.

## What is this?
This is my implementation of shell program.
It is very simple, but I'll work on extending it.

## What is this for?
As any other shell, this is a program that let's user to control a computer.

# How to install?
First, make sure that you've got below packages on your system:
`gcc make git`

Once installed, clone this project and go to it's directory:
`git clone https://github.com/Micha1207/MSH.git && cd MSH`

Since this is written in C, you've got to compile it:
`make`

This will create `msh` binary, which you can run using `./msh` (GNU/Linux, macOS) or `.\msh.exe` (Windows).

You can install it using:
`sudo make install`. You'll be asked for your password.

You can also uninstall it using:
`sudo make uninstall`

If you'd want to recompile this, run:
`make clean`
