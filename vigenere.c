#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CRU 65
#define CRL 97

int main(int argc, string argv[])
{
    if (argc != 2) // Exits if a key that should be second command line argument is not provided
    {
        printf ("Wrong input\n");
        return 1;
    }
    
    string key = argv[1];
    
    for (int i = 0, n = strlen(key); i < n; i++) // Loop is designed to go through the "key" string 
    {
        if (isalpha(key[i]) == 0)
        {
        printf ("Wrong input\n"); // Exits if "key" sting comprises not alpha characters
        return 1;
        }
    }
    
    string text = GetString (); // Ask user to provide input which is a plain text 
    
    for (int i = 0, j = 0, n = strlen(text), m = strlen(key); i < n; i++) // Loop is designed to go through the "input" and "key" 
    {
        if  (isalpha (text[i]) && isupper (text[i])) // If input text chracter is am uppercase letter 
        {
            key[j] = (key[j] - CRU); // Calculate conversion ration for Kj
            text[i] = ((text[i] - CRU + key[j % m]) % 26 + CRU); // Encrypt texts
            j++; // Pass to the next j in the key
            printf("%c", text[i]);  
        }
        
        else if (isalpha (text[i]) && islower (text[i])) // If input text chracter is am lowercase letter 
        {
            key[j] = (key[j] - CRL);
            text[i] = ((text[i] - CRL + key[j % m]) % 26 + CRL);
            j++;
            printf("%c", text[i]);  
        }
        
        else // If input text chracter is something else 
        {
            printf ("%c", text[i]);
        }
    }
    printf ("\n");
    
    return 0;
}