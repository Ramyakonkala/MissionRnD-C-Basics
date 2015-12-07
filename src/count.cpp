/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).

INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	int c = 0;
	int greaterNum = num2;
	int lesserNum = num1;
//	if (num1 > num2){
	//	greaterNum = num1;
	//	lesserNum = num2;
	//}
	if (greaterNum == 0){
		return 0;
	}
	if (lesserNum == 0){
		return -1;
	}
	if (lesserNum == 1){
		return greaterNum;
	}
	for (int i = greaterNum; i > 1; i--){
		if (i % lesserNum == 0){
			c++;
		}
	}
	return c;
}