#include<stdio.h>

struct date {
	int day;
	int month;
	int year;
};

void main() {

	

	struct date d1;
	struct date d2;


	scanf_s("%d",&d1.day);
	scanf_s("%d",&d1.month);
	scanf_s("%d",&d1.year);

	scanf_s("%d",&d2.day);
	scanf_s("%d",&d2.month);
	scanf_s("%d",&d2.year);

	if(isgreat(d1,d2)){
		int ydef = d1.year - d2.year;

		int mdef;
		if ((d1.month - d2.month )<0) {
			mdef = 12 - d1.month - d2.month;
		}
		else
			mdef = d1.month - d2.month;

		int ddef;
		if ((d1.day - d2.day) < 0) {
			mdef = 31 - d1.day - d2.day;
		}
		else
			mdef = d1.month - d2.month;;



	}


		

	getchar();
}

int isgreat(struct date d1, struct date d2) {

	if (d1.year > d2.year)
		return 1;
	else if (d1.year < d2.year)
		return -1;
	else {
		if (d1.month > d2.month)
			return 1;
		else if (d1.month < d2.month)
			return -1;
		else {
			if (d1.day > d2.day)
				return 1;
			else if (d1.day < d2.day)
				return -1;
			else
				return 0;
		}
	
	}

}