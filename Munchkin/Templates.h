#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <functional>

namespace MunchkinTemplates
{
	template<typename T>
	void deleteArtifact(T**& array, int& size, int index)
	{
		if (index < 0 || index >= size)
		{
			std::cout << "You entered incorrect index[" << index << "]\n";
			return;
		}

		T** tmp_array = new T * [size - 1];
		for (int cell = 0; cell < size - 1; ++cell)
			tmp_array[cell] = new T;

		for (int before = 0; before < index; ++before)
			* tmp_array[before] = *array[before];

		for (int after = index + 1; after < size; ++after)
			* tmp_array[after - 1] = *array[after];

		--size;

		for (int cell = 0; cell < size; ++cell)
			* array[cell] = *tmp_array[cell];

		delete[] tmp_array;
	}
}
#endif // !TEMPLATES_H
