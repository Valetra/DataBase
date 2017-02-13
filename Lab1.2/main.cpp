#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;

static const size_t MAX_ARGC_COUNT = 2;

bool IsFileEmpty(fstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}

bool FindIdByName(string name, fstream &inputFile, vector<string> &indexes)
{
	string id;
	string file;
	string description;
	string date;
	string author;
	string platform;
	string type;
	string port;

	while (getline(inputFile, id, ','))
	{
		getline(inputFile, file, ',');
		getline(inputFile, description, ',');
		getline(inputFile, date, ',');
		getline(inputFile, author, ',');
		getline(inputFile, platform, ',');
		getline(inputFile, type, ',');
		getline(inputFile, port);

		if (author == name || author == "\"" + name + "\"")
		{
			indexes.push_back(id);
		}
	}

	if (!indexes.empty())
	{
		cout << "\nRecord id : ";
	}
	else
	{
		cerr << "This name is not in the database\n";
		return EXIT_FAILURE;
	}
	
	for (size_t i = 0; i < indexes.size(); ++i)
	{
		if (i + 1 == indexes.size())
		{
			cout << indexes.at(i) << '\n';
		}
		else
		{
			cout << indexes.at(i) << ", ";
		}
	}
	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	if (argc != MAX_ARGC_COUNT)
	{
		cerr << "lab1.2.exe need db.csv\n";
	}

	fstream inputFile(argv[1], ios::in);

	if (IsFileEmpty(inputFile))
	{
		cerr << "File is empty\n";
		return EXIT_FAILURE;
	}

	cout << "Enter username: ";
	
	string name;
	getline(cin, name);

	vector<string> indexes;

	return FindIdByName(name, inputFile, indexes);
}