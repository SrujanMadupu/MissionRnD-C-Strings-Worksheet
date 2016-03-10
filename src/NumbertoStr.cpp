/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void reversestr(char *rev, int l, int start);
int powerof(int x, int y);
int updatestr(char *str, int num, int i);
void number_to_str(float number, char *str,int afterdecimal){
	int i = 0,start,len=0;
	int intpart = (int)number;
	int floatpart = (number - (float)intpart)*powerof(10, afterdecimal);
	if (intpart < 0){
		str[i] = '-';
		intpart = -1 * intpart;
		floatpart = -1 * floatpart;
		i++;
	}
	start = i;
	i = updatestr(str, intpart, i);
	str[i] = '\0';
	reversestr(str, start, i - 1);
	if (afterdecimal > 0){
		str[i] = '.';
		i++;
		start = i;
		i = updatestr(str, floatpart, i);
		str[i] = '\0';
		reversestr(str, start, i-1);
	}
}
int powerof(int x, int y){
	int pow = x;
	while (y > 1){
		pow = pow*x;
		y--;
	}
	return pow;
}
void reversestr(char *rev, int start, int end){
	int i = start;
	int j = end ;
	while (i < j){
		char ch = rev[i];
		rev[i] = rev[j];
		rev[j] = ch;
		i++;
		j--;
	}
}
int updatestr(char *str, int num, int i){
	int m = i;
	while (num > 0){
		int r = num % 10;
		str[m] = r + 48;
		m++;
		num = num / 10;
	}
	return m;
}

