#include "Artifact.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Artifact artifact{ Artifact::getRandomArtifact() };

	artifact.printArtifact();

	return 0;
}