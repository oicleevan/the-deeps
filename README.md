<!-- such a cool logo, huh -->
![THE DEEPS](https://i.ibb.co/kJjV5jH/2021-09-18-16-22.png "THE DEEPS")
***a text-based adventure game written in c++***

### [Download](https://github.com/oicleevan/the-deeps/releases/latest) | [Building](#building-from-source)
**RELEASE 1.2.1 OUT NOW!**

## what is this game?

This game is a text-based adventure game written in good ol' C++, and runs in a terminal. You play as a character who delves into a dungeon, where ghastly enemies hope to stop you from finding the hidden treasure.

As you fight and defeat enemies, you grow stronger. But be weary, so do the enemies...

Use your tactics and skill to defeat these enemies and claim your prize!

## installing from release files

### gnu/linux

Download the latest edition of the Linux release [here](https://github.com/oicleevan/the-deeps/releases/download/1.2.1/the-deeps_linux).

Make it executable with `chmod +x the-deeps_linux` (in a terminal, from the directory containing the file).

Launch with `./the-deeps_linux`.


### mac os

Download the latest edition of the mac os release [here](https://github.com/oicleevan/the-deeps/releases/download/1.2.1/the-deeps_osx).

Make it executable with `chmod +x the-deeps_osx` (in a terminal, from the directory containing the file).

Launch with `./the-deeps_osx`.

### windows

There is currently no native way to run this game on Windows, unless you hack something up to compile yourself. That being said, the best way to run the game on Windows would be running the Linux release [through WSL2](https://docs.microsoft.com/en-us/windows/wsl/install).

## building from source

To make the software, GNU make and a c++ compiler (i use clang) is required. You must also compile libeo first (see [src/libeo](src/libeo)).

Type `make` to compile the program. It places a binary as `bin/the-deeps`.

# Thanks!

**credits:**

- uses [libeo](src/libeo/README.md), my custom library that makes menial tasks less annoying.

- released under the good ol' [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt)

**supporting me:**

[![Support me at paypal.me](https://www.zahlungsverkehrsfragen.de/wp-content/uploads/2018/10/paypalme.png "Support me at paypal.me")](https://paypal.me/eoicle)

<sub>a boy can dream, right?</sub>

-- [oicleevan](https://oicleevan.xyz)
