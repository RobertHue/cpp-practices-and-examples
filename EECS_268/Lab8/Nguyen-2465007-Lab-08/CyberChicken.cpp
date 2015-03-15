#include "CyberChicken.h"

CyberChicken::CyberChicken() {
	setName("CyberChicken");	
}

int CyberChicken::getCyberEggs() const {
	return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs) {
	m_eggs = eggs;
}
