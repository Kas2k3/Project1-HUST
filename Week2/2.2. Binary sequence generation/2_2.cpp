//C++ 
#include <iostream> 
using namespace std;

int n;
int a[1000];

void Binary(int a[], int n) {
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        a[k] = i;
        if(k == n) Binary(a, n);
        else Try(k + 1);
    }
}

int main() 
{ 
cin>>n;
Try(1);
}
