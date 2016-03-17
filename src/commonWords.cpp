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

int isWordExist(char *str, char *word, int wordLen) {
	if (*str == '\0' || *word == '\0' || wordLen == 0) {
		return 0;
	}
	int i = 0, j = 0;
	while (str[i] != '\0' && word[j] != '\0') {
		if (word[j] == str[i]) {
			j++;
		}
		else{
			j = 0;
		}
		i++;
	}
	if (j == wordLen && (str[i] == ' ' || str[i] == '\0')) {
		return 1; // word exists
	}
	return 0;
}

void addWordToResult(char **result, char *word, int wordLen, int r) {
	for (int c = 0; c < wordLen; c++) {
		result[r][c] = word[c];
	}
	result[r][wordLen] = '\0';
}

char ** commonWords(char *str1, char *str2) {
	if (!str1 || !str2) {
		return NULL;
	}
	char **result = (char**)malloc(sizeof(char*) * 10); // max common words 10
	for (int i = 0; i < 10; i++) {
		result[i] = (char*)malloc(SIZE);
	}
	int r = 0;
	char *word = (char*)malloc(SIZE);
	*word = NULL;
	int i = 0, j = 0;
	while (str1[i] != '\0') {
		if (str1[i] != ' ') {
			word[j] = str1[i];
			j++;
			word[j] = '\0';
		}
		else {
			// if space, compare word			
			if (isWordExist(str2, word, j)) {
				addWordToResult(result, word, j, r); // j = length of word, r = row
				r++;
			}
			j = 0;
		}
		i++;
	}
	// last word
	if (isWordExist(str2, word, j)) {
		addWordToResult(result, word, j, r); // j = length of word, r = row
		r++;
	}
	if (r == 0) {
		return NULL; // No common words
	}
	result[r] = NULL; // make remaining rows null
	return result;
}
