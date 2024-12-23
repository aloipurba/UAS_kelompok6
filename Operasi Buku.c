void borrowBook() {
    char bookTitle[50];
    int found = 0;

    printf("\n=== Meminjam Buku ===\n");
    printf("Masukkan judul buku yang ingin dipinjam: ");
    fflush(stdin);
    fgets(bookTitle, sizeof(bookTitle), stdin);
    bookTitle[strcspn(bookTitle, "\n")] = 0; // Menghapus newline dari input

    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, bookTitle) == 0 && books[i].available > 0) {
            books[i].available--;
            printf("Buku '%s' berhasil dipinjam.\n", bookTitle);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Buku '%s' tidak ditemukan atau tidak tersedia.\n", bookTitle);
    }
}

void returnBook() {
    char bookTitle[50];
    int found = 0;

    printf("\n=== Mengembalikan Buku ===\n");
    printf("Masukkan judul buku yang ingin dikembalikan: ");
    fflush(stdin);
    fgets(bookTitle, sizeof(bookTitle), stdin);
    bookTitle[strcspn(bookTitle, "\n")] = 0; // Menghapus newline dari input

    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, bookTitle) == 0) {
            books[i].available++;
            printf("Buku '%s' berhasil dikembalikan.\n", bookTitle);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Buku '%s' tidak ditemukan dalam sistem.\n", bookTitle);
    }
}


void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Perpustakaan penuh!\n");
        return;
    }
    printf("Masukkan ID Buku: ");
    scanf("%d", &library[book_count].id);
    printf("Masukkan Judul Buku: ");
    getchar();
    fgets(library[book_count].title, 100, stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = 0;
    printf("Masukkan Penulis Buku: ");
    fgets(library[book_count].author, 100, stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = 0;
    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &library[book_count].year);
    printf("Masukkan Kategori Buku: ");
getchar();
fgets(library[book_count].category, 50, stdin);
library[book_count].category[strcspn(library[book_count].category, "\n")] = 0;


    book_count++;
    saveToFile();
    printf("Buku berhasil ditambahkan!\n");
}

void merge(Book arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Book L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Book arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}