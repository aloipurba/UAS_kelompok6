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
