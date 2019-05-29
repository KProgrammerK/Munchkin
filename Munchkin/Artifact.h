#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "RandomNumber.h"

#include <string>
#include <iostream>

class Artifact
{
public:

	enum class ArtifactType
	{
		SWORD_GUDS,
		SWORD_FIRE,
		VIKING_HELMET,
		FIRE_HELMET,
		CUT_DRAGON,
		FIRE_ARMOR,
		MAX_ARTIFACT_TYPE
	};

	//          Name       B     S
	Artifact(std::string = "", int = 0, char = ' ');

	// This is lookup table about artifacts
	static const Artifact artifactsTable[];

	// Functions getters informations
	std::string getName() const;
	int         getBuff() const;
	char        getSign() const;

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
