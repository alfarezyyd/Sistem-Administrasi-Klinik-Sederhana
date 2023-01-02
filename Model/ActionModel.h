#pragma once

// Built-in Header File
#include <stdio.h>
#include <string.h>
#include <time.h>

// User-defined Header File
#include "../Custom/Structure.h"
#include "../Custom/Helper.h"

void getAllDataAction()
{
    FILE *allActionData = fopen("Data/ActionData.csv", "r");

    char bufferData[64];
    while (fgets(bufferData, 64, allActionData))
    {
        char *valueData = strtok(bufferData, ",");
        while (valueData)
        {
            printf("%s", valueData);
            valueData = strtok(NULL, ",");
        }
    }
    fclose(allActionData);
}

void addPriceOfAction(char *choiceAction, int *actionPrice, int *statusSuccess)
{
    FILE *actionDetails = fopen("Data/ActionData.csv", "r");

    char bufferData[64];
    int columnNumber;
    while (fgets(bufferData, 64, actionDetails))
    {
        char *valueData = strtok(bufferData, ",");
        columnNumber = 1;
        if (strcmp(valueData, choiceAction) == 0)
        {
            while (valueData)
            {
                printf("%s", valueData);
                if (columnNumber == 3)
                {
                    if (*valueData == '-')
                    {
                        *statusSuccess = 0;
                        break;
                    }
                    *actionPrice = atoi(valueData);
                }
                valueData = strtok(NULL, ",");
                columnNumber++;
                *statusSuccess = 1;
            }
        }
    }

    if (*statusSuccess == 0)
    {
        sendFeedback("Pilihan Anda Tidak Valid\nMohon Pilih Opsi Layanan Yang Tersedia", "\x1b[31m");
    }
    fclose(actionDetails);
}

void makingReferrals()
{
    time_t timeNow = time(NULL);
    FILE *PatientData = fopen("Docs/Surat-Rujukan.txt", "w+");

    fprintf(
        PatientData,
        "\t\t\t\tKlinik Sakit Melarat \n \
        \t\t  Jalan Marlboro No. 18 RT. 02/14 \n \
          Kp. Meikarta, Cikarang Panas, Bekasi Apa Lagi \n \
          ===================================================== \n \
           -------------- Surat Rujukan Klinik -------------- \n \
          ===================================================== \n \
           Tanggal dan Waktu Cetak : %s \n \
           Nomor Surat Rujukan : %d \n \
          ===================================================== \n \
            ------------------ Data Pasien ------------------ \n \
          ===================================================== \n \
           Kode Rekam Medis : %s \n \
           Nama Lengkap : %s \n \
           Alamat : %s, RT. %d, RW. %d \n \
          ===================================================== \n \
            --------------- Informasi Penyakit --------------- \n \
          ===================================================== \n \
           Kelompok ICD : %s \n \
           Diagnosis Penyakit : %s \n \
          ===================================================== \n \
           Mohon bantu Pemeriksaaan, Pengobatan dan Perawatan \n \
           Atas bantuannya, kami ucapkan terima kasih",
        ctime(&timeNow),
        timeNow,
        FullPatientData.medicalRecordCode,
        FullPatientData.fullName,
        FullPatientData.patientAddress.subDistrictName,
        FullPatientData.patientAddress.neighborhoodNumber,
        FullPatientData.patientAddress.hamletNumber,
        FullPatientData.diseaseHistoryPatient.icdGroup,
        FullPatientData.diseaseHistoryPatient.diseaseDiagnosis);
    fclose(PatientData);
}