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
