#include <iostream>
using namespace std;

int qsort(int arr[], int leftidx, int rightidx) 
{
    if (rightidx > leftidx){
        int pivotIdx = (leftidx+rightidx)/2;
        int pivotVal = arr[pivotIdx];
        int i = leftidx;
        int j = rightidx;
        while (i <= j) {
            while (arr[j] < pivotVal) j--;
            while (arr[i] > pivotVal) i++;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (leftidx < i)
            qsort (arr, leftidx, j);
        if (rightidx > j)
            qsort (arr, i, rightidx);
    }
}

int main() 
{
    int numCoins;
    cin >> numCoins;
    int *coins = new int[numCoins];
    
    for (int i=0; i<numCoins; i++) {
        cin >> coins[i];
    }
    qsort(coins, 0, numCoins-1);
    
    int amount;
    int *change = new int[numCoins];
    
    cin >> amount;
    for (int i =0; i<numCoins; i++) {
        int used = amount/coins[i];
        amount = amount % coins[i];
        change[i] = used;
    }

    if (amount > 0){
        cout << "Impossible" << endl;
    }
    else {
        for (int i =0; i<numCoins; i++) {
            if (change[i] != 0)
                cout << change[i] << " x " << coins[i] << endl;
        }
    }
        
}

