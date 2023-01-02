#pragma once

// Built-in Header File
#include <string.h>

// User-defined Header File
#include "../Model/ActionModel.h"
#include "../Custom/Helper.h"

int actionOnPatients()
{
    int actionPrice = 0, statusSuccess;
    char choiceAction[5];
    do
    {
        getAllDataAction();
        inputCharacter(choiceAction, "Masukan Pilihan Tindakan Terhadap Pasien : ");
        if (strcmp(choiceAction, "17") == 0)
        {
            makingReferrals();
            sendFeedback("Surat Rujukan Telah Dibuat", "\x1b[32m");
            return 0;
        }
        else 
        {
            addPriceOfAction(choiceAction, &actionPrice, &statusSuccess);
        }

    } while (statusSuccess == 0);
    printf("Harga Tindakan : %d \n", actionPrice);
    return actionPrice;
}