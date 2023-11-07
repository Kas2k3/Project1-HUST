//C++
#include <iostream>
#include <string>

using namespace std;
int main() {
	string s1,s2,s3;
	//Doc vao chuoi s1, s2, s3
	getline(cin,s1);
	getline(cin,s2);
	getline(cin,s3);

	//Neu s1 ton tai trong s3 thi thay the
	while(s3.find(s1) != string::npos){
		s3.replace(s3.find(s1), s1.length(), s2);
	}
  	cout << s3 << endl;
}

