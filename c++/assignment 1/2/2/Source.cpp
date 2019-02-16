#include<iostream>

using namespace std;



class student {
public:
	char studentName[20];
	int grade;
	float sub[3];
	float avg;

public:

	void set_data(const char *str, int gr, float a, float b, float c) {
		strcpy_s(studentName,strlen(str)+1, str);
		sub[0] = a;
		sub[1] = b;
		sub[2] = c;
		grade = gr;
	}

	void calculateAverage() {

		avg = (sub[0] + sub[1] + sub[2]) / 3;

	}

	void computeGrade() {

		if (avg >= 60)
			grade = 1;
		else if (avg >= 50 && avg < 60)
			grade = 2;
		else if (avg >= 40 && avg < 50)
			grade = 3;
		else
			grade = -1;

		
	}

	void display() {
	
		cout <<"student name : "<< studentName<<endl;
		cout <<"subject 1 marks : "<< sub[0] << endl;
		cout <<"subject 2 marks : " << sub[1] << endl;
		cout <<"subject 3 marks : " << sub[2] << endl;
		switch (grade) {
		case 1: cout << "Grade : " << "first class"; break;
		case 2: cout << "Grade : " << "second class"; break;
		case 3: cout << "Grade : " << "third class"; break;
		case -1: cout << "Grade : " << "fail";
		}
		cout << endl;

	}
};


int main(){

	
	student s[2];
	s[0].set_data("yashwanth", 0, 50, 60, 40);
	s[1].set_data("trivikam", 0, 100, 96, 88);

	for (int i = 0; i < 2; i++) {
		s[i].calculateAverage();
		s[i].computeGrade();
		s[i].display();
	}


	getchar();
	return 0;
}