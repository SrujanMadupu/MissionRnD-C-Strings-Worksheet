/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#define SIZE 31
int stringlen(char *rev);
int checkword(char *p, char *w);

char** commonWords(char *str1, char *str2) {
	if (str1 !=NULL&&str2 != NULL){
		int i=0,j=0,n=0;
		char *commonwords[10];
		char *word = (char*)malloc(sizeof(char)*SIZE);
		word = NULL;
		while (str1[i] != '\0'){
			if ((str1[i]== ' ' || str1[i] == '\0')&&word!=NULL){
				word[j] = '\0';
				if (checkword(str2, word)){
					commonwords[n][10]= (char)malloc(sizeof(char)*SIZE);
					commonwords[n][10] = *word;
					n++;
					j = 0;
					free(word);
					word = (char*)malloc(sizeof(char)*SIZE);
				}
				i++;
			}
			else{
				word[j] = str1[i];
				j++;
				i++;
			}
		}
		if (n == 0){
			return NULL;
		}
		else{
			return commonwords;
		}
	}
	else{
		return NULL;
	}
}
int stringlen(char *rev){
	int len = 0;
	while (*rev != '\0'){
		len++;
		rev++;
	}
	return len;
}
int checkword(char *p, char *w){
	int count = 0, k = 0, j = 0;
	while (p[k] != '\0'){
		if (p[k] == w[j]){
			count++;
			j++;
			k++;
			continue;
		}
		else if (p[k] == ' ' || p[k] == '\0'){
			if (count == stringlen(w)){
				return 1;
			}
			else{
				if (p[k] == '\0'){
					return 0;
				}
				else{
					k++;
					j = 0;
					count = 0;
					continue;
				}
			}
		}

	 }
}