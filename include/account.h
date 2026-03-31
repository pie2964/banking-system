#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "constants.h"

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char ownerName[OWNER_NAME_LENGTH];
    long balance;
    int isActive;
} Account;

void account_clear(Account *account);
int account_create(Account *account, const char *accountNumber, const char *ownerName, long initialBalance);
int account_is_valid_number(const char *accountNumber);
int account_is_valid_owner_name(const char *ownerName);
int account_matches_number(const Account *account, const char *accountNumber);
void account_print(const Account *account);

#endif
