# pios
One of the most useless things I ever made

<br/>

# About this project
This is an operating system with the only purpose of calculating pi (and Euler's number because why not). Even very well optimized programs for approximating pi have (in most cases) a major flaw: there is too much bloat running in the background that makes computing pi a lot slower. Even well-optimized operating systems like arch-linux are in most cases still using more than 16mb of RAM! A disaster!!  
Saying it is one of the most useless things I ever made is actually not true. It is _the_ most useless thing I ever made, which is because it is not working yet :(  
More on that later.  

<br/>

# Why?
It's not why, it's why not

<br/>

# Why is it not fully working yet?
My current problem is allocating huge amounts of memory to store very, very big and very, very small numbers. It is actually not hard to implement, but still full of bugs and a ton of issues, so I will update this as soon as I found a solution.  

<br/>

# How to use
You will first need to install the following packages, if not done yet:
  - gcc
  - nasm
  - qemu

Then you run the make-file: `make setup`  

To build and emulate the operating system, run: `make run`  

To build and make an ISO image you can then put on a usb-drive, a disk or a floppy, run: `make all`  
This is create a "pios.iso" file.

<br/>

# Whom to blame for this?
- Me of course :(  
- The idea is by [MisterSilversagle](https://github.com/MisterSilvereagle) and me  
- It would not have been possible without [this guy's](https://www.youtube.com/channel/UCofr5KcAmI_CB_tCYpVzZEw) great tutorial series

<br/>

Pease note all the sarcasm behind my writing 
