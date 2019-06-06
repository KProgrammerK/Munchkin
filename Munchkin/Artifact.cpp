#include "Artifact.h"

//Standard constructor
Artifact::Artifact(const std::string& name, int buff, char sign) :
	m_name{ name },
	m_buff{ buff },
	m_sign{ sign }{}

// This is lookup table informations about artifacts
const Artifact Artifact::artifactsTable[static_cast<int>(Artifact::ArtifactType::MAX_ARTIFACT_TYPE)]
{
	//  Name          BF   S
    {"Viking helmet", 10, 'A'},
    {"Fire helmet"  , 15, 'A'},
    {"Iron crown"   , 20, 'A'},
    {"Wooden armor" , 10, 'H'},
    {"Iron armor"   , 15, 'H'},
    {"Cut dragon"   , 20, 'H'},
    {"Sword fire"   , 5,  'D'},
    {"Sword Guds"   , 10, 'D'},
    {"Scepter Loki" , 15, 'D'}
};

//Functions getters informations
std::string Artifact::getName() const { return m_name; }
int         Artifact::getBuff() const { return m_buff; }
char        Artifact::getSign() const { return m_sign; }

// Get random type and get informations about artifact from table by type of artifact
Artifact Artifact::getRandomArtifact()
{
	// Get random artifact from table
	Artifact artifact = artifactsTable[RandomNumber::getRandomNumber(0, (static_cast<int>(Artifact::ArtifactType::MAX_ARTIFACT_TYPE) - 1))];
	return artifact;
}

std::ostream& operator<<(std::ostream& out, const Artifact& artifact)
{
	out << "Name:" << artifact.getName() << " \t Buff:" << artifact.getBuff() << " \t Sign:" << artifact.getSign();
	return out;
}

void Artifact::printArtifact() const
{
	std::cout << "Name:" << getName() << "   Buff:" << getBuff() << "   Sign:" << getSign();
}
