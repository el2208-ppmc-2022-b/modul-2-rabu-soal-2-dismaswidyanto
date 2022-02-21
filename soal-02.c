/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : -
*Hari dan Tanggal : Rabu, 23 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

#define len 35

int main() {
	/**
	 * Deklarasi variabel-variabel
	 */
	FILE *fp;
	char namafile[len];
	char character;
	int tempResult = 0;
	int index = 0;
	int jumlahPBerdekatan = 0;
	int resultLookUp[6] = {0, 1, 2, 4, 8, 16};

	/**
	 * Input nama file
	 */
	printf("Input pesan: ");
	scanf("%s", &namafile);

	/**
	 * Buka file yang diinput
	 */
	fp = fopen(namafile, "r");

	/**
	 * Algoritma utama pemberian nilai
	 */
	while(index<5) {
		character = (char)fgetc(fp);
		if (character == 'p' || character == 'P'){
			// Kasus karakter ditemukan, jumlah berdekatan + 1
			jumlahPBerdekatan++;
			if (jumlahPBerdekatan > 5) {
				// Kasus khusus, lebih dari 5 berdekatan sehingga langsung keluar dari program
				printf("Nilai ketidaksabaran: 1000.00");
				return 0;
			}
		}
		else {
			// Kasus karakter tidak ditemukan, nilai langsung ditambah ke hasil dan jumlah berdekatan di reset
			tempResult += resultLookUp[jumlahPBerdekatan];
			if (character == '\n') {
				// End of line ditemukan, indeks ditambahkan
				index++;
			}
			jumlahPBerdekatan = 0;
		}
	}

	// Penghitungan Hasil
	float result = (float)(tempResult)/(float)5;

	// Output hasil
	printf("Nilai ketidaksabaran: %.2f", result);

	return 0;
}
