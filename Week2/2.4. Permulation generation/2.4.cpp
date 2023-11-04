//C++ 
#include <iostream> 
using namespace std;

int x[100], mark[100], n;

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void process(int i) {
    if (i > n) {
        print();
        return;
    }
    for (int j = 1; j <= n; j++){
        if(!mark[j]) {
            mark[j] = 1;
            x[i] = j;
            process(i + 1);
            mark[j] = 0;
        }
    }
    
}
int main() 
{ 
cin >> n;
process(1);
return 0;
}

