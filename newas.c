#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{
    int i, j, keylen, msglen;
    char massage[100], key[30], temp[30], quot[100], rem[30], key1[30];
    printf("Enter The massage: ");
    gets(massage);
    printf("Enter Polynomial: ");
    gets(key);
    keylen = strlen(key);
    msglen = strlen(massage);
    strcpy(key1, key);
    for (i = 0; i < keylen - 1; i++)
    {
        massage[msglen + i] = '0';
    }
    for (i = 0; i < keylen; i++)
        temp[i] = massage[i];
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        else
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[keylen - 1] = massage[i + keylen];
        strcpy(temp, rem);
    }
    strcpy(rem, temp);
    printf("\nCRC is ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    printf("\nChechsummed: ");
    for (i = 0; i < msglen; i++)
        printf("%c", massage[i]);
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    getch();
}