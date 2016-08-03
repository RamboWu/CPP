#ifndef _STRING_UTILS_H_
#define _STRING_UTILS_H_

#include <string>
#include <sstream>
#include <vector>

class StringUtils {
public:

	static void split(std::vector<std::string> &dest, const std::string &str, char* sep) {
		int pos = 0;
		int index = str.find(sep, pos);
		while (pos < str.length() && index != std::string::npos) {
			std::string temp = str.substr(pos, index - pos);
			dest.push_back(temp);
			pos = index + 1;
			index = str.find(sep, pos);
		}

		if (pos < str.length()) {
			std::string temp = str.substr(pos, str.length() - pos);
			dest.push_back(temp);
		}
		else if (pos == str.length()) {
			dest.push_back("");
		}
	}
	static void StringUtils::ToString(int num, std::string& dest) {
		std::stringstream ss;
		ss << num;
		ss >> dest;
	}

	static void StringUtils::ReplaceAll(std::string& str, const std::string& old_value, const std::string& new_value) {
		while (true) {
			std::string::size_type   pos(0);
			if ((pos = str.find(old_value)) != std::string::npos)
				str.replace(pos, old_value.length(), new_value);
			else   break;
		}
	}
};


#endif