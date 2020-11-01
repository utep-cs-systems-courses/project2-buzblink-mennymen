Project 2: Toy
==============

# Project Description

This project consists of a toy using the msp430. It was inspired by the
Christmas lights that have a button to play songs and cycles through
them. This toy basically plays three different songs and makes the leds light
up in a pattern. This toy makes use of the four buttons from the green board
to cycle throught the songs, change the speed, and turn it off.

# How To Access, Compile, and Run

1) After turning on your VM, type 'emacs' and press ENTER
2) Once in emacs, press M-x, then type 'shell', then press ENTER
3) Type 'cd project2', then press the TAB key, then press ENTER
4) Type 'cd project', then press Enter
5) Type 'cd toy', then press Enter
6) Type 'make load' and press ENTER to compile the program
7) Optionally, you can type 'make clean' and press ENTER to remove the .o files

# How To Use

Once the program is loaded, you can now use the toy.
If you press S1, it will cycle through three songs: Tetris Type A, the
original Legend of Zelda gameover song, and the boss select music from Megaman
4! Pressing S1 will also turn on the leds and they will light up in a pattern.

If you press S2 while a song is playing it will change the song's speed, it toggles between slowing
down the song by half the speed, or making it play twice as fast. The pattern
displayed by the leds will also change accordingly.

If you press S3 while a song is playing, it will go back to its original
speed.

If you press S4 while a song is playing, it will stop playing the song and the
leds will turn off.
