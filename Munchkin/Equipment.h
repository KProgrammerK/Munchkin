#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Artifact.h"

class Equipment
{
public:

	enum class EquipmentType
	{
		HEAD,
		BODY,
		WEAPON
	};

	 Equipment();
	~Equipment();

	bool busyCell(EquipmentType) const;
	void addArtifact(EquipmentType,Artifact&);
	void showEquipment() const;
	void addCell();

	Artifact& getArtifact(EquipmentType type) const { return *m_equipment[static_cast<int>(type)]; }
	
private:
	Artifact** m_equipment;
	int m_cell_equipment;
};
#endif // !EQUIPMENT_H
