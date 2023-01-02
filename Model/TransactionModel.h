#pragma once

// Built-in Header File
#include <stdio.h>
#include <time.h>

// User Defined Header File
#include "../Custom/Structure.h"

void makingPaymentReceipts(int *medicinePrice, int *actionPrice, int *paymentMoney, float *priceAfterTax)
{
  time_t timeNow = time(NULL);

  FILE *PatientData = fopen("Docs/Bukti-Pembayaran.txt", "w+");

    fprintf(
      PatientData,
      "\t\t\t\tKlinik Sakit Melarat \n \
        \t\t  Jalan Marlboro No. 18 RT. 02/14 \n \
          Kp. Meikarta, Cikarang Panas, Bekasi Apa Lagi \n \
          ===================================================== \n \
           ---------- Bukti Pembayaran Administrasi ---------- \n \
          ===================================================== \n \
           Tanggal dan Waktu Cetak : %s \
           Nomor Transaksi : %d \n \
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
            ---------- Informasi Biaya Administrasi ---------- \n \
          ===================================================== \n \
          TOTAL HARGA TINDAKAN   (Rp) : %d \n \
          TOTAL HARGA OBAT       (Rp) : %d \n \
          --------------------------------------- (+) \n \
          BIAYA TOTAL (PPn 11%)  (Rp) : %.2f \n \
          UANG PEMBAYARAN        (Rp) : %d \n \
          ======================================= (-) \n \
          KEMBALIAN              (Rp) : %.2f",
      ctime(&timeNow),
      timeNow,
      FullPatientData.medicalRecordCode,
      FullPatientData.fullName,
      FullPatientData.patientAddress.urbanVillageName,
      FullPatientData.patientAddress.neighborhoodNumber,
      FullPatientData.patientAddress.hamletNumber,
      FullPatientData.diseaseHistoryPatient.icdGroup,
      FullPatientData.diseaseHistoryPatient.diseaseDiagnosis,
      *actionPrice,
      *medicinePrice,
      *priceAfterTax,
      *paymentMoney,
      (*paymentMoney - *priceAfterTax));
  fclose(PatientData);
}
