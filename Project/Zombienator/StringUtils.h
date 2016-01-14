#pragma once
#include <vector>
#include <string>
#include <sstream>

class StringUtils
{
public:
	static std::vector<std::string>& Split(const std::string& s, char delim, std::vector<std::string>& elems);
private:
	StringUtils() {};
	~StringUtils() {};
};

