#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: elfry file\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Failed to open file %s\n", argv[1]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    byte *elf_file_buf = malloc(size);
    fread(elf_file_buf, size, 1, fp);

    for (int i = 0; i < 4; i++) {
        byte b = elf_file_buf[i];
        printf("%c %x \n", b, b);
    }

    fclose(fp);

    return 0;
}

