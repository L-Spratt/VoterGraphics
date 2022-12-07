#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#include <chrono>
using namespace std;

//References:
//Class slides for referencing sorting algorithms
//geeksforgeeks.org for use of the timer

class Voter																								//Class object to store voter information
{
private:

	// CLASS VARIABLES 
	string firstName;
	string lastName;
	string gender;
	string race;
	string address;
	string party;
	string state;
	int age;
	int ZIP;
	int SSN;
	int vote;
public:
	Voter()																								// Default construct
	{																									// Sets all variables to empty
		firstName = "";
		lastName = "";
		gender = "";
		race = "";
		state = "";
		party = "";
		age = 0;
		ZIP = 0;
		SSN = 0;
		vote = 0;
	}

	// int getter functions
	int getZIP();
	int getSSN();
	int getAge();
	int getVote();

	// string getter functions
	string getLastName();
	string getFirstName();
	string getState();
	string getRace();
	string getParty();
	
	void SSNsetter(int ssn);																			// sets the social security 
	void Input(string input, int count);																// inputs the public data set information from csv file to the voter object 
};

//functions to input information into voter object
void Voter::Input(string input, int counter)
{
	if (counter == 1)
	{
		this->firstName = input;																		// sets the first name equal to the input 
	}
	else if (counter == 2)
	{
		this->lastName = input;																			// sets the last name euqal to the input
	}
	else if (counter == 3)
	{																									// randomly generate the race data for the public data set 
		this->gender = input;																			// sets the gender equal to the input 
		int random = rand() % 7;																		// sets the random int to a random number from 1-7
		if (random == 0)																				// if the random generator spits out 0....
		{
			this->race = "White";																		// set the race as white 					
		}
		else if (random == 1)																			// if the random generator spits out 1....
		{
			this->race = "Black";																		// set the race as black
		}
		else if (random == 2)																			// if the random generator spits out 2.. 
		{
			this->race = "Asian";																		// set the race as Asian
		}
		else if (random == 3)																			// if the random generator spits out 3... 
		{
			this->race = "Hispanic";																	// set the race as Hispanic 
		}
		else if (random == 4)																			// if the random generator spits out 4... 
		{
			this->race = "American Indian";																// set the race as American Indian 
		}
		else if (random == 5)																			// if the random generator spits out 5...
		{
			this->race = "Native Hawaiian";																// set the race as native hawaiian
		}
		else																							// if it was 6...
		{
			this->race = "Other/Multiracial";															// set the race as other 
		}
	}
	else if (counter == 4)																																				
	{
		this->age = stoi(input);																		// convert the string value of the age to an int and store it 
	}
	else if (counter == 6)
	{
		this->state = input;																			// set the state equal to the input
	}
	else if (counter == 7)
	{
		this->SSN = stoi(input);																		// set the social securty to the input 
	}
	else if (counter == 8)
	{
		int random = rand() % 1001;																		// randomly generate the party data for the public data set  
		if (random == 1000)																				
		{
			this->party = "Green Party";																// set the party equal to the green party 
		}
		else if (random == 999)
		{
			this->party = "Libertarian";																// set the party equal to the libertarian party 
		}
		else if (random % 2 == 0)
		{
			this->party = "Democrat";																	// set the party equal to democrat 
		}
		else
		{
			this->party = "Republican";																	// set the party equal to republican 
		}
		this->ZIP = stoi(input);																		// convert the string value of the zip code to the int value 
	}
	else if (counter == 9)
	{
		this->race = input;																			    // set the race equal to the input 
	}
	else if (counter == 10)
	{
		this->party = input;																			// set the party equal to the input 
	}
	else if (counter == 11)
	{
		this->vote = stoi(input);																		// convert the string value of the vote to an int 
	}
}

// setter function for the social security number of the voter 
void Voter::SSNsetter(int ssn)
{
	this->SSN = ssn;																			
}

// getter functions
int Voter::getSSN()
{
	return this->SSN;
}

int Voter::getAge()
{
	return this->age;
}

string Voter::getLastName()
{
	return this->lastName;
}

int Voter::getZIP()
{
	return this->ZIP;
}

string Voter::getFirstName()
{
	return this->firstName;
}

string Voter::getState()
{
	return this->state;
}

string Voter::getRace()
{
	return this->race;
}

string Voter::getParty()
{
	return this->party;
}

int Voter::getVote()
{
	return this->vote;
}

// Merge sort functions for vector of voters
void merge(vector<Voter>& voters, int left, int mid, int right, int based)
{
	int nX = mid - left + 1;																					// gets the index to split the sub vector
	int nY = right - mid;																						// gets a separate index to split another sub vector 
	vector<Voter> X;																							// creates the sub vector X
	vector<Voter> Y;																							// creates the sub vector Y 

	for (int i = 0; i < nX; i++)
	{
		X.push_back(voters[left + i]);																			// splits the first half of the vector into the new sub vector 
	}
	for (int i = 0; i < nY; i++)
	{
		Y.push_back(voters[mid + 1 + i]);																		// splits the second half of the vector into the second new sub vector 
	}

	int i = 0;
	int j = 0;
	int k = left;

	// code to merge both sub list together 
	while (i < nX && j < nY)
	{
		if (based == 1)																						   // based checks which integer value stored in voter the algorithm is sorting for 
		{
			if (X[i].getSSN() <= Y[j].getSSN())																   // sort based on social security
			{
				voters[k] = X[i];
				i++;
			}
			else
			{
				voters[k] = Y[j];
				j++;
			}
			k++;
		}
		if (based == 2)
		{
			if (X[i].getZIP() <= Y[j].getZIP())																  // sort based on zip code 
			{
				voters[k] = X[i];
				i++;
			}
			else
			{
				voters[k] = Y[j];
				j++;
			}
			k++;
		}
		if (based == 3)
		{
			if (X[i].getAge() <= Y[j].getAge())																 // sort based on age 
			{
				voters[k] = X[i];
				i++;
			}
			else
			{
				voters[k] = Y[j];
				j++;
			}
			k++;
		}
		if (based == 4)
		{
			if (X[i].getLastName() <= Y[j].getLastName())												    // sort based on last name 
			{
				voters[k] = X[i];
				i++;
			}
			else
			{
				voters[k] = Y[j];
				j++;
			}
			k++;
		}
	}

	// Merge the final elements 
	while (i < nX)
	{
		voters[k] = X[i];
		i++;
		k++;
	}
	while (j < nY)
	{
		voters[k] = Y[j];
		j++;
		k++;
	}
}
// Merge Sort main algorithm 
void MergeSort(vector<Voter>& voters, int left, int right, int based)
{
	if (left < right)																					  // if the array can still be split up.. 
	{
		int mid = left + (right - left) / 2;															  // find the mid value 
		MergeSort(voters, left, mid, based);															  // call the function on the indexes of the vector from the beginning to the mid index
		MergeSort(voters, mid + 1, right, based);														  // call the function on the indexes of the vector from the mid index to the end
		merge(voters, left, mid, right, based);														      // merge these two sub indexed vectors 
	}
}

//Quick sort functions for vector of voters
//Different partitions used depending on what the sort is based on
int SSNpartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;																						  // create three different pivots and choose their median value to improve performance
	int pivone = low + rand() % (high - low);															   
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low); 
	if (voters[pivone].getSSN() >= voters[pivtwo].getSSN() && voters[pivone].getSSN() >= voters[pivthree].getSSN())
	{
		if (voters[pivtwo].getSSN() >= voters[pivthree].getSSN())									      // whichever social security number is smaller between pivot two and three...
		{
			pivot = voters[pivtwo].getSSN();															  // set the pivot to that value.. 														
		}
		else
		{
			pivot = voters[pivthree].getSSN();
		}
	}
	if (voters[pivtwo].getSSN() >= voters[pivone].getSSN() && voters[pivtwo].getSSN() >= voters[pivthree].getSSN())
	{
		if (voters[pivone].getSSN() >= voters[pivthree].getSSN())										  // repeat comparison with pivot one and three
		{
			pivot = voters[pivone].getSSN();															  // set the pivot to the smaller value 
		}
		else
		{
			pivot = voters[pivthree].getSSN();
		}
	}
	if (voters[pivthree].getSSN() >= voters[pivtwo].getSSN() && voters[pivthree].getSSN() >= voters[pivone].getSSN())
	{
		if (voters[pivtwo].getSSN() >= voters[pivone].getSSN())											  // repeat comparison with pivot two and one 
		{
			pivot = voters[pivtwo].getSSN();															  // set the pivot to the smaller value 
		}
		else
		{
			pivot = voters[pivone].getSSN();
		}
	}

	int up = low;																						 // initializes the up and down variables 
	int down = high;																					 // to move values around the pivot 

	while (up < down)																				     // while the variables have not crossed paths 
	{
		for (int j = up; j < high; j++)																	 // run until up reaches the high value 
		{
			if (voters[up].getSSN() > pivot)
			{
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--)																// run until high reaches the low value 
		{
			if (voters[down].getSSN() < pivot)
			{
				break;
			}
			down--;
		}
		if (up < down)																				   // once they cross paths.. 
		{
			temp = voters[up];																		   // create a temp voter 
			voters[up] = voters[down];																   // move the data of the voter at the down index to the up index 
			voters[down] = temp;																	   // set the data of the voter at the down index equal to the original voter at the up index (temp)
		}
	}
	temp = voters[low];																				   // change the data of the temp voter to the voter at index low 
	voters[low] = voters[down];																		   // move the data of the voter at index down to the index low
	voters[down] = temp;																			   // set the data of the voter at the down index to the temp voter 
	return down;
}

// Same algortithm/comments from previous function (solely different on data pulled from the voter information
int ZIPpartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);														  //Median is chosen of three random pivots to improve performance
	if (voters[pivone].getZIP() >= voters[pivtwo].getZIP() && voters[pivone].getZIP() >= voters[pivthree].getZIP())
	{
		if (voters[pivtwo].getZIP() >= voters[pivthree].getZIP())
		{
			pivot = voters[pivtwo].getZIP();
		}
		else
		{
			pivot = voters[pivthree].getZIP();
		}
	}
	if (voters[pivtwo].getZIP() >= voters[pivone].getZIP() && voters[pivtwo].getZIP() >= voters[pivthree].getZIP())
	{
		if (voters[pivone].getZIP() >= voters[pivthree].getZIP())
		{
			pivot = voters[pivone].getZIP();
		}
		else
		{
			pivot = voters[pivthree].getZIP();
		}
	}
	if (voters[pivthree].getZIP() >= voters[pivtwo].getZIP() && voters[pivthree].getZIP() >= voters[pivone].getZIP())
	{
		if (voters[pivtwo].getZIP() >= voters[pivone].getZIP())
		{
			pivot = voters[pivtwo].getZIP();
		}
		else
		{
			pivot = voters[pivone].getZIP();
		}
	}
	int up = low;
	int down = high;
	while (up < down)
	{
		for (int j = up; j < high; j++)
		{
			if (voters[up].getZIP() > pivot)
			{
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--)
		{
			if (voters[down].getZIP() < pivot)
			{
				break;
			}
			down--;
		}
		if (up < down)
		{
			temp = voters[up];
			voters[up] = voters[down];
			voters[down] = temp;
		}
	}
	temp = voters[low];
	voters[low] = voters[down];
	voters[down] = temp;
	return down;
}

// Same algortithm/comments from previous function (solely different on data pulled from the voter information
int AgePartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);														//Median is chosen of three random pivots to improve performance
	if (voters[pivone].getAge() >= voters[pivtwo].getAge() && voters[pivone].getAge() >= voters[pivthree].getAge())
	{
		if (voters[pivtwo].getAge() >= voters[pivthree].getAge())
		{
			pivot = voters[pivtwo].getAge();
		}
		else
		{
			pivot = voters[pivthree].getAge();
		}
	}
	if (voters[pivtwo].getAge() >= voters[pivone].getAge() && voters[pivtwo].getAge() >= voters[pivthree].getAge())
	{
		if (voters[pivone].getAge() >= voters[pivthree].getAge())
		{
			pivot = voters[pivone].getAge();
		}
		else
		{
			pivot = voters[pivthree].getAge();
		}
	}
	if (voters[pivthree].getAge() >= voters[pivtwo].getAge() && voters[pivthree].getAge() >= voters[pivone].getAge())
	{
		if (voters[pivtwo].getAge() >= voters[pivone].getAge())
		{
			pivot = voters[pivtwo].getAge();
		}
		else
		{
			pivot = voters[pivone].getAge();
		}
	}
	int up = low;
	int down = high;
	while (up < down)
	{
		for (int j = up; j < high; j++)
		{
			if (voters[up].getAge() > pivot)
			{
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--)
		{
			if (voters[down].getAge() < pivot)
			{
				break;
			}
			down--;
		}
		if (up < down)
		{
			temp = voters[up];
			voters[up] = voters[down];
			voters[down] = temp;
		}
	}
	temp = voters[low];
	voters[low] = voters[down];
	voters[down] = temp;
	return down;
}

// Same algortithm/comments from previous function (solely different on data pulled from the voter information
int NamePartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	string pivot = "";
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);															//Median is chosen of three random pivots to improve performance
	if (voters[pivone].getLastName() >= voters[pivtwo].getLastName() && voters[pivone].getLastName() >= voters[pivthree].getLastName())
	{
		if (voters[pivtwo].getLastName() >= voters[pivthree].getLastName())
		{
			pivot = voters[pivtwo].getLastName();
		}
		else
		{
			pivot = voters[pivthree].getLastName();
		}
	}
	if (voters[pivtwo].getLastName() >= voters[pivone].getLastName() && voters[pivtwo].getLastName() >= voters[pivthree].getLastName())
	{
		if (voters[pivone].getLastName() >= voters[pivthree].getLastName())
		{
			pivot = voters[pivone].getLastName();
		}
		else
		{
			pivot = voters[pivthree].getLastName();
		}
	}
	if (voters[pivthree].getLastName() >= voters[pivtwo].getLastName() && voters[pivthree].getLastName() >= voters[pivone].getLastName())
	{
		if (voters[pivtwo].getLastName() >= voters[pivone].getLastName())
		{
			pivot = voters[pivtwo].getLastName();
		}
		else
		{
			pivot = voters[pivone].getLastName();
		}
	}
	int up = low;
	int down = high;
	while (up < down)
	{
		for (int j = up; j < high; j++)
		{
			if (voters[up].getLastName() > pivot)
			{
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--)
		{
			if (voters[down].getLastName() < pivot)
			{
				break;
			}
			down--;
		}
		if (up < down)
		{
			temp = voters[up];
			voters[up] = voters[down];
			voters[down] = temp;
		}
	}
	temp = voters[low];
	voters[low] = voters[down];
	voters[down] = temp;
	return down;
}

// Actual quick sort algorithm 
void QuickSort(vector<Voter>& voters, int low, int high, int based)
{
	if (low < high)
	{
		int pivot = 0;
		if (based == 1)																						// if the user wants to sort based off of social security numbers...
		{
			pivot = SSNpartition(voters, low, high);														// call the social security partition 
		} //Partition based on what is being sorted
		else if (based == 2)																				// if the user wants to sort based off of zip code number...
		{
			pivot = ZIPpartition(voters, low, high);														// call the zip code partition 
		}
		else if (based == 3)																				// if the user wants to sort based off of the voters age
		{
			pivot = AgePartition(voters, low, high);														// call the age partition 
		}
		else																								// if the user wants to sort based off of the voters name 
		{
			pivot = NamePartition(voters, low, high);														// call the name partition 												
		}
		QuickSort(voters, low, pivot - 1, based);															// recursively call the function around the pivot (lower half of vector)
		QuickSort(voters, pivot + 1, high, based);															// recursively call the function around the pivot (higher end of vector)
	}
}

//function to determine which sort is used
void Sort(vector<Voter>& voters, string type, int based)
{
	if (type == "merge")																					// if the user choose to utilize the merge sort algorithm 
	{
		MergeSort(voters, 0, voters.size() - 1, based);														// call the merge sort function 
	}
	else
	{
		QuickSort(voters, 0, voters.size() - 1, based);														// else call the quick sort fucntion 
	}
}

void PrintSSN(vector<Voter> voters)																			// prints out the social security numbers in the voter vector 
{
	for (int i = 0; i < voters.size(); i++)
	{
		cout << voters[i].getSSN() << endl;
	}
}

int main()
{
	srand(time(0));																							// Sets random seed
	ifstream file;
	string line;
	set<int> SSNbank;																						// Stores unique social security numbers
	map<string, int> states;																				// Stores number of voters per state
	map<string, int> genders;																				// Stores number of voters by gender
	map<string, int> races;																					// Stores number of voters by race
	unordered_map<string, int> parties;																		// Stores number of voters by political party
	unordered_map<int, pair<string, Voter>> ballot;															// Stores account information
	vector<Voter> voters;																					// Stores the list of voters
	string word;

	file.open("Voter Info.csv");																			// Opens the CSV file 
	while (getline(file, line))																				// Inputs original data set of 100,000 voters, line by line
	{
		Voter tempPerson;																					// Temporary voter
		stringstream str(line);																				// Open up the reading platform to read each line 
		int counter = 1;
		while (getline(str, word, ','))																		//Iterates through each word of current row
		{
			if (counter == 3)
			{
				if (genders.find(word) == genders.end())													//Increments voter amount for gender
				{
					genders[word] = 1;
				}
				else {
					genders[word]++;
				}
			}
			if (counter == 5)																				// Used to skip over the street address collumn
			{
				getline(str, word, ',');
				getline(str, word, ',');
				counter++;
			}
			tempPerson.Input(word, counter);																// Inputs information associated with current voter
			counter++;
		}
		if (SSNbank.count(tempPerson.getSSN()) == 0)														// Adds voter to list if social security number has not been used yet
		{
			voters.push_back(tempPerson);
			SSNbank.insert(tempPerson.getSSN());
		}
		if (states.find(tempPerson.getState()) == states.end())												// Increments voter amount for state
		{
			states[tempPerson.getState()] = 1;
		}
		else {
			states[tempPerson.getState()]++;
		}
	}

	int check = 0;
	string method = "Merge";																				// Stores sorting method choosen by user 
	string input = "";
	while (input != "-1")																					// Will return to main menu until user chooses to exit
	{
		check = 0;
		cout << endl;																						// Prints out main menu for the user to choose the actions 
		cout << "		Welcome to VoterGraphics!" << endl;
		cout << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "0) Cast Vote" << endl;
		cout << "1) Register Voter" << endl;
		cout << "2) Change Information" << endl;
		cout << "3) See Party Affiliation Demographics" << endl;
		cout << "4) See Age Demographics" << endl;
		cout << "5) See Gender and Race Demographics" << endl;
		cout << "6) See State Demographics" << endl;
		cout << "7) List of Names" << endl;
		cout << "8) Sort Database" << endl;
		cout << "9) Change Sorting Method (currently " << method << " sort)" << endl;
		cout << "10) Quit" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << endl << "Please enter a menu option: ";
		cin >> input;																						// Gets the users input based off the menu 
		if (input == "0")																					// Allows user to cast vote for a candidate
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			if (input.length() != 9)																		// Validates social security to make sure the number of digits is equal to 9 
			{
				check++;
			}
			for (char c : input)																			// Validates input
			{
				if (!isdigit(c))																			// Validates the name information to make sure it does not include numbers 
				{
					check++;
				}
			}
			if (check != 0)																					// If it did not pass the validating input tests
			{
				cout << "Invalid input, try again... " << endl;												// tell the user the input is invalid 
			}
			else {
				int tempSSN = stoi(input);
				cout << "Enter your password: ";
				cin >> input;
				if (ballot.find(tempSSN) == ballot.end())													// Checks if voter exists in system
				{
					cout << "You have not registered to vote yet!" << endl;
				}
				else if (ballot[tempSSN].first != input)													// Checks for correct password
				{
					cout << "Incorrect password!" << endl;
				}
				else
				{
					cout << "Thank you for choosing to vote! Who would you like to vote for?" << endl;		// When the user casts a vote .. 
					cout << "You are currently supporting ";
					string candidate = "";																	// Make sure they chose a valid selection 
					if (ballot[tempSSN].second.getVote() == 0)
					{
						candidate = "nobody! You need to vote!";											// If they did not select either candidate let them know they need to vote 
					}
					else if (ballot[tempSSN].second.getVote() == 1)											// Print out to them whichever candidate they choose 
					{
						candidate = "Kapoor!";																
					}
					else if (ballot[tempSSN].second.getVote() == 2)
					{
						candidate = "Resch!";
					}
					cout << candidate << endl << endl;

					cout << "1) Kapoor" << endl;															// Print out the menu option for them to choose their candidate 
					cout << "2) Resch" << endl;
					cout << "Vote for: ";
					cin >> input;																			// Get the users input 

					if (input == "1")																		// If they choose option 1
					{
						ballot[tempSSN].second.Input(input, 11);											// input in their choice 
						cout << "Thank you for voting!" << endl;
					}
					else if (input == "2")																	// same for option 2
					{
						ballot[tempSSN].second.Input(input, 11);
						cout << "Thank you for voting!" << endl;
					}
					else
					{
						cout << "Invalid input, try again..." << endl;
					}
				}
			}
		}
		else if (input == "1")																				// Allows the user to register a new voter
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			if (input.length() != 9)																		// Validates input in the same manner as before 
			{
				check++;
			}
			for (char c : input)																			// Validates input (same way as before) 
			{
				if (!isdigit(c))
				{
					check++;
				}
			}
			if (check != 0)
			{
				cout << "Invalid input, try again... " << endl;
			}
			else {
				if (SSNbank.count(stoi(input)) == 1)														// Checks for unique SSN
				{
					cout << "That number is already in use!" << endl;										// If not print that it is invalid 
				}
				else {
					int tempSSN = stoi(input);																// convert the string version of the social security number 
					cout << "Create a password: ";
					cin >> input;
					Voter temp;
					ballot[tempSSN] = make_pair(input, temp);
					cout << "Enter your first name: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 1);
					cout << "Enter your last name: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 2);
					cout << "Enter your gender: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 3);
					cout << "Enter your age: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 4);
					cout << "Enter your State of Residence: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 6);
					ballot[tempSSN].second.SSNsetter(tempSSN);
					cout << "Enter your ZIP code: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 8);
					cout << "Enter your race: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 9);
					cout << "Enter your party affiliation: " << endl;
					cin >> input;
					ballot[tempSSN].second.Input(input, 10);
					cout << endl << "Information saved! Thank you!" << endl;

					voters.push_back(ballot[tempSSN].second);
				}
			}
		}
		else if (input == "2")																				// Allows user to change their information
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			int tempSSN = stoi(input);
			if (input.length() != 9)																		// Validates input
			{
				check++;
			}
			for (char c : input)																			// Validates input
			{
				if (!isdigit(c))
				{
					check++;
				}
			}
			if (check != 0)
			{
				cout << "Invalid input, try again... " << endl;
			}
			else if (ballot.find(tempSSN) == ballot.end())													// Checks if voter exists
			{
				cout << "You have not registered to vote yet!" << endl;
			}
			else {
				cout << "Enter your password: ";
				cin >> input;
				if (ballot[tempSSN].first != input)															// Checks for correct password
				{
					cout << "Incorrect password!" << endl;													// If the password is incorrect tell the user 
				}
				else
				{
					cout << "1) First Name" << endl;														// Print out the menu list of informatino that can be updated for the voter
					cout << "2) Last Name" << endl;
					cout << "3) Gender" << endl;
					cout << "4) Age" << endl;
					cout << "5) Race" << endl;
					cout << "6) Party Affiliation" << endl;
					cout << "7) State of Residence" << endl;
					cout << "8) ZIP Code" << endl;
					cout << "9) Cancel" << endl;
					cout << "What would you like to update: " << endl;
					cin >> input;

					if (input == "1")																		// If they would like to update their first name... 
					{
						cout << "Enter your first name: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 1);												// change the stored first name for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "2")																	// If they would like to update their last name....
					{
						cout << "Enter your last name: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 2);												// change the stored last name for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "3")																	// If they would like to update their gender...
					{
						cout << "Enter your gender: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 3);												// change the stored gender for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "4")																	// If they would like to update their age...
					{
						cout << "Enter your age: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 4);												// change the stored age for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "5")																	// If they would like to update their race... 
					{
						cout << "Enter your race: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 9);												// change the stored race for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "6")																	// If they would like to update their party affiliation 
					{
						cout << "Enter your party affiliation: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 10);											// change the stored party affiliation for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "7")																	// If they would like to update their residing state 
					{
						cout << "Enter your State of Residence: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 6);												// change the stored residing state for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "8")																	// If they would like to update their zip code 
					{
						cout << "Enter your ZIP code: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 8);												// change the stored zip code for the correct voter in the vector 
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input != "9")																	// if their input is invalid... 
					{
						cout << "Invalid input, try again..." << endl;										// let them know 
					}
				}
			}
		}
		else if (input == "3")																					// Prints percentage of voters based on political party
		{
			unordered_map<string, int>::iterator it;
			for (it = parties.begin(); it != parties.end(); it++)												// Resets count
			{
				it->second = 0;
			}

			for (int i = 0; i < voters.size(); i++)
			{
				if (parties.find(voters[i].getParty()) == parties.end())										// Increments voter amount for state
				{
					parties[voters[i].getParty()] = 1;
				}
				else {
					parties[voters[i].getParty()]++;
				}
			}

			cout << "Percentage of voters who are..." << endl << endl;
			for (it = parties.begin(); it != parties.end(); it++)
			{
				cout << fixed << setprecision(2) << it->first << ": " << it->second * 100.f / voters.size() << "%" << endl;
			}
		}
		else if (input == "4")																					// Prints mean, median, range, and mode of ages among voters
		{
			Sort(voters, method, 3);																			// Calls the sorting function 
			int median = voters[voters.size() / 2].getAge();													// gets the median age of voters
			int mean = 0;
			int range = voters[voters.size() - 1].getAge() - voters[0].getAge();							    // gets the range of the voters 
			int mode = 0;

			int current = 0;
			int amount = 0;
			int max = 0;
			for (int i = 0; i < voters.size(); i++)
			{
				mean = mean + voters[i].getAge();
				if (current == voters[i].getAge())															   // Keeps track of mode
				{
					amount++;
				}
				else {
					if (amount > max)
					{
						max = amount;
						mode = current;
					}
					amount = 1;
					current = voters[i].getAge();
				}
			}
			mean = mean / voters.size();																	  // Calculate mean

			cout << endl << "Average voter age: " << mean << endl;
			cout << endl << "Median voter age: " << median << endl;
			cout << endl << "Most common voter age: " << mode << endl;
			cout << endl << "Range of voter ages: " << range << endl;
		}
		else if (input == "5")																				 // Prints percentage of voters based on gender and race
		{
			map<string, int>::iterator it;
			for (it = races.begin(); it != races.end(); it++)												 // Resets count
			{
				it->second = 0;
			}

			for (int i = 0; i < voters.size(); i++)
			{
				if (races.find(voters[i].getRace()) == races.end())											 // Increments voter amount for state
				{
					races[voters[i].getRace()] = 1;
				}
				else {
					races[voters[i].getRace()]++;
				}
			}

			cout << "Percentage of voters who are..." << endl << endl;
			cout << "Female: " << fixed << setprecision(2) << 100.f * genders["Female"] / voters.size() << "%" << endl;
			cout << "Male: " << fixed << setprecision(2) << 100.f * genders["Male"] / voters.size() << "%" << endl << endl;

			for (it = races.begin(); it != races.end(); it++)
			{
				cout << it->first << ": " << it->second * 100.f / voters.size() << "%" << endl;
			}
		}
		else if (input == "6")																				// Displays number of voters in each state
		{
			cout << "Number of voters, by state:" << endl;
			map<string, int>::iterator it;
			for (it = states.begin(); it != states.end(); it++)
			{
				cout << it->first << ": " << it->second << endl;
			}
		}
		else if (input == "7")																				// Lists all voters alphabetically by last name
		{
			cout << "Are you sure you want to list all names? (enter Y to confirm): " << endl;				// Confirms input
			cin >> input;
			if (input == "Y" || input == "y")
			{
				Sort(voters, method, 4);
				cout << endl;
				for (int i = 0; i < voters.size(); i++)
				{
					cout << voters[i].getLastName() << ", " << voters[i].getFirstName() << endl;
				}
			}
		} 
		else if (input == "8")																			   // Sorts the list based on preferred parameter, and displays time spent sorting
		{
			cout << endl;
			cout << "1) Social Security Number" << endl;
			cout << "2) ZIP Code" << endl;
			cout << "3) Age" << endl;
			cout << "4) Alphabetically" << endl << endl;
			cout << "How do you want to sort?: ";

			cin >> input;
			if (input == "1" || input == "2" || input == "3" || input == "4")
			{
				auto start = chrono::high_resolution_clock::now();										  // Used to time the sort
				Sort(voters, method, stoi(input));
				auto stop = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
				cout << "Done! Database sorted with " << method << " Sort in " << duration.count() << " microseconds." << endl;
			}
			else {
				cout << "Invalid input, try again... " << endl;
			}
		}
		else if (input == "9")																			 // Switches sorting method
		{
			if (method == "Merge")
			{
				method = "Quick";
			}
			else
			{
				method = "Merge";
			}
			cout << endl << "You are now using " << method << " Sort!" << endl;
		}
		else if (input == "10")																		   	// Quits program
		{
			cout << endl;
			cout << "	Thanks for using VoterGraphics!" << endl;
			input = "-1";
		}
		else																							// Case for invalid input
		{
			cout << "Invalid input, try again... " << endl;
		}
		cout << endl << "Enter 1 to continue, or -1 to quit." << endl;
		cin >> input;
	}
	return 0;
}
