#include <iostream>
#include <string>

#include "gitHubUserq1.h"

using namespace std;

//returns address of arr where UserName found, returns null otherwise
gitHubUser* searchUser(gitHubUser* users, int size, string UserName) {

	for (int c = 0; c < size; ++c) {
		if (users[c].userName == UserName) {
			return  &users[c];
		}
	}
	
	return nullptr;
}

//checks if username already exists
//returns 1 if Username already exists in arr
bool exists(gitHubUser* arr, int size, string UserName) {

	for (int c = 0; c < size; ++c) {
		if (arr[c].userName == UserName) {
			return 1;
		}
	}

	return 0;
}

//inputs a unique username and stores it in arr
void InputUserName(gitHubUser * arr, int size,int UserNum) {
	//temp username variable
	string UserName;

	cout << "enter username: ";
	cin >> UserName;

	while (exists(arr, size, UserName) == 1) {

		cout << "this username already exists, enter another username: ";
		cin >> UserName;
	}

	arr[UserNum].userName = UserName;
}

//fills arr from userinput upto size passed
void inputFromUser(gitHubUser * arr,int size) {

	for (int UserCount = 0; UserCount < size; ++UserCount) {

		cout << "enter name: ";
		cin >> arr[UserCount].firstName;

		InputUserName(arr, size, UserCount);

		cout << "Enter password: ";
		cin >> arr[UserCount].password;

		cout << "Enter email: ";
		cin >> arr[UserCount].email;

		cout << "Enter folderCount: ";
		cin >> arr[UserCount].folderCount;
	}
}

//takes two structs gitHubUser as parameters and returns 1 if they are equal
bool Comparison(gitHubUser UserA, gitHubUser UserB) {

	if (UserA.firstName != UserB.firstName)
		return 0;
	
	if (UserA.userName != UserB.userName)
		return 0;

	if (UserA.password != UserB.password)
		return 0;

	if (UserA.email != UserB.email)
		return 0;

	if (UserA.folderCount != UserB.folderCount)
		return 0;

	return 1;
}

//tests the comparision function
void ComparisionTest() {
	gitHubUser DummyA, DummyB;
	DummyA.userName = "a";
	DummyA.firstName = "a";
	DummyA.password = "a";
	DummyA.email = "a";
	DummyA.folderCount = 1;

	DummyB.userName = "a";
	DummyB.firstName = "b";
	DummyB.password = "a";
	DummyB.email = "a";
	DummyB.folderCount = 1;

	if (Comparison(DummyA, DummyB) == 1) {
		cout << endl << "the two users are identical";
	}
	else {
		cout << endl << "the two users are different";
	}
	cout << endl;
}

void main() {
	ComparisionTest();

	//testing input and UserName uniquness
	int NumOfUsers = 4;
	gitHubUser * UserArr=new gitHubUser[NumOfUsers];

	inputFromUser(UserArr, NumOfUsers);

	//testing searchUser
	cout << endl << "Enter userName to search ";
	string TestUserName;
	cin >> TestUserName;
	cout << searchUser(UserArr, NumOfUsers, TestUserName);

	//delete Dynamic arr
	delete[] UserArr;
	UserArr = nullptr;

	int dum;
	cin >> dum;
}