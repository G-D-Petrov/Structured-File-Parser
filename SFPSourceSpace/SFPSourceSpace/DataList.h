#pragma once
#include <vector>
#include <string>

class DataList
{
public:
	DataList(const std::vector<std::string> & format);
	~DataList();

	bool IsValid() const { return isValid; }
	int TypesCount() const { return format.size(); }

	void AddElement(const std::vector<std::string> & data);
	void AddElementAtIndex(const unsigned int index, const std::vector<std::string> & data);
	void RemoveAtIndex(const unsigned int index);
	void Sort();

	friend std::ostream& operator<< (std::ostream& stream, std::shared_ptr<DataList> list)
	{
		std::string format_str;
		for (auto &type : list->format)
		{
			format_str += type;
			format_str += "|";
		}
		format_str.pop_back();
		stream << format_str << std::endl;

		Node* curr_position = list->start;

		for (int i = 0; i < list->size; ++i)
		{
			format_str = DataList::ntos(curr_position, list->format);
			stream << format_str << std::endl;
			curr_position = curr_position->next;
		}

		return stream;
	}

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

	void AddDataToNode(Node *node, const std::vector<std::string> & data);
	Node* GetNodeAtIndex(const unsigned int index);

	bool CompareElements(Element first, Element second, std::string type);
	static std::string ntos(Node *node, const std::vector<std::string> & format);
	static std::string utos(Element element, const std::string &type);

	Node *start;
	Node *current;
	std::vector<std::string> format;
	bool isValid;
	int size;
};

