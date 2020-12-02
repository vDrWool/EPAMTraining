#pragma once
#include <fstream>
#include <iostream>

namespace EPAM
{
	class RAIIFiles
	{
	public:
		RAIIFiles(const char* path);

		std::fstream* operator -> ();

		~RAIIFiles();
	private:
		std::fstream m_file{};
	};
}