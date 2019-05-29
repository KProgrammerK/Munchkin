#include "BackPack.h"

// Initially cell of backpack points on zero cell of backpack
// In constructor of class BackPack memory stands out for backpack and for everybody cell of backpack
BackPack::BackPack() :
	m_cell_backpack{ 0 }
{
	m_backpack = new Artifact * [10];
	for (int cell = 0; cell < 10; ++cell)
		m_backpack[cell] = new Artifact;
}

// In destructor of class BackPack memory freeds up for backpack
BackPack::~BackPack() { delete[] m_backpack; }

void BackPack::addArtifact(const Artifact& artifact)
{
	if(m_backpack)
	*m_backpack[m_cell_backpack] = artifact;
	++m_cell_backpack;
}

void BackPack::printBackPack() const
{
	if (m_cell_backpack == 0)
	{
		std::cout << "Your backPack is empty.\n";
		return;
	}

	std::cout << "In your backpack:\n";
	for (int cell = 0; cell < m_cell_backpack; ++cell)
		std::cout << *m_backpack[cell] << "  [" << cell+1 << "]\n";
}

void BackPack::emptyBackPack()
{
	for (int cell = 0; cell < m_cell_backpack; ++cell)
		*m_backpack[cell] = Artifact{};

	m_cell_backpack = 0;
}

void BackPack::emptyBackPack(bool)
{
	for (int cell = 0; cell < m_cell_backpack; ++cell)
		*m_backpack[cell] = Artifact{};

}
void BackPack::deleteArtifact(int index)
{
	if (index < 0 || index >= m_cell_backpack)
	{
		std::cout << "You entered incorrect index [" << index << "]\n";
		return;
	}

	if (m_cell_backpack == 1)
	{
		emptyBackPack();
		return;
	}

	Artifact** tmp_backpack = new Artifact * [m_cell_backpack - 1];
	for (int cell = 0; cell < m_cell_backpack - 1; ++cell)
		tmp_backpack[cell] = new Artifact;

	for (int before = 0; before < index; ++before)
		*tmp_backpack[before] = *m_backpack[before];

	for (int after = index + 1; after < m_cell_backpack; ++after)
		*tmp_backpack[after - 1] = *m_backpack[after];

	emptyBackPack(true);

	--m_cell_backpack;

	for (int cell = 0; cell < m_cell_backpack; ++cell)
		*m_backpack[cell] = *tmp_backpack[cell];

	delete[] tmp_backpack;
}

void BackPack::deleteUselessArtifacts(std::vector<int>& v)
{
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());

	for (size_t cell = 0; cell < v.size(); ++cell)
		deleteArtifact(--v[cell]);
}

Artifact BackPack::getArtifact(int index)
{
	--index;

	if (index < 0 || index >= m_cell_backpack)
	{
		std::cout << "You entered incorrect index [" << index << "]\n";
		return Artifact{};
	}

	Artifact artifact = *m_backpack[index];

	deleteArtifact(index);

	return artifact;
}