#include<stdio.h>

/* 漂亮代码的示例通常都是一些良性有界且易于理解的问题的局部解*/
/* match: find regexp in text */
int match(char *regexp, char *text) {

	if (regexp[0] == '^') 
		return matchere(regexp, text);

	do { /* check even if string is none*/
	    if (matchhere(regexp, text))
			return 1
	} while(*text != '\0');

	return 0;
}

/* matchhere: find regexp in begin of text */
int matchhere(char *regexp, char *text) {
	
	if (regexp[0] == '\0')
		return 1;
	if (regexp[1] == '*') 
		return matchstar(regexp[0], regexp+2, text);
	if (regexp[0] == '$' && regexp[1] == '\0')
		return *text == '\0';
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return matchhere(regexp+1, text+1)
	return 0
}

/* matchstar: find C*regexp in begin of text */
int matchstar(int c, char *regexp, char *text) {

	do{ /* (*: char >= 0) */
		if (matchhere(regexp, text))
			return 1;
	} while(*text != '\0' && (*text++ == c || cc == '.'));
	return 0;
}

int main() {
	char *text = "I am a student!"
	int flag = match("*^stu.*", text);
	printf("%d", flag);
	return 0;
}
