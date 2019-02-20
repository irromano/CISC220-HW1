/*
 * Ian Romano, Kyle Sapia
 * TA: Daniel Gaston
 * 2/15/19
 *
 * Lab1a.cpp
 * This file contains the problem functions for lab1. Most of the functions are not releated to each other. It also
 * contains test fucntions which contain the '_Test#' annotation in their definition.
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

void printStars();
bool isPrime(int num);
void add();
int totalTerms();
void multiply(int num);
void multiplyAllNumbers();
int collatz();
void leapYearPrint();
void printXofStars(int len);
void collatzPair(int firstNum, int secondNum);
int collatzHelper(int num);

/* The main function for Lab 1. Prints "Hello World!" to the console and executes test cases as per the assignment.
 * Parameters -
 *		None
 * Returns -
 * 		int 0
 */
int main() {
	cout << "Problem 1" << endl;
	cout << "Hello, world!" << endl;
	printStars();				//divider
	cout << "Problem 3" << endl;
	cout << isPrime(7) << endl; // '1' is expected.
	cout << isPrime(9) << endl; // '0' is expected.
	cout << isPrime(-1) << endl; // '0' is expected.
	cout << isPrime(0) << endl; // '0' is expected.
	printStars();
	cout << "Problem 4:" << endl;
	add(); //Expecting 45150
	printStars();
	cout << "Problem 5" << endl;
	cout << totalTerms() << endl; // '447' is expected.
	printStars();
	cout << "Problem 6:" << endl;
	multiply(-2); //Expecting multiplication table of 2 from 1-12
	multiply(0); //Expecting multiplication table of 3 from 1-12
	multiply(4); //Expecting multiplication table of 4 from 1-12
	printStars();
	cout << "Problem 7:" << endl;
	multiplyAllNumbers(); //Expecting multiplication table of all numbers from 1-12 from 1-12
	printStars();
	cout << "Problem 8" << endl;
	collatz();			// prompt for an integer. Prints the number of terms for the Collatz Conjecture to return to 1.
	printStars();
	cout << "Problem 9" << endl;
	leapYearPrint();	//print out all leap years from 2017 to 2417
	printStars();
	cout << "Problem 10" << endl;
	printXofStars(4); // An 'x' with length 5 is expected
	printXofStars(5); // An 'x' with length 5 is expected
	printXofStars(7); // An 'x' with length 7 is expected
	printStars();
	cout << "Problem 11" << endl;
	collatzPair(3, 7);	//Analyzes integers 4, 5, 6 with the Collatz Conjecture. Prints out "Collatz Conjecture is still working" if the iteration ends.
	return 0;
}
/* Problem 2
 * This function prints out a string of stars to the console. It's useful for seperating testcases on the console.
 Parameters - None
 Returns - None*/
void printStars() {
	cout
			<< "******************************************************************************************"
			<< endl;
}
/* Problem 3
 * This function takes an integer variable and tests if its prime. It accomplishes this by taking a module of
 the integer by every integer between 1 and the parameter integer.
 Parameters -
 num (int): An integer that could be a prime number.
 Returns -
 bool: True if num is a prime number. False otherwise.
 */
bool isPrime(int num) {
	if (num < 1)		// Return false if input is negative or zero.
		return false;
	int divisor = num - 1;
	while (divisor > 1) {
		if (num % divisor == 0)	// return false if the parameter num is divisible by a number between 1 and itself.
			return false;
		divisor--;
	}
	return true;// Return true if the parameter num is not divisible by any number between 1 and itself.
}

/*
 * Problem 4
 * This function calculates the sum of all numbers from 1 to 300 and shows the
 running total after every 20 terms.
 * Parameters: None.
 * Returns: None.
 */
void add() {
	int a = 0;
	int sum = 0;
	while (a <= 300) {
		sum = sum + a;
		if (a % 20 == 0) {
			cout << sum << endl;
		}
		a++;
	}
//cout << sum << endl;
}

/* Problem 5
 * This function returns the amount of terms it requires to create a sum which exceeds 10,000. It
 accomplishes this with a while loop.
 Parameters - None
 Returns - int terms: Number of terms required to exceed 100,000*/
int totalTerms() {
	int nextNum = 1;
	int sum = 0;
	while (sum < 100000) {
		sum += nextNum;
		nextNum++;
	}
	return nextNum - 1;
}

/*
 * Problem 6
 * This function takes an integer and prints the multiplication table for this number
 from 1-12.
 * Parameters: An integer.
 * Returns: None.
 */
void multiply(int num) {
	cout << "Multiplication Table for " << num << endl;
	int mult;
	for (int i = 1; i < 13; i++) {
		mult = num * i;
		cout <<'x' << i << " | " << mult << endl;
	}
}
/*
 * Problem 7
 * This function increments from 1 to 12 and prints a multiplication table for each of
 these numbers from 1-12.
 * Parameters: None.
 * Returns: None.
 */
void multiplyAllNumbers() {
	for (int i=1; i < 13; i++)
		multiply(i);
}

/* Problem 8
 * This function asks for a positive number from the user and returns the amount of Collatz Conjecture cycles to
 transform the number into 1.
 Parameters - None
 Returns - int terms*/

int collatz() {
	int num;
	int counter = 0;
	cout << "Type in a number" << endl;
	cin >> num;
	while (num > 1) {
		if (num % 2 == 0) {
			num /= 2;
			counter++;
		} else {
			num = num * 3 + 1;
			counter++;
		}
	}
	cout << counter << endl;
	return counter;
}

/* Problem 9
 * This function prints out all the leap years from 2017 to 2417
 Parameters - None
 Returns - None*/
void leapYearPrint() {
	for (int currentYear = 2017; currentYear < 2417; currentYear++) {
		if (currentYear % 4 != 0) //Skip to next loop if currentYear is not a leap-year.
			continue;
		if (currentYear % 100 == 0 && currentYear % 400 != 0) //Skip to next loop if currentYear is not a leap-year.
			continue;
		cout << currentYear << endl;
	}
}
/* Problem 10
 * This function prints an 'x' symbol of stars. The length of each leg will consist of 'len' amount of stars, where len is the parameter.
 If len is an even number, the length is rounded up to the next odd number.
 Parameters -
 len (int): Determins the length of the 'x' printout.
 Returns - Nothing*/
void printXofStars(int len) {
	if (len % 2 == 0)
		len++;
	for (int i = 0; i < len - 1; i++) {	//print top-half of 'x'
		for (int j = i; j > 0; j--)		//print spaces before row
			cout << ' ';
		cout << '*';				//print first * of row
		for (int j = 2 * (len - i - 1) - 1; j > 0; j--)	//print spaces between *s
			cout << ' ';
		cout << '*' << endl;		//print second * of row
	}
	for (int i = 0; i < len - 1; i++)	//print len -1 spaces before middle *
		cout << ' ';
	cout << '*' << endl;			//print middle *
	for (int i = 0; i < len - 1; i++) {	//print bottom-half of 'x'
		for (int j = i; j < len - 2; j++)	//print spaces before row
			cout << ' ';
		cout << '*';				//print first * of row
		for (int j = 0; j < 2 * i + 1; j++)	//print spaces between *s of row
			cout << ' ';
		cout << '*' << endl;		//print second * of row
	}
}

/* Problem 11
 * This function takes in two integers and analyzes all numbers between them. It then calls the collatzHelper() function
 for every value between the original numbers. It will print a statement when the function concludes.
 Parameters -
 firstNum (int)
 secondNum (int)
 Returns -
 Nothing*/
void collatzPair(int firstNum, int secondNum) {
	for (int num = firstNum + 1; num < secondNum; num++) {
		collatzHelper(num);
	}
}
/*This function is a helper function used by the collatzPair function to compute the Collatz Conjecture
 for a given number. It should not be used directly.
 Parameters -
 num (int) - The number that will be analyzed with the Callatz Conjecture.
 Returns -
 counter (int) - Number of terms the collatz conjecture went through before arriving at 1.*/
int collatzHelper(int num) {
	int counter = 0;
	cout << num << endl;
	while (num > 1) {
		if (num % 2 == 0) {
			num /= 2;
			counter++;
		} else {
			num = num * 3 + 1;
			counter++;
		}
	}
	cout << "Collatz Conjecture is still working" << endl;
	return counter;
}
