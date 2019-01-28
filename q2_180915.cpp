#include <iostream>
#include <string>
#include <fstream>

#include "gitHubUserq2.h"

using namespace std;

//reads all the folders of passed user from file
void ReadgitHubFoldersFromFile(gitHubUser * &Users, int UserCount, ifstream& File) {
	//temp variable to read from file
	string LOT;

	Users[UserCount].gitHubFolders = new string[Users[UserCount].folderCount];

	for (int fCount = 0; fCount < Users[UserCount].folderCount; ++fCount) {

		getline(File, LOT);
		Users[UserCount].gitHubFolders[fCount] = LOT;
	}
}

//reads all the data of a user from passed File
void ReadUserFromFile(gitHubUser * &Users, int UserCount,ifstream& File) {
	//temp variable to read from file
	string LOT;

	getline(File, LOT);
	Users[UserCount].firstName = LOT;

	getline(File, LOT);
	Users[UserCount].userName = LOT;

	getline(File, LOT);
	Users[UserCount].email = LOT;

	getline(File, LOT);
	Users[UserCount].folderCount = stoi(LOT);

	ReadgitHubFoldersFromFile(Users,UserCount, File);
}

//reads User data from file
void readDataFromFile(gitHubUser * &Users, string filepath) {
	//read user data from
	ifstream File(filepath);

	//temp variable to read from file
	string LOT;

	getline(File, LOT);
	//number of users in file
	int NumOfUsers = stoi(LOT);

	Users = new gitHubUser[NumOfUsers];

	for (int UserCount = 0; UserCount < NumOfUsers; ++UserCount) {

		ReadUserFromFile(Users, UserCount, File);
	}
}

void main() {
	//array of type gitHubUser
	gitHubUser * arr;

	readDataFromFile(arr, "input.txt");

	int dum;
	cin >> dum;
}