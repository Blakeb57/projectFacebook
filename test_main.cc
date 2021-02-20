#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "friend.h"
#include "fbfriends.h"
using namespace std;

int main()
{
    Friend myfriend;
    FBFriends myfb;
    string friendname;
    string username, filename;
    ifstream fin;
    ofstream fout;

	cout << "Welcome to Friends Management.\n\n";
	cout << "Begin by entering your username: ";
	getline(cin, username);

	filename = username + ".txt";
	fin.open(filename.c_str());

    if(!fin.fail())
	{
		myfb.load(fin);
	}
	fin.close();

	FBFriends original(myfb);

    cout << myfb.current();

}