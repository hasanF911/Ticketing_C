#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Ticket
{
    int record;
    char tanggal[25];
    char nama[50];
    char jenisticket[50];
    char event[50];
    int jmlticket;
    int harga;
    int totalpembayaran;
};

struct Ticket Tic[100];


void addData(int x)
{
    struct Ticket Tic;
    FILE *ptr;
    int lastRecord = 0;
    ptr = fopen("sales.txt", "r");

    if (ptr != NULL)
    {
        char ch;
        while ((ch = fgetc(ptr)) != EOF)
        {
            if (ch == '\n')
            {
                lastRecord++;
            }
        }
        fclose(ptr);
    }
    Tic.record = lastRecord + 1;
    ptr = fopen("sales.txt", "a");
    printf("===Add Data===\n");
    printf("Record : %d\n", Tic.record);
        
    getchar();
    printf("Tanggal : ");
    scanf("%[^\n]", &Tic.tanggal);
    getchar();
    printf("Nama Pelanggan : ");
    scanf("%[^\n]", &Tic.nama);
    getchar();
    printf("Jenis Ticket : ");
    scanf("%s", &Tic.jenisticket);
    getchar();
    printf("Nama Event : ");
    scanf("%[^\n]", &Tic.event);
    getchar();
    printf("Jumlah Ticket : ");
    scanf("%d", &Tic.jmlticket);
    getchar();
    printf("Harga Ticket : ");
    scanf("%d", &Tic.harga);
    getchar();

    Tic.totalpembayaran = Tic.harga * Tic.jmlticket;
    printf("Total Pembayaran : %d", Tic.totalpembayaran);

    fprintf(ptr, "\n%d;%s;%s;%s;%s;%d;%d;%d", Tic.record, Tic.tanggal, Tic.nama, Tic.jenisticket, Tic.event, Tic.jmlticket, Tic.harga, Tic.totalpembayaran);
    printf("\nData Successfully added\n");
    fclose(ptr);
}


int searchByRecord(int x) {
    int record, found = -1;
    printf("========== Search ==========\n");
    printf("Enter the record number to search: ");
    scanf("%d", &record);

    for (int i = 0; i < x; i++) {
        if (Tic[i].record == record) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Record not found.\n");
    } else {
        system ("cls");
        printf("========================================================================= Search By Record %d =========================================================================\n", Tic[found].record);
        printf("Record #    Tanggal Transaksi\t Nama Pelanggan\t\t\t\t Jenis Ticket\t Nama Event\t Jumlah Ticket\t Harga Ticket\t Total Pembayaran\n");
        printf("======================================================================================================================================================================\n");
        printf("%-12d%-20s %-39s %-15s %-15s %-15d %-15d Rp.%d\n", Tic[found].record, Tic[found].tanggal, Tic[found].nama, Tic[found].jenisticket, Tic[found].event, Tic[found].jmlticket, Tic[found].harga, Tic[found].totalpembayaran);
    }
}

void sortByJenisTicket(int x) {
    int i, j;
    struct Ticket temp;

    for (i = 0; i < x-1; i++) {
        for (j = 0; j < x-i-1; j++) {
            if (strcmp(Tic[j].jenisticket, Tic[j+1].jenisticket) > 0) {
                temp = Tic[j];
                Tic[j] = Tic[j+1];
                Tic[j+1] = temp;
            }
        }
    }
    printf("========== Sorted by Jenis Ticket ==========\n");
    printf("Record #    Tanggal Transaksi\t Nama Pelanggan\t\t\t\t Jenis Ticket\t Nama Event\t Jumlah Ticket\t Harga Ticket\t Total Pembayaran\n");
    printf("======================================================================================================================================================================\n");
    for (i = 0; i < x; i++) {
        printf("%-12d%-20s %-39s %-15s %-15s %-15d %-15d Rp.%d\n", Tic[i].record, Tic[i].tanggal, Tic[i].nama, Tic[i].jenisticket, Tic[i].event, Tic[i].jmlticket, Tic[i].harga, Tic[i].totalpembayaran);
    }
}

void sortByNamaEvent(int x) {
    int i, j;
    struct Ticket temp;

    for (i = 0; i < x-1; i++) {
        for (j = 0; j < x-i-1; j++) {
            if (strcmp(Tic[j].event, Tic[j+1].event) > 0) {
                temp = Tic[j];
                Tic[j] = Tic[j+1];
                Tic[j+1] = temp;
            }
        }
    }
    printf("========== Sorted by Nama Event ==========\n");
    printf("Record #    Tanggal Transaksi\t Nama Pelanggan\t\t\t\t Jenis Ticket\t Nama Event\t Jumlah Ticket\t Harga Ticket\t Total Pembayaran\n");
    printf("======================================================================================================================================================================\n");
    for (i = 0; i < x; i++) {
        printf("%-12d%-20s %-39s %-15s %-15s %-15d %-15d Rp.%d\n", Tic[i].record, Tic[i].tanggal, Tic[i].nama, Tic[i].jenisticket, Tic[i].event, Tic[i].jmlticket, Tic[i].harga, Tic[i].totalpembayaran);
    }
}




int readData(int *x)
{
    FILE *ptr;
    int count = 0;
    struct Ticket temp;

    ptr = fopen("sales.txt", "r");
    if (ptr == NULL)
    {
        printf("Can't open file or file doesn't exist\n");
        return -1;
    }
    printf("========================================================================= Data Ticket =============================================================================\n");
    printf("Record #    Tanggal Transaksi\t Nama Pelanggan\t\t\t\t Jenis Ticket\t Nama Event\t Jumlah Ticket\t Harga Ticket\t Total Pembayaran\n");
    printf("===================================================================================================================================================================\n");
    while (fscanf(ptr, "%d;%[^\';'];%[^\';'];%[^\';'];%[^\';'];%d;%d;%d\n", &Tic[count].record, Tic[count].tanggal, Tic[count].nama, Tic[count].jenisticket, Tic[count].event, &Tic[count].jmlticket, &Tic[count].harga, &Tic[count].totalpembayaran) != EOF)
    {
        printf("%-12d%-20s %-39s %-15s %-15s %-15d %-15d Rp.%d\n", Tic[count].record, Tic[count].tanggal, Tic[count].nama, Tic[count].jenisticket, Tic[count].event, Tic[count].jmlticket, Tic[count].harga, Tic[count].totalpembayaran);
        count += 1;
    }

    *x = count;
    printf("\n");
    fclose(ptr);
}

int importData(int *x)
{
    FILE *ptr;
    int count = 0;

    ptr = fopen("sales.txt", "r");
    if (ptr == NULL)
    {
        printf("Can't open file or file doesn't exist\n");
        return -2;
    }
    printf("========================================================================= Data Ticket =============================================================================\n");
    printf("Record #    Tanggal Transaksi\t Nama Pelanggan\t\t\t\t Jenis Ticket\t Nama Event\t Jumlah Ticket\t Harga Ticket\t Total Pembayaran\n");
    printf("===================================================================================================================================================================\n");
    while (fscanf(ptr, "%d;%[^\';'];%[^\';'];%[^\';'];%[^\';'];%d;%d;%d\n", &Tic[count].record, Tic[count].tanggal, Tic[count].nama, Tic[count].jenisticket, Tic[count].event, &Tic[count].jmlticket, &Tic[count].harga, &Tic[count].totalpembayaran) != EOF)
    {
    
        count += 1;
    }

    *x = count;

    fclose(ptr);
}

void deleteData(int *x)
{
    FILE *ptr;
    int deleteRecord;
    int found = 0;
    readData(x);
    int count = *x;
    ptr = fopen("sales.txt", "w");

    printf("Select Record : ");
    scanf("%d", &deleteRecord);
    for (int i = 0; i < count; i++)
    {
        if (Tic[i].record == deleteRecord)
        {
            found = 1;
            continue;
        }
        else
        {
            (i == count - 1) ? fprintf(ptr, "%d;%s;%s;%s;%s;%d;%d;%d\n", Tic[i].record, Tic[i].tanggal, Tic[i].nama, Tic[i].jenisticket, Tic[i].event, Tic[i].jmlticket, Tic[i].harga, Tic[i].totalpembayaran) : fprintf(ptr, "%d;%s;%s;%s;%s;%d;%d;%d\n", Tic[i].record, Tic[i].tanggal, Tic[i].nama, Tic[i].jenisticket, Tic[i].event, Tic[i].jmlticket, Tic[i].harga, Tic[i].totalpembayaran);
        }
    }
    if (found == 0)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("Record deleted\n");
    }
    fclose(ptr);
}

int main()
{
        int count = 0;

    int selek;
    char username[15];
    char password[12];

    do
    {
        printf("========== Login Admin ==========\n");
        printf("username:");
        scanf("%s", &username);

        printf("password:");
        scanf("%s", &password);
        printf("=================================\n");
        system("cls");
    } while (strcmp(username, "admin") && strcmp(password, "admin"));

    importData(&count);
    system("cls");

    do
    {
        system("cls");
        printf("===== Ticket =====\n");
        printf("1. Add Data\n");
        printf("2. Search Data\n");
        printf("3. View Data\n");
        printf("4. Delete Data\n");
        printf("0. Exit\n");
        printf("Pilih Menu : ");
        scanf("%d", &selek);

        switch (selek)
        {
        case 1:
            system("cls");
            addData(count);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            searchByRecord(count);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            readData(&count);
            	int selectSort;
            	printf("\n\n\n=========== Sorting Menu ===========\n");
            	printf("1. Sort by Jenis Ticket\n");
                printf("2. Sort by Nama Event\n");
                printf("0. Back To Main Menu\n");
            	printf("Pilihan : ");
            	scanf("%d", &selectSort);
            	switch (selectSort)
            	{
            		case 1:
	            		system("cls");
	            		sortByJenisTicket(count);
	            		system("pause");
	            		system("cls");
	            		break;
                    
                    case 2:
                            system("cls");
	            		    sortByNamaEvent(count);
	            		    system("pause");
	            		    system("cls");
                            break;
                    case 0:

					default:
						break;
				}
            system("cls");
            break;
        case 4:
            system("cls");
            deleteData(&count);
            system("pause");
            system("cls");
			break;
        case 0:

        default:
            system("cls");
            printf("========================================\n");
            printf("            Invalid Input !\n");
            printf("  Please Enter The Available Numbers !\n");
            printf("========================================\n");
            system("pause");
            system("cls");
            break;
        }
    } while (selek != 0);
}