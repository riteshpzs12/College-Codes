## Typo Generator
A simple tool to generate typos of a word (password). [[What it does?]]
The code takes an input of the path to the keyboard layout.  It is now done for
the normal laptop keyboard. [[How does it work?]]
for any layout the code will work..  
First you need to create the keyboard layout you want to solve in a text file 
and save it locally.Sample layout is given in the qwerty.txt as english normal 
laptop keyboard.download it give the absolute path as first input then type in the 
password.

## Files of this Project
Build.java, Generator.java:-> Main code files, Build.java is the first file to be comppiled

qwerty.txt:-> US English normal keyboard layout Sample with shift and unshift layouts.

before_1.txt, before_2.txt, finalout.txt:-> This code builds a character array of probable typos for a given
keyboard layout. before_1 and before_2 are the pattern generated from qwerty.txt for without
shift and with shift respectively. finalout is the final pattern after merging those two.

first_test_case.txt:-> This is the first test case i tried after the code writing was done......HA HA HA

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

## Main Instruction
1. First download the qwerty.txt in your machine.
2. run Build.java
3. The first input you have to give is the absolute file path for the downloaded file.
4. It generates the pattern with this input with the help of generator object.
5. Give the password for which you want to know the typos as the second input.
6. The output will come in a list format for all one letter typos for all indexes.
7. No more answer is in front of You. Judge it brother.

### Author  

Ritesh Chatterjee
