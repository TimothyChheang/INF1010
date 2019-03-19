//
//  Boisson.cpp
//  intra
//
//  Created by Martine Bellaiche on 2019-03-10.
//  Copyright © 2019 Martine Bellaiche. All rights reserved.
//

#include "Boisson.h"
// TODO
Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix)
{// TODO}


string_view Boisson::getNom() const
{ return nom_;}
double Boisson::getPrix()  const
{return prix_;}
