#include <stdio.h>
#include "data.h"

char *namaFilm[JUMLAH_FILM] = {
    "Agak Laen",
    "Dune: Part Two",
    "Exhuma",
    "Kung Fu Panda 4",
    "Inside Out 2",
    "Deadpool & Wolverine"
};

int hargaWeekdays[JUMLAH_FILM] = {30000, 35000, 40000, 45000, 32000, 48000};
int hargaWeekend[JUMLAH_FILM]  = {45000, 50000, 55000, 60000, 47000, 65000};

char *namaBioskop[JUMLAH_BIOSKOP] = {"Cinema Pusat", "Cinema Timur", "Cinema Barat"};

/* Data letak bioskop bertingkat: Provinsi -> Kota -> Nama Bioskop */
typedef struct {
    const char *provinsi;
    const char *kota;
    const char *namaBioskop;
} LokasiBioskop;

LokasiBioskop daftarLokasiBioskop[] = {
    {"Riau", "Pekanbaru", "Cinema XXI SKA"},
    {"Riau", "Pekanbaru", "CGV Transmart"},
    {"Riau", "Dumai", "Cinema XXI Citimall"},
    {"Sumatera Barat", "Padang", "Cinema XXI Plaza Andalas"},
    {"Sumatera Barat", "Bukittinggi", "CGV Raya Bukittinggi"},
    {"DKI Jakarta", "Jakarta Selatan", "Cinema XXI Pondok Indah"},
    {"DKI Jakarta", "Jakarta Pusat", "CGV Grand Indonesia"},
    {"Jawa Barat", "Bandung", "Cinema XXI Ciwalk"}
};

int jumlahLokasiBioskop = sizeof(daftarLokasiBioskop) / sizeof(daftarLokasiBioskop[0]);

/* akhirPekan: 0 = weekdays, 1 = weekend (Sabtu dan Minggu) */
char *namaTanggal[JUMLAH_TANGGAL] = {"Senin", "Selasa", "Rabu", "Kamis",
                                     "Jumat", "Sabtu", "Minggu"};
int akhirPekan[JUMLAH_TANGGAL] = {0, 0, 0, 0, 0, 1, 1};

/* Jam tayang unik untuk setiap film (18 jam berbeda, tidak ada yang nabrak) */
char *namaJam[JUMLAH_FILM][JUMLAH_JAM] = {
    {"12:30", "15:15", "19:00"}, // Agak Laen
    {"13:00", "16:30", "20:00"}, // Dune: Part Two
    {"14:00", "17:15", "21:15"}, // Exhuma
    {"11:30", "14:15", "16:45"}, // Kung Fu Panda 4
    {"11:00", "13:45", "18:15"}, // Inside Out 2
    {"15:45", "19:30", "21:45"}  // Deadpool & Wolverine
};

char *namaCamilan[JUMLAH_CAMILAN] = {"Tanpa camilan", "Minum", "Popcorn", "Popcorn dan Minum"};

/* Ukuran dipakai bersama oleh popcorn dan minuman */
char *namaUkuran[JUMLAH_UKURAN] = {"Kecil", "Sedang", "Besar"};

/* hargaPopcorn[rasa][ukuran] */
char *namaRasa[JUMLAH_RASA] = {"Asin", "Karamel"};
int hargaPopcorn[JUMLAH_RASA][JUMLAH_UKURAN] = {
    {25000, 30000, 35000},  /* Asin    */
    {27000, 32000, 37000}   /* Karamel */
};

/* hargaMinuman[jenis][ukuran] */
char *namaMinuman[JUMLAH_MINUMAN] = {"Teh", "Soda"};
int hargaMinuman[JUMLAH_MINUMAN][JUMLAH_UKURAN] = {
    {12000, 15000, 20000},   /* Teh  */
    {15000, 18000, 23000}   /* Soda */
};

char *namaMetode[JUMLAH_METODE] = {"Tunai", "Transfer Bank", "E-Wallet"};

int bacaPilihan(int n) {
    int pilihan;

    printf("Pilih (1-%d): ", n);
    scanf("%d", &pilihan);
    while (pilihan < 1 || pilihan > n) {
        printf("Pilihan tidak valid, ulangi: ");
        scanf("%d", &pilihan);
    }
    return pilihan - 1;
}

int pilihMenu(char *judul, char *nama[], int harga[], int n) {
    printf("\n--- %s ---\n", judul);
    for (int i = 0; i < n; i++) {
        printf("%d. %s", i + 1, nama[i]);
        if (harga != NULL) {
            printf(" - Rp%d", harga[i]);
        }
        printf("\n");
    }
    return bacaPilihan(n);
}

int hitungHargaTiket(Pesanan p) {
    if (akhirPekan[p.tanggal]) {
        return hargaWeekend[p.film];
    }
    return hargaWeekdays[p.film];
}

int adaPopcorn(Pesanan p) {
    /* 2 = Popcorn, 3 = Popcorn dan Minum */
    return p.camilan == 2 || p.camilan == 3;
}

int adaMinuman(Pesanan p) {
    /* 1 = Minum, 3 = Popcorn dan Minum */
    return p.camilan == 1 || p.camilan == 3;
}

int hitungHargaCamilan(Pesanan p) {
    int harga = 0;

    if (adaPopcorn(p)) {
        harga += hargaPopcorn[p.rasa][p.ukuranPopcorn];
    }
    if (adaMinuman(p)) {
        harga += hargaMinuman[p.minuman][p.ukuranMinuman];
    }
    return harga;
}

void cetakCamilan(Pesanan p) {
    printf("%s", namaCamilan[p.camilan]);

    if (adaPopcorn(p) || adaMinuman(p)) {
        printf(" (");
        if (adaPopcorn(p)) {
            printf("%s %s", namaRasa[p.rasa], namaUkuran[p.ukuranPopcorn]);
        }
        if (adaPopcorn(p) && adaMinuman(p)) {
            printf(" + ");
        }
        if (adaMinuman(p)) {
            printf("%s %s", namaMinuman[p.minuman], namaUkuran[p.ukuranMinuman]);
        }
        printf(")");
    }
}
