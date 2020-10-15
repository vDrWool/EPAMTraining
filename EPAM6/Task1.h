#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <optional>

namespace EPAM
{
	template<typename Type>
	std::optional<Type> task(std::initializer_list<Type>&& elems)
	{
		Type mult{ 1 };
		std::for_each(elems.begin(), elems.end(), 
			[&mult] (Type elem)
			{
				mult *= elem;
			});
		return { mult };
	}

	std::string taskS(std::string str1, std::string str2)
	{
		std::string equalsSymbols{};

		size_t size{ str1.size() <= str2.size() ? str1.size() : str2.size() };

		for (auto i{ 0 }; i < static_cast<int>(size); i++)
		{
			if (str1[i] == str2[i])
				equalsSymbols += str1[i];
		}
		return equalsSymbols;
	}

	template<typename Type>
	std::optional<Type> task(std::vector<Type> elems)
	{
		Type mult{ 1 };
		std::for_each(elems.begin(), elems.end(),
			[&mult](Type elem)
			{
				mult *= elem;
			});
		return { mult };
	}
}