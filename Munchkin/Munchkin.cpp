#include "BackPack.h"
#include "Artifact.h"

int main()
{
	BackPack backpack;

	for (int cell = 0; cell < 10; ++cell)
		backpack.addArtifact(Artifact::getRandomArtifact());

	backpack.printBackPack();

	return 0;
}