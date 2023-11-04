#include <iostream>
using namespace std;

#define M 1000000007
long a[501][1000];
long C(int k,int n) {
	if(k==0 || k==n) return 1;
    //Neu a[k][n] chua duoc tinh => de quy
    //Su dung chia lay du tranh tran so
	if(a[k][n]==0) {
		a[k][n]=C(k-1,n-1)+C(k,n-1);
		a[k][n]%=M;
	}
	return a[k][n];
}

int main() {
	int k,n;
	cin>>k>>n;
	cout<<C(k,n);
    return 0;
}
