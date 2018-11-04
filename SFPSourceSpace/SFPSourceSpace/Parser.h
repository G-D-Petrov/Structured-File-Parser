#pragma once
#include <vector>
#include <string>
#include "DataList.h"

class Parser
{
public:
	Parser(const std::string &filepath);
	~Parser();

	DataList& Parse();

private:
	std::vector<std::string> Split(std::string strToSplit, char delimeter = '|');

	std::string filePath;
};

