#pragma once

// Built-in Header File
#include <string.h>
#include <stdio.h>

// User-defined Header File
#include "../Custom/Helper.h"

void getClassTherapyMedicine()
{
    FILE *allClassTherapyData = fopen("Data/MedicineTherapyClassData.csv", "r");

    char bufferData[64];
    while (fgets(bufferData, 64, allClassTherapyData))
    {
        char *valueData = strtok(bufferData, ",");
        if (valueData[1] != '.')
        {
            while (valueData)
            {
                printf(" %s", valueData);
                valueData = strtok(NULL, ",");
            }
        }
    }
    fclose(allClassTherapyData);
}

void getSubClassTherapyMedicine(char *therapyClass, int *statusSuccess)
{
    FILE *subClassTherapyData = fopen("Data/MedicineTherapyClassData.csv", "r");

    char bufferData[64];
    while (fgets(bufferData, 64, subClassTherapyData))
    {
        char *valueData = strtok(bufferData, ",");
        if (valueData[0] == *therapyClass)
        {
            while (valueData)
            {
                printf(" %s", valueData);
                valueData = strtok(NULL, ",");
            }
            *statusSuccess = 1;
        }
    }

    if (*statusSuccess == 0)
    {
        sendFeedback("Pilihan Anda Tidak Valid\nMohon Pilih Opsi Obat Yang Tersedia", "\x1b[31m");
    }
    fclose(subClassTherapyData);
}

void getAllMedicine(char *subClassTherapy, int *statusSuccess)
{
    FILE *MedicineData = fopen("Data/MedicineData.csv", "r");

    char bufferData[128];
    int rowData = 1;
    char subStringClassTherapy[9];
    while (fgets(bufferData, 128, MedicineData))
    {
        char *valueData = strtok(bufferData, ",");
        if (rowData == 1)
        {
            while (valueData)
            {
                printf("%s", valueData);
                valueData = strtok(NULL, ",");
            }
            rowData = 0;
            continue;
        }

        strncpy(subStringClassTherapy, valueData, 3);
        if (strcmp(subStringClassTherapy, subClassTherapy) == 0)
        {
            while (valueData)
            {
                printf(" %s", valueData);
                valueData = strtok(NULL, ",");
            }
            *statusSuccess = 1;
        }
    }
    if (*statusSuccess == 0)
    {
        sendFeedback("Pilihan Anda Tidak Valid\nMohon Pilih Opsi Obat Yang Tersedia", "\x1b[31m");
    }
    fclose(MedicineData);
}

void getPriceMedicine(char *medicineCode, int *priceOfMedicine, int *statusSuccess)
{
    FILE *medicinePriceData = fopen("Data/MedicineData.csv", "r");

    char bufferData[128];
    int columnNumber = 0;
    while (fgets(bufferData, 128, medicinePriceData))
    {
        char *valueData = strtok(bufferData, ",");
        columnNumber = 1;
        if (strcmp(valueData, medicineCode) == 0)
        {
            while (valueData)
            {
                printf("%s", valueData);
                if (columnNumber == 4)
                {
                    *priceOfMedicine += atoi(valueData);
                }
                valueData = strtok(NULL, ",");
                columnNumber++;
            }
            *statusSuccess = 1;
        }
    }
    if (*statusSuccess == 0)
    {
        sendFeedback("Pilihan Anda Tidak Valid\nMohon Pilih Opsi Obat Yang Tersedia", "\x1b[31m");
    }
    fclose(medicinePriceData);
}