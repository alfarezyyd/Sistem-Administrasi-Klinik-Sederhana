#pragma once

// Built-in Header File

// User Defined Header File
#include "../Model/PatientModel.h"
#include "../Custom/Helper.h"
#include "../Custom/Structure.h"

void newPatientRegistration()
{
    int validationState;
    char bpjsStatus[2];
    do
    {
        inputCharacter(bpjsStatus, "Apakah Anda Memiliki BPJS (Y/N) : ");
        if (strcmp(bpjsStatus, "Y") != 0 && strcmp(bpjsStatus, "y") != 0 && strcmp(bpjsStatus, "N") != 0 && strcmp(bpjsStatus, "n") != 0)
        {
            sendFeedback("Pilihan Anda Tidak Valid\nMohon Lakukan dengan Benar", "\x1b[31m");
            continue;
        }
        break;
    } while (1);

    do
    {
        validationState = 1;
        inputCharacter(FullPatientData.medicalRecordCode, "Masukkan Kode Rekam Medis : ");
        validateMedicalRecordCode(&validationState);
    } while (validationState == 0);
    inputCharacter(FullPatientData.fullName, "Masukkan Nama Lengkap Pasien : ");
    inputCharacter(FullPatientData.dateOfBirth, "Masukkan Tanggal Lahir Pasien (DD-MM-YYYY) : ");
    inputNumber(&FullPatientData.nationalIdentityNumber, "Masukkan NIK Pasien : ");
    if (strcmp(bpjsStatus, "Y") == 0 || strcmp(bpjsStatus, "y") == 0)
    {
        inputNumber(&FullPatientData.bpjsNumber, "Masukkan Nomor BPJS : ");
    }
    else
    {
        FullPatientData.bpjsNumber = 0;
    }

    inputCharacter(FullPatientAddressData.urbanVillageName, "Masukkan Nama Kelurahan : ");
    inputCharacter(FullPatientAddressData.subDistrictName, "Masukkan Nama Kecamatan : ");
    inputCharacter(FullPatientAddressData.districtName, "Masukkan Nama Kabupaten : ");
    inputCharacter(FullPatientAddressData.provinceName, "Masukkan Nama Provinsi : ");
    inputNumber(&FullPatientAddressData.neighborhoodNumber, "Masukkan Nomor RT : ");
    inputNumber(&FullPatientAddressData.hamletNumber, "Masukkan Nomor RW : ");
    inputNumber(&FullPatientAddressData.postalCode, "Masukkan Kode Pos : ");
    FullPatientData.patientAddress = FullPatientAddressData;
    writeFullPatientData();
    sendFeedback("Data Pasien Telah Berhasil Ditambahkan", "\x1b[32m");
}

int searchDataPatient()
{
    int successStatus = 0;
    char medicalRecordCode[15];
    inputCharacter(medicalRecordCode, "Masukkan Kode Rekam Medis Pasien : ");
    getPatientData(medicalRecordCode, &successStatus);
    return successStatus;
}

void inputDiseaseDataPatient()
{
    writeDiseaseDataPatient();
    sendFeedback("Data Penyakit Pasien Berhasil Ditambahkan", "\x1b[32m");
}