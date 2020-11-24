#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "Employer.h"

namespace EPAM::DB
{
	void loadData			(std::vector<Employer>& Employers);
	void EnterData			(std::vector<Employer>& employers);
	void AppendData			(const std::vector<Employer>& Employers, bool add);

	void sortByName			(std::vector<Employer>& Employers);
	void sortByAge			(std::vector<Employer>& Employers);

	void outputByMonth      (const std::vector<Employer>& Employers, unsigned month);
	void outputTheOldestMan (const std::vector<Employer>& Employers);
	void outputByFirstLetter(const std::vector<Employer>& Employers, char letter);
}