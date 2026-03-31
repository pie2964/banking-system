#include "../include/account.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void copy_text(char *destination, size_t destinationSize, const char *source) {
    if (destination == NULL || destinationSize == 0) {
        return;
    }

    if (source == NULL) {
        destination[0] = '\0';
        return;
    }

    strncpy(destination, source, destinationSize - 1);
    destination[destinationSize - 1] = '\0';
}

void account_clear(Account *account) {
    if (account == NULL) {
        return;
    }

    account->accountNumber[0] = '\0';
    account->ownerName[0] = '\0';
    account->balance = 0L;
    account->isActive = 0;
}

int account_is_valid_number(const char *accountNumber) {
    size_t index;
    size_t length;

    if (accountNumber == NULL) {
        return 0;
    }

    length = strlen(accountNumber);
    if (length == 0 || length >= ACCOUNT_NUMBER_LENGTH) {
        return 0;
    }

    for (index = 0; index < length; ++index) {
        if (!isdigit((unsigned char)accountNumber[index])) {
            return 0;
        }
    }

    return 1;
}

int account_is_valid_owner_name(const char *ownerName) {
    if (ownerName == NULL) {
        return 0;
    }

    if (strlen(ownerName) == 0 || strlen(ownerName) >= OWNER_NAME_LENGTH) {
        return 0;
    }

    return 1;
}

int account_create(Account *account, const char *accountNumber, const char *ownerName, long initialBalance) {
    if (account == NULL) {
        return 0;
    }

    if (!account_is_valid_number(accountNumber) || !account_is_valid_owner_name(ownerName)) {
        return 0;
    }

    if (initialBalance < MIN_INITIAL_BALANCE) {
        return 0;
    }

    copy_text(account->accountNumber, sizeof(account->accountNumber), accountNumber);
    copy_text(account->ownerName, sizeof(account->ownerName), ownerName);
    account->balance = initialBalance;
    account->isActive = 1;

    return 1;
}

int account_matches_number(const Account *account, const char *accountNumber) {
    if (account == NULL || accountNumber == NULL) {
        return 0;
    }

    if (!account->isActive) {
        return 0;
    }

    return strcmp(account->accountNumber, accountNumber) == 0;
}

void account_print(const Account *account) {
    if (account == NULL || !account->isActive) {
        printf("Account information is not available.\n");
        return;
    }

    printf("Account Number : %s\n", account->accountNumber);
    printf("Owner Name     : %s\n", account->ownerName);
    printf("Balance        : %ld\n", account->balance);
}
