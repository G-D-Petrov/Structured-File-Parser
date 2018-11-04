#include "DataList.h"

DataList::DataList(const std::vector<std::string> &format) : format(format), isValid(false), size(0)
{
	start = new Node();
	start->next = NULL;
	start->prev = NULL;
	current = start;
	++size;
}

DataList::~DataList()
{
	DeleteList();
	isValid = false;
	size = 0;
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

void DataList::AddDataToNode(Node *node, const std::vector<std::string> & data)
{
	for (unsigned int i = 0; i < format.size(); ++i)
	{
		if ("double" == format[i])
		{
			Element el;
			el._double = stod(data[i]);
			node->data.push_back(el);
		}
		else if ("float" == format[i])
		{
			Element el;
			el._float = stof(data[i]);
			node->data.push_back(el);
		}
		else if ("ulong" == format[i])
		{
			Element el;
			el._ulong = stoul(data[i]);
			node->data.push_back(el);
		}
		else if ("long" == format[i])
		{
			Element el;
			el._long = stol(data[i]);
			node->data.push_back(el);
		}
		else if ("uint" == format[i])
		{
			Element el;
			el._uint = stoi(data[i]);
			node->data.push_back(el);
		}
		else if ("int" == format[i])
		{
			Element el;
			el._int = stoi(data[i]);
			node->data.push_back(el);
		}
		else if ("uchar" == format[i])
		{
			Element el;
			el._uchar = data[i][0];
			node->data.push_back(el);
		}
		else if ("char" == format[i])
		{
			Element el;
			el._char = data[i][0];
			node->data.push_back(el);
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

			node->data.push_back(el);
		}
		else
		{
			throw std::invalid_argument("Unknown format in file");
		}
	}
}

void DataList::AddElement(const std::vector<std::string> & data)
{
	AddDataToNode(current, data);

	current->next = new Node();
	current->next->prev = current;
	current = current->next;
	current->next = NULL;
	++size;

	isValid = true;
}

DataList::Node* DataList::GetNodeAtIndex(const unsigned int index)
{
	Node *curr_position = start;
	unsigned int curr_index = 0;

	while (index != curr_index)
	{
		curr_position = curr_position->next;
		++curr_index;
	}

	return curr_position;
}

void DataList::AddElementAtIndex(const unsigned int index, const std::vector<std::string> & data)
{
	// TODO: Validate node
	Node *curr_position = GetNodeAtIndex(index);

	Node *temp = new Node();
	AddDataToNode(temp, data);
	curr_position->prev->next = temp;
	temp->next = curr_position;
	curr_position->prev = temp;
	++size;

	isValid = true;
}

void DataList::RemoveAtIndex(const unsigned int index)
{
	// TODO: Validate node
	Node *curr_position = GetNodeAtIndex(index);
	curr_position->prev->next = curr_position->next;
	delete curr_position;
	--size;

	if (NULL == start)
	{
		isValid = false;
	}
}

bool DataList::CompareElements(Element first, Element second, std::string type)
{
	bool result = false;

	if ("double" == type)
	{
		result =  first._double < second._double;
	}
	else if ("float" == type)
	{
		result = first._float < second._float;
	}
	else if ("ulong" == type)
	{
		result = first._ulong < second._ulong;
	}
	else if ("long" == type)
	{
		result = first._long < second._long;
	}
	else if ("uint" == type)
	{
		result = first._uint < second._uint;
	}
	else if ("int" == type)
	{
		result = first._int < second._int;
	}
	else if ("uchar" == type)
	{
		result = first._uchar < second._uchar;
	}
	else if ("char" == type)
	{
		result = first._char < second._char;
	}
	else if ("bool" == type)
	{
		result = first._bool < second._bool;
	}
	else
	{
		throw std::invalid_argument("Unknown format in file");
	}

	return result;
}

void DataList::Sort()
{
	for (int i = 0; i < size; ++i)
	{
		Node *curr_position = start;
		while (NULL != curr_position->next)
		{
			if (!CompareElements(curr_position->data[0], curr_position->next->data[0], format[0]))
			{
				Node * X = curr_position->prev;
				Node * A = curr_position;
				Node * B = curr_position->next;
				Node * Y = curr_position->next->next;
				
				A->prev = B;
				A->next = Y;
				B->prev = X;
				B->next = A;

				curr_position = A;
			}
		}
	}
}

std::string DataList::ntos(Node *node, const std::vector<std::string> & format)
{
	std::string result = "";
	for(unsigned int i = 0; i < node->data.size(); ++i)
	{
		result += utos(node->data[i], format[i]);
		result += "|";
	}

	if (!result.empty())
	{
		result.pop_back();
	}
	
	return result;
}

std::string DataList::utos(Element element, const std::string &type)
{
	std::string result = "";

	if ("double" == type)
	{
		result = std::to_string(element._double);
	}
	else if ("float" == type)
	{
		result = std::to_string(element._float);
	}
	else if ("ulong" == type)
	{
		result = std::to_string(element._ulong);
	}
	else if ("long" == type)
	{
		result = std::to_string(element._long);
	}
	else if ("uint" == type)
	{
		result = std::to_string(element._uint);
	}
	else if ("int" == type)
	{
		result = std::to_string(element._int);
	}
	else if ("uchar" == type)
	{
		result = element._uchar;
	}
	else if ("char" == type)
	{
		result = element._char;
	}
	else if ("bool" == type)
	{
		if (true == element._bool)
		{
			result = "true";
		}
		else
		{
			result = "false";
		}
	}
	else
	{
		throw std::invalid_argument("Unknown format in file");
	}

	return result;
}
