#pragma once

#include <string>
#include <optional>
#include <fstream> 
#include <filesystem>


class FileReader
{
public:
	FileReader(const std::filesystem::path& fileName, const std::streampos& startPosition, const std::streampos& endPosition);
	~FileReader();

	auto getNextLine() -> std::optional<std::string>;

private:
	std::ifstream m_fileStream;
	std::streampos m_endPosition;
};