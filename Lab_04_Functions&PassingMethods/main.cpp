#include <iostream>
using std::cout;


// Function to calculate the sum of the all the student scores
// This function uses constant reference parameters to avoid copying the array and size
// This function takes 2 parameters:
// 1. A constant reference to an array of integers representing student scores
// 2. A constant reference to an integer representing the size of the array
int calculateSum (const int(&scores)[5], const int& size) {
	// Here I declare a variable to hold the sum of scores
	// I intialize it to 0
	int sum = 0;

	// I then use a classic for loop to iterate through the array and add each score to the sum variable
	for (int i = 0; i < size; ++i) {
		sum += scores[i];
	}

	// I then return the final sum
	return sum;
}


int main() {

	// Constant variable for array size
	int const SIZE = 5;

	// Array holding all student scores
	int scores[SIZE] = { 65, 82, 90, 45, 78 };

	// Calculate the sum of all student scores
	int totalScore = calculateSum(scores, SIZE);

	// Output the total score
	cout << "Total Score of all students: " << totalScore << "\n";


	return 0;
}