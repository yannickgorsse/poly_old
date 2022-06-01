/****************************************************************************
* Copyright (c) 2022, CEA
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
// File:        Op_Conv_PolyMAC_iterateur_base.h
// Directory:   $TRUST_ROOT/src/PolyMAC/Operateurs/Conv_iterateur
// Version:     /main/14
//
//////////////////////////////////////////////////////////////////////////////


#ifndef Op_Conv_PolyMAC_iterateur_base_included
#define Op_Conv_PolyMAC_iterateur_base_included

#include <Operateur_Conv.h>
#include <Iterateur_PolyMAC_base.h>

//
// .DESCRIPTION class Op_Conv_PolyMAC_iterateur_base
//
// Classe de base des operateurs de convection PolyMAC

//
// .SECTION voir aussi
//
//


//////////////////////////////////////////////////////////////////////////////
//
// CLASS: Op_Conv_PolyMAC_iterateur_base
//
//////////////////////////////////////////////////////////////////////////////

class Op_Conv_PolyMAC_iterateur_base : public Operateur_Conv_base
{

  Declare_base(Op_Conv_PolyMAC_iterateur_base);

public:

  inline Op_Conv_PolyMAC_iterateur_base( const Iterateur_PolyMAC_base&);
  inline DoubleTab& ajouter(const DoubleTab& inco, DoubleTab& resu) const override;
  inline DoubleTab& calculer(const DoubleTab& inco, DoubleTab& resu ) const override;
  inline void contribuer_a_avec(const DoubleTab&, Matrice_Morse&) const override;
  inline void contribuer_bloc_vitesse(const DoubleTab&, Matrice_Morse&) const override;
  inline void contribuer_au_second_membre(DoubleTab& ) const override;
  virtual const Champ_base& vitesse() const=0;
  virtual Champ_base& vitesse()=0;
  void completer() override;
  double calculer_dt_stab() const override;
  void calculer_pour_post(Champ& espace_stockage,const Nom& option,int comp) const override;
  Motcle get_localisation_pour_post(const Nom& option) const override;
  int impr(Sortie& os) const override;
  void associer_zone_cl_dis(const Zone_Cl_dis_base&) override;
protected:

  Iterateur_PolyMAC iter;

};

//
// Fonctions inline de la classe Op_Conv_PolyMAC_iterateur_base
//

// Description:
// constructeur
inline Op_Conv_PolyMAC_iterateur_base::Op_Conv_PolyMAC_iterateur_base(const Iterateur_PolyMAC_base& iter_base) :
  iter(iter_base)
{}

// Description:
// ajoute la contribution de la convection au second membre resu
// renvoie resu
inline DoubleTab& Op_Conv_PolyMAC_iterateur_base::ajouter(const DoubleTab& inco, DoubleTab& resu) const
{
  return iter.ajouter(inco, resu);
}

//Description:
//on assemble la matrice.

inline void Op_Conv_PolyMAC_iterateur_base::contribuer_a_avec(const DoubleTab& inco,
                                                              Matrice_Morse& matrice) const
{
  iter.ajouter_contribution(inco, matrice);
}

inline void Op_Conv_PolyMAC_iterateur_base::contribuer_bloc_vitesse(const DoubleTab& inco,
                                                                    Matrice_Morse& matrice) const
{
  iter.ajouter_contribution_vitesse(inco, matrice);
}

//Description:
//on ajoute la contribution du second membre.

inline void Op_Conv_PolyMAC_iterateur_base::contribuer_au_second_membre(DoubleTab& resu) const
{
  iter.contribuer_au_second_membre(resu);
}


// Description:
// calcule la contribution de la convection, la range dans resu
// renvoie resu
inline DoubleTab& Op_Conv_PolyMAC_iterateur_base::calculer(const DoubleTab& inco, DoubleTab& resu) const
{
  return iter.calculer(inco, resu);
}



//
// Fonction utile pour le calcul du pas de temps de stabilite
//

inline void eval_fluent(const double , const int , const int , DoubleVect& );


#endif
