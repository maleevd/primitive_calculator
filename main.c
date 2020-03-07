/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.c"

double parse(double a, char f, double b);
void format_print(double r);

int main()
{
	char digit[15];
	char c, f;
	int i;
	double a, b, r;
	
	a = b = r = 0;
	for(i = 0; i < 15; ++i) digit[i] = 0;
	i = 0;
	printf(INFO1 INFO2);
start:
	c = getchar();
	if (c == '\n') goto parse_input;
	else if (c >= '0' && c <= '9'){
		digit[i] = c;
		++i;}
	else if (c == '.' || c == ','){
		digit[i] = '.';
		++i;}
	else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%'){
		f = c;
		a += strtod(digit, NULL);
		for(i = 0; i < 15; ++i) digit[i] = 0;
		i = 0;}
	if (i > 15){
	printf(ERR1);
	goto end;} 
goto start;
parse_input:
if(i > 0){
	b = strtod(digit, NULL);
	r = parse(a, f, b);
	a = r;
	format_print(r);
	for(i = 0; i < 15; ++i) digit[i] = 0;
	i = 0;
	goto start;}
end:
return 0;}
