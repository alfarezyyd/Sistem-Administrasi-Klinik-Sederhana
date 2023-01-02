// Built-in Header File
#include <stdio.h>

// User Defined Header File
#include "Custom/Helper.h"
#include "Controller/PatientController.h"
#include "Controller/DiseaseController.h"
#include "Controller/ActionController.h"
#include "Controller/MedicineController.h"
#include "Controller/TransactionController.h"
#include "Controller/InformationController.h"

int main()
{
    int userChooseMenu, successStatus = 0, medicinePrice = 0, actionPrice = 0;

    printf("================================================= \n");
    printf("========== Selamat Datang di Aplikasi =========== \n");
    printf("===== Sistem Informasi Klinik Sakit Melarat ===== \n");
    printf("================================================= \n");

checkPointUserChoose:

    printf("Menu Aplikasi - Klinik Sakit Melarat \n");
    printf("1. Registrasi Pasien Baru \n");
    printf("2. Registrasi Berobat Pasien \n");
    printf("3. Informasi Klinik \n");

    inputNumber(&userChooseMenu, "Pilih Menu Aplikasi Anda : ");

    switch (userChooseMenu)
    {
    case 1:
        newPatientRegistration();
        goto checkPointUserChoose;
        break;
    case 2:
        successStatus = searchDataPatient();
        if (!successStatus)
        {
            sendFeedback("Data Pasien Tidak Ditemukan\nKembali Ke Menu Aplikasi", "\x1b[31m");
            goto checkPointUserChoose;
        }

        printf("Pemeriksaan Pasien \n");
        patientExamination();
        inputDiseaseDataPatient();

        printf("Tindakan Terhadap Pasien \n");
        actionPrice = actionOnPatients();
        if (actionPrice == 0)
        {
            break;
        }
        
        printf("Pelayanan Obat Untuk Pasien \n");
        medicinePrice = medicineForPatients();

        printf("Pembayaran Administrasi \n");
        administrationPayments(&medicinePrice, &actionPrice);
        break;
    case 3:
        informationApplication();
        goto checkPointUserChoose;
        break;
    default:
        sendFeedback("Pilihan Anda Tidak Valid", "\x1b[31m");
        goto checkPointUserChoose;
        break;
    }

    printf("Terima Kasih Telah Berobat Ke Klinik Sakit Melarat \n");
    printf("\x03\x03\x03 - Semoga Sakitnya Semakin Parah Agar Kembali Lagi - \x03\x03\x03\n");
    return 0;
}