#include<stdio.h>
#include"string.h"
/*
 * Function to implement the output with colors
 * The below */

// function to print output in red
void red(int bold) {
    if (bold) printf("\033[1;31m");
    else printf("\033[0;31m");
}

// function to print output in green
void green(int bold) {
    if (bold) printf("\033[1;32m");
    else printf("\033[0;32m");
}

// function to print output in yellow
void yellow(int bold) {
    if (bold) printf("\033[1;33m");
    else printf("\033[0;33m");
}

// function to print output in blue
void blue(int bold) {
    if (bold) printf("\033[1;34m");
    else printf("\033[0;34m");
}

// function to print output in magenta
void magenta(int bold) {
    if (bold) printf("\033[1;35m");
    else printf("\033[0;35m");
}

// function to print output in cyan
void cyan(int bold) {
    if (bold) printf("\033[1;36m");
    else printf("\033[0;36m");
}

// function to bring the printing statements back to normal casting
void normal() {
    printf("\033[0m");
}

/*
 * Functions to systemize various checks as per requirement
 * */

/*
 * Function to output the data as per requirements
 */
void printWithIndentationError(char str[], int lineNo, int spaces, int requiredSpaces) {
    red(1);
    printf("%3d ", lineNo);
    cyan(1);
    printf("%s", str);
    yellow(1);
    int n  = strlen(str);
    for (int i = 0; i < 60 - n; i++) printf(" ");
    printf(" : Indentation error Found (Required spaces as '%d' and found as '%d') \n", requiredSpaces, spaces);
    normal();
}

void printWithPaddingError(char str[], int lineNo) {
    yellow(1);
    printf("%3d ", lineNo);
    yellow(1);
    printf("%s \033[1;34m : Padding error Found\n", str);
    normal();
}

void printWithoutError(char str[], int lineNo) {
    green(1);
    printf("%3d ", lineNo);
    normal();
    puts(str);
    normal();
}

void printIndentationReport(int error[], int noOfErrors) {
    printf("\n");
    if (!noOfErrors) {
        green(1);
        printf("\t\tThe file is completely intended\n");
    } else {
        red(1);
        printf("\t\t'%d' Indentation Errors were found in the file\n", noOfErrors);
        cyan(1);
        printf("\t\tThe line locations of the indentation errors are : ");
        for (int i = 0; i < noOfErrors; i++) {
            printf("%d", error[i]);
            if (i != noOfErrors - 1) printf(", ");
        }

        normal();
    }

    printf("\n");
    printf("\n");
}

void printPaddingReport(int error[], int noOfErrors) {
    printf("\n");
    if (!noOfErrors) {
        green(1);
        printf("\t\tThe file has no padding errors\n");
    } else {
        red(1);
        printf("\t\t'%d' Padding Errors were found in the file\n", noOfErrors);
        cyan(1);
        printf("\t\tThe line locations of the indentation errors are : ");
        for (int i = 0; i < noOfErrors; i++) {
            printf("%d", error[i]);
            if (i != noOfErrors - 1) printf(", ");
        }
    }

    printf("\n");
    printf("\n");
}
