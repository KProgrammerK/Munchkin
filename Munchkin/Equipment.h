// Player use equipment to improve yourself 
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Artifact.h"
#include "Constans.h"

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

	//Functions for work with cell of equipment
	bool busyCell(EquipmentType) const;
	void addCell();

	void addArtifact(EquipmentType,Artifact&);
	void showEquipment() const;

	// When happens swap artifacts and need 
	// add artifact from equipment in backapck
	Artifact& getArtifact(EquipmentType type) const;
	
private:
	Artifact** m_equipment;
	int m_cell_equipment;
};
#endif // !EQUIPMENT_H
