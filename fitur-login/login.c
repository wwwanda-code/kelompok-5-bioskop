#include <stdio.h>
#include <string.h>
#include "login.h"

int login() {
    char username[20], password[20];

    printf("===== LOGIN CINEMA X =====\n");

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "12345") == 0) {

        printf("\nLogin berhasil!\n");
        return 1;

    } else {
        printf("\nLogin gagal!\n");
        return 0;
    }
}