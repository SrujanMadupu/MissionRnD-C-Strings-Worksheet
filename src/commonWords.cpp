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

char ** commonWords(char *str1, char *str2) {
	if (str1 != '\0'&&str2 != '\0'){
		int i=0, j=0,k=0,l=0,m=0,n=0;
		char wordpool[20][SIZE] = {NULL};
		char **commonwords[10][SIZE];
		int len1 = stringlen(str1);
		int len2 = stringlen(str2);
		char *word1 = (char*)malloc(sizeof(char) * SIZE);
		while (i<=len1){
			
			if (str1[i] != ' '||str1[i]!='\0'){
				word1[k] = str1[i];
				k++;
			}
			else{
				word1[k] = '\0';
				wordpool[m][SIZE] = *word1;
				free(word1);
				word1 = (char*)malloc(sizeof(char)*SIZE);
				k = 0;
				m = m + 2;;
			}
			i++;
		}
		free(word1);
		char *word2 = (char*)malloc(sizeof(char) * SIZE);
		while (j<=len2){
		
			if (str2[j] != ' '||str2[j] != '\0'){
				word2[l] = str2[j];
				l++;
			}
			else{
				word2[l] = '\0';
				int i;
				for (i = 0; i < 20; i=i+2){
					if (*word2 == wordpool[i][SIZE]){
						wordpool[i + 1][SIZE] = *word2;
						free(word2);
						l = 0;
						word2 = (char*)malloc(sizeof(char)*SIZE);
						break;
					}
				}
			}
			j++;
		}
		free(word2);
		for (int i = 0; i < 20; i = i + 2){
			if (wordpool[i][SIZE] != NULL&&wordpool[i + 1][SIZE] != NULL){
				char *temp = (char*)malloc(sizeof(char) * 10);
			     temp = wordpool[i];
				*commonwords[n][SIZE] = (char*)malloc(sizeof(char) * SIZE);
				*commonwords[n][SIZE] = temp;
				n++;
			}
			
		}
		if (n == 0){
			return NULL;
		}
		else{
			return **commonwords;
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