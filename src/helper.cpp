#include "helper.hpp"

std::string readFromFile(const std::string &filename) {
	std::ifstream ifs(filename);
	std::ostringstream oss;
	oss << ifs.rdbuf();
	return oss.str();
}

std::string readFromStdin() {
	std::ostringstream oss;
	oss << std::cin.rdbuf();
	return oss.str();
}

int countLines(std::string &s) {
	int cntLines = 0;
	for(char c : s) {
		cntLines += c == '\n';
	}
	return cntLines;
}

int countWords(std::string &s) {
	std::istringstream input(s);
	std::string words;
	int cntWords = 0;
	while(input >> words) {
		cntWords++;
	}
	return cntWords;
}

int countBytes(std::string &s) {
	return ssize(s);
}

int countMultiBytes(const std::string &s) {
	std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
	std::wstring wide_str = converter.from_bytes(s);
	return ssize(wide_str);
}