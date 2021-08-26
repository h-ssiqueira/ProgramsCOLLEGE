#include <stdbool.h>
#include <stdint.h>
#include "driver.h"

bool capslock = false, shift = false;

// Get input from keyboard
uint8_t inb(uint16_t port){
	uint8_t value;
	asm volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
	return value;
}

// Translate the code from keyboard to character (ascii)
char translate(uint8_t key){
    switch(key){
        case 41:
            if(shift)
                return '\"';
            return '\'';
        case 2:
            if(shift)
                return '!';
            return '1';
        case 3:
            if(shift)
                return '@';
            return '2';
        case 4:
            if(shift)
                return '#';
            return '3';
        case 5:
            if(shift)
                return '$';
            return '4';
        case 6:
            if(shift)
                return '%';
            return '5';
        case 7:
            return '6';
        case 8:
            if(shift)
                return '&';
            return '7';
        case 9:
            if(shift)
                return '*';
            return '8';
        case 10:
            if(shift)
                return '(';
            return '9';
        case 11:
            if(shift)
                return ')';
            return '0';
        case 12:
            if(shift)
                return '_';
            return '-';
        case 13:
            if(shift)
                return '+';
            return '=';
        case 14:
            return '\b';
        case 15:
            return '\t';
        case 16:
            if(capslock ^ shift)
                return 'Q';
            return 'q';
        case 17:
            if(capslock ^ shift)
                return 'W';
            return 'w';
        case 18:
            if(capslock ^ shift)
                return 'E';
            return 'e';
        case 19:
            if(capslock ^ shift)
                return 'R';
            return 'r';
        case 20:
            if(capslock ^ shift)
                return 'T';
            return 't';
        case 21:
            if(capslock ^ shift)
                return 'Y';
            return 'y';
        case 22:
            if(capslock ^ shift)
                return 'U';
            return 'u';
        case 23:
            if(capslock ^ shift)
                return 'I';
            return 'i';
        case 24:
            if(capslock ^ shift)
                return 'O';
            return 'o';
        case 25:
            if(capslock ^ shift)
                return 'P';
            return 'p';
        case 27:
            if(shift)
                return '{';
            return '[';
        case 30:
            if(capslock ^ shift)
                return 'A';
            return 'a';
        case 31:
            if(capslock ^ shift)
                return 'S';
            return 's';
        case 32:
            if(capslock ^ shift)
                return 'D';
            return 'd';
        case 33:
            if(capslock ^ shift)
                return 'F';
            return 'f';
        case 34:
            if(capslock ^ shift)
                return 'G';
            return 'g';
        case 35:
            if(capslock ^ shift)
                return 'H';
            return 'h';
        case 36:
            if(capslock ^ shift)
                return 'J';
            return 'j';
        case 37:
            if(capslock ^ shift)
                return 'K';
            return 'k';
        case 38:
            if(capslock ^ shift)
                return 'L';
            return 'l';
        case 40:
            if(shift)
                return '^';
            return '~';
        case 43:
            if(shift)
                return '}';
            return ']';
        case 86:
            if(shift)
                return '|';
            return '\\';
        case 44:
            if(capslock ^ shift)
                return 'Z';
            return 'z';
        case 45:
            if(capslock ^ shift)
                return 'X';
            return 'x';
        case 46:
            if(capslock ^ shift)
                return 'C';
            return 'c';
        case 47:
            if(capslock ^ shift)
                return 'V';
            return 'v';
        case 48:
            if(capslock ^ shift)
                return 'B';
            return 'b';
        case 49:
            if(capslock ^ shift)
                return 'N';
            return 'n';
        case 50:
            if(capslock ^ shift)
                return 'M';
            return 'm';
        case 51:
            if(shift)
                return '<';
            return ',';
        case 52:
            if(shift)
                return '>';
            return '.';
        case 53:
            if(shift)
                return ':';
            return ';';
        case 58:
            capslock = !capslock;
            break;
        case 54:
        case 42:
            shift = true;
            break;
        case 182:
        case 170:
            shift = false;
            break;
        case 115:
            if(shift)
                return '?';
            return '/';
        case 57:
            return ' ';
        case 28:
            return '\n';
        case 78:
            return '+';
        case 55:
            return '*';
    }
    return -1;
}

// Function to print the digit of key in keyboard
void printDigit(int N){
    // To store the digit of the number N
    int arr[MAX], i, j, r;
    i ^= i;

    // Till N becomes 0
    while(N != 0){
        // Extract the last digit of N
        r = N % 10;
        // Put the digit in arr[]
        arr[i++] = r;
        // Update N to N/10 to extract next last digit
        N /= 10;
    }

    // Print the digit of N by traversing arr[] reverse
    for(j = i - 1; j > -1; j--)
        terminal_putchar('0'+arr[j]);
}

// Read and store input from keyboard in a buffer
void terminal_readString(char *buffer){
    uint8_t i, status, invalue;
    char c;
    i ^= i;
    while(true){
        status = inb(0x64);
        if(status & 1){
            invalue = inb(0x60);
            /* Code to collect the code of pressed and released keys (P-R)*/
            /*
            printDigit(invalue);
            i++;
            i % 2 == 0 ? terminal_putchar(' ') : terminal_putchar('-');
            */
            c = translate(invalue);
            if(c != -1){
                if(c == '\b'){
                    if(i > 0)
                        i--;
                    else
                        continue;
                }
                else if(c != '\n')
                    buffer[i++] = c;
                else{
                    buffer[i++] = 0;
                    break;
                }
            }
            if(i == 80){
                buffer[i] = 0;
                break;
            }
        }
    }
}