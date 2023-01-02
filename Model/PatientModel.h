#pragma once
// Built-in Header File
#include <stdio.h>

// User Defined Header File
#include "../Custom/Structure.h"
#include "../Custom/Helper.h"

// Template Function
void assignPatientData(int columnNumber, char *valueData);
void getHistoryDiseaseData();

void writeFullPatientData()
{
    FILE *PatientData = fopen("Data/PatientData.csv", "a");

    fprintf(
        PatientData,
        "%s, %s, %s, %d, %d, %s, %s, %s, %s, %d, %d, %d\n",
        FullPatientData.medicalRecordCode,
        FullPatientData.fullName,
        FullPatientData.dateOfBirth,
        FullPatientData.nationalIdentityNumber,
        FullPatientData.bpjsNumber,
        FullPatientData.patientAddress.urbanVillageName,
        FullPatientData.patientAddress.subDistrictName,
        FullPatientData.patientAddress.districtName,
        FullPatientData.patientAddress.provinceName,
        FullPatientData.patientAddress.neighborhoodNumber,
        FullPatientData.patientAddress.hamletNumber,
        FullPatientData.patientAddress.postalCode);
    fclose(PatientData);
}

void getPatientData(char *medicalRecordCode, int *statusSuccess)
{
    FILE *PatientData = fopen("Data/PatientData.csv", "r");

    char bufferData[256];
    while (fgets(bufferData, 256, PatientData))
    {
        char *valueData = strtok(bufferData, ",");
        int columnNumber = 1;
        if (strcmp(valueData, medicalRecordCode) == 0)
        {
            while (valueData)
            {
                assignPatientData(columnNumber, valueData);
                printf("%s\n", valueData);
                valueData = strtok(NULL, ",");
                columnNumber++;
            }
            getHistoryDiseaseData();
            *statusSuccess = 1;
            break;
        }
    }
    if (*statusSuccess == 1)
    {
        sendFeedback("Data Pasien Berhasil Didapat", "\x1b[32m");
    }

    fclose(PatientData);
}

void writeDiseaseDataPatient()
{
    FILE *writeDiseaseData = fopen("Data/PatientDiseaseHistoryData.csv", "a");

    fprintf(
        writeDiseaseData,
        "%s, %s           ,%s\n",
        FullPatientData.medicalRecordCode,
        FullPatientData.diseaseHistoryPatient.icdGroup,
        FullPatientData.diseaseHistoryPatient.diseaseDiagnosis);
    fclose(writeDiseaseData);
}

void getHistoryDiseaseData()
{
    FILE *HistoryDiseasePatient = fopen("Data/PatientDiseaseHistoryData.csv", "r");
    char bufferData[128];
    int columnNumber = 1, statusData = 0;
    printf("KELOMPOK ICD    DIAGNOSA PENYAKIT\n");
    while (fgets(bufferData, 128, HistoryDiseasePatient))
    {
        char *valueData = strtok(bufferData, ",");
        columnNumber = 1;
        if (strcmp(valueData, FullPatientData.medicalRecordCode) == 0)
        {
            while (valueData)
            {
                if (columnNumber != 1)
                {
                    printf("%s", valueData);
                }
                valueData = strtok(NULL, ",");
                columnNumber++;
            }
            statusData = 1;
        }
    }
    if (statusData == 0)
    {
        printf("Data Riwayat Pasien Belum Ada! \n");
    }

    fclose(HistoryDiseasePatient);
}

void validateMedicalRecordCode(int *validationState)
{
    FILE *PatientData = fopen("Data/PatientData.csv", "r");
    char bufferData[128];
    while (fgets(bufferData, 128, PatientData))
    {
        char *valueData = strtok(bufferData, ", ");
        if (strcmp(valueData, FullPatientData.medicalRecordCode) == 0)
        {
            sendFeedback("Data Pasien Telah Terdaftar\nSilahkan Input Kode Rekam Medis Kembali", "\x1b[31m");
            *validationState = 0;
            break;
        }
    }
    fclose(PatientData);
}

void assignPatientData(int columnNumber, char *valueData)
{
    switch (columnNumber)
    {
    case 1:
        printf("Kode Rekam Medis : ");
        strcpy(FullPatientData.medicalRecordCode, valueData);
        break;
    case 2:
        printf("Nama Lengkap : ");
        strcpy(FullPatientData.fullName, valueData);
        break;
    case 3:
        printf("Tanggal Lahir : ");
        break;
    case 4:
        printf("NIK : ");
        break;
    case 5:
        printf("Nomor BPJS : ");
        FullPatientData.bpjsNumber = atoi(valueData);
        break;
    case 6:
        printf("Nama Kelurahan : ");
        strcpy(FullPatientData.patientAddress.urbanVillageName, valueData);
        break;
    case 7:
        printf("Nama Kecamatan : ");
        break;
    case 8:
        printf("Nama Kabupaten : ");
        break;
    case 9:
        printf("Nama Provinsi : ");
        break;
    case 10:
        printf("Nomor RT : ");
        FullPatientData.patientAddress.neighborhoodNumber = atoi(valueData);
        break;
    case 11:
        printf("Nomor RW : ");
        FullPatientData.patientAddress.hamletNumber = atoi(valueData);
        break;
    case 12:
        printf("Kode Pos : ");
        break;
    default:
        break;
    }
}