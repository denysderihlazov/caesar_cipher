# Caesar Cipher Encoder

This program is a simple and optimized implementation of the Caesar Cipher encoder in C. It allows encoding a text file by shifting its characters by a specified integer value.

## Installation

Clone the repository to your local machine:
```sh
git clone git@github.com:denysderihlazov/caesar_cipher.git
```
Navigate to the project directory:
```sh
cd <path_on_your_computer>/caesar_cipher
```
Compile the program using GCC:
```sh
gcc -Wall -g main.c -o main
```

## Usage

Run the program with the desired shift value and the name of the text file you want to encode:
```sh
./main <shift> <file_name>
```
Example
```sh
./main 3 caesar.txt
```
Replace <shift> with the number of positions you want each character in your text to be shifted by. Replace <file_name> with the path to the text file you want to encode.

## Help
For usage instructions, you can run the program with -h or --help:
```sh
./main --help
```
This will display helpful information on how to use the program.

## Features
 - Encodes text files using the Caesar cipher.
 - Customizable shift value.
 - Handles non-printable ASCII characters by keeping the encoded characters within the printable ASCII range (33 to 126).
 - Error handling for non-digit shift values.

## Future Enhancements
Add an option for negative shift values to enable decoding of encoded texts.