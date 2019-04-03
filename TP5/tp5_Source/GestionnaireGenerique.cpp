

#include "GestionnaireGenerique.h"

template<typename T, typename C>
void GestionnaireGenerique<T,C>::ajouter(T t) 
{
	inserter(t, conteneur_.begin());
	//conteneur_.insert(t);

}

template <typename T, typename C>
int GestionnaireGenerique<T,C>::getNombreElements() const
{
	return conteneur_.size();
}

template <typename T, typename C>
C GestionnaireGenerique<T,C>::getConteneur() const
{
	return conteneur_;
}