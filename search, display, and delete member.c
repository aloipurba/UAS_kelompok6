void searchMember() {
	char target_name[100];
	printf ("Masukkan nama anggota yang ingin di cari: ");
	getchar();
	fgets(target_name, 100, stdin);
	target_name[strcspn(target_name,"\n")] = 0;

	for (int i = 0; i < member_count; i++) {
		if (strcmp(member[i].name, target_name) == 0) {
			printf("\nAnggota ditemukan\n");
			printf("ID: %d\nNama: %s\nAlamat: %s\nTelepon: %s\n",member[i].member_id, member[i].name, member[i]address, member[i].phone);
			return;
		}
	}
	printf("Anggota dengan nama %s tidak ditemukan.\n",target_name);
}

void displayMembers() {
    if (member_count == 0) {
        printf("Tidak ada anggota yang terdaftar.\n");
        return;
    }

	 printf("\nDaftar Anggota:\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("| %-3s | %-20s | %-30s | %-15s | %-30s |\n", "ID", "Nama", "Alamat", "Telepon", "Buku yang Dipinjam");
    printf("--------------------------------------------------------------------------------------\n");

for (int i = 0; i < member_count; i++) {
        printf("| %-3d | %-20.20s | %-30.30s | %-15.15s | ", 
               members[i].member_id, members[i].name, members[i].address, members[i].phone);

	if (members[i].borrowed_count > 0) {
            for (int j = 0; j < members[i].borrowed_count; j++) {
                // Mencari judul buku berdasarkan ID buku yang dipinjam
                for (int k = 0; k < book_count; k++) {
                    if (members[i].borrowed_books[j] == library[k].id) {
                        printf("%s", library[k].title);
                        if (j < members[i].borrowed_count - 1) {
                            printf(", ");
                        }
                    }
                }
            }
        } else {
            printf("Tidak ada buku yang dipinjam.");
        }

        printf(" |\n");
    }
    printf("--------------------------------------------------------------------------------------\n");
}

void deleteMember() {
    char target_name[100];
    printf("Masukkan nama anggota yang ingin dihapus: ");
    getchar();
    fgets(target_name, 100, stdin);
    target_name[strcspn(target_name, "\n")] = 0;

    for (int i = 0; i < member_count; i++) {
        if (strcmp(members[i].name, target_name) == 0) {
            
            printf("Anggota yang akan dihapus:\n");
            printf("ID: %d\nNama: %s\nAlamat: %s\nTelepon: %s\n", 
                   members[i].member_id, members[i].name, members[i].address, members[i].phone);
            
            for (int j = i; j < member_count - 1; j++) {
                members[j] = members[j + 1];
            }
            
            member_count--;
            printf("Anggota dengan nama %s berhasil dihapus.\n", target_name);
            return;
        }
    }
    printf("Anggota dengan nama %s tidak ditemukan.\n", target_name);
}
