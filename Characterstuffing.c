#include <stdio.h>
#include <string.h>

void main()
{
    int i = 0, j = 0, len, lenh, lend;
    char sorc[50], stf[80] = {'\0'}, destf[50] = {'\0'};
    char header[] = "DLESTX", trailer[] = "DLEETX";

    printf("\n\nEnter the Data in character\n");
    gets(sorc);

    strcpy(stf, header);
    len = strlen(sorc);
    lenh = strlen(header);
    j = lenh;

    // Character Stuffing
    for (i = 0; i < len; i++)
    {
        if ((sorc[i] == 'D') && (sorc[i + 1] == 'L') && (sorc[i + 2] == 'E'))
        {
            stf[j] = 'D';
            stf[j + 1] = 'L';
            stf[j + 2] = 'E';
            j += 3;
        }
        stf[j] = sorc[i];
        j++;
    }

    strcat(stf, trailer);
    printf("\n\nThe Stuffed Data is:\n%s", stf);

    // Character De-stuffing
    j = 0;
    lend = strlen(stf);

    for (i = lenh; i < lend - lenh; i++)
    {
        if ((stf[i] == 'D') && (stf[i + 1] == 'L') && (stf[i + 2] == 'E'))
        {
            i += 3;
        }
        destf[j] = stf[i];
        j++;
    }

    printf("\n\nThe Destuffed Data is:\n%s", destf);
}

