//C/C++ 
#include <bits/stdc++.h> 
using namespace std;

double giadiencu(int n){
    if (n <= 50)
        return 1728*n;
    else if (n <= 100)
        return 1728*50 + (n-50)*1786;
    else if (n <= 200)
        return 1728*50 + 1786*50 +(n-100)*2074;
    else if (n <= 300)
        return 1728*50 + 1786*50 + 2074*100 + (n-200)*2612;
    else if (n <= 400)
        return 1728*50 + 1786*50 + 2074*100 + 100*2612 + (n-300)*2919;
    else return 1728*50 + 1786*50 + 2074*100 + 100*2612 + 100*2919 + (n-400)*3015;
}

double giadienmoi(int n){
    if (n <= 100)
        return 1728*n;
    else if (n <= 200)
        return 1728*100 + (n-100)*2074;
    else if (n <= 400)
        return 1728*100 + 2074*100 +(n-200)*2612;
    else if (n <= 700)
        return 1728*100 + 2074*100 + 2612*200 + (n-400)*3111;
    else return 1728*100 + 2074*100 + 2612*200 + 300*3111 + (n-700)*3457;
}
    
int main() {
    int n;
    cin>>n;
    double giacu = giadiencu(n);
    double giamoi = giadienmoi(n);
    
    giacu += giacu*0.1;
    giamoi += giamoi*0.1;
    
    double chenhlech = giamoi - giacu;
    //co dinh 2 chu so thap phan sau dau phay
    cout<< fixed << setprecision(2) << chenhlech << endl; 
    return 0;
}

