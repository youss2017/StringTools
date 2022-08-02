#include "stringtool.hpp"
#include <algorithm>

namespace utility {

	int IndexOf(std::string_view s, const char* val)
	{
		int len = strlen(val);
		if (len > s.length())
			return -1;
		int matchIndex = 0;
		for (int i = 0; i < s.length(); i++) {
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
		int len = strlen(val);
		if (len > s.length())
			return -1;
		int matchIndex = len - 1;
		for (int i = s.length() - 1; i >= 0; i--) {
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

	std::vector<std::string> SplitString(std::string_view s, const char* regex)
	{
		return std::vector<std::string>();
	}

	std::string Replace(std::string_view s, const char* find, const char* replaceWith)
	{
		int len = strlen(find);
		int matchIndex = 0;
		std::string result;
		for (int i = 0; i < s.length(); i++) {
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
		int len = strlen(find);
		int matchIndex = 0;
		int lastPos = 0;
		std::string result;
		for (int i = 0; i < s.length(); i++) {
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
		int len = strlen(find);
		if (len > s.length())
			return false;
		int matchIndex = 0;
		for (int i = 0; i < s.length(); i++) {
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
		int len = strlen(find);
		if (s.length() < len)
			return false;
		return strncmp(s.data(), find, len) == 0;
	}

	bool EndsWith(std::string_view s, const char* find)
	{
		int len = strlen(find);
		if (s.length() < len)
			return false;
		const char* end = (const char*)((char*)s.data() + s.length() - len - 1);
		return strcmp(end, find) == 0;
	}

	std::string UpperCase(std::string_view s)
	{
		std::string upperCase = s.data();
		std::transform(upperCase.begin(), upperCase.end(), upperCase.begin(), std::toupper);
		return upperCase;
	}

	std::string LowerCase(std::string_view s)
	{
		std::string lowerCase = s.data();
		std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), std::tolower);
		return lowerCase;
	}

	std::string Trim(const std::string& s)
	{
		int offsetStart = 0;
		int offsetEnd = s.length();
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
