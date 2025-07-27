#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

std::vector<std::string> getLineVector()
{
	std::vector<std::string> splittedData;
	std::string line;
	while (getline(std::cin, line))
	{
		splittedData.push_back(line);
	}
	return splittedData;
}

std::string stringify(std::vector<std::string> vt){
	std::string str;
	for (std::string s : vt){
		str.append(s + '\n');
	}
	return str;
}

std::string makePrettier(
	std::vector<std::string>::iterator& it,
	std::vector<std::string>::iterator end)
{
	std::string prettierData;
	std::vector<std::string> buffer;
	std::string endscope;
	while (it != end)
	{
		buffer.push_back(*it);
		if (it->find('{') != std::string::npos)
		{
			prettierData.append(stringify(buffer));
			buffer.clear();
			prettierData.append(makePrettier(++it, end));
		}
		else if (it->find('}') != std::string::npos)
		{
			endscope = buffer.back();
			buffer.pop_back();
			std::sort(buffer.begin(), buffer.end());
			prettierData.append(stringify(buffer));
			prettierData.append(endscope + '\n');
			buffer.clear();
			return prettierData;
		}
		it++;
	}
	return prettierData;
}

int main()
{
	std::vector<std::string> splittedData = getLineVector();
	std::vector<std::string>::iterator it = splittedData.begin();
	std::string prettierStr = makePrettier(it, splittedData.end());
	std::cout << prettierStr << std::endl;
}
