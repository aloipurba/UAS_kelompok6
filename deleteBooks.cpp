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
