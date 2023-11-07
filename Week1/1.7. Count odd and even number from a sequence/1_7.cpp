//CPP 
#include <bits/stdc++.h> 
using namespace std;

int main() 
{ 
    int n  ;
    int a = 0;
    cin >> n;
    int b[n];
    for(int i = 0; i < n ; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        if(b[i] % 2 != 0) a++;
    }
    cout << a << " " << (n-a);
    
}

