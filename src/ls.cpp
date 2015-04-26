#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <sys/types.h>

//custom ls header file
#include "ls.h"

using namespace std;

int main(int argc, char** argv)
{
	//bool variables for flag status
	//TODO: implement switch-cases to trigger flags
	bool aflag = false;
	bool lflag = false;
	bool Rflag = false;

	//keeps track of all arguments passed after ls
	vector<char*> lsargs;

	//char* that store ".". use if lsargs is empty
	char dot = '.';
	char* pdot = &dot;

	//sort through args for flags or directories
	for (unsigned i=1; i < argc; i++)
	{
		//if first char in char** is '-', the argument is a flag
		if (argv[i][0] == '-')
		{
			//if flag is detected, set flag bools accordingly
				for (unsigned j = 1; j < strlen(argv[i]); j++)
				{
					if (aflag == false && argv[i][j] == 'a') aflag = true;
					if (lflag == false && argv[i][j] == 'l') lflag = true;
					if (Rflag == false && argv[i][j] == 'R') Rflag = true;
				}
		}
		else //if the argument is not a flag, it is a parameter that should be kept
		{
			lsargs.push_back(argv[i]);
		}
	}

	//parsing and flag test output
	#define FLAGTEST(x) cout << #x " = " << (x==true)?"true":"false"; cout << endl;
	#define PARSETEST(x) for(unsigned i=0; i < x.size() ; i++) { cout << x.at(i) << endl; }

	FLAGTEST(aflag);
	FLAGTEST(lflag);
	FLAGTEST(Rflag);
	PARSETEST(lsargs); 
	cout << "lsargs.size = " << lsargs.size() << endl;

	if(lsargs.empty())
	{
		lsargs.push_back(pdot);
	}

	//vector that stores all filenames in directory
	vector<char*> filenames;

	//get directory pointer 
	for (unsigned i=0; i < lsargs.size(); i++)
	{
		DIR* dirptr = opendir(lsargs[i]);
		if (dirptr == NULL)
		{
			perror("opendir");
			exit(1);
		}
		//get directory entry pointers and store file names
		struct dirent* de;
		while (de = readdir(dirptr))
		{
			if (errno !=0) 
			{
				perror("readdir");
				exit(1);
			}
			if (de->d_name[0] != '.') 
			{
				filenames.push_back(de->d_name);
			}
			if (de->d_name[0] == '.' && aflag)
			{
				filenames.push_back(de->d_name);
			}
		}
	}

	sort(filenames.begin(), filenames.end(), compcstrings);

	//TEST: output filenames
	for (unsigned i=0; i < filenames.size(); i++) 
	{
		cout << filenames.at(i) << endl;
	}
		

	return 0;
}
