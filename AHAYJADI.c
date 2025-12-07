#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hargaAncolWeekday = 30000;
int hargaAncolWeekend = 35000;

int hargaPaketKeluarga = 120000;
int hargaPaketPasangan = 55000;

int hargaWahana1 = 0;
int hargaWahana2 = 250000;
int hargaWahana3 = 150000;
int hargaWahana4 = 200000;
int hargaWahana5 = 160000;

int getHargaWahana(int kode)
{
  switch (kode)
  {
  case 1:
    return hargaWahana1;
  case 2:
    return hargaWahana2;
  case 3:
    return hargaWahana3;
  case 4:
    return hargaWahana4;
  case 5:
    return hargaWahana5;
  default:
    return 0;
  }
}

const char *getNamaWahana(int kode)
{
  switch (kode)
  {
  case 1:
    return "Hanya Tiket Ancol";
  case 2:
    return "Dufan";
  case 3:
    return "Atlantis";
  case 4:
    return "Samudra";
  case 5:
    return "Seaworld";
  default:
    return "Wahana Tidak Dikenal";
  }
}

void tampilHarga()
{
  system("cls");
  printf("============== DAFTAR HARGA TIKET ANCOL ==============\n");
  printf("TIKET REGULER:\n");
  printf("  - Weekday : %d\n", hargaAncolWeekday);
  printf("  - Weekend : %d\n", hargaAncolWeekend);
  printf("\nPAKET HARGA:\n");
  printf("  - Paket Keluarga (5 org): %d\n", hargaPaketKeluarga);
  printf("  - Paket Pasangan (2 org): %d\n", hargaPaketPasangan);
  printf("=======================================================\n\n");
  printf("Tekan Enter untuk melanjutkan...");
  getchar();
}

void sortingWahana()
{
  int kode[5] = {1, 2, 3, 4, 5};
  int harga[5];

  for (int i = 0; i < 5; i++)
  {
    harga[i] = getHargaWahana(kode[i]);
  }

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4 - i; j++)
    {
      if (harga[j] > harga[j + 1])
      {
        int tmpHarga = harga[j];
        harga[j] = harga[j + 1];
        harga[j + 1] = tmpHarga;

        int tmpKode = kode[j];
        kode[j] = kode[j + 1];
        kode[j + 1] = tmpKode;
      }
    }
  }

  printf("\n=== DAFTAR WAHANA (SORT BY HARGA TERMURAH) ===\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%s - Rp %d\n", getNamaWahana(kode[i]), harga[i]);
  }
  printf("\n");
}

void searchingWahana()
{
  int cari;
  printf("\nMasukkan kode wahana yang ingin dicari (1-5): ");
  scanf("%d", &cari);

  if (cari < 1 || cari > 5)
  {
    printf("Kode tidak valid!\n");
    return;
  }

  printf("\n=== HASIL PENCARIAN ===\n");
  printf("Nama Wahana : %s\n", getNamaWahana(cari));
  printf("Harga       : Rp %d\n\n", getHargaWahana(cari));
}

int main()
{
  char nama[50];
  int menu;

  int hari, tipe, kendaraan;
  int jumlahTiket = 1;
  int daftarWahana[10];
  int jumlahWahana = 0;
  char tambahan;

  int adaPesanan = 0;

  tampilHarga();

menuUtama:
  printf("\n======== MENU UTAMA ========\n");
  printf("1. Pesan Tiket\n");
  printf("2. Lihat Pesanan\n");
  printf("3. Ubah Pesanan\n");
  printf("4. Hapus Pesanan\n");
  printf("5. Sorting Wahana\n");
  printf("6. Searching Wahana\n");
  printf("Pilih menu (1-6): ");
  scanf("%d", &menu);

  if (menu == 1)
  {

    do
    {
      // Bersihkan buffer
      while (getchar() != '\n')
        ;
      printf("Masukkan Nama Customer: ");
      fgets(nama, sizeof(nama), stdin);

    } while (strlen(nama) <= 1);

    do
    {
      printf("\nPilih hari:\n");
      printf("1. Weekday\n");
      printf("2. Weekend\n");
      printf("Pilihan (1-2): ");
      scanf("%d", &hari);

      if (hari < 1 || hari > 2)
      {
        printf("Input tidak valid! Masukkan angka 1 atau 2.\n");
      }
    } while (hari < 1 || hari > 2);

    do
    {
      printf("\nPilih tipe tiket:\n");
      printf("1. Personal\n");
      printf("2. Couple\n");
      printf("3. Family\n");
      printf("Pilihan (1-3): ");
      scanf("%d", &tipe);

      if (tipe < 1 || tipe > 3)
      {
        printf("Input tidak valid! Masukkan angka 1-3.\n");
      }
    } while (tipe < 1 || tipe > 3);

    if (tipe == 1)
    {
      printf("\nInput Jumlah Tiket Personal: ");
      scanf("%d", &jumlahTiket);
    }
    else if (tipe == 2)
    {
      jumlahTiket = 2;
    }
    else if (tipe == 3)
    {
      jumlahTiket = 5;
    }

    jumlahWahana = 0;
    do
    {
      printf("\nPilih wahana:\n");
      printf("1. Ancol Only\n");
      printf("2. Dufan\n");
      printf("3. Atlantis\n");
      printf("4. Samudra\n");
      printf("5. Seaworld\n");
      printf("Pilihan (1-5): ");
      scanf("%d", &daftarWahana[jumlahWahana]);

      if (daftarWahana[jumlahWahana] < 1 || daftarWahana[jumlahWahana] > 5)
      {
        printf("Input tidak valid! Pilih angka 1-5.\n");
        continue;
      }

      jumlahWahana++;

      getchar();
      printf("Tambah wahana lagi? (y/n): ");
      scanf("%c", &tambahan);
      getchar();

    } while (tambahan == 'y');

    do
    {
      printf("\nPilih kendaraan:\n");
      printf("1. Motor\n");
      printf("2. Mobil\n");
      printf("3. Tidak Membawa Kendaraan\n");
      printf("4. Bus\n");
      printf("Pilihan: ");
      scanf("%d", &kendaraan);

      if (kendaraan < 1 || kendaraan > 4)
      {
        printf("Input tidak valid! Masukkan angka 1-4.\n");
      }
    } while (kendaraan < 1 || kendaraan > 4);

    adaPesanan = 1;

    printf("\nPesanan Berhasil Dibuat!\n");
    printf("\nTerima Kasih Telah Memesan Tiket, Selamat Besrsenang-senang di Ancol\n");

    goto menuUtama;
  }

  else if (menu == 2)
  {
    if (!adaPesanan)
    {
      printf("\nBelum ada pesanan!\n");
      goto menuUtama;
    }

    printf("\n=========== STRUK PEMBELIAN ===========\n");
    printf("Nama Customer : %s", nama);
    printf("Hari          : %s\n", (hari == 1) ? "Weekday" : "Weekend");

    printf("Tipe Tiket    : ");
    switch (tipe)
    {
    case 1:
      printf("Personal\n");
      break;
    case 2:
      printf("Couple\n");
      break;
    case 3:
      printf("Family\n");
      break;
    }
    printf("Jumlah Tiket  : %d\n", jumlahTiket);

    printf("Wahana        : ");
    int hargaWahanaTotal = 0;
    for (int i = 0; i < jumlahWahana; i++)
    {
      printf("%s (Rp %d)\n", getNamaWahana(daftarWahana[i]), getHargaWahana(daftarWahana[i]));
      hargaWahanaTotal += getHargaWahana(daftarWahana[i]);
    }

    if (tipe == 2)
    {
      hargaWahanaTotal *= 2; // Couple
    }
    else if (tipe == 3)
    {
      hargaWahanaTotal *= 5; // Family
    }
    else if (tipe == 1)
    {
      hargaWahanaTotal *= jumlahTiket;
    }

    int biayaKendaraan = 0;
    if (kendaraan == 1)
      biayaKendaraan = 20000;
    else if (kendaraan == 2)
      biayaKendaraan = 35000;
    else if (kendaraan == 4)
      biayaKendaraan = 70000;

    printf("Kendaraan     : ");
    switch (kendaraan)
    {
    case 1:
      printf("Motor (Rp 20000)\n");
      break;
    case 2:
      printf("Mobil (Rp 35000)\n");
      break;
    case 3:
      printf("Tanpa Kendaraan (Rp 0)\n");
      break;
    case 4:
      printf("Bus (Rp 70000)\n");
      break;
    }

    int hargaHari = (hari == 1) ? hargaAncolWeekday : hargaAncolWeekend;
    int hargaTiket = hargaHari * jumlahTiket;
    int total = hargaTiket + hargaWahanaTotal + biayaKendaraan;

    printf("\n----------------------------------------\n");
    printf("Harga Tiket   : Rp %d\n", hargaTiket);
    printf("Harga Wahana  : Rp %d\n", hargaWahanaTotal);
    printf("Biaya Parkir  : Rp %d\n", biayaKendaraan);
    printf("----------------------------------------\n");
    printf("TOTAL BAYAR   : Rp %d\n", total);
    printf("\nTerima Kasih Telah Memesan Tiket, Selamat Bersnang-senang di Ancol!\n");
    printf("----------------------------------------\n");

    goto menuUtama;
  }

  else if (menu == 3)
  {
    if (!adaPesanan)
    {
      printf("\nBelum ada pesanan yang bisa diubah!\n");
      goto menuUtama;
    }

  updateMenu:
    printf("\n============== UBAH PESANAN ==============\n");
    printf("1. Ubah Hari\n");
    printf("2. Ubah Tipe Tiket\n");
    printf("3. Ubah Wahana\n");
    printf("4. Ubah Kendaraan\n");
    printf("5. Ubah Nama Customer\n");
    printf("6. Kembali ke Menu Utama\n");
    printf("Pilihan: ");

    int pilihUpdate;
    scanf("%d", &pilihUpdate);

    if (pilihUpdate == 1)
    {
      printf("\nPilih hari baru:\n");
      printf("1. Weekday\n");
      printf("2. Weekend\n");
      printf("Pilihan: ");
      scanf("%d", &hari);
      printf("Hari berhasil diupdate!\n");
      goto updateMenu;
    }
    else if (pilihUpdate == 2)
    {
      printf("\nPilih tipe tiket baru:\n");
      printf("1. Personal\n");
      printf("2. Couple\n");
      printf("3. Family\n");
      printf("Pilihan: ");
      scanf("%d", &tipe);

      if (tipe == 1)
      {
        printf("Masukkan jumlah tiket personal: ");
        scanf("%d", &jumlahTiket);
      }
      else if (tipe == 2)
        jumlahTiket = 2;
      else if (tipe == 3)
        jumlahTiket = 5;

      printf("Tipe tiket berhasil diupdate!\n");
      goto updateMenu;
    }
    else if (pilihUpdate == 3)
    {
      jumlahWahana = 0;
      char ulang;
      do
      {
        printf("\nPilih wahana baru:\n");
        printf("1. Ancol Only\n");
        printf("2. Dufan\n");
        printf("3. Atlantis\n");
        printf("4. Samudra\n");
        printf("5. Seaworld\n");
        printf("Pilihan: ");
        scanf("%d", &daftarWahana[jumlahWahana]);
        jumlahWahana++;

        getchar();
        printf("Tambah wahana lagi? (y/n): ");
        scanf("%c", &ulang);
        getchar();

      } while (ulang == 'y');

      printf("Wahana berhasil diupdate!\n");
      goto updateMenu;
    }
    else if (pilihUpdate == 4)
    {
      printf("\nPilih kendaraan baru:\n");
      printf("1. Motor\n");
      printf("2. Mobil\n");
      printf("3. Tanpa kendaraan\n");
      printf("4. Bus\n");
      printf("Pilihan: ");
      scanf("%d", &kendaraan);

      printf("Kendaraan berhasil diupdate!\n");
      goto updateMenu;
    }
    else if (pilihUpdate == 5)
    {
      getchar();
      printf("\nMasukkan nama customer baru: ");
      fgets(nama, sizeof(nama), stdin);

      printf("Nama berhasil diupdate!\n");
      goto updateMenu;
    }
    else if (pilihUpdate == 6)
    {
      goto menuUtama;
    }
    else
    {
      printf("Pilihan tidak valid!\n");
      goto updateMenu;
    }
  }

  else if (menu == 4)
  {
    if (!adaPesanan)
    {
      printf("\nTidak ada pesanan yang dapat dihapus!\n");
    }
    else
    {
      adaPesanan = 0;
      jumlahWahana = 0;
      jumlahTiket = 0;

      printf("\nPesanan berhasil dihapus!\n");
      printf("Terimakasih, silakan lakukan pemesanan kembali.\n");
    }

    goto menuUtama;
  }

  else if (menu == 5)
  {
    sortingWahana();
    goto menuUtama;
  }

  else if (menu == 6)
  {
    searchingWahana();
    goto menuUtama;
  }

  return 0;
}