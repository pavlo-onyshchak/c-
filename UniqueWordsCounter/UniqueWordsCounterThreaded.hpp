#pragma once

#include <set>
#include <string>
#include <vector>
#include <filesystem>
#include <future>

class UniqueWordsCounter;

class UniqueWordsCounterThreaded
{
public:
	using UniqueWordCounterCreator = std::function<std::unique_ptr<UniqueWordsCounter>(const std::filesystem::path& fileName,
		const std::streampos& startPosition, const std::streampos& endPosition)>;

public:
	UniqueWordsCounterThreaded(const std::filesystem::path& fileName, int numberOfThreads,
		UniqueWordCounterCreator counterCreator);
	~UniqueWordsCounterThreaded();

	int getCount();

private:
	void createCounters(const std::filesystem::path& fileName, int numberOfThreads, UniqueWordCounterCreator counterCreator);
	void initWorkers();

private:
	using UniqueWords = std::set<std::string>;

private:
	std::vector<std::unique_ptr<UniqueWordsCounter>> m_counters;
	std::vector<std::future<UniqueWords>> m_workers;
};