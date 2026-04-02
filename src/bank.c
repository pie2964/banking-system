#include "../include/bank.h"

#include <stdio.h>

static int bank_find_empty_account_slot(Bank *bank) {
    int index;

    if (bank == NULL) {
        return -1;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        if (!bank->accounts[index].isActive) {
            return index;
        }
    }

    return -1;
}

void bank_initialize(Bank *bank) {
    int index;

    if (bank == NULL) {
        return;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        account_clear(&bank->accounts[index]);
    }
}

int bank_has_account_number(const Bank *bank, const char *accountNumber) {
    int index;

    if (bank == NULL || accountNumber == NULL) {
        return 0;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        if (account_matches_number(&bank->accounts[index], accountNumber)) {
            return 1;
        }
    }

    return 0;
}

const Account *bank_find_account_by_number(const Bank *bank, const char *accountNumber) {
    int index;

    if (bank == NULL || accountNumber == NULL) {
        return NULL;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        if (account_matches_number(&bank->accounts[index], accountNumber)) {
            return &bank->accounts[index];
        }
    }

    return NULL;
}

int bank_create_account(Bank *bank, const char *accountNumber, const char *ownerName, long initialBalance) {
    int slotIndex;

    if (bank == NULL) {
        return 0;
    }

    if (bank_find_account_by_number(bank, accountNumber) != NULL) {
        return 0;
    }

    slotIndex = bank_find_empty_account_slot(bank);
    if (slotIndex < 0) {
        return 0;
    }

    return account_create(&bank->accounts[slotIndex], accountNumber, ownerName, initialBalance);
}

int bank_get_account_count(const Bank *bank) {
    int index;
    int count = 0;

    if (bank == NULL) {
        return 0;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        if (bank->accounts[index].isActive) {
            ++count;
        }
    }

    return count;
}

void bank_print_all_accounts(const Bank *bank) {
    int index;

    if (bank == NULL) {
        printf("은행 정보가 초기화되지 않았습니다.\n");
        return;
    }

    if (bank_get_account_count(bank) == 0) {
        printf("등록된 계좌가 없습니다.\n");
        return;
    }

    for (index = 0; index < MAX_ACCOUNTS; ++index) {
        if (!bank->accounts[index].isActive) {
            continue;
        }

        account_print(&bank->accounts[index]);
        printf("\n");
    }
}
