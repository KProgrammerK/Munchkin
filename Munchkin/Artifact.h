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
		VIKING_HELMET,
		CUT_DRAGON,
		MAX_ARTIFACT_TYPE
	};

	//          Name       B     S
	Artifact(std::string, int, char);

	// This is lookup table informations about artifacts
	static const Artifact artifactsTable[];

	//Functions getters informations
	std::string getName() const;
	int         getBuff() const;
	char        getSign() const;

	static Artifact getRandomArtifact();

	void printArtifact() const;

private:
	std::string m_name;
	int         m_buff;
	char        m_sign;
};
#endif // !ARTIFACT_H
