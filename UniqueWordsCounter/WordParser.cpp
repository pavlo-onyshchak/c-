#include "WordParser.hpp"
#include "FileReader.hpp"

#include <sstream>


WordParser::WordParser(std::unique_ptr<FileReader> fileReader) :
	m_fileReader(std::move(fileReader))
{
}

WordParser::~WordParser() = default;

auto WordParser::getNextWord() -> std::optional<std::string>
{
	if (m_currentWordIdx < m_parsedWords.size())
	{
		return m_parsedWords[m_currentWordIdx++];
	}

	std::optional<std::string> nextLine;
	do
	{
		nextLine = m_fileReader->getNextLine();
	} while (nextLine.has_value() && nextLine.value().empty());

	if (nextLine.has_value())
	{
		parseLine(nextLine.value());
		return m_parsedWords[m_currentWordIdx++];
	}

	return std::nullopt;
}

void WordParser::parseLine(const std::string& line)
{
	m_parsedWords.clear();
	m_currentWordIdx = 0;

	std::istringstream iss(line);
	std::string word;
	while (iss >> word) {
		m_parsedWords.push_back(word);
	}
}