#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>

int main(int arvc, char argv[])
{
    FILE *file = fopen("/media/iris/D0044E7D044E6716/Users/PC/Mes documents/retrieve ma phone/aimp-retrieve-music/files/PlaylistManager/data/this.aimpbpl", "rb+");
    fseek(file, 2, SEEK_END);
    long size = ftell(file);
    printf("%ld\n", size);
    uint16_t *buf = (uint16_t *)malloc(size);

    if (file == NULL)
    {
        printf("Couldn't open it\n");
        exit(0);
    }

    fseek(file, 0, SEEK_SET);

    size = size / 2;
    fread(buf, 2, size, file);
    for (int i = 0; i < (size + 1); i++)
    {

        // if ((buf[i] >= 65 && buf[i] <= 90) || (buf[i] >= 97 && buf[i] <= 122) ||
        //     (buf[i] >= 33 && buf[i] <= 47) || (buf[i] >= 58 && buf[i] <= 64) ||
        //     (buf[i] >= 123 && buf[i] <= 126) || 1)
        printf("%C", buf[i]);
    }
    // printf("%x", buf[0]);
    return 0;
}