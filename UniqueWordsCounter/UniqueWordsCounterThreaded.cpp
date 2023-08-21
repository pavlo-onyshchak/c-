#include "UniqueWordsCounterThreaded.hpp"
#include "UniqueWordsCounter.hpp"
#include "FileReader.hpp"


UniqueWordsCounterThreaded::UniqueWordsCounterThreaded(const std::filesystem::path& fileName, int numberOfThreads,
	UniqueWordCounterCreator counterCreator)
{
	createCounters(fileName, numberOfThreads, counterCreator);
	initWorkers();
}

UniqueWordsCounterThreaded::~UniqueWordsCounterThreaded() = default;

int UniqueWordsCounterThreaded::getCount()
{
	std::set<std::string> uniqueWords;
	for (auto& worker : m_workers)
	{
		uniqueWords.merge(worker.get());
	}

	return uniqueWords.size();
}

void UniqueWordsCounterThreaded::createCounters(const std::filesystem::path& fileName, int numberOfThreads,
	UniqueWordCounterCreator counterCreator)
{
	const auto fileSize = std::filesystem::file_size(fileName);
	const auto offset = fileSize / numberOfThreads;
	auto begin = 0;
	for (int i = 0; i < numberOfThreads; ++i)
	{
		auto end = i == numberOfThreads - 1 ? fileSize : begin + offset;
		auto uniqueWordsCounter = counterCreator(fileName, begin, end);
		m_counters.push_back(std::move(uniqueWordsCounter));
		begin += offset + 1;
	}
}

void UniqueWordsCounterThreaded::initWorkers()
{
	for (const auto& counter : m_counters)
	{
		auto worker = std::async(std::launch::async, &UniqueWordsCounter::getUniqueWords, counter.get());
		m_workers.push_back(std::move(worker));
	}
}