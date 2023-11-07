//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

int cal(int n){
    if (n >= 1 && n <= 999){
        for(int i = 100; i < 1000; i++){
            if (i%n == 0){
            cout<< i << " ";
            }
        }
    }
    return 0;
}

int main() 
{ 
int n;
cin >> n;
cal(n);
}

