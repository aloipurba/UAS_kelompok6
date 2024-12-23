#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 100
#define PASSWORD "12345"

typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
    char category[50];
    int available;
} Book;

Book library[MAX_BOOKS];
Book books[MAX_BOOKS];
int book_count = 0;

typedef struct {
    int member_id;
    char name[100];
    char address[100];
    char phone[15];
    int borrowed_books[MAX_BOOKS]; 
    int borrowed_count;
} Member;

Member members[MAX_MEMBERS];
int member_count = 0;



void saveToFile() {
    FILE *file = fopen("library_data.txt", "w");
    if (!file) {
        printf("Error membuka file!\n");
        return;
    }
    for (int i = 0; i < book_count; i++) {
        fprintf(file, "%d|%s|%s|%d|%s\n", library[i].id, library[i].title, library[i].author, library[i].year, library[i].category);
    }
    fclose(file);
    
    // Save member data
    file = fopen("members_data.txt", "w");
    if (!file) {
        printf("Error membuka file anggota!\n");
        return;
    }
    for (int i = 0; i < member_count; i++) {
        fprintf(file, "%d|%s|%s|%s\n", members[i].member_id, members[i].name, members[i].address, members[i].phone);
    }
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("library_data.txt", "r");
    if (!file) {
        printf("File buku tidak ditemukan. Memulai dengan data awal.\n");
        
library[book_count++] = (Book){1, "Bahasa Pemrograman", "Brian W. Kernighan dan Dennis M. Ritchie", 1978, "Pemrograman"};
library[book_count++] = (Book){2, "Kode Bersih", "Robert C. Martin", 2008, "Pengembangan Perangkat Lunak"};
library[book_count++] = (Book){3, "Programmer Pragmatis", "Andrew Hunt dan David Thomas", 1999, "Pengembangan Perangkat Lunak"};
library[book_count++] = (Book){4, "Pola Desain", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", 1994, "Arsitektur Perangkat Lunak"};
library[book_count++] = (Book){5, "Pengantar ke Algoritma", "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest", 2009, "Algoritma"};
library[book_count++] = (Book){6, "Head First Java", "Kathy Sierra, Bert Bates", 2003, "Pemrograman"};
library[book_count++] = (Book){7, "Jaringan Komputer: Pendekatan Top-Down", "James F. Kurose, Keith W. Ross", 2017, "Jaringan Komputer"};
library[book_count++] = (Book){8, "Pendekatan Modern", "Stuart Russell, Peter Norvig", 2010, "Kecerdasan Buatan"};
library[book_count++] = (Book){9, "Kode Lengkap", "Steve McConnell", 2004, "Pengembangan Perangkat Lunak"};
library[book_count++] = (Book){10, "Tiga Bagian Mudah", "Remzi H. Arpaci-Dusseau, Andrea C. Arpaci-Dusseau", 2018, "Sistem Operasi"};
saveToFile();
 // Save books immediately to file
        return;
    }
    while (fscanf(file, "%d|%99[^|]|%99[^|]|%d|%49[^\n]\n", &library[book_count].id, library[book_count].title, library[book_count].author, &library[book_count].year, library[book_count].category) != EOF) {
        book_count++;
    }
    fclose(file);
    
    // Load member data
    file = fopen("members_data.txt", "r");
    if (!file) {
        printf("File anggota tidak ditemukan. Memulai dengan data anggota awal.\n");
        
        members[member_count++] = (Member){1, "haekal", "123 Elm Street", "555-1234"};
        members[member_count++] = (Member){2, "bagas", "456 Oak Avenue", "555-5678"};
        members[member_count++] = (Member){3, "bagus", "789 Pine Road", "555-8765"};
		saveToFile(); // Save members immediately to file
        return;
    }
}
