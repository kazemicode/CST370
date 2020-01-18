/*
 * Title: sieve.cpp
 * Abstract: Identifies all the prime numbers up to a number input by the user (positive integer)
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 01/14/2020
 */

#include <iostream>
#include <cmath>


using namespace std;

int* findPrimes(int numArray[], int number)
{
    int *result;
    int count = 2;
    // Eliminate non-primes by marking with 0
    for(int i = 2 ; i <= floor(sqrt(number)); i++){
        int current = numArray[i];
        if(current != 0)
        {
            int mults = i*i;
            while(mults <= number)
            {
                if(numArray[mults] != 0)
                {
                    count = count + 1; // keep track of number of marked (non-primes)
                }
                numArray[mults] = 0; // eliminate all multiples of the non-prime element
                mults = mults + i;

            }
        }
    }
    int numPrimes = number + 1 - count; // calculate number of primes to determine size of result array

    // Copy primes to new array to return as result
    result = new int[numPrimes]();
    int newIndex = 0;
    cout << "Primes found (up to) " << number << " and stored to result array: \n";
    for(int i = 0; i <= number; i++)
    {
        if(numArray[i] != 0)
        {
            result[newIndex] = numArray[i];
            cout << numArray[i] << '\t';
            newIndex = newIndex + 1;
        }

    }
    return result;
}

int main() {
    // prompt user for number
    int number;
    cout << "Enter a number and I'll identify the primes up to this number! " << std::endl;
    cin >> number;

    // allocate memory for the array
    int *numArray;
    numArray = new int[number+1]();

    // fill array from 2 to input number
    for(int i = 2; i <= number; i++)
    {
        numArray[i] = i;
    }


    // find the primes and return to pointer result for further usage if necessary
    int* result = findPrimes(numArray, number);


    delete[] numArray;
    return 0;
}


