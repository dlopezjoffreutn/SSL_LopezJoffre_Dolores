#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int decimalToOctal(int decimalNumber){
    int octalNumber = 0, i = 1;
    while (decimalNumber != 0){
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return octalNumber;
}

int octalToDecimal(int octalNumber){
    int decimalNumber = 0, i = 0;
    while(octalNumber != 0){
        decimalNumber += (octalNumber % 10) * pow(8, i);
        ++i;
        octalNumber /= 10;
    }
    i = 1;
    return decimalNumber;
}

int decimalToBinary(int decimalNumber) {
    int binaryNumber = 0;
    int rem = 0, i = 1;
    while (decimalNumber != 0){
        rem = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += rem * i;
        i *= 10;
    }
    return binaryNumber;
}

int binaryToDecimal(int binaryNumber){
    int decimalNumber = 0, rem = 0, i = 0;
    while (binaryNumber != 0){
        rem = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += rem * pow(2, i);
        ++i;
    }
    return decimalNumber;
}


/* int octalToBinary(int octalNumber){
    int binaryNumber = 0, digit = 0, i = 1;
    while (octalNumber != 0) {
        digit = (octalNumber % 10);
        binaryNumber += decimalToBinary(digit) * i;
        i *= 10;
        octalNumber /= 10;
    }
}  */


bool isValid(int number, int base) {
    int firstDigit = number;
    while(firstDigit >= 10){
        firstDigit /= 10;   
    }
    if(!firstDigit && base!=8){
        return false;
    }

    switch(base){
        case 8:
            while(number){
                if(number % 10 >= 8) return false;
                number /= 10;
            }
            break;
        case 2:
            while(number){
                if(number % 10 >= 2) return false;
                number /= 10;
            }
            break;
        default:
            return true;
            break;
    }
    return true;
}

int getNumber(int base, char title[]){
    int number;
    printf("Por favor, ingresa un numero %s \n", title);
    do{                
        scanf("%i", &number);
        if(!isValid(number, base)){
            printf("ERROR, ingresa un numero %s \n", title);
        }
    } while(!isValid(number, base));
    return number;
}

int main(int argc, char **argv){
    int inputNumber = 0, outputNumber = 0;
    int baseInput = 0, baseOutput = 0;

    if(argc < 2){
        printf("Por favor, ingresa 2 bases. \n");
        return 0;
    }

    sscanf(argv[1], "%i", &baseInput);
    sscanf(argv[2], "%i", &baseOutput);
    if(baseInput == baseOutput){
        printf("Por favor, ingresa 2 bases distintas. \n");
        return 0;
    }

    switch (baseInput){
        case 10:
            if(baseOutput != 8 && baseOutput != 2){
                printf("Par de bases no disponible. \n");
                return 0;
            }

            inputNumber = getNumber(baseInput, "decimal");
            
            switch(baseOutput){
                case 8:
                    outputNumber = decimalToOctal(inputNumber);
                    break;
                case 2:
                    outputNumber = decimalToBinary(inputNumber);
                    break;
            }
            break;

        case 8:
            if(baseOutput != 10 && baseOutput != 2){
                printf("Par de bases no disponible. \n");
                return 0;
            }

            inputNumber = getNumber(baseInput, "octal");
            outputNumber = octalToDecimal(inputNumber);
            if(baseOutput == 2){    
                outputNumber = decimalToBinary(outputNumber);
            }
            break;
        
        case 2:
            if(baseOutput != 10 && baseOutput != 8){
                printf("Par de bases no disponible. \n");
                return 0;
            }

            inputNumber = getNumber(baseInput, "binario");
            outputNumber = binaryToDecimal(inputNumber);
            if(baseOutput == 8){    
                outputNumber = decimalToOctal(outputNumber);
            }
            break;
        
        default:
            printf("Base de entrada no disponible. \n");
            return 0;
            break;
    }
    printf("%i (%i) es %i (%i)", inputNumber, baseInput, outputNumber, baseOutput);
    return 0;
}