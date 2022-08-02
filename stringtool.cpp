#include "stringtool.hpp"
#include <regex>
#include <algorithm>

namespace utility {

	int IndexOf(std::string_view s, const char* val)
	{
		size_t len = strlen(val);
		if (len > s.length())
			return -1;
		size_t matchIndex = 0;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == val[matchIndex]) {
				matchIndex++;
				if (matchIndex == len)
					return i - len + 1;
			}
			else {
				if (s.length() - i < len)
					break;
				matchIndex = 0;
			}
		}
		return -1;
	}

	int LastIndexOf(std::string_view s, const char* val)
	{
		size_t len = strlen(val);
		if (len > s.length())
			return -1;
		size_t matchIndex = len - 1;
		for (size_t i = s.length() - 1; i >= 0; i--) {
			if (s[i] == val[matchIndex]) {
				matchIndex--;
				if (matchIndex == 0)
					return i - 1;
			}
			else {
				matchIndex = len - 1;
			}
		}
		return -1;
	}

	std::vector<std::string> SplitString(std::string_view s, const char* in_pattern)
	{
		std::vector<std::string> split_content;
		std::string content = s.data();
		std::regex pattern(in_pattern);
		std::copy(std::sregex_token_iterator(content.begin(), content.end(), pattern, -1),
			std::sregex_token_iterator(), back_inserter(split_content));
		return split_content;
	}

	std::string Replace(std::string_view s, const char* find, const char* replaceWith)
	{
		size_t len = strlen(find);
		size_t matchIndex = 0;
		std::string result;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == find[matchIndex]) {
				matchIndex++;
				if (matchIndex == len) {
					result = s.substr(0, i - len + 1);
					result += replaceWith;
					result += s.substr(i + 1);
					return result;
				}
			}
			else {
				matchIndex = 0;
			}
		}
		return std::string(s);
	}

	std::string ReplaceAll(std::string_view s, const char* find, const char* replaceWith)
	{
		size_t len = strlen(find);
		size_t matchIndex = 0;
		size_t lastPos = 0;
		std::string result;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == find[matchIndex]) {
				matchIndex++;
				if (matchIndex == len) {
					result += s.substr(lastPos, i - len + 1 - lastPos);
					result += replaceWith;
					lastPos = i + 1;
					matchIndex = 0;
				}
			}
			else {
				matchIndex = 0;
			}
		}
		result += s.substr(lastPos);
		return result;
	}

	bool Contains(std::string_view s, const char* find)
	{
		size_t len = strlen(find);
		if (len > s.length())
			return false;
		size_t matchIndex = 0;
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == find[matchIndex]) {
				matchIndex++;
				if (matchIndex == len)
					return true;
			}
			else {
				if (s.length() - i < len)
					break;
				matchIndex = 0;
			}
		}
		return false;
	}

	bool StartsWith(std::string_view s, const char* find)
	{
		size_t len = strlen(find);
		if (s.length() < len)
			return false;
		return strncmp(s.data(), find, len) == 0;
	}

	bool EndsWith(std::string_view s, const char* find)
	{
		size_t len = strlen(find);
		if (s.length() < len)
			return false;
		const char* end = (const char*)((char*)s.data() + s.length() - len - 1);
		return strcmp(end, find) == 0;
	}

	std::string UpperCase(std::string_view s)
	{
		std::string upperCase = s.data();
		//std::transform(upperCase.begin(), upperCase.end(), upperCase.begin(), std::toupper);
		for (size_t i = 0; i < upperCase.length(); i++) upperCase[i] = std::toupper(upperCase[i]);
		return upperCase;
	}

	std::string LowerCase(std::string_view s)
	{
		std::string lowerCase = s.data();
		//std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), std::tolower);
		for (size_t i = 0; i < lowerCase.length(); i++) lowerCase[i] = std::tolower(lowerCase[i]);
		return lowerCase;
	}

	std::string Trim(const std::string& s)
	{
		size_t offsetStart = 0;
		size_t offsetEnd = s.length();
		for (; offsetStart < s.length(); offsetStart++) {
			if (s[offsetStart] != ' ' && s[offsetStart] != '\t')
				break;
		}
		for (; offsetEnd > 0; offsetEnd--) {
			if (s[offsetEnd - 1] != ' ' && s[offsetEnd - 1] != '\t')
				break;
		}
		if (offsetEnd > offsetStart) {
			std::string trimed;
			trimed.resize((offsetEnd - offsetStart) + 1, 0);
			memcpy(&trimed[0], &s[offsetStart], offsetEnd - offsetStart);
			return trimed;
		}
		else {
			return "";
		}
	}

}
