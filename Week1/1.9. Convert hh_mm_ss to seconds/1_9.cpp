//CPP 
#include <bits/stdc++.h> 
using namespace std;

//int main() 
//{ 
//    string time_string;
//    cin >> time_string;
//    regex time_string_regex("^([0-1][0-9]|[2][0-3]):([0-5][0-9]):([0-5][0-9])$");
//    if(!regex_match(time_string,time_string_regex)) {
//        cout << "INCORRECT";
//    } else {
//        smatch matches;
//        regex_match(time_string, matches, time_string_regex);
//
// 			//Chuyen doi tu dang chuoi sang dang int de luu tru
//        int hour = stoi(matches[1]);
//        int minute = stoi(matches[2]);
//        int second = stoi(matches[3]);
//
//        int seconds = hour * 3600 + minute * 60 + second;
//
//
//        cout << seconds     ;
//    }
//}

int main() {
    string time_string;
    cin >> time_string;

    // Kiem tra dinh dang date
    if (time_string.size() != 8 || time_string[2] != ':' || time_string[5] != ':') {
        cout << "INCORRECT" << endl;
        return 0;
    }

    int hour, minute, second;
    char colon;
    
    istringstream ss(time_string); //Ham phan tach gio
    ss >> hour >> colon >> minute >> colon >> second;

    if (ss.fail() || colon != ':') {
        cout << "INCORRECT" << endl;
        return 0;
    }

    // Kiem tra gia tri hop le cua date
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
        cout << "INCORRECT" << endl;
        return 0;
    }
	int seconds = hour * 3600 + minute * 60 + second;
	cout << seconds;
    return 0;
}


