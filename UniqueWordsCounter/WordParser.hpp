#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

class FileReader;

class WordParser
{
public:
	WordParser(std::unique_ptr<FileReader> fileReader);
	~WordParser();

	auto getNextWord() -> std::optional<std::string>;

private:
	void parseLine(const std::string& line);

private:
	std::unique_ptr<FileReader> m_fileReader;
	std::vector<std::string> m_parsedWords;
	int m_currentWordIdx = 0;
};