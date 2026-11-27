#include <stdio.h>
#include "login.h"
#include "menu.h"

int main() {
    int status, pilihan;

    status = login();

    if (status == 1) {
        do {
            menuUtama();

            printf("Pilih menu: ");
            scanf("%d", &pilihan);

            switch (pilihan) {
                case 1:
                    printf("Menu pemesanan tiket\n");
                    break;

                case 2:
                    printf("Menu riwayat transaksi\n");
                    break;

                case 3:
                    logout();
                    break;

                default:
                    printf("Pilihan tidak tersedia!\n");
            }

        } while (pilihan != 3);
    }

    return 0;
}