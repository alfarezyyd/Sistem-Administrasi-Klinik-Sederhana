#pragma once

struct Address
{
    char urbanVillageName[64];
    char subDistrictName[64];
    char districtName[64];
    char provinceName[64];
    int neighborhoodNumber, hamletNumber, postalCode;
} FullPatientAddressData;

struct Disease
{
    char icdGroup[10];
    char diseaseDiagnosis[128];
};

struct Patient
{
    char medicalRecordCode[15];
    char fullName[64];
    char dateOfBirth[20];
    int nationalIdentityNumber;
    int bpjsNumber;
    struct Address patientAddress;
    struct Disease diseaseHistoryPatient;
} FullPatientData;
