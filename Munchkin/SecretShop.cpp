#include "SecretShop.h"

// Memory stands out for shop and
// for secret artifacts in this shop and
// Initialize artifact values from tableSecretArtifacts
SecretShop::SecretShop() :
	m_cell_shop{ 0 }
{
	m_shop = new SecretArtifact * [static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE)];

	for (int artifact = 0; artifact < static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE); ++artifact)
	{
		m_shop[artifact] = new SecretArtifact{ SecretArtifact::tableSecretArtifacts[artifact] };
		++m_cell_shop;
	}
}

SecretShop::~SecretShop() { delete[] m_shop; }

void SecretShop::showShop() const
{
	std::cout << "It's shop of Secret Artifacts.\n";
	std::cout << "Here you can buy artifacts to improve your AHD.\n\n";
	for (int artifact = 0; artifact < m_cell_shop; ++artifact)
	{
		m_shop[artifact]->printArtifact();
		std::cout << " \t[" << artifact + 1 << "]\n";
	}
}

void SecretShop::emptyShop()
{
	for (int artifact = 0; artifact < static_cast<int>(SecretArtifact::SecretArtifactType::MAX_SECRET_TYPE); ++artifact)
		*m_shop[artifact] = SecretArtifact{};
}

int SecretShop::getCell() const { return m_cell_shop; }

void SecretShop::deleteArtifact(int index)
{
	if (index < 0 || index >= m_cell_shop)
	{
		std::cout << "You entered isn't correct artifact!\n";
		return;
	}

	if (m_cell_shop == 1)
	{
		emptyShop();
		return;
	}

	SecretArtifact** tmp_shop = new SecretArtifact * [m_cell_shop - 1];
	for (int artifact = 0; artifact < m_cell_shop - 1; ++artifact)
		tmp_shop[artifact] = new SecretArtifact;

	for (int before = 0; before < index; ++before)
		*tmp_shop[before] = *m_shop[before];
	
	for (int after = index + 1; after < m_cell_shop; ++after)
		*tmp_shop[after - 1] = *m_shop[after];

	emptyShop();

	--m_cell_shop;

	for (int artifact = 0; artifact < m_cell_shop; artifact++)
		*m_shop[artifact] = *tmp_shop[artifact];

	delete[] tmp_shop;
	
}

SecretArtifact SecretShop::getArtifact(int index)
{
	--index;
	SecretArtifact artifact = *m_shop[index];
	deleteArtifact(index);
	return artifact;
}

SecretArtifact& SecretShop::getArtifact(int index, bool) 
{
	if (index > m_cell_shop)
	{
		std::cout << "You entered isn't correct index!\n";
	}

	--index;
	return *m_shop[index]; 
}
