#include <iostream>

using namespace std;

class Student {
private:
	int num;
	int score;
public:
	Student():num(7),score(100){}

	void setdata() {
		cin >> num;
		cin >> score;
	}

	void display(){
		cout << "num=" << num << ",score=" << score << endl;
	}
};
