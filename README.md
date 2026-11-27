# kelompok-5 - SISTEM PEMESANAN TIKET FILM BIOSKOP (CONSOL)

**NAMA KELOMPOK**
1. Wanda Desfa Hamidah (26071105052)
2. Dzafif Al-Ikhsan (26071103579
3. Mabkhud Shadadz Ibra (26071104235)
4. Askia Yuna Ananda (26071101350)

## Latar Belakang & Tujuan Aplikasi

Aplikasi ini adalah sistem berbasis konsol (Command Line Interface) yang dirancang untuk mensimulasikan proses pemesanan tiket bioskop secara end-to-end secara digital, interaktif, dan terstruktur. Tujuan utamanya adalah memudahkan pengguna dalam memilih film, menentukan jadwal, memesan kursi, hingga melakukan pembayaran dan melihat riwayat transaksi melalui antarmuka teks yang efisien.

## Fitur Utama Aplikasi

Aplikasi ini dilengkapi dengan 11 fitur utama yang saling terintegrasi:

1. **Login**: Sistem autentikasi awal untuk memastikan keamanan akses pengguna ke dalam sistem pemesanan. Pengguna baru dapat membuat akun lewat menu Daftar akun.
2. **Menu Utama**: Pusat navigasi utama yang mengarahkan pengguna ke berbagai pilihan layanan aplikasi setelah berhasil masuk.
3. **Pilih Film**: Menampilkan daftar film yang sedang tayang beserta harga tiketnya untuk dipilih oleh pengguna.
4. **Pilih Lokasi**: Memungkinkan pengguna untuk menentukan cabang bioskop atau lokasi penayangan film yang diinginkan.
5. **Pilih Jadwal**: Menyediakan pilihan tanggal dan jam penayangan film yang tersedia di lokasi pilihan.
6. **Pilih Kursi**: Fitur interaktif untuk memilih nomor kursi bioskop yang masih kosong di dalam studio. Kursi yang sudah dipesan ditandai `X`.
7. **Paket Camilan (F&B)**: Opsi tambahan bagi pengguna untuk memesan makanan dan minuman ringan pendamping menonton.
8. **Perhitungan Harga**: Kalkulator otomatis yang menjumlahkan harga tiket dan paket camilan secara transparan.
9. **Pembayaran**: Simulasi proses transaksi pembayaran dengan berbagai metode yang tersedia (Tunai, Transfer Bank, E-Wallet).
10. **Bukti Pemesanan**: Menampilkan ringkasan pesanan yang berisi detail transaksi setelah pembayaran berhasil.
11. **Riwayat Transaksi**: Fitur untuk melihat kembali daftar pesanan atau transaksi yang pernah dilakukan sebelumnya oleh akun pengguna.

## Alur Penggunaan (User Flow)

1. **Autentikasi**: Pengguna membuka aplikasi dan melakukan Login.
2. **Eksplorasi & Pemilihan**: Masuk ke Menu Utama, lalu memilih Film, Lokasi, dan Jadwal penayangan.
3. **Kustomisasi Pesanan**: Pengguna memilih Kursi bioskop dan dapat menambahkan Paket Camilan opsional.
4. **Checkout & Selesai**: Sistem melakukan Perhitungan Harga, pengguna melakukan Pembayaran, dan aplikasi menerbitkan Bukti Pemesanan.
5. **Manajemen Sesi**: Pengguna dapat mengecek Riwayat Transaksi.

```
Login -> Pemesanan -> Pembayaran -> Konfirmasi -> Riwayat
```

## Struktur File

| File | Fungsi |
|---|---|
| `main.c` | Program utama, menu awal dan menu utama |
| `data.h`, `data.c` | Struct `Pesanan`, daftar pilihan (film, bioskop, tanggal, jam, camilan, metode), dan fungsi `pilihMenu` |
| `akun.h`, `akun.c` | Daftar akun dan login |
| `pemesanan.h`, `pemesanan.c` | Proses memilih film sampai camilan, serta rincian pesanan |
| `pembayaran.h`, `pembayaran.c` | Memilih metode bayar dan proses pembayaran |
| `konfirmasi.h`, `konfirmasi.c` | Menampilkan bukti pemesanan |
| `riwayat.h`, `riwayat.c` | Menyimpan dan menampilkan riwayat, serta mengecek kursi yang sudah terisi |

## Konsep yang Digunakan

- **Modular programming**: program dibagi menjadi beberapa modul (`.c` dan `.h`).
- **Array**: menyimpan daftar film, bioskop, tanggal, jam, camilan, dan metode pembayaran.
- **Struct**: `Akun` dan `Pesanan`.
- **Pointer**: `Pesanan *p` untuk mengisi data pesanan, dan `char *username` untuk membawa nama pengguna antar fungsi.
- **File handling**: data akun disimpan di `users.txt`, data transaksi di `riwayat.txt`.

## Cara Menjalankan

Semua file harus berada dalam satu folder. Buka terminal di folder tersebut, lalu kompilasi:

```
gcc main.c data.c akun.c pemesanan.c pembayaran.c konfirmasi.c riwayat.c -o main
```

## Data Pilihan

| Film | Harga Tiket Weekdays | Harga Tiket Weekend | Jam Tayang |
| :--- | :--- | :--- | :--- |
| Agak Laen | Rp30.000 | Rp45.000 | 12:30, 15:15, 19:00 |
| Dune: Part Two | Rp35.000 | Rp50.000 | 13:00, 16:30, 20:00 |
| Exhuma | Rp40.000 | Rp55.000 | 14:00, 17:15, 21:15 |
| Kung Fu Panda 4 | Rp45.000 | Rp60.000 | 11:30, 14:15, 16:45 |
| Inside Out 2 | Rp32.000 | Rp47.000 | 11:00, 13:45, 18:15 |
| Deadpool & Wolverine | Rp48.000 | Rp65.000 | 15:45, 19:30, 21:45 |

| Camilan | Harga |
|---|---|
| Tanpa camilan | Rp0 |
| Minum | Rp12.000 |
| Popcorn | Rp25.000 |
| Popcorn dan Minum | Rp35.000 |

Lokasi bioskop: Cinema Pusat, Cinema Timur, Cinema Barat.
Jam tayang: 13:00, 16:00, 19:00. Metode bayar: Tunai, Transfer Bank, E-Wallet.

Data film, harga, dan lainnya bisa diubah di `data.c`.

## Format Penyimpanan

`users.txt` (satu akun per baris):

```
username password
```

`riwayat.txt` (satu transaksi per baris, berisi nomor pilihan):

```
username film bioskop tanggal jam kursi camilan metode total
```
