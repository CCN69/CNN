#include <stdio.h>
#include <string.h>

int xor2div(char *in, char *out, int mode)
{
    int i, j, k;
    char gen[100] = {"110101"};
    strcpy(out, in);

    if (mode)
        strcat(out, "00000");  // Append zeros for CRC calculation

    for (j = 0; j < strlen(in); j++)
    {
        if (out[j] == '1')
            for (k = 0; k < strlen(gen); k++)
            {
                if ((out[j + k] == '0' && gen[k] == '0') ||
                    (out[j + k] == '1' && gen[k] == '1'))
                    out[j + k] = '0';
                else
                    out[j + k] = '1';
            }
    }

    // Check if any remainder (error)
    for (j = 0; j < strlen(out); j++)
        if (out[j] == '1')
            return 1;

    return 0;
}

void main()
{
    char in[100] = {'\0'}, out[100] = {'\0'}, rec[100] = {'\0'};
    char gen[100] = {"110101"};

    printf("\n\nEnter the message code in binary: ");
    scanf("%s", in);

    printf("\n\nThe generator polynomial is: %s", gen);

    xor2div(in, out, 1);

    printf("\n\nCRC CCITT code to Transmit is: %s%s", in, out + strlen(in));

    printf("\n\nEnter the received frame: ");
    scanf("%s", rec);

    if (xor2div(rec, out, 0))
        printf("\n\nThere is an error in the received frame.");
    else
        printf("\n\nNo Error is found in the received frame.");
}
