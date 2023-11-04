//C++ 
#include <iostream> 
using namespace std;

int n;
int a[1000];

//Ham kiem tra de loai bo TH hai so 1 canh nhau
bool Check(int i, int k) {
    if(a[k-1]+i >= 2) return false;
    return true;
}

void Binary(int a[], int n) {
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        if(Check(i, k)) {
            a[k] = i;
            if(k == n) Binary(a, n);
            else Try(k + 1);
            }
        }
    }

int main() 
{ 
cin>>n;
a[0] = 0;
Try(1);
}
