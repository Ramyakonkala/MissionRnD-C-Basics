/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int length(char*);
int check(int, int, int);
int isLeap(int year);
int isOlder(char *dob1, char *dob2) {
	if (length(dob1) != 10 || length(dob2) != 10)
		return -1;
	char year1[] = { dob1[6], dob1[7], dob1[8], dob1[9], '\0' };
	int dayInt1 = dob1[0] - '0';
	dayInt1 *= 10;
	dayInt1 += dob1[1] - '0';
	int monthInt1 = dob1[3] - '0';
	monthInt1 *= 10;
	monthInt1 += dob1[4] - '0';
	int yearInt1 = dob1[6] - '0';
	for (int i = 7; i <= 9; i++) {
		yearInt1 *= 10;
		yearInt1 += dob1[i] - '0';
	}
	char year[] = { dob2[6], dob2[7], dob2[8], dob2[9], '\0' };
	int dayInt = dob2[0] - '0';
	dayInt *= 10;
	dayInt += dob2[1] - '0';
	int monthInt = dob2[3] - '0';
	monthInt *= 10;
	monthInt += dob2[4] - '0';
	int yearInt = dob2[6] - '0';
	for (int i = 7; i <= 9; i++) {
		yearInt *= 10;
		yearInt += dob2[i] - '0';
	}
	if (check(dayInt1, monthInt1, yearInt1) == -1 || !check(dayInt, monthInt, yearInt) == -1)
		return -1;
	int i = 0, count = 0;
	while (dob1[i] != '\0')  {
		if (dob1[i] == dob2[i]) {
			count++;
		}
		i++;
	}
	if (count == 10)
		return 0;
	if (yearInt1 < yearInt)
		return 1;
	else if (yearInt1 > yearInt)
		return 2;
	if (monthInt1 < monthInt)
		return 1;
	else if (monthInt1 > monthInt)
		return 2;
	if (dayInt1 < dayInt)
		return 1;
	else
		return 2;
}
int check(int dayInt, int monthInt, int yearInt) {
	if (monthInt > 12 || monthInt == 0)
		return -1;
	else if (isLeap(yearInt) && monthInt == 2 && dayInt > 29)
		return -1;
	else if (!isLeap(yearInt) && monthInt == 2 && dayInt > 28)
		return -1;
	else if ((monthInt == 8 || monthInt == 10 || monthInt == 12 || monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7) && dayInt > 31)
		return -1;
	else if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30)
		return -1;
	return 1;
}
int isLeap(int year) {
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return 0;
	else if (year % 4 == 0)
		return 1;
	else
		return 0;
}
int length(char* ch) {
	int result = 0;
	while (ch[result] != '\0')
		result++;
	return result;
}