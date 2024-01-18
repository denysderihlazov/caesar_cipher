# Caesar Cipher Encoder

This program is a simple and optimized implementation of the Caesar Cipher encoder and decoder in C. It allows encoding and decoding text by shifting its characters by a specified integer value, either from a text file or directly from standard input.

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

To encode or decode text using the Caesar cipher, you have two options:
 - ### Using a text file:
    Run the program with the desired shift value and the name of the text file you want to process:
    ```sh
    ./main <shift> <file_name>
    ```
    ### Examples:
    - To encode :
    ```sh
    ./main 3 caesar.txt
    ```
     - To decode:
    ```sh
    ./main -3 caesar.txt
    ```
 - ### Using standard input (stdin):
    Run the program with the desired shift value and input text directly:
    ```sh
    ./main <shift>
    ```
    ### Examples:
    - To encode :
    ```sh
    ./main 3
    ```
     - To decode:
    ```sh
    ./main -3
    ```
Replace <shift> with the number of positions you want each character in your text to be shifted by. Positive values encode and negative values decode. Replace <file_name> with the path to the text file you want to encode or decode.

## Help
For usage instructions, you can run the program with -h or --help:
```sh
./main --help
```
This will display helpful information on how to use the program.

## Features
 - Encodes and decodes text files using the Caesar cipher.
 - Works with both text files and standard input.
 - Customizable shift value for encoding and decoding.
 - Handles non-printable ASCII characters by keeping the encoded characters within the printable ASCII range (32 to 126).
 - Error handling for non-digit shift values.