#pragma once
#include <vector>
#include <string>
#include "DataList.h"

class Parser
{
public:
	Parser(const std::string &filepath);
	~Parser();

	std::shared_ptr<DataList> Parse();
	void Save(std::shared_ptr<DataList> list, const std::string &fileName);

private:
	std::vector<std::string> Split(std::string strToSplit, char delimeter = '|');

	std::string filePath;
};

