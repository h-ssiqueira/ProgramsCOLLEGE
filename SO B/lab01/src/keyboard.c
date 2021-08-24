#include <stdint.h>
#include "driver.h"

uint8_t inb(uint16_t port){
	uint8_t value;
	asm volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
	return value;
}

char translate(uint8_t key){
    switch(key){
        case 41:
            while(inb(0x60) != (uint8_t)169) continue;
                return '\'';
        case 2:
            while(inb(0x60) != (uint8_t)130) continue;
                return '1';
        case 3:
            while(inb(0x60) != (uint8_t)131) continue;
                return '2';
        case 4:
            while(inb(0x60) != (uint8_t)132) continue;
                return '3';
        case 5:
            while(inb(0x60) != (uint8_t)133) continue;
                return '4';
        case 6:
            while(inb(0x60) != (uint8_t)134) continue;
                return '5';
        case 7:
            while(inb(0x60) != (uint8_t)135) continue;
                return '6';
        case 8:
            while(inb(0x60) != (uint8_t)136) continue;
                return '7';
        case 9:
            while(inb(0x60) != (uint8_t)137) continue;
                return '8';
        case 10:
            while(inb(0x60) != (uint8_t)138) continue;
                return '9';
        case 11:
            while(inb(0x60) != (uint8_t)139) continue;
                return '0';
        case 12:
            while(inb(0x60) != (uint8_t)140) continue;
                return '-';
        case 13:
            while(inb(0x60) != (uint8_t)141) continue;
                return '=';
        case 14:
            while(inb(0x60) != (uint8_t)142) continue;
                return '\b';
        case 15:
            while(inb(0x60) != (uint8_t)143) continue;
                return '\t';
        case 16:
            while(inb(0x60) != (uint8_t)144) continue;
                return 'q';
        case 17:
            while(inb(0x60) != (uint8_t)145) continue;
                return 'w';
        case 18:
            while(inb(0x60) != (uint8_t)146) continue;
                return 'e';
        case 19:
            while(inb(0x60) != (uint8_t)147) continue;
                return 'r';
        case 20:
            while(inb(0x60) != (uint8_t)148) continue;
                return 't';
        case 21:
            while(inb(0x60) != (uint8_t)149) continue;
                return 'y';
        case 22:
            while(inb(0x60) != (uint8_t)150) continue;
                return 'u';
        case 23:
            while(inb(0x60) != (uint8_t)151) continue;
                return 'i';
        case 24:
            while(inb(0x60) != (uint8_t)152) continue;
                return 'o';
        case 25:
            while(inb(0x60) != (uint8_t)153) continue;
                return 'p';
        case 27:
            while(inb(0x60) != (uint8_t)155) continue;
                return '[';
        case 30:
            while(inb(0x60) != (uint8_t)158) continue;
                return 'a';
        case 31:
            while(inb(0x60) != (uint8_t)159) continue;
                return 's';
        case 32:
            while(inb(0x60) != (uint8_t)160) continue;
                return 'd';
        case 33:
            while(inb(0x60) != (uint8_t)161) continue;
                return 'f';
        case 34:
            while(inb(0x60) != (uint8_t)162) continue;
                return 'g';
        case 35:
            while(inb(0x60) != (uint8_t)163) continue;
                return 'h';
        case 36:
            while(inb(0x60) != (uint8_t)164) continue;
                return 'j';
        case 37:
            while(inb(0x60) != (uint8_t)165) continue;
                return 'k';
        case 38:
            while(inb(0x60) != (uint8_t)166) continue;
                return 'l';
        case 40:
            while(inb(0x60) != (uint8_t)168) continue;
                return '~';
        case 43:
            while(inb(0x60) != (uint8_t)171) continue;
                return ']';
        case 86:
            while(inb(0x60) != (uint8_t)214) continue;
                return '\\';
        case 44:
            while(inb(0x60) != (uint8_t)172) continue;
                return 'z';
        case 45:
            while(inb(0x60) != (uint8_t)173) continue;
                return 'x';
        case 46:
            while(inb(0x60) != (uint8_t)174) continue;
                return 'c';
        case 47:
            while(inb(0x60) != (uint8_t)175) continue;
                return 'v';
        case 48:
            while(inb(0x60) != (uint8_t)176) continue;
                return 'b';
        case 49:
            while(inb(0x60) != (uint8_t)177) continue;
                return 'n';
        case 50:
            while(inb(0x60) != (uint8_t)178) continue;
                return 'm';
        case 51:
            while(inb(0x60) != (uint8_t)179) continue;
                return ',';
        case 52:
            while(inb(0x60) != (uint8_t)180) continue;
                return '.';
        case 53:
            while(inb(0x60) != (uint8_t)181) continue;
                return ';';
        case 115:
            while(inb(0x60) != (uint8_t)243) continue;
                return '/';
        case 57:
            while(inb(0x60) != (uint8_t)185) continue;
                return ' ';
        case 28:
            while(inb(0x60) != (uint8_t)156) continue;
                return '\n';
        case 78:
            while(inb(0x60) != (uint8_t)206) continue;
                return '+';
        case 55:
            while(inb(0x60) != (uint8_t)183) continue;
                return '*';
    }
    return ' ';
}

#define MAX 80

// Function to print the digit of key in keyboard
void printDigit(int N){
    // To store the digit of the number N
    int arr[MAX];
    int i = 0;
    int j, r;

    // Till N becomes 0
    while(N != 0){

        // Extract the last digit of N
        r = N % 10;

        // Put the digit in arr[]
        arr[i] = r;
        i++;

        // Update N to N/10 to extract next last digit
        N /= 10;
    }

    // Print the digit of N by traversing arr[] reverse
    for(j = i - 1; j > -1; j--)
        terminal_putchar('0'+arr[j]);
}

void terminal_readString(char *buffer){
    uint8_t i, status, invalue;
    char c;
    i ^= i;
    while(true){
        status = inb(0x64);
        if(status & 1){
            invalue = inb(0x60);
            /* Code to collect the code of pressed and released keys (P-R)
            printDigit(invalue);
            i++;
            i % 2 == 0 ? terminal_putchar(' ') : terminal_putchar('-');
            */
            c = translate(invalue);
            if(c != '\n')
                buffer[i++] = c;
            else{
                buffer[i++] = 0;
                break;
            }
            if(i == 80){
                buffer[i] = 0;
                break;
            }
        }
    }
}