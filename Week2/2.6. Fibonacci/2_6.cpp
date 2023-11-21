//C++ 
#include <bits/stdc++.h> 
using namespace std;
int a[1000];
int n;
int fibonacci(int a[], int n) {
    if( n ==0) {
        a[n] = 0;
        
    }
    if(n  == 1) {
        a[n] = 1;
      
    }

    //Ham de quy tinh toan fibonacci voi so >= 2
    if(n >= 2) {
        a[n] = fibonacci(a,n-1) + fibonacci(a,n-2);
        
    }
    return a[n];
}
int main() 
{ 
    cin >> n;
    //Tinh fibonacci(a, n-1)
    cout << fibonacci(a,n) - fibonacci(a,n-2);

}
