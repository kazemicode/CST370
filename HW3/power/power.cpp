/*
 * Title: power.cpp
 * Abstract: Recursively calculates 2^n for a non-negative integer n input by the user
 * ID: 4444
 * Name: Sara Kazemi
 * Date: 01/21/2020
 */

#include <iostream>

using namespace std;

int power(int n)
{
    if(n == 0)
        return 1;                    // 2^0 = 1
    // Upon encountering an even number of n, we will eventually reach power(1) through recursion
    // This will then trigger the call in the else clause, 2 * power(0), which return  2*1 -> 2
    // This will then be returned to the value of m to the last call to power() on the stack and each
    // subsequent return value will returned to the next value of m to the call stack until all
    // calls are resolved and the final answer is computed
    else if(n % 2 == 0)
    {
        int m = power(n/2);
        return m * m;
    }
    else{
        return 2 * power(n-1);
    }
}

int main() {
    int n;
    cout << "Enter a positive integer and I will compute 2^n: ";
    cin >> n;
    cout << "2^" << n << " = " << power(n);
    return 0;
}
