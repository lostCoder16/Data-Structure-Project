/*
 * Data Structures Innovative Project Work
 * Group Members :
 * Prabhpreet Singh (2k19/CO/277)
 * Mohmmad Arshad (2k19/CO/235)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"utilities.h"

const int spacesPerTab = 8;
const int N = (int) (2e5 + 10);
int shift = 4;
int curLine = 1;
int noOfErrors = 0;
int curSpaces = 0;

int main(int argc, char *argv[]) {
    int errors[N];
    char str[N];

    if (argc == 3) {
        shift = atoi(argv[2]);
    }

    FILE *fptr = fopen(argv[1], "r");
    while (fgets(str, N, fptr) != NULL) {
        int terminationPoint = strcspn(str, "\n");
        str[terminationPoint] = '\0';
        int i = 0, spaces = 0;
        for (; i < terminationPoint; i++) {
            if (str[i] == ' ') spaces++;
            else if (str[i] == '\t') spaces += spacesPerTab;
            else break;
        }

        if (shouldDecrease(str, i)) {
            curSpaces -= shift;
        }

        if (isWrong(str, i, spaces, curSpaces)) {
            errors[noOfErrors++] = curLine;
            printWithError(str, curLine);
        } else {
            printWithoutError(str, curLine);
        }

        if (shouldIncrease(str, i, terminationPoint)) {
             curSpaces += shift;
        }

        curLine++;
    }

    printFinalErrors(errors, noOfErrors);
}
