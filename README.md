<!-- such a cool logo, huh -->
![THE DEEPS](https://i.ibb.co/kJjV5jH/2021-09-18-16-22.png "THE DEEPS")

A text-based adventure game/dungeon crawler written in good ol' C++. Defeat enemies as you delve into a dungeon in search of treasure! 

<p align=center>### [Download](https://github.com/oicleevan/the-deeps/releases/latest) | [Source Code](src)</p>

**RELEASE 2.0 OUT NOW! TECHNICALLY AN ACTUAL THING NOW!**

## what is this game?

This game is text-based, and runs in a terminal. You play as a character who delves into a dungeon, where ghastly enemies hope to stop you from finding the hidden treasure.

As you fight and defeat enemies, you grow stronger. But be weary, so do the enemies...

Use your tactics and skill to defeat these enemies and claim your prize!

## how to play

### release files

You can download the binary file for your respective operating system from [the release section](https://github.com/oicleevan/the-deeps/releases/). Make it executable with `chmod +x ./adventure_{your os}`. 

You can then launch it from a terminal with `./adventure_{your os}`. (Pre-release candidates do not include a binary, you must compile from source.)

*i've decided against including binaries in the repo because it bloats directory structure and i find it unnecessary. all release builds work.*

## building from source

To make the software, GNU make and g++ is required. You must also compile libeo first (see [src/libeo](src/libeo)).

Type `make` to compile the program. It places a binary as `bin/adventure`.

Currently only supports UNIX-based systems. I don't have a Windows machine to test on, so if anyone wishes to port this, that would be great!

# Thanks!

**credits:**

uses [libeo](src/libeo), my custom library that makes menial tasks less annoying.

released under the [MIT License](https://github.com/git/git-scm.com/blob/main/MIT-LICENSE.txt)

**supporting me:**

[![Support me at paypal.me](https://www.zahlungsverkehrsfragen.de/wp-content/uploads/2018/10/paypalme.png "Support me at paypal.me")](https://paypal.me/eoicle)

-- [oicleevan](https://oicleevan.xyz)
