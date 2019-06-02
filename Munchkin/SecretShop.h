#ifndef SECRETSHOP_H
#define SECRETSHOP_H

#include "SecretArtifact.h"

class SecretShop
{
public:
	SecretShop();
	~SecretShop();

	void showShop () const;
	void emptyShop();
	int getCell() const;
	//                        index
	void deleteArtifact       (int);
	SecretArtifact getArtifact(int);
	SecretArtifact& getArtifact(int,bool);

private:
	SecretArtifact** m_shop;
	int m_cell_shop;
};
#endif // !SECRETSHOP_H
