#pragma once

// User-defined Header File
#include "../Model/MedicineModel.h"
#include "../Custom/Helper.h"

int medicineForPatients()
{
    int priceOfMedicine = 0, statusSuccess = 0;
    char userChoice[2], therapyClass[4], subTherapyClass[4], medicineChoice[6];
    do
    {
        getClassTherapyMedicine();
        inputCharacter(therapyClass, "Masukkan Pilihan Kelas Terapi Obat : ");

        if (strcmp(therapyClass, "5") != 0 && strcmp(therapyClass, "3") != 0)
        {
            getSubClassTherapyMedicine(therapyClass, &statusSuccess);
            if (statusSuccess == 0)
            {
                continue;
            }
            inputCharacter(subTherapyClass, "Masukkan Pilihan Sub Kelas Terapi Obat : ");
        }
        else
        {
            strcat(therapyClass, ".1");
            strcpy(subTherapyClass, therapyClass);
        }
        
        statusSuccess = 0;
        getAllMedicine(subTherapyClass, &statusSuccess);

        if (statusSuccess == 0)
        {
            continue;
        }

        inputCharacter(medicineChoice, "Masukkan Pilihan Kode Obat : ");
        statusSuccess = 0;
        
        getPriceMedicine(medicineChoice, &priceOfMedicine, &statusSuccess);
        if (statusSuccess == 0)
        {
            continue;
        }

        inputCharacter(userChoice, "Apakah Anda Ingin Menambahkan Pilihan Obat (Y/N) : ");
        if (strcmp(userChoice, "Y") != 0 && strcmp(userChoice, "y") != 0 && strcmp(userChoice, "N") != 0 && strcmp(userChoice, "n") != 0)
        {
            sendFeedback("Pilihan Anda Tidak Valid\nMohon Pilih Opsi  Yang Tersedia", "\x1b[31m");
            continue;
        }

    } while (strcmp(userChoice, "N") != 0 && strcmp(userChoice, "n") != 0);
    printf("Total Harga Semua Obat : %d \n", priceOfMedicine);
    return priceOfMedicine;
}