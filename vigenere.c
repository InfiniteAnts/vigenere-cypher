#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MODC 26
#define ASCUP 65
#define ASCLO 97

int main(int argc, string argv[])
{
    // error if more or less than one command line argument 
    if (argc != 2)
    {
        printf("Error. Usage: ./vigenere key\n");
        return 1;
    }
    
    // making sure argument string is valid
    if (argv[1] != NULL)
    {
        int m = strlen(argv[1]);
    
        // converts key from ASCII to alphabetical indices. Error if key has characters other than alphabets.
        for (int j = 0; j < m; j++)
        {
            if (isalpha(argv[1][j]))
            {
                if (isupper(argv[1][j]))
                {
                    argv[1][j] = argv[1][j] - ASCUP;
                }
                else if (islower(argv[1][j]))
                {
                    argv[1][j] = argv[1][j] - ASCLO;
                }
            }
            else
            {
                printf("Error. Use a key with only alphabets.\n");
                return 1;
            }
        }
        
        // get plaintext from user
        printf("plaintext: ");
        string p = get_string();
        
        // making sure entered string is valid
        if (p != NULL)
        {
            printf("ciphertext: ");
            
            // going through the string one character at a time. 
            // In this loop, j is only incremented if the ith character in p is an alphabet.
            
            for (int i = 0, n = strlen(p), j = 0; i < n; i++)
            {
                // if character is an alphabet
                if (isalpha(p[i]))
                {
                    // if alphabet is uppercase. 
                    if (isupper(p[i]))
                    {
                        p[i] = (p[i] - ASCUP + argv[1][(j % m)]) % MODC;
                        printf("%c", p[i] + ASCUP);
                        j++;
                    }
                    // if alphabet is lowercase
                    else
                    {
                        p[i] = (p[i] - ASCLO + argv[1][(j % m)]) % MODC;
                        printf("%c", p[i] + ASCLO);
                        j++;
                    }
                    
                }
                // if not an alphabet, print as it is
                else
                    printf("%c", p[i]);
            }
            // print a new line at the end
            printf("\n");
        }
    }
}