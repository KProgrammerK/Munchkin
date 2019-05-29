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
    {"Sword Guds"   , 10, 'D'},
    {"Sword Fire"   , 20, 'D'},
    {"Viking Helmet", 10, 'A'},
    {"Fire Helmet"  , 20, 'A'},
    {"Cut Dragon"   , 10, 'H'},
    {"Fire armor"   , 20, 'H'}
};

//Functions getters informations
std::string Artifact::getName() const { return m_name; }
int         Artifact::getBuff() const { return m_buff; }
char        Artifact::getSign() const { return m_sign; }

std::ostream& operator<<(std::ostream& out, const Artifact& artifact)
{
	out << "Name:" << artifact.getName() << " \t Buff:" << artifact.getBuff() << "  Sign:" << artifact.getSign();
	return out;
}

void Artifact::printArtifact() const
{
	std::cout << "Name:" << getName() << " Buff:" << getBuff() << "  Sign:" << getSign() << '\n';
}

Artifact Artifact::getRandomArtifact()
{
	// Get random artifact from table
	Artifact artifact = artifactsTable[RandomNumber::getRandomNumber(0, static_cast<int>((Artifact::ArtifactType::MAX_ARTIFACT_TYPE)) - 1)];
	// And return it's values in caller
	return artifact;
}