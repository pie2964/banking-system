#include "../include/account.h"
#include "../include/bank.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void trim_newline(char *text) {
    size_t length;

    if (text == NULL) {
        return;
    }

    length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }
}

static int read_line(const char *prompt, char *buffer, size_t size) {
    if (prompt != NULL) {
        printf("%s", prompt);
    }

    if (buffer == NULL || size == 0) {
        return 0;
    }

    if (fgets(buffer, (int)size, stdin) == NULL) {
        return 0;
    }

    trim_newline(buffer);
    return 1;
}

static int read_long_value(const char *prompt, long *value) {
    char buffer[64];
    char *endPointer;
    long parsedValue;

    if (value == NULL) {
        return 0;
    }

    if (!read_line(prompt, buffer, sizeof(buffer))) {
        return 0;
    }

    parsedValue = strtol(buffer, &endPointer, 10);
    if (buffer[0] == '\0' || *endPointer != '\0') {
        return 0;
    }

    *value = parsedValue;
    return 1;
}

static void print_menu(void) {
    printf("\n=== Banking System ===\n");
    printf("1. Create Account\n");
    printf("2. List Accounts\n");
    printf("0. Exit\n");
    printf("Select: ");
}

static void handle_create_account(Bank *bank) {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char ownerName[OWNER_NAME_LENGTH];
    long initialBalance;

    if (!read_line("Account Number: ", accountNumber, sizeof(accountNumber))) {
        printf("Failed to read account number.\n");
        return;
    }

    if (bank_has_account_number(bank, accountNumber)) {
        printf("Account number already exists.\n");
        return;
    }

    if (!read_line("Owner Name: ", ownerName, sizeof(ownerName))) {
        printf("Failed to read owner name.\n");
        return;
    }

    if (!read_long_value("Initial Balance: ", &initialBalance)) {
        printf("Invalid balance input.\n");
        return;
    }

    if (!bank_create_account(bank, accountNumber, ownerName, initialBalance)) {
        printf("Failed to create account. Check the input values.\n");
        return;
    }

    printf("Account created successfully.\n");
}

static void handle_list_accounts(const Bank *bank) {
    printf("\n=== Account List ===\n");
    bank_print_all_accounts(bank);
}

int main(void) {
    Bank bank;
    long menu;

    bank_initialize(&bank);

    while (1) {
        print_menu();

        if (!read_long_value(NULL, &menu)) {
            printf("Invalid menu input.\n");
            continue;
        }

        if (menu == 0) {
            printf("Exiting program.\n");
            break;
        }

        if (menu == 1) {
            handle_create_account(&bank);
        } else if (menu == 2) {
            handle_list_accounts(&bank);
        } else {
            printf("Invalid menu option.\n");
        }
    }

    return 0;
}
