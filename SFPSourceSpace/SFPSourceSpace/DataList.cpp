#include "DataList.h"

DataList::DataList(const std::vector<std::string> &format) : format(format), isValid(false)
{
	start = new Node();
	start->next = NULL;
	start->prev = NULL;
	current = start;
}

DataList::~DataList()
{
	DeleteList();
	isValid = false;
}

void DataList::DeleteList()
{
	if (nullptr != start)
	{
		Node *temp;
		while (NULL != start)
		{
			temp = start;
			start = start->next;
			
 			delete temp;
		}
	}
}

void DataList::AddElement(const std::vector<std::string> & data)
{
	for (unsigned int i = 0; i < format.size(); ++i)
	{
		if ("double" == format[i])
		{
			Element el;
			el._double = stod(data[i]);
			current->data.push_back(el);
		}
		else if ("float" == format[i])
		{
			Element el;
			el._float = stof(data[i]);
			current->data.push_back(el);
		}
		else if ("ulong" == format[i])
		{
			Element el;
			el._ulong = stoul(data[i]);
			current->data.push_back(el);
		}
		else if ("long" == format[i])
		{
			Element el;
			el._long = stol(data[i]);
			current->data.push_back(el);
		}
		else if ("uint" == format[i])
		{
			Element el;
			el._uint = stoi(data[i]);
			current->data.push_back(el);
		}
		else if ("int" == format[i])
		{
			Element el;
			el._int = stoi(data[i]);
			current->data.push_back(el);
		}
		else if ("uchar" == format[i])
		{
			Element el;
			el._uchar = data[i][0];
			current->data.push_back(el);
		}
		else if ("char" == format[i])
		{
			Element el;
			el._char = data[i][0];
			current->data.push_back(el);
		}
		else if ("bool" == format[i])
		{
			Element el;
			if ("1" == data[i] || "true" == data[i])
			{
				el._bool = true;
			}
			else
			{
				el._bool = false;
			}

			current->data.push_back(el);
		}
		else
		{
			throw std::invalid_argument("Unknown format in file");
		}
	}

	current->next = new Node();
	current->next->prev = current;
	current = current->next;
	current->next = NULL;
}
