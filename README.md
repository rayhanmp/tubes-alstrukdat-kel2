# BNMO 
## IF2111 Algoritma dan Struktur Data 
BNMO adalah suatu program berbasis CLI (command-line interface) yang ditulis dengan bahasa C. Seorang pengguna dapat memainkan gim, menambahkan gim, menghapus gim, dan mengurutkan gim yang akan dimainkan. Konfigurasi akan disimpan pada suatu file .txt yang dibaca menggunakan tipe bentukan mesin kata dan mesin karakter. 

## Struktur Folder
Berikut ini adalah struktur folder dari project ini:
* Folder `data` berisi file konfigurasi default serta konfigurasi dari user (save file)
* Folder `docs` berisi laporan, notulensi, dan spesifikasi Tugas Besar
* Folder `src` berisi source program. Pada folder ini terdiri atas:
  * file program utama `main.c`
  * file `header boolean`
  * file shell `compile.sh`
  * folder `ADT` berisi file c, header, dan driver ADT
  * folder `Commands` berisi perintah utama yang dapat dijalankan di _main_
  * folder `RNGGAME` berisi file c dan header untuk gim Diner Dash
  * folder `prs` berisi file c dan header untuk gim Paper Rock Scissor
  * folder `hangman` berisi file c dan header untuk gim Hangman
  * folder `Tower_of_Hanoi` berisi file c dan header untuk gim Tower of Hanoi
  * folder `snake on meteor` berisi file c dan header untuk gim Snake on Meteor
  * folder `gameTambahan` berisi file c dan header untuk gim tambahan

## Prosedur Penggunaan
### Instal C
Program dibuat dengan menggunakan bahasa C sehingga pengguna wajib memiliki _compiler_ C, disarankan menggunakan GCC versi terbaru. Apabila GCC telah terinstall, pengguna dapat melakukan _clone_ pada _repository_ ini atau langsung mengunduh _repository_ dalam file zip.

### Instal GitBash
Apabila Anda menggunakan sistem operasi Linux, abaikan langkah ini karena Linux sudah memiliki Bash. Abaikan pula jika Anda sudah memiliki Git. Anda dapat memasang GitBash dengan  meng-_install_ Git dari situs git-scm.com. 

### Compile Program
Buka bash lalu tuliskan perintah berikut:
```
./src/compile.sh
```

### Eksekusi Program
Apabila _compile_ telah sukses dilakukan, pengguna dipersilakan untuk mengetik perintah berikut pada direktori yang sama dengan direktori _compile_:
```
./src/main.exe
```

## Fitur
Program ini memiliki sejumlah fitur utama di _main_ yang dapat diakses oleh pengguna, di antaranya adalah:
<table>
<tr><td>No.</td><td>Command</td><td>Fungsi</td></tr>
<tr><td>1.</td><td>START</td><td>Memuat konfigurasi default.</td></tr>
<tr><td>2.</td><td>LOAD</td><td>Memuat konfigurasi dari _save file_ tertentu sesuai masukan user.
</td></tr>
<tr><td>3.</td><td>SAVE</td><td>Menyimpan konfigurasi serta kondisi array ke _file_ tertentu</td></tr>
<tr><td>4.</td><td>CREATEGAME</td><td>Menambahkan gim baru ke daftar gim</td></tr>
<tr><td>5.</td><td>LISTGAME</td><td>Menampilkan daftar gim yang tersedia</td></tr>
<tr><td>6.</td><td>DELETEGAME</td><td>Menghapus sebuah gim dari daftar gim</td></tr>
<tr><td>7.</td><td>QUEUEGAME</td><td>Menambahkan suatu gim ke daftar antrean</td></tr>
<tr><td>8.</td><td>PLAYGAME</td><td>Memainkan gim dengan urutan pertama di antrean</td></tr>
<tr><td>9.</td><td>SKIPGAME</td><td>Melewatkan sejumlah permainan tertentu berdasarkan masukan</td></tr>
<tr><td>11.</td><td>SCOREBOARD</td><td>Menampilkan nama pemain dan score</td></tr>
<tr><td>12.</td><td>RESET SCOREBOARD</td><td>Mengosongkan data pemain dan score pada scoreboard</td></tr>
<tr><td>13.</td><td>HISTORY</td><td>Menampilkan riwayat permainan yang pernah dimainkan</td></tr>
<tr><td>14.</td><td>RESET HISTORY</td><td>Mengosongkan riwayat game yang dimainkan pemain</td></tr>
<tr><td>15.</td><td>QUIT</td><td>Keluar dari program</td></tr>
<tr><td>16.</td><td>HELP</td><td>Program akan menampilkan daftar perintah yang bisa diakses.</td></tr>

</table>

## Gim
Program ini memiliki sejumlah gim yang dapat dimainkan oleh pengguna, di antaranya adalah:
<table>
<tr><td>No.</td><td>Nama</td>
<tr><td>1.</td><td>RNG</td>
<tr><td>2.</td><td>DINER DASH</td>
<tr><td>3.</td><td>HANGMAN</td>
<tr><td>4.</td><td>TOWER OF HANOI</td>
<tr><td>5.</td><td>SNAKE ON METEOR</td>
<tr><td>6.</td><td>PAPER ROCK SCISSOR</td>
</td></tr>

</table>

## Kontributor
Program ini dibuat untuk memenuhi Tugas Besar 2 Mata Kuliah Algoritma dan Struktur Data (IF2111) untuk Program Studi Sistem dan Teknologi Informasi Insitut Teknologi Bandung. Berikut kontributor dari Kelompok 2 Kelas Genap untuk program ini:
* Jazmy Izzati Alamsyah (18221124)
* Karunia Mega Lestari (18221126)
* Marcheline Fanni Hidayat Putri (18221090)
* Raditya Azka Prabaswara (18221152)
* Rayhan Maheswara Pramanda (18221130)
