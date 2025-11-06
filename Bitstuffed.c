#include <stdio.h>
#include <string.h>

void main()
{
    int i = 0, j = 0, k = 0, len, lenf, lend, count = 0;
    char sorc[50], stf[80] = {'\0'}, destf[50] = {'\0'}, flag[] = {"01111110"};

    printf("\n\nEnter the bit stream in binary\n");
    gets(sorc);

    strcpy(stf, flag);
    len = strlen(sorc);
    lenf = strlen(flag);
    j = lenf;

    // Bit Stuffing
    for (i = 0; i < len; i++)
    {
        if (sorc[i] == '1')
            count++;
        else
            count = 0;

        stf[j] = sorc[i];

        if (count == 5)
        {
            j++;
            stf[j] = '0';
            count = 0;
        }
        j++;
    }

    lend = strlen(stf);
    strcat(stf, flag);
    printf("\n\nThe Stuffed Data is:\n\n%s", stf);
    count = 0;

    // Bit De-stuffing
    for (j = 8; j < lend; j++)
    {
        if (stf[j] == '1')
            count++;
        else
            count = 0;

        destf[k] = stf[j];
        k++;

        if (count == 5)
        {
            j++;
            count = 0;
        }
    }

    printf("\n\nThe Destuffed Data is:\n\n%s", destf);
}
