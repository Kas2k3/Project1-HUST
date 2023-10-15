#include <iostream>
#include <string>
using namespace std;

int main() {
    string date;
    cin >> date;

    // Kiem tra dinh dang cua date
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int year, month, day;
    //Ham sscanf de phan tich chuoi
    //Phan tich bi sai hoac khong du 3 thanh phan thi INCORRECT
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    // Ham kiem tra gia tri hop le cua date
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        cout << "INCORRECT" << endl;
        return 0;
    }

    cout << year << " " << month << " " << day << endl;

    return 0;
}

