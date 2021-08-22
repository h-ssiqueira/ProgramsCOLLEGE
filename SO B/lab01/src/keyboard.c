#include <stdint.h>
#include "driver.h"

uint8_t inb(uint16_t port){
	uint8_t value;
	asm volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
	return value;
}

/*
107 teclas

esc = 1
f1 = 59
f2 = 60
f3 = 61
f4 = 62
f5 = 63
f6 = 64
f7 = 65
f8 = 66
f9 = 67
f10 = 68
f11 = 87
f12 = 88

' = 41
1 = 2
2 = 3
3 = 4
4 = 5
5 = 6
6 = 7
7 = 8
8 = 9
9 = 10
0 = 11
- = 12
= = 13
backspace = 14
tab = 15
q = 16
w = 17
e = 18
r = 19
t = 20
y = 21
u = 22
i = 23
o = 24
p = 25
´ = 26
[ = 27
] = 43
~ = 40
ç = 39
l = 38
k = 37
j = 36
h = 35
g = 34
f = 33
d = 32
s = 31
a = 30
capslock = 58
shift left = 42
\ = 86
z = 44
x = 45
c = 46
v = 47
b = 48
n = 49
m = 50
, = 51
. = 52
; = 53
/ = 115
ctrl left = 29
windows left = 91
alt left = 56
space = 57
alt right = 56
windows right = 92
options = 93
ctrl right = 54
shift right = 42

insert = 82
del = 83
home = 71
end = 79
pag up = 73
pag down = 81

up = 72
left = 75
right = 77
down = 80

0 = 82
, = 83
1 = 79
2 = 80
3 = 81
4 = 75
5 = 76
6 = 77
7 = 71
8 = 72
9 = 73
. = 126
+ = 78
- = 74
* = 55
/ = 53
enter = 169 ou 170
num lock =

print = 55
scroll lock = 70
pause break = 197

*/


unsigned char translate(uint8_t key){
    switch(key){
        case 41: return '\'';
        case 2: return '1';
        case 3: return '2';
        case 4: return '3';
        case 5: return '4';
        case 6: return '5';
        case 7: return '6';
        case 8: return '7';
        case 9: return '8';
        case 10: return '9';
        case 11: return '0';
        case 12: return '-';
        case 13: return '=';
        case 14: return '\b';
        case 15: return '\t';
        case 16: return 'q';
        case 17: return 'w';
        case 18: return 'e';
        case 19: return 'r';
        case 20: return 't';
        case 21: return 'y';
        case 22: return 'u';
        case 23: return 'i';
        case 24: return 'o';
        case 25: return 'p';
        //case 26: return '´';
        case 27: return '[';
        case 30: return 'a';
        case 31: return 's';
        case 32: return 'd';
        case 33: return 'f';
        case 34: return 'g';
        case 35: return 'h';
        case 36: return 'j';
        case 37: return 'k';
        case 38: return 'l';
        //case 39: return 'ç';
        case 40: return '~';
        case 43: return ']';
        case 86: return '\\';
        case 44: return 'z';
        case 45: return 'x';
        case 46: return 'c';
        case 47: return 'v';
        case 48: return 'b';
        case 49: return 'n';
        case 50: return 'm';
        case 51: return ',';
        case 52: return '.';
        case 53: return ';';
        case 115: return '/';
        case 57: return ' ';
        case 169: return '\n';
        case 170: return '\n';
        case 78: return '+';
        case 55: return '*';
    }
    return ' ';
}