#include "RAIIFiles.h"

namespace EPAM
{
	RAIIFiles::RAIIFiles(const char* path)
	{
		this->m_file.open(path);

		std::cout << "File opened!\n";
	}

	std::fstream* RAIIFiles::operator -> ()
	{
		return &this->m_file;
	}

	RAIIFiles::~RAIIFiles()
	{
		this->m_file.close();
		
		std::cout << "File closed!\n";
	}
}