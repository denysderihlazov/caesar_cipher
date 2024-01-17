#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HELP_INFO \
"Usage instructions:\n\n" \
"1) To encode text using the Caesar cipher:\n" \
"   Run: ./main <shift> <file_name>\n" \
"   Example: ./main \"3\" str.txt\n\n" \
"Attention: \n\n" \
"The shift must be an integer!\n" \

void printHelpInfo()
{
    printf(HELP_INFO);
}

int parseShift(int shift, char *argv)
{
    char *args;
    int temp = 0;

    for(args = argv; *args != '\0'; ++args) {
        if(((int)*args - (int)'0') < 0 || ((int)*args - (int)'0') > 9) {
            fprintf(stderr, "Shift is not a digit!\n\n");
            printHelpInfo();
            exit(3);
        }

        if(temp == 0) {
            temp = (int)*args - (int)'0';
        } else {
            temp = temp * 10 + (int)*args - (int)'0';
        }
    }
    // in case if shift is bigger then ASCII list size
    temp %= 127;

    return temp;
}

void encoderCaesar(FILE *f, int shift)
{
    char fbuffer[256];
    int currentChar = 0;

    while(fgets(fbuffer, sizeof(fbuffer), f)) {
        for(int i = 0; fbuffer[i] ; i++) {
            fseek(f, currentChar, SEEK_SET); // set cursor

            // Our working ASCII range is between 33 and 126. If the character  
            // falls outside this range, the next part of the code will handle it.
            int outOfASCII = ((int)fbuffer[i]+shift); 

            // Processing non-printable ASCII characters
            if(outOfASCII >= 127) {
                fputc((char)((((int)fbuffer[i]+shift) % 127) + 33), f);
            } else {
                fputc((char)((int)fbuffer[i]+shift), f);
            }

            currentChar++;
        }
    }
}

int main(int argc, char *argv[])
{
    int shift = 0;
    FILE *f;

    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printHelpInfo();
    } else if(argc < 3) {
        fprintf(stderr, "Too few arguments!\n");
        printHelpInfo();
        exit(1);
    }

    if (argc == 3) {
        // check if shift is a digit and convert char -> integer
        shift = parseShift(shift, argv[1]);

        f = fopen(argv[2], "rw+");

        if(!f) {
            fprintf(stderr, "No such file or directory!\n");
            exit(2);
        }

        encoderCaesar(f, shift);
        fclose(f);
    }

    return 0;
}

// In the future, add an option for negative shift (it will enable decoding).