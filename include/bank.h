#ifndef BANK_H
#define BANK_H

#include "account.h"

typedef struct {
    Account accounts[MAX_ACCOUNTS];
} Bank;

void bank_initialize(Bank *bank);
int bank_create_account(Bank *bank, const char *accountNumber, const char *ownerName, long initialBalance);
int bank_has_account_number(const Bank *bank, const char *accountNumber);
int bank_get_account_count(const Bank *bank);
void bank_print_all_accounts(const Bank *bank);

#endif
