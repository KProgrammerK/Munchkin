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
	void emptyBackPack();
	void emptyBackPack(bool);
	//                 index
	void deleteArtifact(int);
	void deleteUselessArtifacts(std::vector<int>&);
	void printBackPack() const;
	//                 index
	Artifact getArtifact(int);

private:
	Artifact** m_backpack;
	int   m_cell_backpack;
};
#endif // !BACKPACK_H
