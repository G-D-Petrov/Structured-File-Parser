#include <iostream>
#include <string>

#include "Parser.h"
#include "DataList.h"

using namespace std;

enum Options
{
	RunTests,
	EnterFilePath,
	Exit,
	Invalid
};

Options InitialMenu()
{
	cout << "Hello, please select an action:" << endl;
	cout << "Press 1 to run tests." << endl;
	cout << "Press 2 to enter a path to a file for parsing." << endl;
	cout << "Press 3 to exit the program." << endl;

	int input = 0;
	Options selectedOption = Invalid;
	cin.clear();
	cin >> input;

	switch (input)
	{
	case 1:
		selectedOption = RunTests;
		break;
	case 2:
		selectedOption = EnterFilePath;
		break;
	case 3:
		selectedOption = Exit;
		break;
	default:
		selectedOption = Invalid;
		break;
	}

	return selectedOption;
}

void RunUnitTests()
{
	cout << "Running tests" << endl;
	Parser parser("test.sf");
}

void OperateOnList(Parser &parser, std::shared_ptr<DataList> list)
{
	cout << "Hello, please select an action:" << endl;
	cout << "Press 1 to add an item." << endl;
	cout << "Press 2 to remove an item." << endl;
	cout << "Press 3 to save." << endl;
	int input = 0;
	cin.clear();
	cin >> input;

	switch (input)
	{
	case 1:
		list->AddElementAtIndex(2, std::vector<std::string>(list->TypesCount()));
		break;
	case 2:
		list->RemoveAtIndex(2);
		break;
	case 3:
		parser.Save(list, "new_test.sf");
		break;
	default:
		break;
	}
}

void HandleFile()
{
	string filepath;
	cout << "Please enter a path to a valid file:" << endl;
	cin.clear();
	cin >> filepath;

	// TODO: Validate filepath
	Parser parser(filepath);
	
	auto list = parser.Parse();

	OperateOnList(parser, list);
}

void HandleUserOption(const Options userOption)
{
	switch (userOption)
	{
	case RunTests:
		RunUnitTests();
		break;
	case EnterFilePath:
		HandleFile();
		break;
	default:
		cout << "Unknown option" << endl;
		break;
	}
}

int main()
{
	Options selectedOption = Invalid;

	while (Invalid == selectedOption)
	{
		selectedOption = InitialMenu();
	}

	if (Exit != selectedOption)
	{
		HandleUserOption(selectedOption);
	}

	cout << "Terminating the program" << endl;
	system("pause");
	return 0;
}