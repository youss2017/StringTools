#define _CRT_SECURE_NO_WARNINGS
#include "fileutil.hpp"
#include <filesystem>
#include <stdio.h>

std::vector<char> utility::ReadTextFile(std::string_view path)
{
    std::vector<char> text;
    text.push_back(0);
    try {
        std::filesystem::path location(path);
        if (std::filesystem::is_regular_file(location)) {
            FILE* input = fopen(path.data(), "r");
            if (!input) {
                return text;
            }
            fseek(input, 0, SEEK_END);
            int size = ftell(input);
            fseek(input, 0, SEEK_SET);
            text.resize(size + 1);
            size = fread(&text[1], 1, size, input);
            fclose(input);
            text.resize(size + 1);
            text.shrink_to_fit();
            text[0] = 1;
        }
    }
    catch (std::exception) {
        return text;
    }
    return text;
}

std::vector<uint8_t> utility::ReadBinaryFile(std::string_view path)
{
    std::vector<uint8_t> binary;
    binary.push_back(0);
    try {
        std::filesystem::path location(path);
        if (std::filesystem::is_regular_file(location)) {
            FILE* input = fopen(path.data(), "rb");
            if (!input) {
                return binary;
            }
            fseek(input, 0, SEEK_END);
            int size = ftell(input);
            fseek(input, 0, SEEK_SET);
            binary.resize(size + 1);
            size = fread(&binary[1], 1, size, input);
            fclose(input);
            binary.resize(size + 1);
            binary.shrink_to_fit();
            binary[0] = 1;
        }
    }
    catch (std::exception) {
        return binary;
    }
    return binary;
}

bool utility::WriteBinaryFile(std::string_view path, void* data, uint64_t size)
{
    FILE* output = fopen(path.data(), "wb");
    if (!output)
        return false;
    fwrite(data, 1, size, output);
    fclose(output);
    return true;
}

bool utility::WriteTextFile(std::string_view path, char* text, uint64_t size)
{
    FILE* output = fopen(path.data(), "w");
    if (!output)
        return false;
    fwrite(text, 1, size, output);
    fclose(output);
    return true;
}

