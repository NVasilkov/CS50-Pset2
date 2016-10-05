/**
Use Caesar cipher to encrypt and decrypt messages. Written in C.
**/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CRU 65 // CRU stands for Conversion Ratio UpperCase
#define CRL 97 // CRL stands for Conversion Ratio LowerCase

int main(int argc, string argv[])
{
    // Cipher key is the second string in a command line argument 
    if (argc != 2)
    {
        printf ("Usage: Input for the cipher key");
        return 1;
    }
    
    // Converts cipher key string provided at command line argument to an integer 
    int key = atoi(argv[1]);
    
    // Breaks if cipher key is given as an negative number 
    if (key < 0)
    {
        printf ("Cipher key is a single and positive integrer\n");
        return 1;
    }
    
    // Ask user to provide a plain text 
    string text = GetString ();
    
    // Loop to access each individual "box" of the string 
    for (int i = 0, n = strlen(text); i < n; i++ )
    {
        //If "box" is an appercase letter, CRU is used 
        if (isalpha (text[i]) && isupper (text[i]))
        {
            text[i] = ((text[i] - CRU + key) % 26 + CRU);
            printf ("%c", text[i]);
        }
        
        // If "box" is a lowercase letter, CRU is ised 
        else if (isalpha (text[i]) && islower (text[i]))
        {
            text[i] = ((text[i] - CRL + key) % 26 + CRL);
            printf ("%c", text[i]);
        }
        
        // if "box" is not a letter, "box" stays unchanged 
        else 
        {
            printf ("%c", text[i]);
        }
    }
    
    printf ("\n");
}
  
  
/** 
   Formula to convert uppercase letter in ASCII to Alpha and back 
    plain text = 'A';
    cipher text = (plain text - Conversion Ratio + Key) % 26 + Conversion Ratio;
**/
