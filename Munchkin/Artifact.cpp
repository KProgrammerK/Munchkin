#include "Artifact.h"

//Standard constructor
Artifact::Artifact(std::string name, int buff, char sign) :
	m_name{ name },
	m_buff{ buff },
	m_sign{ sign }{}

const Artifact Artifact::artifactsTable[static_cast<int>(Artifact::ArtifactType::MAX_ARTIFACT_TYPE)]
{
	//  Name          BF   S
    {"Sword Guds"   , 10, 'D'},
    {"Viking Helmet", 10, 'A'},
    {"Cut Dragon"   , 10, 'H'}
};

//Functions getters informations
std::string Artifact::getName() const { return m_name; }
int         Artifact::getBuff() const { return m_buff; }
char        Artifact::getSign() const { return m_sign; }

void Artifact::printArtifact() const { std::cout << "Name:" << getName() << ", Buff:" << getBuff() << ", Sign:" << getSign(); }

Artifact Artifact::getRandomArtifact()
{
	// Get random artifact from table
	Artifact artifact = artifactsTable[RandomNumber::getRandomNumber(0, static_cast<int>((Artifact::ArtifactType::MAX_ARTIFACT_TYPE)) - 1)];
	// And return in caller
	return artifact;
}