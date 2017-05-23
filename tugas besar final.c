/* author : Riyan Nursyalim
            Anjar Pratiwi
            Rahmi Amalia
    Tubes pemrograman terstruktur 1 */

#include <stdio.h> //Mengakses file library stdio.h untuk fungsi input/output
#include <stdlib.h> //Mengakses file library stdlib.h untuk fungsi system()
#include <string.h> //Mengakses file library string.h untuk fungsi gets(), strcmp
#include <time.h> //mengakses waktu


typedef struct
{
    int kode,harga;
    char judul[40],kategory[20],penerbit[30];
}daftar;

void menu();
void tulisdata(daftar buku[]);
void bacadata(daftar buku[],int *n);
void sortingdata(daftar buku[],int n);
void tampildaftar();
void tambahdata();
void ubahdata();
void hapusdata();
void searchkode();
void resetdata();
void pembayaran();

int main() //Fungsi yang harus ada pada setiap program c
{
char kata1[20], kata2[20], pass1[20], pass2[20]; //Deklarasi array 1 dimensi
int cek1, cek2, a=0; //Deklarasi variabel, cek1 dan cek2 merupakan variabel yang bertipe data

ulang: //Inisialisasi

strcpy(kata1,"pt1"); //Menyalin string
printf("|||||SELAMAT DATANG DI PROGRAM PENJUALAN BUKU|||||. \n\n");
printf(" DEMI KEAMANAN SILAHKAN LOG IN dengan IDENTITAS ANDA \n"); //Login yang ke 1 dilooping +1
printf(" INGAT!!KESEMPATAN LOG IN HANYA 3x \n\n");
printf("LOG IN KE %d\n",a+1);
printf(" \t MASUKAN PASSWORD ANDA       : ",kata1); //Menampilkan Masukkan Password :
gets(pass1); //Input string
strcpy(kata2,"pt1"); //Menyalin string
printf("\t MASUKAN ULANG PASSWORD ANDA : "); //Menampilkan Konfirmasi Password :
gets(pass2); //Input string
printf("\n");

cek1=strcmp(kata1,pass1); //Pembandingan dua string antara kata1 dan pass1 disimpan pada variabel cek1
cek2=strcmp(kata2,pass2); //Pembandingan dua string antara kata2 dan pass2 disimpan pada variabel cek2


if (cek1 == 0 && cek2 == 0)//Fungsi control flow, jika cek1 samadengan 0 dan cek2 samadengan 0
{
printf("!!IDENTITAS ANDA BENAR!! \n"); //Pesan ini akan muncul
system("pause"); //Salah satu fungsi dari library stdlib.h agar program tidak langsung tutup secara otomatis
menu();
}
else { //Jika tidak

a=a+1; //Perhitungan password akan diulang
if(a<3) //Fungsi control flow, ulang password sebanyak kecil dari 3
{
printf("\n(!!WARNING!!)PASSWORD ANDA SALAH \n"); //Menampilkan pesan jika password salah
printf("IDENTITAS ANDA TIDAK DIKENAL \n\n"); //Menampilkan pesan jika password salah
goto ulang; //Ulang
}

else //Jika ulang password sudah kecil dari 3
{
printf("\n (!!STOP!!) AKSES DITOLAK\n"); //Jika looping bernilai kecil dari 3, maka informasi ini akan ditampilkan
system("cls");
return 0;
}
}
}


void menu()
{
    system("cls");
    printf("             ||==========================================||\n");
    printf("             ||          PROGRAM TOKO BUKU               ||\n");
    printf("             ||==========================================||\n\n\n");

    char m;
    time_t lt;
    lt = time(NULL);

    printf("\t\tWAKTU HARI INI : ");
    printf(ctime(&lt));
    printf("\n");
    printf("\t\tPILIHAN MENU :\n");
    printf("\t\t1.TAMPILKAN DAFTAR BUKU YANG TERSEDIA\n");
    printf("\t\t2.TAMBAH BUKU BARU\n");
    printf("\t\t3.UBAH HARGA BUKU \n");
    printf("\t\t4.CARI BUKU BERDASARKAN KODE BUKU\n");
    printf("\t\t5.RESET DAFTAR BUKU\n");
    printf("\t\t6.PEMBAYARAN BUKU\n\n");
    printf("\t\t7.Searching judul\n\n");


    printf("\t\tMASUKAN PILIHAN MENU : ");
    m=getche(); printf("\n\n");

    switch(m)
    {
        case '1':tampildaftar();menu();break;
        case '2':tambahdata();menu();break;
        case '3':ubahdata();menu();break;
        case '4':searchkode();menu();break;
        case '5':resetdata();menu();break;
        case '6':pembayaran();menu();break;
        case '7':searchjudul();menu();break;

        default:printf("\t\t!!PILIHAN YANG ANDA MASUKAN SALAH!!\n\n"); system("pause");main();break;

    }
}

void tulisdata(daftar buku[])
{
    FILE *tulis=fopen("databuku.txt","w");
    int i=0;
    while(buku[i].kode!=NULL){
        fprintf(tulis,"%d\t\n",buku[i].kode);
        fprintf(tulis,"%s\t\n",buku[i].judul);
        fprintf(tulis,"%d\t\n",buku[i].harga);
        fprintf(tulis,"%s\t\n",buku[i].kategory);
        fprintf(tulis,"%s\t\n\n",buku[i].penerbit);
        i++;
    }
    fclose(tulis);
}

void bacadata(daftar buku[],int *n)
{
    int i=0;
    FILE
     *baca=fopen("databuku.txt","r");

    fscanf(baca,"%d",&buku[i].kode);
    if(buku[i].kode!=NULL)
        while(!feof(baca)){
            fscanf(baca,"%d\t",&buku[i].kode);
            fscanf(baca,"%s\t",&buku[i].judul);
            fscanf(baca,"%d\t",&buku[i].harga);
            fscanf(baca,"%s\t",&buku[i].kategory);
            fscanf(baca,"%s\t",&buku[i].penerbit);
            i++;
        }
    *n=i;
    fclose(baca);
}

void sortingdata(daftar buku[],int n)
{
    daftar tmp;
    int i,j;
    for(i=1;i<n;i++){
        tmp=buku[i];
        j=i;
        while((j>0)&&(tmp.kode<buku[j-1].kode)){
            buku[j]=buku[j-1];
            j--;
        }
        buku[j]=tmp;
    }
}

void resetdata()
{
    system("cls");
    FILE *hapus=fopen("databuku.txt","w");
    fclose(hapus);

    printf("\n\t!!RESET DAFTAR BUKU BERHASIL!!\n\n");
    system("pause");
}

void tambahdata()
{
    system("cls");
    daftar buku[9999];

    int i;
    bacadata(buku,&i);

    char m;
    printf("             ||==========================================||\n");
    printf("             ||          TAMBAH DAFTAR BUKU              ||\n");
    printf("             ||==========================================||\n\n\n");

        printf("!!NOTE!!\n");
        printf("KODE BUKU 6 DIGIT ANGKA\n");
        printf("SPASI DIGANTI ( _ )\n\n");
    do{
        printf("1.masukan kode buku     : ");
        scanf("%d",&buku[i].kode);
        printf("2.masukan judul buku    : ");
        scanf("%s",&buku[i].judul);
        printf("3.masukan harga buku    : Rp");
        scanf("%d",&buku[i].harga);
        printf("4.masukan kategory buku : ");
        scanf("%s",&buku[i].kategory);
        printf("5.masukan penerbit buku : ");
        scanf("%s",&buku[i].penerbit);
        printf("ingin masukan data buku lagi (Y/N)? ");
        m=getche(); printf("\n\n");
        i++;
    }while(m=='y');

    sortingdata(buku,i);

    tulisdata(buku);

    printf("SELESAI.\n\n");
    system("pause");
}

void ubahdata()
{
    system("cls");
    daftar buku[9999];

    int kode;
    printf("             ||==========================================||\n");
    printf("             ||            UPDATE DATA BUKU              ||\n");
    printf("             ||==========================================||\n\n\n");

    printf("masukan kode buku yang ingin di ubah: ");
    scanf("%d",&kode);

    int i,n,c=0;
    bacadata(buku,&i);
    n=i;
    i=0;

    while(buku[i].kode!=NULL){
        if(buku[i].kode==kode){
            printf("\n judul buku yang ingin diubah :%s\n\n",buku[i].judul);
            printf("MASUKAN KODE BUKU BARU     : ");
            scanf("%d",&buku[i].kode);
            printf("MASUKAN JUDUL BUKU BARU    : ");
            scanf("%s",&buku[i].judul);
            printf("MASUKAN HARGA BUKU BARU    : Rp");
            scanf("%d",&buku[i].harga);
            printf("MASUKAN KATEGORY BUKU BARU : ");
            scanf("%s",buku[i].kategory);
            printf("MASUKAN PENERBIT BUKU BARU : ");
            scanf("%s",&buku[i].penerbit);
            c=1;
            break;
        }
        i++;
    }
    if(c==0)
        printf("\n!!KODE BUKU TIDAK TERDAFTAR!!\n\n");
    else{
        sortingdata(buku,n-1);
        tulisdata(buku);
        printf("\n!!DATA BUKU BERHASIL DIUBAH!!\n\n");
    }

    system("pause");
}

void searchkode()
{
    system("cls");
    daftar buku[9999];
    int n;
    printf("             ||==========================================||\n");
    printf("             ||             SEARCHING BUKU               ||\n");
    printf("             ||==========================================||\n\n\n");

    printf("MASUKAN KODE BUKU YANG DICARI : "); scanf("%d",&n);

    int i;
    bacadata(buku,&i);

    i=0;
    while(buku[i].kode!=NULL){
        if(buku[i].kode==n){
            printf("\n\nKODE BUKU     :\t%d\n",buku[i].kode);
            printf("JUDUL BUKU    :\t%s\n",buku[i].judul);
            printf("HARGA BUKU    :\tRp%d\n",buku[i].harga);
            printf("KATEGORY BUKU :\t%s\n",buku[i].kategory);
            printf("PENERBIT BUKU :\t%s\n\n",buku[i].penerbit);
            break;
        }
        i++;
    }
    if(buku[i].kode!=n)
        printf("\n\t!!DATA BUKU YANG DICARI TIDAK DITEMUKAN!!\n\n");
    system("pause");
}

void searchjudul()
{
    system("cls");
    daftar buku[9999];
    int n;
    printf("             ||==========================================||\n");
    printf("             ||             SEARCHING BUKU               ||\n");
    printf("             ||==========================================||\n\n\n");

    printf("MASUKAN KODE BUKU YANG DICARI : "); scanf("%d",&n);

    int i;
    bacadata(buku,&i);

    i=0;
    while(buku[i].judul!=NULL){
        if(buku[i].judul==n){
            printf("\n\nKODE BUKU     :\t%d\n",buku[i].kode);
            printf("JUDUL BUKU    :\t%s\n",buku[i].judul);
            printf("HARGA BUKU    :\tRp%d\n",buku[i].harga);
            printf("KATEGORY BUKU :\t%s\n",buku[i].kategory);
            printf("PENERBIT BUKU :\t%s\n\n",buku[i].penerbit);
            ;
        }
        i++;
    }
    if(buku[i].judul!=n)
        printf("\n\t!!DATA BUKU YANG DICARI TIDAK DITEMUKAN!!\n\n");
    system("pause");
}


void tampildaftar()
{
    system("cls");
    daftar buku[9999];
    int i,n;

    bacadata(buku,&i);
    n=i;
    printf("             ||==========================================||\n");
    printf("             ||        DAFTAR BUKU YANG TERSEDIA         ||\n");
    printf("             ||==========================================||\n\n\n");

    for(i=0;i<n;i++){
        printf("KODE BUKU    :\t%d\n",buku[i].kode);
        printf("JUDUL BUKU   :\t%s\n",buku[i].judul);
        printf("HARGA BUKU   :\tRp%d\n",buku[i].harga);
        printf("KATEGORY BUKU:\t%s\n",buku[i].kategory);
        printf("PENERBIT BUKU:\t%s\n\n",buku[i].penerbit);
    }

    system("pause");
}

    void pembayaran(){
        system ("cls");
    pembayaran:
               printf("------------------------------------------------\n");


        daftar buku[9999];
        int n;
        char m;
        printf("MASUKAN KODE BUKU: "); scanf("%d",&n);
        int i,x,total,kembali,p;

        bacadata(buku,&i);
        i=0;
        while(buku[i].kode!=NULL){
            if(buku[i].kode==n){
                printf("JUDUL BUKU    : %s\n",buku[i].judul);
                printf("HARGA BUKU    : Rp%d\n",buku[i].harga);
                printf("BANYAK BUKU   : "); scanf("%d",&x);
                total=x*buku[i].harga;
                printf("TOTAL         : Rp%d\n",total);
                printf("MASUKAN UANG YANG DIBERIKAN  : Rp");
                scanf("%d",&p);
                kembali=p-total;
                printf("KEMBALIAN      : Rp%d\n",kembali);
                printf("ingin masukan data buku lagi (Y/N)? ");
            m=getche(); printf("\n\n");
    if(m=='y'){
        goto pembayaran;
    }else{
        printf("SELESAI");
        menu();
    }
    i++;
}
    if(buku[i].kode!=n)
        printf("\n\t!!DATA BUKU TIDAK ADA!!\n\n");
    printf("SELESAI.\n\n");
    system("pause");
    menu();

}
}
