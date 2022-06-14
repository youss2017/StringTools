#pragma once
#include <string>
#include <string_view>
#include <vector>

/// <summary>
/// Finds the first occurence of a substring inside std::string
/// </summary>
/// <param name="s">Source String</param>
/// <param name="val">String value to find in source string</param>
/// <returns>Returns position of the first character of [val] or -1 if it could be found.</returns>
int st_IndexOf(std::string_view s, const char* val);

/// <summary>
/// Finds the last occurence of a substring inside std::string
/// </summary>
/// <param name="s">Source String</param>
/// <param name="val">String value to find in source string</param>
/// <returns>Returns position of the first character of [val] or -1 if it could be found.</returns>
int st_LastIndexOf(std::string_view s, const char* val);

/// <summary>
/// Splits a string using regex
/// </summary>
/// <param name="s">Input String</param>
/// <param name="regex">regex expression</param>
/// <returns>List of all splits</returns>
std::vector<std::string> st_SplitString(std::string_view s, const char* regex);

/// <summary>
/// Replaces the first occurence of a certain substring with another value
/// </summary>
/// <param name="s">Source string</param>
/// <param name="find">String to find in the source string</param>
/// <param name="replaceWith">The replacement</param>
/// <returns>The string after the replacement, if the find substr could not be found, it returns the original string.</returns>
std::string st_Replace(std::string_view s, const char* find, const char* replaceWith);

/// <summary>
/// Replaces the all occurence of a certain substring with another value
/// </summary>
/// <param name="s">Source string</param>
/// <param name="find">String to find in the source string</param>
/// <param name="replaceWith">The replacement</param>
/// <returns>The string after the replacement, if the find substr could not be found, it returns the original string.</returns>
std::string st_ReplaceAll(std::string_view s, const char* find, const char* replaceWith);

/// <summary>
/// Checks whether the string contains a certain substring
/// </summary>
/// <param name="s"></param>
/// <param name="find"></param>
/// <returns></returns>
bool st_Contains(std::string_view s, const char* find);

/// <summary>
/// Checks whether the string starts with a certain substring
/// </summary>
/// <param name="s"></param>
/// <param name="find"></param>
/// <returns></returns>
bool st_StartsWith(std::string_view s, const char* find);


/// <summary>
/// Checks whether the string ends with a certain substring
/// </summary>
/// <param name="s"></param>
/// <param name="find"></param>
/// <returns></returns>
bool st_EndsWith(std::string_view s, const char* find);

/// <summary>
/// Converts input string to uppercase
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
std::string st_UpperCase(std::string_view s);

/// <summary>
/// Converts input string to lowercase
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
std::string st_LowerCase(std::string_view s);

/// <summary>
/// Removes spaces from left and right side of the string (not inside the string)
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
std::string st_Trim(const std::string& s);
