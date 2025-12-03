#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Structure to hold question and answer
struct Question{
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctAnswer;
};

// Fisher-Yates shuffle algorithm
void shuffleQuestions(struct Question questions[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Swap questions[i] and questions[j]
        struct Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    // Initialize 50 questions from your screenshots
    struct Question questionBank[50] = {
        {"Who developed the C programming language?", "Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Ken Thompson", 'A'},
        {"What is the size of char data type in C?", "1 byte", "2 bytes", "4 bytes", "8 bytes", 'A'},
        {"Which header file is required for printf() function?", "stdlib.h", "stdio.h", "string.h", "math.h", 'B'},
        {"What is the correct syntax for main function in C?", "void main()", "int main()", "main()", "function main()", 'B'},
        {"Which of the following is not a valid C identifier?", "_name", "2ndName", "name2", "name_2", 'B'},
        {"What does the & operator represent in C?", "Logical AND", "Address of operator", "Bitwise AND", "Both B and C", 'D'},
        {"Which loop is guaranteed to execute at least once?", "for loop", "while loop", "do-while loop", "none of these", 'C'},
        {"What is the range of int data type (typically)?", "-32768 to 32767", "-2147483648 to 2147483647", "0 to 65535", "depends on system", 'B'},
        {"Which keyword is used to prevent variable modification?", "static", "const", "volatile", "extern", 'B'},
        {"What is the output of printf(%d, 5/2)?", "2", "2.5", "3", "error", 'A'},

        {"What is the size of float in C?", "2 bytes", "4 bytes", "8 bytes", "16 bytes", 'B'},
        {"Which format specifier is used for unsigned int?", "%d", "%u", "%i", "%x", 'B'},
        {"What is the default value of static variables?", "0", "1", "garbage value", "undefined", 'A'},
        {"Which storage class has local scope but retains value?", "auto", "static", "extern", "register", 'B'},
        {"What is the size of double data type?", "4 bytes", "8 bytes", "12 bytes", "16 bytes", 'B'},
        {"Which operator has highest precedence?", "*", "+", "()", "/", 'C'},
        {"What does %x format specifier represent?", "decimal", "octal", "hexadecimal", "character", 'C'},
        {"Which is not a storage class in C?", "auto", "static", "volatile", "extern", 'C'},
        {"What is the ASCII value of 'A'?", "65", "97", "64", "96", 'A'},
        {"Which data type can store both positive and negative?", "unsigned int", "signed int", "unsigned char", "both A and B", 'B'},

        {"What is the correct syntax for if statement?", "if condition then", "if (condition)", "if condition:", "if [condition]", 'B'},
        {"The 'continue' statement is used to:", "Exit function", "Skip iteration", "Stop program", "Pause program", 'B'},
        {"The escape sequence for new line is:", "\\t", "\\n", "\\x", "\\s", 'B' },
        {"Which operator is used for bitwise AND?", "&&", "&", "|", "&&&", 'B'},
        {"Which is not a valid C constant?", "const", "#define", "enum", "constant", 'D'},
        {"What is the use of break statement?", "exits program", "exits loop", "skips iteration", "continues loop", 'B'},
        {"Which statement is used for unconditional jump?", "break", "continue", "goto", "return", 'C'},
        {"Which one is a storage class keyword?", "auto", "printf", "external", "scanf", 'A'},
        {"In C, 'a' represents:", "a digit", "an integer", "a character", "a word", 'C'},
        {"Number of arithmetic operators in C:", "4", "5", "6", "7", 'C'},

        {"How many keywords are available in C?", "32", "34", "36", "40", 'A'},
        {"The keyword 'goto' is used for:", "Looping", "Jumping to a label", "Defining variables", "Ending program", 'B'},
        {"What does << operator represent?", "Logical OR", "Logical AND", "Bitwise left shift", "Bitwise right shift", 'C'},
        {"Which function is used to return the length of string?", "strlen()", "strlength()", "length()", "size()", 'A'},
        {"What will be returned by function if no return type?", "int", "void", "char", "Error", 'A'},
        {"Which header file for memory allocation functions in C?", "malloc.h", "stdio.h", "stdlib.h", "memory.h", 'C'},
        {"Which is not a valid if-else statement?", "if ((char)x){}", "if (x) else {}", "if x else {}", "if (x){} else{}", 'C'},
        {"Which operator is used for logical NOT?", "!", "^", "&", "|", 'A'},
        {"Which is correct syntax for single-line comment?", "/* comment */", "// comment", "# comment", "* comment", 'B'},

        {"Which data type holds decimal numbers?", "int", "double", "char", "long", 'B'},
        {"What will be output of: printf(%c, 'A'+1);?", "A", "B", "1", "ASCII value", 'B'},
        {"Which is a conditional control structure?", "switch", "goto", "for", "do-while", 'A'},
        {"Which function is used to compare strings?", "strcmp()", "compare()", "strcompare()", "cmps()", 'A'},
        {"What is the result of sizeof(float)?", "2", "4", "8", "Depends", 'B'},
        {"Which is not a correct array declaration?", "int a[10];", "int a[];", "int[] a;", "int a;", 'C'},
        {"Which is not a loop control statement?", "break", "continue", "exit", "default", 'D'},
        {"What is the initial value of static int variables?", "0", "1", "-1", "Garbage", 'A'},
        {"Which functions can be used for dynamic memory allocation?", "malloc()", "calloc()", "realloc()", "All of the above", 'D'},
        {"Which is correct way to declare pointer to an int?", "int *ptr;", "int ptr;", "int &ptr;", "pointer", 'A'}
    };

    int score = 0;
    char userAnswer;

    // Seed random number generator
    srand(time(NULL));

    // Shuffle all 50 questions
    shuffleQuestions(questionBank, 50);

    printf("\n\t\t***WELCOME_TO_THE_QUIZ_ARENA***\n");
    printf("\n\t*INSTRUCTION* You_Will_be_asked_ten_Random_Question");
    printf("\n\t\t  {Each_Correct_Answer = 1 mark}\n\n");

    // Display first 10 questions one by one
    for (int i = 0; i < 10; i++) {
        printf("\nQuestion %d: %s", i + 1, questionBank[i].question);
        printf("\nA.  %s ", questionBank[i].optionA);
        printf("\nB.  %s", questionBank[i].optionB);
        printf("\nC.  %s", questionBank[i].optionC);
        printf("\nD.  %s", questionBank[i].optionD);
        printf("\nYour answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);

        // Convert to uppercase for comparison
        userAnswer = toupper(userAnswer);
        
        // Check answer
        if (userAnswer == questionBank[i].correctAnswer) {
            printf("Correct! +1 mark \n");
            score++;
        } else {
            printf("Wrong! Correct answer was: %c \n", questionBank[i].correctAnswer);
        }


    }

    // Display Final Score 
    printf("\n\t    ***QUIZ_COMPLETED!***\n");
    printf("\tYour final score: %d out of 10", score);
    printf("\n\t     Percentage: %.2f%%\n\n",(score * 10.0));

    return 0;
}
