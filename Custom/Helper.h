#pragma once
// Built-in Header File
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void sendFeedback(const char *feedbackMessage, const char *statusCode)
{
    printf("%s%s.\x1b[0m\n", statusCode, feedbackMessage);
    printf("Tekan Tombol Apapun Untuk Melanjutkan");
    getch();
    system("cls");
}

void inputNumber(int *inputData, const char *instructionMessage)
{
    do
    {
        printf("%s", instructionMessage);
        fflush(stdin);
        if (scanf(" %d", inputData) == 0)
        {
            printf("\x1b[31mInput Anda Tidak Valid! Mohon Lakukan Dengan Benar.\n \x1b[0m");
        }
        else
        {
            break;
        };
    } while (1);
}

void inputCharacter(char *containerVariable, const char *instructionMessage)
{
    printf("%s", instructionMessage);
    scanf(" %[^\n]s", containerVariable);
}
