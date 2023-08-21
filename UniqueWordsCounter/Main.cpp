#include "UniqueWordsCounterThreaded.hpp"
#include "FileReader.hpp"
#include "WordParser.hpp"
#include "UniqueWordsCounter.hpp"

#include <iostream>

int main()
{
	auto uniqueWordCounterCreator = [](const std::filesystem::path& fileName,
		const std::streampos& startPosition, const std::streampos& endPosition) {
			auto fileReader = std::make_unique<FileReader>(fileName, startPosition, endPosition);
			auto wordParser = std::make_unique<WordParser>(std::move(fileReader));
			return std::make_unique<UniqueWordsCounter>(std::move(wordParser));
		};

	const auto fileName = "Test.txt";
	const auto numberOfThreads = 2;
	UniqueWordsCounterThreaded counter(fileName, numberOfThreads, uniqueWordCounterCreator);
	std::cout << "Number of unique words in '" << fileName << "' are: " << counter.getCount() << std::endl;

	return 0;
}