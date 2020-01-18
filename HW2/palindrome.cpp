/*
 * Title: sieve.cpp
 * Abstract: Identifies if a user inputted string is a palindrome or not.
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 01/14/2020
 */

#include <iostream>
#include <string.h>

using namespace std;

// Method effectively splits the character array into two halves and compares
// the characters on either ends to see if they are the same.
// If, at any point, we find a mismatch, we can declare that the string entered
// is NOT a palindrome.
// However, if we get through all the comparisons without a mismatch (exit the for loop)
// we can declare that the string entered IS a palindrome.
bool isBoolean(char word[])
{
    for(int i = 0; i < strlen(word)/2; i++)
    {
        if(word[i] != word[strlen(word)-1-i])
            return false;
    }
    return true;
}

int main() {
    // allocate memory for single element of char type
    char *word;
    // allocate array to hold up to 256 char elements
    word = new char[256];

    // Prompt user
    cout << "Enter a word, and I will tell you if it is a palindrome! " << std::endl;

    // Store input to char array
    cin.getline(word, 256);

    // determine if word is a palindrome by passing over to isBoolean
    if( isBoolean(word))
    {
        cout << word << " is a palindrome.\n";
    }
    else{
        cout << word << " is not a palindrome.\n";
    }
    return 0;
}


