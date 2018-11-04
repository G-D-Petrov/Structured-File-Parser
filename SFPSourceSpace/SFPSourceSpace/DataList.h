#pragma once
#include <vector>
#include <string>

class DataList
{
public:
	DataList(const std::vector<std::string> & format);
	~DataList();

	bool IsValid() { return isValid; }

	void AddElement(const std::vector<std::string> & data);
	
	union Element
	{
		double _double;
		float _float;
		unsigned long _ulong;
		long _long;
		unsigned int _uint;
		int _int;
		unsigned char _uchar;
		char _char;
		bool _bool;
	};

private:
	
	struct Node
	{
		std::vector<Element> data;
		Node *prev;
		Node *next;
	};

	void DeleteList();

	Node *start;
	Node *current;
	std::vector<std::string> format;
	bool isValid;
};

