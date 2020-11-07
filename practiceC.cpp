#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"utilities.h"

// Header to print the required data

#define nullptr NULL

int noOfSpacesInASingleTab = 8;
const int N = (int)(2e5 + 10);

int main(int argc, char *argv[]) {
     FILE *fptr = fopen(argv[1], "r");
     int locationOfErrors[N];
     char curStr[N];
     int noOfErrors = 0;
     int initialIndentation = 0;
     int lenOfIndent = 0;
     int previousCount = 0;
     int currentLine = 1;

     if (argc == 3) {
          initialIndentation = 1;
          lenOfIndent = atoi(argv[2]);
     }

     while (fgets(curStr, 1000, fptr) != nullptr) {
          int terminationPosition = strcspn(curStr, "\n");
          curStr[terminationPosition] = '\0';
          int spaces = 0;
          int presentCount = 0;

          // At first we have to find the no of prefix spaces in the current line
          int i = 0;
          for (; i < terminationPosition; i++) {
               if (curStr[i] != ' ' && curStr[i] != '\t') break;
               else if (curStr[i] == ' ') spaces++;
               else if (curStr[i] == '\t') spaces += noOfSpacesInASingleTab;
          }

          if (curStr[i] == '/' || curStr[i] == '*') continue;

          // If we have some spaces in this line and the initialIndentation
          // and initial indentation is not set then this spaces is our initial indentation
          if (spaces != 0 && initialIndentation == 0) {
               initialIndentation = 1;
               lenOfIndent = spaces;

               spaces++;
               spaces--;

          }
//        printf("%d %d %d", lenOfIndent, spaces, terminationPosition);

          if (initialIndentation) {
               presentCount += (spaces / lenOfIndent);

               // Condition to check if the current indentation is wrong
               if (spaces % lenOfIndent != 0 || (presentCount != 0 && abs(presentCount - presentCount) > 1)) {
                    printWithError(curStr, currentLine);
                    locationOfErrors[noOfErrors++] = currentLine;
                    presentCount = previousCount;
               } else
                    printWithoutError(curStr, currentLine);
          } else
               printWithoutError(curStr, currentLine);

          previousCount = presentCount;
          currentLine++;
     }

     // Printing the final review of our file
     printFinalErrors(locationOfErrors, noOfErrors);
}
