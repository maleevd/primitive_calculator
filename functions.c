/* functions.c */
#define INFO1 "Введите два числа со знаком операции(например 2+2) и нажмите ENTER.\n"
#define INFO2 "Для выхода оставьте строку пустой и нажмите ENTER.\n"
#define ERR1 "Ошибка, слишком много символов, выход...\n"

double parse(double a, char f, double b){
	double result;
	if (f == '+') result = a + b;
	else if (f == '-') result = a - b;
	else if (f == '*') result = a * b;
	else if (f == '^') result = pow(a, b);
	else if (f == '/' && b != 0) result = a / b;
	else if (f == '/' && b == 0) printf("на ноль не делю.\n");
	else if (f == '%') result = b / 100 * a;
	else printf("ошибка ввода: %c", f);
	return result;}
void format_print(double r){
	int i, k, integer_flag;
	char digit[15];
	for(i = 0; i < 15; ++i) digit[i] = 0;
	k = i = integer_flag = 0;
	sprintf(digit, "%f", r);
	for(i = 15; i >= 0; --i){
		if (k > 0) ++k;
		if (digit[i] > '0' && k == 0) ++k;
		if (digit[i] == '.' && k == 0){
			integer_flag = 1;
			++k;}}
		if (k > 15){
			k = 15;
			printf("Ошибка. Результат содержит более 16 сиволов: \n");}
	if (integer_flag == 1 && k > 0) --k;
	for(i = 0; i < k; ++i) printf("%c", digit[i]);}
