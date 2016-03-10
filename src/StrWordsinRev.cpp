/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>
void strreverse(char *p, int start ,int end);
void str_words_in_rev(char *input, int len){
	int i, j;
	for (i = 0, j = 0; i <= len; i++){
		if (input[i] == ' '){
			strreverse(input, j, i - 1);
			while (input[i + 1] == ' '&&input[i + 1] != '\0'){
				i = i + 1;
			}
			j = i + 1;
		}
		else if (input[i] == '\0'){
			strreverse(input, j, i - 1);
		}
	}
	strreverse(input, 0, len - 1);
}
void strreverse(char *p, int start, int end){
	while (start < end){
		char ch = p[start];
		p[start] = p[end];
		p[end] = ch;
		start++;
		end--;
	}
}
