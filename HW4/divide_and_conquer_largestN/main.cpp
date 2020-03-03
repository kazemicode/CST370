#include <iostream>
using namespace std;

int getLargestN(int arr[], int start, int end)
{
    if(end - start  == 0 || end < start)
    {
        return start;
    }
    else{
        cout << "start1: " << start << " end1: " << end/2 - 1 << "\n";
        cout << "start2: " << end/2  << " end2: " << end << "\n";
        int largestB = getLargestN(arr, start, end/2);
        int largestC = getLargestN(arr, end/2+1, end);
        if(arr[largestB] > arr[largestC])
        {
            return largestB;
        }
        else{
            return largestC;
        }
    }

}

int main() {
    const int length= 4;
    int arr[4] = {2, 5, 2, 99};
    int start = 0;
    int end = length - 1;
    cout << getLargestN(arr, start, end);
    return 0;
}
