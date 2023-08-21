#pragma once

#include <set>
#include <string>
#include <memory>

class WordParser;

class UniqueWordsCounter
{
public:
	explicit UniqueWordsCounter(std::unique_ptr<WordParser> parser);
	~UniqueWordsCounter();

	auto getUniqueWords() -> std::set<std::string>;

private:
	std::unique_ptr<WordParser> m_parser;
};