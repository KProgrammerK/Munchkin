#include "Artifact.h"

//Standard constructor
Artifact::Artifact(std::string name, int buff, char sign) :
	m_name{ name },
	m_buff{ buff },
	m_sign{ sign }{}

// This is lookup table informations about artifacts
const Artifact Artifact::artifactsTable[static_cast<int>(Artifact::ArtifactType::MAX_ARTIFACT_TYPE)]
{
	//  Name          BF   S
    {"Viking helmet", 5 , 'A'},
    {"Fire helmet"  , 7 , 'A'},
    {"Iron crown"   , 10, 'A'},
    {"Wooden armor" , 5,  'H'},
    {"Iron armor"   , 7,  'H'},
    {"Cut dragon"   , 10, 'H'},
    {"Sword fire"   , 6 , 'D'},
    {"Sword Guds"   , 9,  'D'},
    {"Scepter Loki" , 13, 'D'}
};

//Functions getters informations
std::string Artifact::getName() const { return m_name; }
int         Artifact::getBuff() const { return m_buff; }
char        Artifact::getSign() const { return m_sign; }

std::ostream& operator<<(std::ostream& out, const Artifact& artifact)
{
	out << "Name:" << artifact.getName() << " \t Buff:" << artifact.getBuff() << " \t Sign:" << artifact.getSign();
	return out;
}

void Artifact::printArtifact() const
{
	std::cout << "Name:" << getName() << "   Buff:" << getBuff() << "   Sign:" << getSign();
}

Artifact Artifact::getRandomArtifact()
{
	// Get random artifact from table
	Artifact artifact = artifactsTable[RandomNumber::getRandomNumber(0, static_cast<int>((Artifact::ArtifactType::MAX_ARTIFACT_TYPE)) - 1)];
	// And return it's values in caller
	return artifact;
}