#include<stdio.h>

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

int isWrong(char s[], int i, int spaces, int curSpaces) {
    if (s[i] == '/' || s[i] == '*' || spaces == 0) return 0;
    return spaces != curSpaces;
}

int shouldIncrease(char s[], int i, int n) {
    for (; i < n; i++) {
        if (s[i] == '"') return 0;
        if (s[i] == '{') return 1;
    }

    return 0;
}

int shouldDecrease(char s[], int i) {
    return s[i] == '}';
}

/*
 * Function to output the data as per requirements
 */
void printWithError(char str[], int lineNo) {
    red(1);
    printf("%3d ", lineNo);
    cyan(1);
    printf("%s \033[1;31m : Indentation error Found\n", str);
    normal();
}

void printWithoutError(char str[], int lineNo) {
    green(1);
    printf("%3d ", lineNo);
    yellow(0);
    puts(str);
    normal();
}

void printFinalErrors(int error[], int noOfErrors) {
    printf("\n");
    if (!noOfErrors) {
        green(1);
        printf("\t\tThe file is completely intended\n");
    } else {
        red(1);
        printf("\t\t'%d' Errors were found in the file\n", noOfErrors);
        cyan(1);
        printf("\t\tThe line locations of the errors are : ");
        for (int i = 0; i < noOfErrors; i++) {
            printf("%d", error[i]);
            if (i != noOfErrors - 1) printf(", ");
        }

        normal();
    }

    printf("\n");
    printf("\n");
    printf("\n");
}
