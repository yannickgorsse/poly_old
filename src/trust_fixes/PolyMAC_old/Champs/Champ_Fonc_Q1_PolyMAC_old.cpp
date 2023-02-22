/****************************************************************************
* Copyright (c) 2019, CEA
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
//
// File:        Champ_Fonc_Q1_PolyMAC_old.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Champs
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////


#include <Champ_Fonc_Q1_PolyMAC_old.h>
#include <Domaine_PolyMAC_old.h>
#include <Domaine.h>


Implemente_instanciable(Champ_Fonc_Q1_PolyMAC_old,"Champ_Fonc_Q1_PolyMAC_old",Champ_Fonc_Q1_base);

// printOn

Sortie& Champ_Fonc_Q1_PolyMAC_old::printOn(Sortie& s) const
{
  return s << que_suis_je() << " " << le_nom();
}


// readOn

Entree& Champ_Fonc_Q1_PolyMAC_old::readOn(Entree& s)
{

  return s ;
}

// Description:
//
// Precondition:
//    Signification:
//    Valeurs par defaut:
//    Contraintes:
//    Acces: entree/sortie
// Retour:
//    Signification:
//    Contraintes:
// Exception:
// Effets de bord:
// Postcondition:
const Domaine_dis_base& Champ_Fonc_Q1_PolyMAC_old::domaine_dis_base() const
{
  return la_domaine_VF.valeur();
}
// Description:
//
// Precondition:
//    Signification:
//    Valeurs par defaut:
//    Contraintes:
//    Acces: entree/sortie
// Retour:  z_dis
//    Signification: la domaine discretise
//    Contraintes:
// Exception:
// Effets de bord:
// Postcondition:
void Champ_Fonc_Q1_PolyMAC_old::associer_domaine_dis_base(const Domaine_dis_base& z_dis)
{
  la_domaine_VF=ref_cast(Domaine_VF, z_dis);
}

// Description:
//
// Precondition:
//    Signification:
//    Valeurs par defaut:
//    Contraintes:
//    Acces: entree/sortie
// Retour: la_domaine_PolyMAC_old_P1.valeur()
//    Signification:
//    Contraintes:
// Exception:
// Effets de bord:
// Postcondition:
const Domaine_PolyMAC_old& Champ_Fonc_Q1_PolyMAC_old::domaine_PolyMAC_old() const
{
  return ref_cast(Domaine_PolyMAC_old, la_domaine_VF.valeur());
}

void Champ_Fonc_Q1_PolyMAC_old::mettre_a_jour(double t)
{
  Champ_Fonc_base::mettre_a_jour(t);
}

int Champ_Fonc_Q1_PolyMAC_old::imprime(Sortie& os, int ncomp) const
{
  const Domaine_dis_base& domaine_dis = domaine_dis_base();
  const Domaine& domaine = domaine_dis.domaine();
  const DoubleTab& coord=domaine.coord_sommets();
  const int nb_som = domaine.nb_som();
  const DoubleTab& val = valeurs();
  int som;
  os << nb_som << finl;
  for (som=0; som<nb_som; som++)
    {
      if (dimension==3)
        os << coord(som,0) << " " << coord(som,1) << " " << coord(som,2) << " " ;
      if (dimension==2)
        os << coord(som,0) << " " << coord(som,1) << " " ;
      if (nb_compo_ == 1)
        os << val(som) << finl;
      else
        os << val(som,ncomp) << finl;
    }
  os << finl;
  Cout << "Champ_Fonc_Q1_PolyMAC_old::imprime FIN >>>>>>>>>> " << finl;
  return 1;
}
