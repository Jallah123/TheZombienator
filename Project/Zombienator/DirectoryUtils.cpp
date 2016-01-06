#include "DirectoryUtils.h"
#include "dirent.h"
#include <iostream>

std::vector<std::string> DirectoryUtils::getFilesFromDirectory(std::string folderName, std::string extension, bool returnFullPath)
{
	std::vector<std::string> files;
	DIR* dir;
	struct dirent* ent;
	std::string folder = "assets/" + folderName + '/';
	extension.insert(0, ".");
	if ((dir = opendir(folder.c_str())) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			std::string fileName = ent->d_name;
			if (fileName.substr(fileName.rfind('.'), extension.size()) == extension || extension == ".")
			{
				if (returnFullPath)
					fileName = folder + fileName;
				files.push_back(fileName);
			}
		}
		closedir(dir);
	}
	else {
		std::cerr << "Error opening dir" << std::endl;
	}
	return files;
}