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
