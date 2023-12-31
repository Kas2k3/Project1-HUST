#include<bits/stdc++.h>
using namespace std;

int findmax(int a[], int l, int r) {
    int max = a[l];
    for(int i = l+1 ; i < r+1; i++) 
        if(a[i] > max) max = a[i];
    return max;
}

int findmin(int a[], int l, int r) {
    int min = a[l]; 
    for(int i =l+1 ; i < r+1; i++) 
        if(a[i] < min) min = a[i];
    return min;
}

int sum(int a[], int n) {
    int sum = 0;
    for(int i = 0;i < n; i++) 
    sum += a[i];
    return sum;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<string> input;
    string tmp;
    while(1) {
        getline(cin, tmp);
        if(tmp=="*") continue;
        if(tmp=="***") break; 
        input.push_back(tmp);
    }
    //Vong lap for each duyet qua cac phan tu trong vector input 
    //auto la tu dong xac dinh kieu du lieu cua bien
	//tmp1 de duyet qua phan tu trong vector, luu gia tri phan tu hien tai 
    for(auto tmp1:input) {
        if(tmp1=="find-max") cout << findmax(a, 0, n-1) << endl;
        //a duoc hieu la con tro den phan tu dau tien cua mang a
		//Ham find co the truy cap den cac phan tu trong mang thong qua con tro a  
        else if(tmp1=="find-min") cout << findmin(a, 0, n-1) <<endl;
        else if(tmp1=="sum") cout<<sum(a,n)<<endl; 
        //Lay 1 phan cua chuoi tmp1 tu vi tri 0-15 so sanh voi chuoi find-max-segment
        else if(tmp1.substr(0,16)=="find-max-segment"){
            int i, j;
            string str = tmp1.substr(17);//lay phan con lai cua tmp1 o vi tri 17 den het  
            istringstream iss(str);//chuyen doi chuoi "i j" thanh so nguyen 
            iss >> i >> j;
            cout << findmax(a, i-1, j-1) <<endl;
        }
    }
}

