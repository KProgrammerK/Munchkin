#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "RandomNumber.h"

#include <string>
#include <iostream>
#include <iomanip>

class Artifact
{
public:

	enum class ArtifactType
	{
		VIKING_HELMET,
		FIRE_HELMET,
		IRON_CROWN,
		WOODEN_ARMOR,
		IRON_ARMOR,
		CUT_DRAGON,
		SWORD_FIRE,
		SWORD_GUDS,
		SCEPTER_LOKI,
		MAX_ARTIFACT_TYPE
	};

	//          Name             B       S
	Artifact(std::string = "", int = 0, char = ' ');

	// This is lookup table about artifacts
	static const Artifact artifactsTable[];

	// Functions getters informations
	std::string getName() const;
	int         getBuff() const;
	char        getSign() const;

	// Get random type and get informations about artifact from table by type of artifact
	static Artifact getRandomArtifact();

	// Output informations about artifact
	// For BackPack and Equipment
	friend std::ostream& operator<<(std::ostream&, const Artifact&);
	// For function warning in class Player
	void printArtifact() const;

private:
	std::string m_name;
	int         m_buff;
	char        m_sign;
};
#endif // !ARTIFACT_H
