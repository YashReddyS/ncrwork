#include<iostream>

using namespace std;

class String {

	char *sptr;
	int len;

public:
	String() {
		sptr = NULL;
		len = 0;
	}

	String(const char *c) {
		
		len = strlen(c);
		sptr = new char[len + 1];
		strcpy_s(sptr, len + 1, c);
	}

	String(String &s) {

		
		len = s.len;
		sptr = new char[len + 1];
		strcpy_s(sptr, len + 1, s.sptr);


	}

	String operator=(String temp) {
		String res;
		sptr = new char[temp.len + 1];
		strcpy_s(sptr, temp.len + 1, temp.sptr);
		len = temp.len;
		return(*this);
	}

	String operator=(const char *c) {
		String res;
		
		res.sptr = new char[strlen(c) + 1];
		strcpy_s(res.sptr, strlen(c) + 1, c);
		res.len = strlen(c) + 1;
		return(res);
	}

	String operator+(String& s2) {
		String s3;

		// Use strcat() to concat two specified string 
		strcat(this->sptr, s2.sptr);

		// Copy the string to string to be return 
		strcpy(s3.sptr, this->sptr);

		// return the object 
		return s3;
	}

	char& operator[](int n) {
		return sptr[n];
	}

	String operator,(String c)
	{
		return c;
	}
	String* operator->()
	{
		return  this;
	}

	friend istream& operator>>(istream &, String &);
	friend ostream& operator<<(ostream &, String);

};

istream& operator>>(istream &cin, String &s) {

	s.sptr = new char[20];
	cin >> s.sptr;
	s.len = strlen(s.sptr);
	return cin;

}


ostream& operator<<(ostream &cout, String s) {

	cout << s.sptr << endl;
	cout << s.len;
	return cout;

}

int main() {

	String s1("yashwanth");
	cout << s1 << endl;
	String s2(s1);
	cout << s2 << endl;
	String s3 = " reddy";
	cout << s3 << endl;
	String s4 = s1 + s3 ;
	cout << s4;
	cout << s1[1];
	


	getchar();
	return 0;
}