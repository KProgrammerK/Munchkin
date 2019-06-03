/* Player use backpack for storage artifacts(max 10).
** Player can get artifact from backpack and add it in equipment to improve AHD
** When player get artifact from backpack, it deletes.
** If player already have artifact in equipment then artifact puts from equipment in backpack
** If player don't want swap artifacts then artifact doesn't delete from backpack.
*/
#ifndef BACKPACK_H
#define BACKPACK_H

#include "Artifact.h"
#include "Constans.h"

#include <vector>
#include <algorithm>

class BackPack
{
public:
	BackPack();
	~BackPack();

	//---------------------------------------------
	// Functions for interactions with backpack
	void addArtifact(const Artifact&);

	// With    change m_cell_backpack(reduce)
	// When artifact deletes from backpack
	void emptyBackPack();

    // Without change m_cell_backpack
	// Reset values of cells of backpack
	void emptyBackPack(bool);

	// When artifact gets from backpack 
    // it deletes right away so return by value
	void deleteArtifact(int);
	Artifact getArtifact(int);

	// When backpack is overflow
	void deleteUselessArtifacts(std::vector<int>&);

	void showBackPack() const;
	int getSize() const;
	//----------------------------------------------

private:
	Artifact** m_backpack;
	int   m_cell_backpack;
};
#endif // !BACKPACK_H
