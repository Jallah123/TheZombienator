#pragma once
#include <vector>
#include <string>

class DirectoryUtils
{
public:
	static std::vector<std::string> getFilesFromDirectory(std::string folderName, std::string extension = "", bool returnFullPath = false);
private:
	DirectoryUtils() {};
	~DirectoryUtils() {};
};

