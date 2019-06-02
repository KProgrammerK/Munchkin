#ifndef SECRETARTIFACT_H
#define SECRETARTIFACT_H

#include "Artifact.h"

class SecretArtifact : public Artifact
{
public:

	enum class SecretArtifactType
	{
		CROWN_GONDOR,
		FIRE_ARMOR,
		ARMOR_GUD,
		GLAMDRING,
		ORCRIST,
		MAX_SECRET_TYPE
	};

	//                 Name            B        S          Cost
	SecretArtifact(std::string = "", int = 0, char = ' ', int = 0);

	static const SecretArtifact tableSecretArtifacts[];
	
	int getCost() const;
	void printArtifact() const;

private:
	int m_cost;
};
#endif // !SECRETARTIFACT_H
