#pragma once

// Built-in Header File
#include <stdio.h>

// User Defined Header File
#include "../Custom/Helper.h"
#include "../Model/TransactionModel.h"
#include "../Custom/Structure.h"

void administrationPayments(int *medicinePrice, int *actionPrice)
{
    int paymentMoney = 0;
    float priceAfterTax;
    do
    {
        printf("Total Biaya Administasi Anda Adalah : %d\n", (*medicinePrice + *actionPrice));
        priceAfterTax = (*medicinePrice + *actionPrice) + (0.11 * (*medicinePrice + *actionPrice));

        printf("Total Biaya Administasi Anda Setelah Pajak Adalah : %.2f\n", priceAfterTax);

        if (FullPatientData.bpjsNumber != 0)
        {
            printf("Biaya Administrasi Anda Telah Tercover BPJS Kesakitan \n");
            priceAfterTax = 0;
            break;
        }

        inputNumber(&paymentMoney, "Masukkan Uang Pembayaran : ");
        if (paymentMoney < priceAfterTax)
        {
            sendFeedback("Uang Anda Tidak Cukup\nSilahkan Masukkan Uang Pembayaran Kembali", "\x1b[31m");
        }
        else if (paymentMoney > priceAfterTax)
        {
            printf("Kembalian Anda : %.2f \n", (paymentMoney - priceAfterTax));
            break;
        }
        else
        {
            sendFeedback("Uang Anda Cukup", "\x1b[32m");
            break;
        }
    } while (1);
    makingPaymentReceipts(medicinePrice, actionPrice, &paymentMoney, &priceAfterTax);
    sendFeedback("Bukti Pembayaran Administrasi Telah Dibuat", "\x1b[32m");
}
