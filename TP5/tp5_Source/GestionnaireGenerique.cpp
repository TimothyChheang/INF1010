

#include "GestionnaireGenerique.h"

template<typename T, typename C>


void GestionnaireGenerique::ajouter(T t) const
{


}


int GestionnaireGenerique::getNombreElements() const
{
	return conteneur_.size();
}

C GestionnaireGenerique::getConteneur() const
{
	copy(conteneur_.begin(), conteneur_.end(), );
	return conteneur_;
}