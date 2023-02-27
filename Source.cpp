// Margaret Snyder
// Project 1
// 1/22/23
// 12 and 24 Hour Clock

#include <iostream>
#include <ctime>
using namespace std;

// Print number as 2 Digits
void TwoDigits(int num) {
	if (num < 10) {
		cout << "0" << num;
	}
	else {
		cout << num;
	}
}

// Print line of Stars
void PrintStars() {
	cout << "**************************";
}

// Print time as 24 hours
void Print24Hours(int& hour, int& minute, int& second) {
	TwoDigits(hour);
	cout << ":";
	TwoDigits(minute);
	cout << ":";
	TwoDigits(second);
}

// Print time as 12 hours
void Print12Hours(int& hour, int& minute, int& second) {
	int twelveHour;

	if (hour > 12) {								//  If hour is greater than 12, set time to PM
		twelveHour = hour - 12;
		TwoDigits(twelveHour);
		cout << ":";
		TwoDigits(minute);
		cout << ":";
		TwoDigits(second);
		cout << " PM";
	}
	else if (hour == 12) {							//  If hour is equal to 12, set time to 12 PM
		TwoDigits(hour);
		cout << ":";
		TwoDigits(minute);
		cout << ":";
		TwoDigits(second);
		cout << " PM";
	}
	else if (hour == 0) {							// If hour is equal to 0, set time to 12 AM
		twelveHour = 12;
		TwoDigits(twelveHour);
		cout << ":";
		TwoDigits(minute);
		cout << ":";
		TwoDigits(second);
		cout << " AM";
	}
	else {											// Otherwise, set time to AM
		TwoDigits(hour);
		cout << ":";
		TwoDigits(minute);
		cout << ":";
		TwoDigits(second);
		cout << " AM";
	}
	
}

// Prints both the 12 hour and 24 hour clock displays
void DisplayClock(int& hour, int& minute, int& second) {
	// Line 1 of Clock
	PrintStars();
	cout << "\t";
	PrintStars();

	// Line 2 of Clock
	cout << endl << "*      12-Hour Clock     *\t";
	cout << "*     24-Hour Clock      *" << endl;

	// Line 3 of Clock
	cout << "*       ";
	Print12Hours(hour, minute, second);
	cout << "      *" << "\t";
	cout << "*        ";
	Print24Hours(hour, minute, second);
	cout << "        *" << endl;

	// Line 4 of Clock
	PrintStars();
	cout << "\t";
	PrintStars();
}

// Function to print menu
void PrintMenu() {
	cout << endl;
	cout << endl;
	PrintStars();
	cout << endl;
	cout << "*  1 - Add One Hour      *" << endl;
	cout << "*  2 - Add One Minute    *" << endl;
	cout << "*  3 - Add One Second    *" << endl;
	cout << "*  4 - Exit Program      *" << endl;
	PrintStars();
	cout << endl;
}

// Function to add 1 hour
int AddHour(int& hour) {
	hour += 1;
	if (hour == 24) {							// If hour reaches 24, sets hour to 0
		hour = 0;
	}
	return hour;
}

// Function to add 1 minute
int AddMinute(int& hour, int& minute) {
	minute += 1;
	if (minute == 60) {							// If minute reaches 60, adds 1 to hour and sets minute to 0
		minute = 0;
		hour += 1;
		if (hour == 24) {						// If hour reaches 24, sets hour to 0
			hour = 0;
		}
	}
	return minute;
}

// Function to add 1 second
int AddSecond(int& hour, int& minute, int& second) {
	second += 1;
	if (second == 60) {							// If second reaches 60, adds 1 to minute and sets second to 0
		second = 0;
		minute += 1;
		if (minute == 60) {						// If minute reaches 60, adds 1 to hour and sets minute to 0
			minute = 0;
			hour += 1;
			if (hour == 24) {					// If hour reaches 24, sets hour to 0
				hour = 0;
			}
		}
	}
	return second;
}

int main() {
	int userInput = 0;							// Initializes user input to zero
	int hour;									// Create variable for hour
	int minute;									// Create variable for minute
	int second;									// Create variable for second
	int years;									// Create variable for years
	int days;									// Create variable for days


	time_t now = time(0);						// Get current time

	years = now % 31536000;						// Removing years from now by calculating out seconds in a year
	days = years % 86400;						// Removing days from years by calculating out seconds in a day

	hour = days / 3600;							// Calculating current hour
	minute = (days - (hour * 3600)) / 60;		// Calculating current minute
	second = (days - (hour * 3600)) % 60;		// Calculating current second


	while (userInput != 4) {
		DisplayClock(hour, minute, second);		// Displays the clock for the user

		PrintMenu();							// Prints the menu for the user

		cin >> userInput;

		// Switch statement to operate the user menu
		switch (userInput) {
			case 1:								// Case to add one hour
				AddHour(hour);
				break;
			case 2:								// Case to add one minute
				AddMinute(hour, minute);
				break;
			case 3:								// Case to add one second
				AddSecond(hour, minute, second);
				break;
			case 4:								//  Case to end the program
				cout << "Thank you for enjoying our clock!";
				break;
		}
	}
	
	return 0;
}