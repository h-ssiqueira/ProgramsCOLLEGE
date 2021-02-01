#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 1000

char U(char c){
    if(islower(c))
            return toupper(c);
    else{
        switch(c){              // case the char is accented letter
            case -121:          // note: the ascii table has 255 characters
                return -128;    // accented letters are 128+
                break;          // and the computer uses two's complement
            case -92:           // then, numbers above 127 are represented as negative
                return -91;
                break;
            case -96:
                return -75;
                break;
            case -123:
                return -73;
                break;
            case -125:
                return -75;
                break;
            case -58:
                return -57;
                break;
            case -122:
                return -113;
                break;
            case -124:
                return -114;
                break;
            case -126:
                return -112;
                break;
            case -119:
                return -45;
                break;
            case -118:
                return -44;
                break;
            case -120:
                return -46;
                break;
            case -95:
                return -42;
                break;
            case -115:
                return -34;
                break;
            case -117:
                return -40;
                break;
            case -116:
                return -41;
                break;
            case -94:
                return -32;
                break;
            case -107:
                return -29;
                break;
            case -109:
                return -30;
                break;
            case -28:
                return -27;
                break;
            case -101:
                return -99;
                break;
            case -108:
                return -103;
                break;
            case -93:
                return -23;
                break;
            case -105:
                return -21;
                break;
            case -127:
                return -102;
                break;
            case -106:
                return -22;
                break;
            case -20:
                return -19;
                break;
            case -111:
                return -110;
                break;
            default:
                return c;
        }
    }
}

char L(char c){
    if(isupper(c))
            return tolower(c);
    else{                       // case the char is accented letter
        switch(c){              // note: the ascii table has 255 characters
            case -121:          // accented letters are 128+
                return -128;    // and the computer uses two's complement
                break;          // then, numbers above 127 are represented as negative
            case -92:
                return -91;
                break;
            case -96:
                return -75;
                break;
            case -123:
                return -73;
                break;
            case -125:
                return -75;
                break;
            case -58:
                return -57;
                break;
            case -122:
                return -113;
                break;
            case -124:
                return -114;
                break;
            case -126:
                return -112;
                break;
            case -119:
                return -45;
                break;
            case -118:
                return -44;
                break;
            case -120:
                return -46;
                break;
            case -95:
                return -42;
                break;
            case -115:
                return -34;
                break;
            case -117:
                return -40;
                break;
            case -116:
                return -41;
                break;
            case -94:
                return -32;
                break;
            case -107:
                return -29;
                break;
            case -109:
                return -30;
                break;
            case -28:
                return -27;
                break;
            case -101:
                return -99;
                break;
            case -108:
                return -103;
                break;
            case -93:
                return -23;
                break;
            case -105:
                return -21;
                break;
            case -127:
                return -102;
                break;
            case -106:
                return -22;
                break;
            case -20:
                return -19;
                break;
            case -111:
                return -110;
                break;
            default:
                return c;
        }
    }
}

void Inverter(char string[]){
    for(int i = 0; i < strlen(string); i++){
        if(islower(string[i]))
            string[i] = toupper(string[i]);
        else if(isupper(string[i]))
            string[i] = tolower(string[i]);
        else{                           // case the char is accented letter
            switch(string[i]){          // note: the ascii table has 255 characters
                case -121:              // accented letters are 128+
                    string[i] = -128;   // and the computer uses two's complement
                    break;              // then, numbers above 127 are represented as negative
                case -128:
                    string[i] = -121;
                    break;
                case -91:
                    string[i] = -92;
                    break;
                case -92:
                    string[i] = -91;
                    break;
                case -75:
                    string[i] = -96;
                    break;
                case -96:
                    string[i] = -75;
                    break;
                case -73:
                    string[i] = -123;
                    break;
                case -123:
                    string[i] = -73;
                    break;
                case -74:
                    string[i] = -125;
                    break;
                case -125:
                    string[i] = -75;
                    break;
                case -57:
                    string[i] = -58;
                    break;
                case -58:
                    string[i] = -57;
                    break;
                case -113:
                    string[i] = -122;
                    break;
                case -122:
                    string[i] = -113;
                    break;
                case -114:
                    string[i] = -124;
                    break;
                case -124:
                    string[i] = -114;
                    break;
                case -112:
                    string[i] = -126;
                    break;
                case -126:
                    string[i] = -112;
                    break;
                case -45:
                    string[i] = -119;
                    break;
                case -119:
                    string[i] = -45;
                    break;
                case -44:
                    string[i] = -118;
                    break;
                case -118:
                    string[i] = -44;
                    break;
                case -46:
                    string[i] = -120;
                    break;
                case -120:
                    string[i] = -46;
                    break;
                case -42:
                    string[i] = -95;
                    break;
                case -95:
                    string[i] = -42;
                    break;
                case -34:
                    string[i] = -115;
                    break;
                case -115:
                    string[i] = -34;
                    break;
                case -40:
                    string[i] = -117;
                    break;
                case -117:
                    string[i] = -40;
                    break;
                case -41:
                    string[i] = -116;
                    break;
                case -116:
                    string[i] = -41;
                    break;
                case -32:
                    string[i] = -94;
                    break;
                case -94:
                    string[i] = -32;
                    break;
                case -29:
                    string[i] = -107;
                    break;
                case -107:
                    string[i] = -29;
                    break;
                case -30:
                    string[i] = -109;
                    break;
                case -109:
                    string[i] = -30;
                    break;
                case -27:
                    string[i] = -28;
                    break;
                case -28:
                    string[i] = -27;
                    break;
                case -99:
                    string[i] = -101;
                    break;
                case -101:
                    string[i] = -99;
                    break;
                case -103:
                    string[i] = -108;
                    break;
                case -108:
                    string[i] = -103;
                    break;
                case -23:
                    string[i] = -93;
                    break;
                case -93:
                    string[i] = -23;
                    break;
                case -21:
                    string[i] = -105;
                    break;
                case -105:
                    string[i] = -21;
                    break;
                case -102:
                    string[i] = -127;
                    break;
                case -127:
                    string[i] = -102;
                    break;
                case -22:
                    string[i] = -106;
                    break;
                case -106:
                    string[i] = -22;
                    break;
                case -19:
                    string[i] = -20;
                    break;
                case -20:
                    string[i] = -19;
                    break;
                case -110:
                    string[i] = -111;
                    break;
                case -111:
                    string[i] = -110;
                    break;
                case 33:
                    string[i] = -83;
                    break;
                case -83:
                    string[i] = 33;
                    break;
                case 63:
                    string[i] = -88;
                    break;
                case -88:
                    string[i] = 63;
                    break;
            }
        }
    }
}

void Upper(char string[]){
    for(int i = 0; i < strlen(string); i++){
        string[i] = U(string[i]);
    }
}

void Lower(char string[]){
    for(int i = 0; i < strlen(string); i++)
        string[i] = L(string[i]);
}

void IntersperceUL(char string[]){
    for(int i = 0; i < strlen(string); i++)
        i % 2 == 0 ? (string[i] = U(string[i])) : (string[i] = L(string[i]));
}

void IntersperceLU(char string[]){
    for(int i = 0; i < strlen(string); i++)
        i % 2 != 0 ? (string[i] = U(string[i])) : (string[i] = L(string[i]));
}

void Phrase(char string[]){
    char aux1,aux2;
    string[0] = U(string[0]);
    for(int i = 1,j; i < strlen(string); i++){
        if((string[i] == '.' || string[i] == '!' || string[i] == '?') && (string[i+1] != '\0' || string[i+1] != ' ') && strlen(string) < 999){
            i++;
            aux1 = string[i];
            aux1 = U(aux1);
            string[i] = ' ';
            j = ++i;
            while(j <= strlen(string)){
                aux2 = string[j];
                string[j] = aux1;
                j++;
                aux1 = aux2;
            }
        }
        else if((string[i] == '.' || string[i] == '!' || string[i] == '?') && string[i+1] != '\0'){
            i++;
            string[i] = U(string[i]);
        }
    }
}

void FirstUpper(char string[]){
    string[0] = U(string[0]);
    for(int i = 1; i < strlen(string); i++){
        if((string[i] == ',' || string[i] == '-' || string[i] == ' ' || string[i] == '.' || string[i] == '!' || string[i] == '?') && string[i+1] != '\0'){
            i++;
            string[i] = U(string[i]);
        }
    }
}

void Backwards(char string[]){
    char c;
    int i,j;
    for(i = 0, j = strlen(string) - 1; i < (strlen(string) / 2); i++, j--){
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}

int main(){
    char string[length], output[length];
    int i;
    printf("\n\tInsira o seu texto: ");
    scanf("%[^\n]s",string);

    do{
        printf("\nEscolha uma op%c%co:",135,198);
        printf("\n1 - Inverter.");
        printf("\n2 - Upper.");
        printf("\n3 - Lower.");
        printf("\n4 - IntersperceLU.");
        printf("\n5 - IntersperceUL.");
        printf("\n6 - Phrase.");
        printf("\n7 - FirstUpper.");
        printf("\n8 - Backwards.");
        printf("\n-> ");
        scanf("%d",&i);
        if(i < 1 || i > 8)
            printf("\n\tERROR 404: value not found!\n");
    }while(i < 1 || i > 8);
    switch(i){
        case 1:
            strcpy(output,string);
            Inverter(output);
            printf("\nInverter: %s\n",output);
            break;
        case 2:
            strcpy(output,string);
            Upper(output);
            printf("\nUpper: %s\n",output);
            break;
        case 3:
            strcpy(output,string);
            Lower(output);
            printf("\nLower: %s\n",output);
            break;
        case 4:
            strcpy(output,string);
            IntersperceLU(output);
            printf("\nIntersperce Lower Upper: %s\n",output);
            break;
        case 5:
            strcpy(output,string);
            IntersperceUL(output);
            printf("\nIntersperce Upper Lower: %s\n",output);
            break;
        case 6:
            strcpy(output,string);
            Phrase(output);
            printf("\nPhrase: %s\n",output);
            break;
        case 7:
            strcpy(output,string);
            FirstUpper(output);
            printf("\nFirst Upper: %s\n",output);
            break;
        case 8:
            strcpy(output,string);
            Backwards(output);
            printf("\nBackwards: %s\n",output);
            break;
    }
    return 0;
}
