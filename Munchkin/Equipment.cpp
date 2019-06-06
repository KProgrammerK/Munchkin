#include "Equipment.h"

Equipment::Equipment() :
	m_cell_equipment{ 0 }
{
	m_equipment = new Artifact * [MunchkinConst::max_size_equipment];
	for (int cell = 0; cell < MunchkinConst::max_size_equipment; ++cell)
		m_equipment[cell] = new Artifact;
}

Equipment::~Equipment() { delete[] m_equipment; }

bool Equipment::busyCell(Equipment::EquipmentType type) const { return (m_equipment[static_cast<int>(type)]->getName() == "") ? true : false; }

void Equipment::addArtifact(Equipment::EquipmentType type, Artifact& artifact) { *m_equipment[static_cast<int>(type)] = artifact; }

void Equipment::showEquipment() const
{
	if (m_cell_equipment == 0)
	{
		std::cout << "Your equipment is empty.\n";
		return;
	}

	std::cout << "Your equipment:\n";
	for (int cell = 0; cell < MunchkinConst::max_size_equipment; ++cell)
	{
		if (m_equipment[cell]->getName() == "")
			continue;
		std::cout << *m_equipment[cell] << '\n';
	}
}

Artifact& Equipment::getArtifact(Equipment::EquipmentType type) const { return *m_equipment[static_cast<int>(type)]; }