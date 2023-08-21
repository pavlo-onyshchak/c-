#include "UniqueWordsCounter.hpp"
#include "WordParser.hpp"


UniqueWordsCounter::UniqueWordsCounter(std::unique_ptr<WordParser> parser) : m_parser(std::move(parser))
{
}

UniqueWordsCounter::~UniqueWordsCounter() = default;

auto UniqueWordsCounter::getUniqueWords() -> std::set<std::string>
{
	std::set<std::string> uniqueWords;
	while (auto word = m_parser->getNextWord())
	{
		uniqueWords.insert(word.value());
	}

	return uniqueWords;
}