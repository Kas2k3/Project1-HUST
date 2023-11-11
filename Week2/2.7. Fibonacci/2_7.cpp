//C++ 
#include <bits/stdc++.h> 
using namespace std;
int a[1000];
int n;
int fibonal(int a[], int n) {
    if( n ==0) {
        a[n] = 0;
        
    }
    if(n  == 1) {
        a[n] = 1;
      
    }
    if(n >= 2) {
        a[n] = fibonal(a,n-1) + fibonal(a,n-2);
        
    }
    return a[n];
}
int main() 
{ 
    cin >> n;
    cout << fibonal(a,n) - fibonal(a,n-2);

}
