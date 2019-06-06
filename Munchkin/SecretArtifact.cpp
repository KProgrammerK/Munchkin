#include "SecretArtifact.h"

SecretArtifact::SecretArtifact(const Artifact& artifact, int cost) :
	Artifact{ artifact },
	m_cost{ cost }{}

const SecretArtifact SecretArtifact::tableSecretArtifacts[static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE)]
{
	// Name                    BF    S   Cost
	{{"Crown of Gondor",       30,  'A'}, 75  },
	{{"Fire Crown",            69,  'A'}, 103 },
	{{"Fire Armor",            30,  'H'}, 105 },
	{{"Armor Guds",            100, 'H'}, 200 },
	{{"Glamdring Sword",       69,  'D'}, 100 },
	{{"Orcrist Sword",         45,  'D'}, 69  }
};

int SecretArtifact::getCost() const { return m_cost; }

void SecretArtifact::printArtifact() const { std::cout << "Name:" << getName() << " \t Buff:" << getBuff() << " \t Sign:" << getSign() << " \t Cost:" << m_cost; }