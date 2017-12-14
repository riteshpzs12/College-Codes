## Typo Generator
A simple tool to generate typos of a word (password). [[What it does?]]
The code takes an input of the path to the keyboard layout.  It is now done for
the normal laptop keyboard. [[How does it work?]]
for any layout the code will work..  
First you need to create the keyboard layout you want to solve in a text file 
and save it locally.Sample layout is given in the qwerty.txt as english normal 
laptop keyboard.download it give the absolute path as first input then type in the 
password.
## How to compile
```bash
$ javac Build.java
```
for eclipse just put these two files in the same package and run build.java first.
## How to run  
```bash
$ java Build.class??? # How to run?
```
First input absolute filepath to the layout file and 2nd input is a string.
It takes a seconary input of a String and generates all posible typos of it that
are at one [edit-distance](https://en.wikipedia.org/wiki/Edit_distance) from it.


### Author  

Ritesh Chatterjee
