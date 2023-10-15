#include <bits/stdc++.h> 
using namespace std;
int main() {

    int n,k;
    cin >> n >> k; //n la do dai day, k la do dai day con 
	int a[n]; //cac so nguyen ban dau 
	int b[n-k+1]; //tong cac day con co do dai k lien tiep  
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}  
	int count = 0;
	int sum = 0;
	//Tong k phan tu dau tien  
	for(int i = 0; i < k; i++) {
		sum += a[i];
	}
	b[0] = sum;// tong cua day con dau tien  
	//tiep tuc voi phan tu tiep theo den n-k 
	for(int i = 1; i < n-k+1; i++) {
		//b[i] la tong day con moi bat dau tu i do dai k 
		//b[i-1] la tong cua day con truoc do co do dai k 
		//a[i+k-1] la phan tu tai vi tri cuoi cua day con moi 
		//a[i-1] la phan tu tai vi tri cuoi cung cua day con truoc do  
		b[i] = b[i-1] + a[i+k-1] - a[i-1];
	}
	for(int i = 0; i < n-k+1; i++) {
		if(b[i] %2 == 0) count++;
	}
	cout << count;
}

