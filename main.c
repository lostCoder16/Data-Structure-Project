#include<stdio.h>
#include"string.h"
#include"stdlib.h"
#include"utilities.h"

const int N = (int)(2e5 + 10);
int noOfSpacesInATab = 8;

int main(int argc, char *argv[]) {
    printWelcome(argv[1]);

     int errors_indentation[N];
    char s[N];
    int requiredSpaces = 0;
    int shift = 4;
    int curLine = 1;
    int noOfErrors_indentation = 0;

    if (argc >= 3) shift = atoi(argv[2]);

     FILE *fptr = fopen(argv[1], "r");
    while (fgets(s, N, fptr) != NULL) {
        int terminationPoint = strcspn(s, "\n");
        s[terminationPoint] = '\0';
        int spaces = 0;
        int indentationError = 0;
        for (int i = 0; i < terminationPoint; i++) {
            if (s[i] == ' ') spaces++;
             else if (s[i] == '\t') spaces += noOfSpacesInATab;
            else {
                if (s[i] == '*' || s[i] == '/') break;
                else if (s[i] == '}') requiredSpaces -= shift;
                if (spaces != requiredSpaces) indentationError = 1;
                break;
            }
        }


        if (indentationError) {
            errors_indentation[noOfErrors_indentation++] = curLine;
            printWithIndentationError(s, curLine, spaces, requiredSpaces);
        } else printWithoutError(s, curLine);
        if (s[terminationPoint - 1] == '{') requiredSpaces += shift;
        curLine++;
    }

    printIndentationReport(errors_indentation, noOfErrors_indentation);
}
