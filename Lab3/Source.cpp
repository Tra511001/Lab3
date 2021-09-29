/*	
*	Nikola Trajanovski
*	C++ Lab 3
*	9/29/2021
*/
#include <iostream>
#include <string>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;

float getMean(int a, int b, int c, int d);
float getDeviation(int a, int b, int c, int d);

int main(){
	// declaring and opening files
	ifstream inMean;
	ofstream outMean;
	inMean.open("C:/Users/nikol/Desktop/inMeanStd.dat");
	outMean.open("C:/Users/nikol/Desktop/outMeanStd.dat");

	// Two if statements to check for errors with files
	if (inMean.fail()) {
		cerr << "error opening file 1";
		exit(1);
	}
	if (outMean.fail()) {
		cerr << "error opening file 2";
		exit(1);
	}

	//all needed variables are set tot zero
	float var1 =0;
	float var2 =0;
	float var3 =0;
	float var4 =0;
	float mean =0;
	float deviation = 0;
	
	
	// Get Info from the user about entering variables
	cout << "Enter your 4 numbers: \t";
	cin >> var1 >> var2 >> var3 >> var4;
	//calculating mean and deviation from getMean(); getDeviation(); methods.*/
	mean = getMean(var1, var2, var3, var4);
	deviation = getDeviation(var1,var2,var3,var4);

	//Output to console and out file for user input
	cout << "The mean is: "<< mean <<  endl;
	cout << "The standard deviation is: " <<setprecision(3)<< deviation << endl;
	outMean << "The mean is: " << mean << endl;
	outMean << "The standard deviation is: " << setprecision(3) << deviation << endl << endl << endl;

	//output to outMean from inMean
	inMean >> var1 >> var2 >> var3 >> var4;
	mean = getMean(var1, var2, var3, var4);
	deviation = getDeviation(var1, var2, var3, var4);
	outMean << "The mean  from file is: " << mean << endl;
	outMean << "The standard deviation from file is: " << setprecision(3) << deviation << endl;

	return 0;
}


float getMean(int a, int b, int c, int d) {
	float mean = 0;

	mean = (a + b + c + d) / 4;

	return mean;
}

float getDeviation(int a, int b, int c, int d ) { 
	// get mean of numbers
	int mean = 0;
	float deviation = 0;
	mean = getMean(a, b, c, d);
	int var1, var2, var3, var4;
	//get deviation
	var1 = a - mean;
	var2 = b - mean;
	var3 = c - mean;
	var4 = d - mean;

	//sum of squares
	deviation = (pow(var1, 2) + pow(var2, 2) + pow(var3 , 2) + pow(var4, 2))/4;
	//square root of sum of squares
	deviation = sqrt(deviation);
		
	return deviation;
}

