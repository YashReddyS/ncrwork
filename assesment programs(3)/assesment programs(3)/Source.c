#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>

int expand(char *, char *);

int main()
{
	char shorthand_string[50];//shorthand string
	char expanded_string[50];//Expanded string

	while (1) {
		printf_s("Enter shorthand notation:");
		gets(shorthand_string);
		if(expand(shorthand_string,expanded_string)) {
			printf_s("Expanded string:%s\n", expanded_string);
		}
		else {
			printf_s("Enter a valid string\n");
		}
		printf_s("Press 'Y' to continue, 'N' to exit:");
		char choise = getchar();
		getchar();
		if ('n' == choise)
			exit(0);
		else if ('y' == choise)
			system("cls");
		
	}

}

int expand(char *shorthand_string,char *expanded_string) {

	if (shorthand_string[0] == '-' || shorthand_string[strlen(shorthand_string) - 1] == '-')
		return 0;

	int i = 0;
	char temp;
	while (shorthand_string[i] != '\0') {
		if (shorthand_string[i] == '-' && shorthand_string[i + 1] == '-') {
			i++;
			continue;
		}
		else if (shorthand_string[i] != '-'  &&  shorthand_string[i + 1] == '-') {
			temp = shorthand_string[i];
		}
		else if (shorthand_string[i] == '-' && shorthand_string[i + 1] != '-') {
			if (!are_valid_chars(temp, shorthand_string[i + 1]))
				return 0;
			for (char itr = temp; itr < shorthand_string[i + 1] ; itr++) {
				*expanded_string++ = itr;
			}
		}
		else
			*expanded_string++ = shorthand_string[i];
		i++;
	}
	*expanded_string = '\0';
	return 1;
}

int are_valid_chars(char ch1, char ch2) {

	if (((isdigit(ch1) && isdigit(ch2)) || (isupper(ch1) && isupper(ch2)) || (islower(ch1) && islower(ch2))) && (ch1 <= ch2))
		return 1;
	return 0;

}