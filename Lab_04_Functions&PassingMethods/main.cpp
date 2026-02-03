#include <iostream>
using std::cout;


// Function to calculate the sum of the all the student scores
// This function uses constant reference parameters to avoid copying the array and size
// This function takes 2 parameters:
// 1. A constant reference to an array of integers representing student scores
// 2. A constant reference to an integer representing the size of the array
static int calculateSum (const int(&scores)[5], const int& size) {
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

// Function to calculate the average score from all the student's scores
// This function will use the direct values of total score and size
// This function takes 2 parameters:
// 1. An integer representing the total score of all students
// 2. An integer representing the size of the array
static double getAverage(int sum, int size) {
	// Here I calculate the average by dividing the total score by the size
	// I use static_cast to ensure the division is done in double precision
	return static_cast<double>(sum) / size;
}

// Function to add bonus points to each student's score
// This function will use a pointer to the array to modify the original scores
// This function takes 3 parameters:
// 1. A pointer to an array of integers representing student scores
// 2. An integer representing the size of the array
// 3. An integer representing the bonus points to be added
static void addBonus(int(*scores)[5], int size, int bonus) {

	// Check to make sure the pointer is not null
	if (scores == nullptr) return; // If the pointer is null, simply return
	
	// Here I use a classic for loop to iterate through the array and add the bonus points to each score
	for (int i = 0; i < size; ++i) {
		(*scores)[i] += bonus;
	}
}



int main() {

	// Constant variable for array size
	int const SIZE = 5;

	// Array holding all student scores
	int scores[SIZE] = { 65, 82, 90, 45, 78 };

	// Variable for holding the bonus points to be added to each score
	int bonus = 5;

	// Pointer to the scores array
	int (*ptrScores)[SIZE] = &scores;


	// Calculate the sum of all student scores
	int totalScore = calculateSum(scores, SIZE);

	// Then I use the sum that I got from the calculateSum function to get the average score
	int averageScore = getAverage(totalScore, SIZE);

	// Output of all the current scores 
	cout << "Current Scores: ";
	for (int i = 0; i < SIZE; ++i) {
		cout << scores[i] << " ";
	}
	// Function to add bonus points to each student's score
	addBonus(&scores, SIZE, bonus);

	// Output of all the new scores after adding bonus points
	cout << "\nNew Scores after adding bonus points: ";
	for (int i = 0; i < SIZE; ++i) {
		cout << scores[i] << " ";
	}

	





	return 0;
}