#include "FileReader.hpp"


FileReader::FileReader(const std::filesystem::path& fileName, const std::streampos& startPosition, const std::streampos& endPosition) :
	m_endPosition(endPosition)
{
	m_fileStream.open(fileName);

	if (startPosition != 0)
	{
		m_fileStream.seekg(startPosition);
		while (m_fileStream.peek() != EOF && m_fileStream.peek() != '\n')
		{
			m_fileStream.get();
		}
		m_fileStream.get();
	}
}

FileReader::~FileReader()
{
	m_fileStream.close();
}

auto FileReader::getNextLine() -> std::optional<std::string>
{
	if (m_fileStream.tellg() > m_endPosition || m_fileStream.tellg() == EOF)
	{
		return std::nullopt;
	}

	std::string line;
	std::getline(m_fileStream, line);
	return line;
}