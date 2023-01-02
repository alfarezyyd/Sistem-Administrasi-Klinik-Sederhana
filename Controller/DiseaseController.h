#pragma once

// Built-in Header File
#include <stdio.h>

// User Defined Header File
#include "../Custom/Helper.h"
#include "../Model/DiseaseModel.h"

void patientExamination()
{
    char icdGroup, patientDiagnosis;
    int successStatus = 0;

    do
    {
        printf("ICD - International Classification of Diseases \n");
        getAllICDGroup();

        inputCharacter(&icdGroup, "Masukkan Kelompok ICD : ");
        successStatus = getAllDiseaseData(&icdGroup);

        if (successStatus == 0)
        {
            continue;
        }

        inputCharacter(&patientDiagnosis, "Masukkan Pilihan Diagnosa : ");
        successStatus = getDetailDiseaseData(&patientDiagnosis);
    } while (successStatus == 0);
}