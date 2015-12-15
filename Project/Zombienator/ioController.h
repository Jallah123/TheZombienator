#pragma once
#include <fstream>
#include <cereal/archives/binary.hpp>
using namespace std;
class ioController
{
private:
	ioController();
	ioController(ioController const&) = delete;
	~ioController();

	string path = "assets\\ioFiles\\";

public:
	static ioController& GetInstance() {
		static ioController instance;
		return instance;
	}

	template <class givenClass>
	void SafeFile(string filename, givenClass gClass) {
		std::ofstream os(path + filename + ".cereal", std::ios::binary);
		cereal::JSONOutputArchive archive(os);
		archive(*gClass);
	};

	template <class givenClass>
	givenClass LoadFile(string filename, givenClass gClass) {
		std::ifstream os(path + filename + ".cereal", std::ios::binary);
		if (os.is_open()) {
			cereal::JSONInputArchive archive(os);
			archive(*gClass);
			return gClass;
		}
		return nullptr;
	};
	

};

