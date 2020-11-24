#pragma once
#include <fstream>
#include <iostream>

namespace EPAM
{
	class RAIIFiles
	{
	public:
		RAIIFiles(const char* path);

		~RAIIFiles();
	private:
		std::fstream m_file{};
	};
}