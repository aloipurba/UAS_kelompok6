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
