#include <iostream>
using namespace std;

int main() {
    int n ;
    cout << "Enter size of array :" ;
    cin >> n ;

    int arr[n] ;

    cout<< "Enter the Elements in array :" ;
    for(int i = 0 ; i < n ; i++){
        cin>> arr[i] ;
    }

    int ans = 0;

    for (int i = arr[0]; i < n; i++)
        ans ^= i;

    for (int i = arr[0]; i < n - 1; i++)
        ans ^= arr[i];

    cout << "Missing number: " << ans;