#include<iostream>

using namespace std;

class matrix{

	int row, col,i,j;
	int **p;

	matrix(int r,int c) {
		row = r;
		col = c;
		p = new int*[r];
		for (i = 0; i < r; i++)
			p[i] = new int[c];

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				p[i][j] = 0;
			}
		}
	}

	void getvalues(){
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				cin >> p[i][j];
			}
		}
	}

	void print() {
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
	}

	friend int main();
	friend matrix matmul(matrix, matrix);
};


int main() {

	int a;
	matrix m1(2,2);
	m1.getvalues();
	m1.print();
	matrix m2(2, 2);
	m2.getvalues();
	m2.print();
	matrix m3 = matmul(m1, m2);
	m3.print();
	cin >> a;
	return 0;
}

matrix matmul(matrix m1, matrix m2) {
	matrix temp(m1.row,m2.col);
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.col; j++) {
			for (int k = 0; k < m2.col; k++)
			temp.p[i][k] = temp.p[i][k] + (m1.p[i][j] * m2.p[j][k]);
		}
	}
	return temp;
}