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







void displayBooks() {
    if (book_count == 0) {
        printf("Tidak ada buku di perpustakaan.\n");
        return;
    }

    mergeSort(library, 0, book_count - 1);

    printf("\nDaftar Buku:\n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-30s | %-20s | %-5s | %-18s |\n", "ID", "Judul", "Penulis", "Tahun", "Kategori");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < book_count; i++) {
        printf("| %-3d | %-30.30s | %-20.20s | %-5d | %-18.15s |\n", 
               library[i].id, library[i].title, library[i].author, library[i].year, library[i].category);
    }
    printf("--------------------------------------------------------------------------------------------\n");
}

void searchBook() {
    int target_id;
    printf("Masukkan ID buku yang ingin dicari: ");
    scanf("%d", &target_id);

    mergeSort(library, 0, book_count - 1);

    int l = 0, r = book_count - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (library[m].id == target_id) {
            printf("\nBuku ditemukan:\n");
            printf("ID: %d\nJudul: %s\nPenulis: %s\nTahun: %d\nKategori: %s\n",
       library[m].id, library[m].title, library[m].author, library[m].year, library[m].category);
            return;
        }
        if (library[m].id < target_id)
            l = m + 1;
        else
            r = m - 1;
    }
    printf("Buku dengan ID %d tidak ditemukan.\n", target_id);
}

void deleteBook() {
    char target_title[100];
    int found = 0;
    
    printf("Masukkan judul buku yang ingin dihapus: ");
    getchar();  // Membersihkan newline
    fgets(target_title, 100, stdin);
    target_title[strcspn(target_title, "\n")] = 0;  // Menghapus newline di akhir input judul

    // Mencari buku berdasarkan judul yang dimasukkan
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, target_title) == 0) {
            // Menghapus buku dengan menggeser elemen setelahnya
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;  // Mengurangi jumlah buku
            printf("Buku dengan judul '%s' telah dihapus.\n", target_title);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Buku dengan judul '%s' tidak ditemukan.\n", target_title);
    }
}

void registerMember() {
    if (member_count >= MAX_MEMBERS) {
        printf("Jumlah anggota sudah mencapai batas maksimal!\n");
        return;
    }

    printf("Masukkan ID Anggota: ");
    scanf("%d", &members[member_count].member_id);
    printf("Masukkan Nama Anggota: ");
    getchar();
    fgets(members[member_count].name, 100, stdin);
    members[member_count].name[strcspn(members[member_count].name, "\n")] = 0;

    printf("Masukkan Alamat Anggota: ");
    fgets(members[member_count].address, 100, stdin);
    members[member_count].address[strcspn(members[member_count].address, "\n")] = 0;

    printf("Masukkan Nomor Telepon Anggota: ");
    fgets(members[member_count].phone, 15, stdin);
    members[member_count].phone[strcspn(members[member_count].phone, "\n")] = 0;

    member_count++;
    printf("Anggota berhasil didaftarkan!\n");
}







int loginAsEmployee() {
    char input_password[100];
    int attempts = 0;
    while (attempts < 3) {
        printf("Masukkan password pegawai: ");
        scanf("%s", input_password);

        if (strcmp(input_password, PASSWORD) == 0) {
            printf("Login berhasil!\n");
            return 1;
        } else {
            printf("Password salah! Coba lagi.\n");
            attempts++;
        }
    }
    printf("Terlalu banyak percobaan, keluar dari program.\n");
    system("pause");
    return 0;
}



int main() {
    int role;
    loadFromFile();

    do {
        system("cls");
        printf("\n=== Selamat Datang di Perpustakaan ===\n");
        printf("1. Masuk sebagai Peminjam Buku\n");
        printf("2. Masuk sebagai Pegawai Perpustakaan\n");
        printf("3. Keluar\n");
        printf("Pilih peran: ");
        scanf("%d", &role);

        if (role == 1) {
            int choice;
do {
    system("cls");
    printf("\n=== Menu Peminjam Buku ===\n");
    printf("1. Daftar Anggota Baru\n");
    printf("2. Cari Anggota\n");
    printf("3. Tampilkan Semua Anggota\n");
    printf("4. Pinjam Buku\n");
    printf("5. Kembalikan Buku\n");
    printf("6. Kembali\n");
    printf("Pilih menu: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            registerMember();
            system("pause");
            break;
        case 2:
            searchMember();
            system("pause");
            break;
        case 3:
            displayMembers();
            system("pause");
            break;
        case 4:
            borrowBook();  // Panggil fungsi untuk meminjam buku
            system("pause");
            break;
        case 5:
            returnBook();
            system("pause");
            break;
        case 6:
            break;
        default:
            printf("Pilihan tidak valid!\n");
            system("pause");
    }
} while (choice != 6);
        } else if (role == 2) {
            if (loginAsEmployee()) {
                int choice;
                do {
                    system("cls");
                    printf("\n=== Menu Pegawai Perpustakaan ===\n");
                    printf("1. Tambah Buku\n");
                    printf("2. Tampilkan Semua Buku\n");
                    printf("3. Cari Buku\n");
                    printf("4. Hapus Buku\n");
                    printf("\n=== Menu Anggota ===\n");
					printf("5. Tampilkan Semua Anggota\n");
					printf("6. Cari Anggota\n");
					printf("7. Hapus Anggota\n\n");
                    printf("8. Kembali\n");
                    printf("Pilih menu: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            addBook();
                            break;
                        case 2:
                            displayBooks();
                            system("pause");
                            break;
                        case 3:
                            searchBook();
                            system("pause");
                            break;
                        case 4:
							deleteBook();  
							system("pause");
							break;
						case 5:
						displayMembers();  // Menampilkan anggota
						system("pause");
						break;
						case 6:
						searchMember();  // Mencari anggota
						system("pause");
						break;
						case 7:
						deleteMember();  // Menghapus anggota
						system("pause");
						break;
                        case 8:
                            break;
                        default:
                            printf("Pilihan tidak valid!\n");
                            system("pause");
                    }
                } while (choice != 8);
            }
        } else if (role == 3) {
            printf("Keluar dari program.\n");
        } else {
            printf("Pilihan tidak valid!\n");
            system("pause");
        }
    } while (role != 3);
    
    saveToFile();
    return 0;
}
