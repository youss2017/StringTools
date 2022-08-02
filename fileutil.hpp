#pragma once
#include <string_view>
#include <cstdint>
#include <vector>

namespace utility {

	bool WriteBinaryFile(std::string_view path, void* data, size_t size);
	bool WriteTextFile(std::string_view path, char* text, size_t size);

	/// <summary>
	/// Reads file binary into vector. First element in vector determines success status.
	/// </summary>
	/// <returns>First element in vector determines success status. 1 == success, 0 == fail</returns>
	std::vector<uint8_t> ReadBinaryFile(std::string_view path);

	/// <summary>
	/// Reads file binary into vector. First element in vector determines success status.
	/// </summary>
	/// <returns>First element in vector determines success status. 1 == success, 0 == fail</returns>
	std::vector<char> ReadTextFile(std::string_view path);

}
