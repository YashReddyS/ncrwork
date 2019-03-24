#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 200

int expand(char *, char *);

int main()
{
	while (1) {

		char *shorthand_string; //shorthand string
		char expanded_string[MAX_LENGTH]; //Expanded string

		

		shorthand_string = (char *)malloc(100* sizeof(char));
		getchar();
		printf_s("Enter shorthand notation:");
		gets(shorthand_string);

		if(expand(shorthand_string,expanded_string)) {
			printf_s("Expanded string:%s\n", expanded_string);
		}
		else 
			printf_s("Enter a valid string\n");

		//memory deallocation
		free(shorthand_string);
		
		printf_s("Press 'E' to exit,any other key to continue:");
		char choise = getchar();
		if ('e' == choise)
			exit(0);
		system("cls");	
	}

}

//return 0 if invalid shorthand string is else 1 is returned and
//Expands shorthand string and puts into expanded string 
int expand(char *shorthand_string,char *expanded_string) {

	if (shorthand_string[0] == '-' || shorthand_string[strlen(shorthand_string) - 1] == '-')
		return 0;

	int itr = 0;
	char temp;
	while (shorthand_string[itr] != '\0') {

		//continue if -- occurs
		if (shorthand_string[itr] == '-' && shorthand_string[itr + 1] == '-') {
			itr++;
			continue;
		}

		//at char followed buy - eg for 1212--- at 2- store 2 in temp
		else if (shorthand_string[itr] != '-'  &&  shorthand_string[itr + 1] == '-') {
			temp = shorthand_string[itr];
		}

		//at - followed a char eg for ---221 at -2 , validate temp and 2
		//if valid expand from temp to 2
		else if (shorthand_string[itr] == '-' && shorthand_string[itr + 1] != '-') {
			if (!are_valid_chars(temp, shorthand_string[itr + 1]))
				return 0;

			//expansion between chars to exanded string
			for (char itr2 = temp; itr2 < shorthand_string[itr + 1] ; itr2++) {
				*expanded_string++ = itr2;
			}
		}
		//put char into expanded string
		else
			*expanded_string++ = shorthand_string[itr];
		itr++;
	}
	*expanded_string = '\0';

	return 1;
}

// are valid if both are of same type ie both int,upper or lower character and 
//1st charecter less than 2nd charecter
int are_valid_chars(char ch1, char ch2) {

	if (((isdigit(ch1) && isdigit(ch2)) || 
		(isupper(ch1) && isupper(ch2)) || 
		(islower(ch1) && islower(ch2)))
		
		&&
		
		(ch1 <= ch2))
		
		return 1;
	
	return 0;

}