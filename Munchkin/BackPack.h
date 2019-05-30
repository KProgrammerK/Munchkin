#ifndef BACKPACK_H
#define BACKPACK_H

#include "Artifact.h"

#include <cassert>
#include <vector>
#include <algorithm>

class BackPack
{
public:
	BackPack();
	~BackPack();

	//Functions for interactions with backpack
	void addArtifact(const Artifact&);
	// With    change m_cell_backpack
	void emptyBackPack();
    // Without change m_cell_backpack
	void emptyBackPack(bool);

	//                 index
	void deleteArtifact(int);
	void deleteUselessArtifacts(std::vector<int>&);

	void showBackPack() const;
	int getSize() const;
	//                 index
	// When artifact gets from backpack 
	// it deletes right away so return by value
	Artifact getArtifact(int);

private:
	Artifact** m_backpack;
	int   m_cell_backpack;
};
#endif // !BACKPACK_H
