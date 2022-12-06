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

class Voter
{
private:
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
	Voter()
	{
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
	void Input(string input, int count);
	int getSSN();
	int getAge();
	string getLastName();
	int getZIP();
	string getFirstName();
	string getState();
	string getRace();
	string getParty();
	int getVote();
	void SSNsetter(int ssn);
};

//function to input information into voter object
void Voter::Input(string input, int counter)
{
	if (counter == 1)
	{
		this->firstName = input;
	}
	else if (counter == 2)
	{
		this->lastName = input;
	}
	else if (counter == 3)
	{
		this->gender = input;
		int random = rand() % 7;
		if (random == 0)
		{
			this->race = "White";
		}
		else if (random == 1)
		{
			this->race = "Black";
		}
		else if (random == 2)
		{
			this->race = "Asian";
		}
		else if (random == 3)
		{
			this->race = "Hispanic";
		}
		else if (random == 4)
		{
			this->race = "American Indian";
		}
		else if (random == 5)
		{
			this->race = "Native Hawaiian";
		}
		else
		{
			this->race = "Other/Multiracial";
		}
	}
	else if (counter == 4)
	{
		this->age = stoi(input);
	}
	else if (counter == 6)
	{
		this->state = input;
	}
	else if (counter == 7)
	{
		this->SSN = stoi(input);
	}
	else if (counter == 8)
	{
		int random = rand() % 1001;
		if (random == 1000)
		{
			this->party = "Green Party";
		}
		else if (random == 999)
		{
			this->party = "Libertarian";
		}
		else if (random % 2 == 0)
		{
			this->party = "Democrat";
		}
		else
		{
			this->party = "Republican";
		}
		this->ZIP = stoi(input);
	}
	else if (counter == 9)
	{
		this->race = input;
	}
	else if (counter == 10)
	{
		this->party = input;
	}
	else if (counter == 11)
	{
		this->vote = stoi(input);
	}
}
void Voter::SSNsetter(int ssn)
{
	this->SSN = ssn;
}

//getter functions
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

void merge(vector<Voter>& voters, int left, int mid, int right, int based)
{
	int nX = mid - left + 1;
	int nY = right - mid;
	vector<Voter> X;
	vector<Voter> Y;

	for (int i = 0; i < nX; i++)
	{
		X.push_back(voters[left + i]);
	}
	for (int i = 0; i < nY; i++)
	{
		Y.push_back(voters[mid + 1 + i]);
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < nX && j < nY)
	{
		if (based == 1)
		{
			if (X[i].getSSN() <= Y[j].getSSN())
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
			if (X[i].getZIP() <= Y[j].getZIP())
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
			if (X[i].getAge() <= Y[j].getAge())
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
			if (X[i].getLastName() <= Y[j].getLastName())
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
void MergeSort(vector<Voter>& voters, int left, int right, int based)
{
	if (left < right)
	{
	int mid = left + (right - left) / 2;
	MergeSort(voters, left, mid, based);
	MergeSort(voters, mid + 1, right, based);
	merge(voters, left, mid, right, based);
	}
}

int SSNpartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);
	if (voters[pivone].getSSN() >= voters[pivtwo].getSSN() && voters[pivone].getSSN() >= voters[pivthree].getSSN())
	{
		if (voters[pivtwo].getSSN() >= voters[pivthree].getSSN())
		{
			pivot = voters[pivtwo].getSSN();
		}
		else
		{
			pivot = voters[pivthree].getSSN();
		}
	}
	if (voters[pivtwo].getSSN() >= voters[pivone].getSSN() && voters[pivtwo].getSSN() >= voters[pivthree].getSSN())
	{
		if (voters[pivone].getSSN() >= voters[pivthree].getSSN())
		{
			pivot = voters[pivone].getSSN();
		}
		else
		{
			pivot = voters[pivthree].getSSN();
		}
	}
	if (voters[pivthree].getSSN() >= voters[pivtwo].getSSN() && voters[pivthree].getSSN() >= voters[pivone].getSSN())
	{
		if (voters[pivtwo].getSSN() >= voters[pivone].getSSN())
		{
			pivot = voters[pivtwo].getSSN();
		}
		else
		{
			pivot = voters[pivone].getSSN();
		}
	}
	int up = low;
	int down = high;
	while (up < down)
	{
		for (int j = up; j < high; j++)
		{
			if (voters[up].getSSN() > pivot)
			{
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--)
			{
			if (voters[down].getSSN() < pivot)
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
int ZIPpartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);
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
int AgePartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	int pivot = 0;
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);
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
int NamePartition(vector<Voter>& voters, int low, int high)
{
	Voter temp;
	string pivot = "";
	int pivone = low + rand() % (high - low);
	int pivtwo = low + rand() % (high - low);
	int pivthree = low + rand() % (high - low);
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
void QuickSort(vector<Voter>& voters, int low, int high, int based)
{
	if (low < high)
	{
		int pivot = 0;
		if (based == 1)
		{
			pivot = SSNpartition(voters, low, high);
		}
		else if (based == 2)
		{
			pivot = ZIPpartition(voters, low, high);
		}
		else if (based == 3)
		{
			pivot = AgePartition(voters, low, high);
		}
		else
		{
			pivot = NamePartition(voters, low, high);
		}
		QuickSort(voters, low, pivot - 1, based);
		QuickSort(voters, pivot + 1, high, based);
	}
}

//function to determine which sort is used
void Sort(vector<Voter> &voters, string type, int based)
{
	if (type == "merge")
	{
		MergeSort(voters, 0, voters.size() - 1, based);
	}
	else 
	{
		QuickSort(voters, 0, voters.size() - 1, based);
	}
}

void PrintSSN(vector<Voter> voters)
{
	for (int i = 0; i < voters.size(); i++)
	{
		cout << voters[i].getSSN() << endl;
	}
}

int main()
{
	srand(time(0)); //Sets random seed
	ifstream file;
	string line;
	set<int> SSNbank; //Stores unique social security numbers
	map<string, int> states; //Stores number of voters per state
	map<string, int> genders; //Stores number of voters by gender
	map<string, int> races; //Stores number of voters by race
	unordered_map<string, int> parties; //Stores number of voters by political party
	unordered_map<int, pair<string, Voter>> ballot; //Stores account information
	vector<Voter> voters; //Stores the list of voters
	string word;

	file.open("Voter Info.csv");
	while (getline(file, line)) //Inputs original data set of 100,000 voters, line by line
	{
		Voter tempPerson; //Temporary voter
		stringstream str(line);
		int counter = 1;
		while (getline(str, word, ',')) //Iterates through each word of current row
		{
			if (counter == 3)
			{
				if (genders.find(word) == genders.end()) //Increments voter amount for gender
				{
					genders[word] = 1;
				}
				else {
					genders[word]++;
				}
			}
			if (counter == 5) //Used to skip over the street address collumn
			{
				getline(str, word, ',');
				getline(str, word, ',');
				counter++;
			}
			tempPerson.Input(word, counter); //Inputs information associated with current voter
			counter++;
		}
		if (SSNbank.count(tempPerson.getSSN()) == 0) //Adds voter to list if social security number has not been used yet
		{
			voters.push_back(tempPerson);
			SSNbank.insert(tempPerson.getSSN());
		}
		if (states.find(tempPerson.getState()) == states.end()) //Increments voter amount for state
		{
			states[tempPerson.getState()] = 1;
		}
		else {
			states[tempPerson.getState()]++;
		}
	}

	int check = 0;
	string sorted = "not";
	string method = "Merge";
	string input = "";
	while (input != "-1")
	{
		check = 0;
		cout << endl;
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
		cin >> input;
		if (input == "0")
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			if (input.length() != 9)
			{
				check++;
			}
			for (char c : input)
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
				int tempSSN = stoi(input);
				cout << "Enter your password: ";
				cin >> input;
				if (ballot.find(tempSSN) == ballot.end())
				{
					cout << "You have not registered to vote yet!" << endl;
				}
				else if (ballot[tempSSN].first != input)
				{
					cout << "Incorrect password!" << endl;
				}
				else
				{
					cout << "Thank you for choosing to vote! Who would you like to vote for?" << endl;
					cout << "You are currently supporting ";
					string candidate = "";
					if (ballot[tempSSN].second.getVote() == 0)
					{
						candidate = "nobody! You need to vote!";
					}
					else if (ballot[tempSSN].second.getVote() == 1)
					{
						candidate = "Kapoor!";
					}
					else if (ballot[tempSSN].second.getVote() == 2)
					{
						candidate = "Resch!";
					}
					cout << candidate << endl << endl;

					cout << "1) Kapoor" << endl;
					cout << "2) Resch" << endl;
					cout << "Vote for: ";
					cin >> input;

					if (input == "1")
					{
						ballot[tempSSN].second.Input(input, 11);
						cout << "Thank you for voting!" << endl;
					}
					else if (input == "2")
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
		else if (input == "1")
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			if (input.length() != 9)
			{
				check++;
			}
			for (char c : input)
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
				if (SSNbank.count(stoi(input)) == 1)
				{
					cout << "That number is already in use!" << endl;
				}
				else {
					int tempSSN = stoi(input);
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
		else if (input == "2")
		{
			cout << "Please enter your nine (9) digit SSN: ";
			cin >> input;
			int tempSSN = stoi(input);
			if (input.length() != 9)
			{
				check++;
			}
			for (char c : input)
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
			else if (ballot.find(tempSSN) == ballot.end())
			{
				cout << "You have not registered to vote yet!" << endl;
			}
			else {
				cout << "Enter your password: ";
				cin >> input;
				if (ballot[tempSSN].first != input)
				{
					cout << "Incorrect password!" << endl;
				}
				else
				{
					cout << "1) First Name" << endl;
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

					if (input == "1")
					{
						cout << "Enter your first name: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 1);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "2")
					{
						cout << "Enter your last name: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 2);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "3")
					{
						cout << "Enter your gender: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 3);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "4")
					{
						cout << "Enter your age: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 4);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "5")
					{
						cout << "Enter your race: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 9);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "6")
					{
						cout << "Enter your party affiliation: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 10);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "7")
					{
						cout << "Enter your State of Residence: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 6);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input == "8")
					{
						cout << "Enter your ZIP code: " << endl;
						cin >> input;
						ballot[tempSSN].second.Input(input, 8);
						cout << endl << "Information saved! Thank you!" << endl;
					}
					else if (input != "9")
					{
						cout << "Invalid input, try again..." << endl;
					}
				}
			}
		}
		else if (input == "3") //Prints percentage of voters based on political party
		{
			unordered_map<string, int>::iterator it;
			for (it = parties.begin(); it != parties.end(); it++) //Resets count
			{
				it->second = 0;
			}

			for (int i = 0; i < voters.size(); i++)
			{
				if (parties.find(voters[i].getParty()) == parties.end()) //Increments voter amount for state
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
		else if (input == "4") //Prints mean, median, range, and mode of ages among voters
		{
			Sort(voters, method, 3);
			int median = voters[voters.size() / 2].getAge();
			int mean = 0;
			int range = voters[voters.size() - 1].getAge() - voters[0].getAge();
			int mode = 0;

			int current = 0;
			int amount = 0;
			int max = 0;
			for (int i = 0; i < voters.size(); i++)
			{
				mean = mean + voters[i].getAge();
				if (current == voters[i].getAge()) //Keeps track of mode
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
			mean = mean / voters.size(); //Calculate mean

			cout << endl << "Average voter age: " << mean << endl;
			cout << endl << "Median voter age: " << median << endl;
			cout << endl << "Most common voter age: " << mode << endl;
			cout << endl << "Range of voter ages: " << range << endl;
		}
		else if (input == "5") //Prints percentage of voters based on gender and race
		{
			map<string, int>::iterator it;
			for (it = races.begin(); it != races.end(); it++) //Resets count
			{
				it->second = 0;
			}

			for (int i = 0; i < voters.size(); i++)
			{
				if (races.find(voters[i].getRace()) == races.end()) //Increments voter amount for state
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
		else if (input == "6") //Displays number of voters in each state
		{
			cout << "Number of voters, by state:" << endl;
			map<string, int>::iterator it;
			for (it = states.begin(); it != states.end(); it++)
			{
				cout << it->first << ": " << it->second << endl;
			}
		}
		else if (input == "7") //Lists all voters alphabetically by last name
		{
			cout << "Are you sure you want to list all names? (enter Y to confirm): " << endl;
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
		else if (input == "8") //Sorts the list based on preferred parameter, and displays time spent sorting
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
				auto start = chrono::high_resolution_clock::now(); //Used to time the sort
				Sort(voters, method, stoi(input));
				auto stop = chrono::high_resolution_clock::now();
				auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
				cout << "Done! Database sorted with " << method << " Sort in " << duration.count() << " microseconds." << endl;
			}
			else {
				cout << "Invalid input, try again... " << endl;
			}
		}
		else if (input == "9") //Switches sorting method
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
		else if (input == "10") //Quits program
		{
			cout << endl;
			cout << "	Thanks for using VoterGraphics!" << endl;
			input = "-1";
		}
		else //Case for invalid input
		{
			cout << "Invalid input, try again... " << endl;
		}
		cout << endl << "Enter 1 to continue, or -1 to quit." << endl;
		cin >> input;
	}
	return 0;
}