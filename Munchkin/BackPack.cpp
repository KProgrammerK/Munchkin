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
