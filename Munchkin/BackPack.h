#ifndef BACKPACK_H
#define BACKPACK_H

#include "Artifact.h"

class BackPack
{
public:
	BackPack();
	~BackPack();

	//Functions for interactions with backpack
	void addArtifact(const Artifact&);
	void printBackPack() const;

private:
	Artifact** m_backpack;
	int   m_cell_backpack;
};
#endif // !BACKPACK_H
