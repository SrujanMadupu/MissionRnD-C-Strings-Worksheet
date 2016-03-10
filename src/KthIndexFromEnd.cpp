/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
int findlen(char*);
char KthIndexFromEnd(char *str, int k) {
	int i,len;
	if (str == '\0' || k<0 || str == "")
		return '\0';
	len = findlen(str);
	if (k>len)
		return '\0';
	char temp = str[len - (k + 1)];
	return(temp);
}
int findlen(char *p){
	int len = 0;
	while (*p != '\0'){
		len++;
		p++;
	}
	return len;
}
