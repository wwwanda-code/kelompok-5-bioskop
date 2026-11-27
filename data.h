#ifndef DATA_H
#define DATA_H

#define FILE_USER    "users.txt"
#define FILE_RIWAYAT "riwayat.txt"

#define JUMLAH_FILM    6
#define JUMLAH_BIOSKOP 3
#define JUMLAH_TANGGAL 7
#define JUMLAH_JAM     3
#define JUMLAH_CAMILAN 4
#define JUMLAH_RASA    2
#define JUMLAH_MINUMAN 2
#define JUMLAH_UKURAN  3
#define JUMLAH_METODE  3
#define JUMLAH_KURSI   10

/* Data satu pemesanan.
   film, bioskop, tanggal, jam, camilan, rasa, ukuranPopcorn, minuman,
   ukuranMinuman, metode berisi nomor indeks array (mulai 0) */
typedef struct {
    char username[20];
    int film;
    int bioskop;
    int tanggal;
    int jam;
    int kursi;
    int camilan;
    int rasa;
    int ukuranPopcorn;
    int minuman;
    int ukuranMinuman;
    int metode;
    int total;
} Pesanan;

/* Daftar pilihan (array) */
extern char *namaFilm[JUMLAH_FILM];
extern int hargaWeekdays[JUMLAH_FILM];
extern int hargaWeekend[JUMLAH_FILM];
extern char *namaBioskop[JUMLAH_BIOSKOP];
extern char *namaTanggal[JUMLAH_TANGGAL];
extern int akhirPekan[JUMLAH_TANGGAL];
extern char *namaJam[JUMLAH_FILM][JUMLAH_JAM];   /* jam tayang tiap film berbeda */
extern char *namaCamilan[JUMLAH_CAMILAN];
extern char *namaRasa[JUMLAH_RASA];
extern char *namaMinuman[JUMLAH_MINUMAN];
extern char *namaUkuran[JUMLAH_UKURAN];
extern int hargaPopcorn[JUMLAH_RASA][JUMLAH_UKURAN];
extern int hargaMinuman[JUMLAH_MINUMAN][JUMLAH_UKURAN];
extern char *namaMetode[JUMLAH_METODE];

/* Data letak bioskop bertingkat: Provinsi -> Kota -> Nama Bioskop */
typedef struct {
    const char *provinsi;
    const char *kota;
    const char *namaBioskop;
} LokasiBioskop;

extern LokasiBioskop daftarLokasiBioskop[];
extern int jumlahLokasiBioskop;

/* Membaca pilihan 1 sampai n (diulang jika tidak valid).
   Mengembalikan indeks (mulai 0) */
int bacaPilihan(int n);

/* Menampilkan daftar pilihan lalu mengembalikan indeks yang dipilih (mulai 0).
   Jika harga tidak dipakai, isi dengan NULL */
int pilihMenu(char *judul, char *nama[], int harga[], int n);

/* Mengembalikan harga tiket sesuai film dan hari (weekdays / weekend) */
int hitungHargaTiket(Pesanan p);

/* Mengembalikan 1 jika paket camilan yang dipilih mengandung popcorn */
int adaPopcorn(Pesanan p);

/* Mengembalikan 1 jika paket camilan yang dipilih mengandung minuman */
int adaMinuman(Pesanan p);

/* Mengembalikan harga camilan (popcorn dan/atau minuman sesuai ukuran) */
int hitungHargaCamilan(Pesanan p);

/* Mencetak nama camilan, misalnya: Popcorn dan Minum (Karamel Besar + Teh Sedang) */
void cetakCamilan(Pesanan p);

#endif
