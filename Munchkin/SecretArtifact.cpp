#include "SecretArtifact.h"

SecretArtifact::SecretArtifact(std::string name, int buff, char sign, int cost) :
	Artifact{ name,buff,sign },
	m_cost{ cost }{}

const SecretArtifact SecretArtifact::tableSecretArtifacts[static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE)]
{
	// Name                   BF    S   Cost
	{"Crown of Gondor",       69,  'A', 69},
	{"Fire Armor",            69,  'H', 105},
    {"Armor Guds",            100, 'H', 100},
	{"Glamdring Sword",       100, 'D', 100},
	{"Orcrist Sword",         69,  'D', 69}
};

int SecretArtifact::getCost() const { return m_cost; }

void SecretArtifact::printArtifact() const
{
	std::cout << "Name:" << getName() << " \t Buff:" << getBuff() << " \t Sign:" << getSign() << " \t Cost:" << m_cost;
}