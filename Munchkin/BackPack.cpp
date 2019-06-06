#include "BackPack.h"

// Initially cell of backpack points on zero cell of backpack
// In constructor of class BackPack memory stands out for backpack and for everybody cell of backpack
BackPack::BackPack() :
	m_cell_backpack{ 0 }
{
	m_backpack = new Artifact * [MunchkinConst::max_size_backpack];
	for (int cell = 0; cell < MunchkinConst::max_size_backpack; ++cell)
		m_backpack[cell] = new Artifact;
}

// In destructor of class BackPack memory freeds up for backpack
BackPack::~BackPack() { delete[] m_backpack; }

void BackPack::addArtifact(const Artifact& artifact)
{
	*m_backpack[m_cell_backpack] = artifact;
	++m_cell_backpack;
}

void BackPack::emptyBackPack()
{
	for (int cell = 0; cell < MunchkinConst::max_size_backpack; ++cell)
		*m_backpack[cell] = Artifact{};

	m_cell_backpack = 0;
}

Artifact BackPack::getArtifact(int index)
{
	--index;

	Artifact artifact = *m_backpack[index];

	if (m_cell_backpack == 1)
		emptyBackPack();
	else
		MunchkinTemplates::deleteArtifact<Artifact>(m_backpack, m_cell_backpack, index);

	return artifact;
}

void BackPack::deleteUselessArtifacts(std::vector<int>& v)
{
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());

	if (v.size() == m_cell_backpack || v[0] == MunchkinConst::clearAllArtifacts)
	{
		emptyBackPack();
		return;
	}

	for (size_t cell = 0; cell < v.size(); ++cell)
		MunchkinTemplates::deleteArtifact<Artifact>(m_backpack, m_cell_backpack, --v[cell]);
}

void BackPack::showBackPack() const
{
	if (m_cell_backpack == 0)
	{
		std::cout << "Your backPack is empty.\n";
		return;
	}

	std::cout << "In your backpack:\n";
	for (int cell = 0; cell < m_cell_backpack; ++cell)
		std::cout << *m_backpack[cell] << " \t[" << cell + 1 << "]\n";
}

int BackPack::getSize() const { return m_cell_backpack; }