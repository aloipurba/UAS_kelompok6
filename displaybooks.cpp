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

