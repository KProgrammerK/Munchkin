#ifndef SECRETSHOP_H
#define SECRETSHOP_H

#include "SecretArtifact.h"
#include "Templates.h"

class SecretShop
{
public:

	SecretShop();
	~SecretShop();

	void showShop() const;
	
	// When  a secret artifact is purchased
	// it deletes from secret shop
	// For transfer an artifact in backpack
	SecretArtifact getArtifact(int);
	// For get cost of the artifact
	SecretArtifact& getArtifact(int,bool);

private:
	SecretArtifact** m_shop;
	int m_cell_shop;
};
#endif // !SECRETSHOP_H
