#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>


Parser::Parser(const std::string &filepath) : filePath(filepath)
{
}


Parser::~Parser()
{
}

std::shared_ptr<DataList> Parser::Parse()
{
	std::ifstream file(filePath);

	std::string line;
	std::getline(file, line);

	// TODO: Add validation for the formatLine
	auto dataList = std::make_shared<DataList>(Split(line));

	while (std::getline(file, line))
	{
		dataList->AddElement(Split(line));
	}

	return dataList;
}

void Parser::Save(std::shared_ptr<DataList> list, const std::string &fileName)
{
	std::ofstream file(fileName);
	
	if (list->IsValid())
	{
		file << list;
	}
}

std::vector<std::string> Parser::Split(std::string strToSplit, char delimeter)
{
	std::stringstream ss(strToSplit);
	std::string item;
	std::vector<std::string> splittedStrings;
	while (std::getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}