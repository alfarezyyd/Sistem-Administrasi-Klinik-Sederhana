#pragma once

// Built-in Header File
#include <string.h>
#include <stdio.h>

// User-defined Header File
#include "../Custom/Structure.h"
#include "../Custom/Helper.h"

void getAllICDGroup()
{
    FILE *allICDGroupData = fopen("Data/DiseaseData.csv", "r");

    char bufferData[128];

    while (fgets(bufferData, 128, allICDGroupData))
    {
        char *valueData = strtok(bufferData, ",");
        if (valueData[1] == '.' || valueData[1] == '-')
        {
            while (valueData)
            {
                printf("%s", valueData);
                valueData = strtok(NULL, ",");
            }
        }
    }

    fclose(allICDGroupData);
}

int getAllDiseaseData(char *icdGroup)
{
    int successStatus = 0;
    FILE *allDiseaseData = fopen("Data/DiseaseData.csv", "r");

    char bufferData[128];
    char firstCharDisease[2];

    while (fgets(bufferData, 128, allDiseaseData))
    {
        char *valueData = strtok(bufferData, ",");
        strncpy(firstCharDisease, valueData, 1);

        if (strcmp(icdGroup, "D-E") == 0)
        {
            if (strcmp(firstCharDisease, "D") == 0 || strcmp(firstCharDisease, "E") == 0)
            {
                while (valueData)
                {
                    printf("%s", valueData);
                    valueData = strtok(NULL, ",");
                }
                successStatus = 1;
                continue;
            }
        }

        if (strcmp(firstCharDisease, icdGroup) == 0 && strcmp(icdGroup, "D") != 0 && strcmp(icdGroup, "E") != 0)
        {
            while (valueData)
            {
                printf("%s", valueData);
                valueData = strtok(NULL, ",");
            }
            successStatus = 1;
        }
    }

    if (successStatus == 0)
    {
        sendFeedback("Pilihan Anda Tidak Valid \nMohon Pilih Kembali Dengan Benar", "\x1b[31m");
    }

    fclose(allDiseaseData);
    return successStatus;
}

int getDetailDiseaseData(char *patientDiagnosis)
{
    int successStatus = 0;
    FILE *allDiseaseData = fopen("Data/DiseaseData.csv", "r");

    char bufferData[128];
    while (fgets(bufferData, 128, allDiseaseData))
    {
        char *valueData = strtok(bufferData, ",");
        int columnNumber = 1;

        if (strcmp(valueData, patientDiagnosis) == 0 && patientDiagnosis[1] != '.' && patientDiagnosis[1] != '-')
        {
            while (valueData)
            {
                if (columnNumber == 1)
                {
                    strcpy(FullPatientData.diseaseHistoryPatient.icdGroup, valueData);
                }
                else if (columnNumber == 2)
                {
                    strcpy(FullPatientData.diseaseHistoryPatient.diseaseDiagnosis, valueData);
                }

                valueData = strtok(NULL, ",");
                columnNumber++;
            }
            successStatus = 1;
            break;
        }
    }

    if (successStatus == 0)
    {
        sendFeedback("Pilihan Diagnosa Anda Tidak Valid \nMohon Pilih Kembali Dengan Benar", "\x1b[31m");
    }
    fclose(allDiseaseData);
    return successStatus;
}
