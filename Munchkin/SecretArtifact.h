/* There are artifacts player can buy in Secret Shop
** which don't drop in the game
** Secret artifacts consist of artifact and cost
*/
#ifndef SECRETARTIFACT_H
#define SECRETARTIFACT_H

#include "Artifact.h"

class SecretArtifact : public Artifact
{
public:

	enum class SecretArtifactType
	{
		CROWN_GONDOR,
		FIRE_CROWN,
		FIRE_ARMOR,
		ARMOR_GUD,
		GLAMDRING,
		ORCRIST,
		MAX_SECRET_TYPE
	};

	//                                           Cost
	SecretArtifact(const Artifact& = Artifact{}, int = 0);

	static const SecretArtifact tableSecretArtifacts[];
	
	int getCost() const;
	void printArtifact() const;

private:
	int m_cost;
};
#endif // !SECRETARTIFACT_H
