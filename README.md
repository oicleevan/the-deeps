<!-- such a cool logo, huh -->
![THE DEEPS](https://i.ibb.co/kJjV5jH/2021-09-18-16-22.png "THE DEEPS")

***a text-based adventure game written in c++***
### [Download](https://github.com/oicleevan/the-deeps/releases/latest) | [Building](#building-from-source)

**RELEASE 1.2.1 OUT NOW!**

## what is this game?

This game is a text-based adventure game written in good ol' C++, and runs in a terminal. You play as a character who delves into a dungeon, where ghastly enemies hope to stop you from finding the hidden treasure.

As you fight and defeat enemies, you grow stronger. But be weary, so do the enemies...

Use your tactics and skill to defeat these enemies and claim your prize!

## how to play

### release files

You can download the binary file for your respective operating system from [the release tags section](https://github.com/oicleevan/the-deeps/releases/). Make it executable with `chmod +x ./the-deeps_{your os}`. 

You can then launch it from a terminal with `./the-deeps_{your os}`. (Pre-release candidates do not include a binary, you must compile from source.)

*working on a wiki page on my [website](https://oicleevan.xyz). it'll be up eventually.*

## building from source

To make the software, GNU make and g++ is required. You must also compile libeo first (see [src/libeo](src/libeo)).

Type `make` to compile the program. It places a binary as `bin/the-deeps`.

Currently only supports Mac OS and GNU/Linux. I don't have a Windows machine to test on, so if anyone wishes to port this, that would be great!

# Thanks!

**credits:**

uses [libeo](src/libeo), my custom library that makes menial tasks less annoying.

released under the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt)

**supporting me:**

[![Support me at paypal.me](https://www.zahlungsverkehrsfragen.de/wp-content/uploads/2018/10/paypalme.png "Support me at paypal.me")](https://paypal.me/eoicle)

-- [oicleevan](https://oicleevan.xyz)
