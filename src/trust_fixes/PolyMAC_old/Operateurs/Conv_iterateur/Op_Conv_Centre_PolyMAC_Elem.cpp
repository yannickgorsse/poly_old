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
// File:        Op_Conv_Centre_PolyMAC_Elem.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC/Operateurs/Conv_iterateur
// Version:     /main/9
//
//////////////////////////////////////////////////////////////////////////////

#include <Op_Conv_Centre_PolyMAC_Elem.h>
#include <Champ_P0_PolyMAC.h>
#include <Champ_Face_PolyMAC.h>

Implemente_instanciable_sans_constructeur(Op_Conv_Centre_PolyMAC_Elem,"Op_Conv_Centre_PolyMAC_Elem_PolyMAC",Op_Conv_PolyMAC_iterateur_base);

implemente_It_PolyMAC_Elem(Eval_centre_PolyMAC_Elem)

//// printOn
//

Sortie& Op_Conv_Centre_PolyMAC_Elem::printOn(Sortie& s ) const
{
  return s << que_suis_je() ;
}

//// readOn
//

Entree& Op_Conv_Centre_PolyMAC_Elem::readOn(Entree& s )
{
  return s ;
}


// Description:
// complete l'iterateur et l'evaluateur
void Op_Conv_Centre_PolyMAC_Elem::associer(const Zone_dis& zone_dis,
                                           const Zone_Cl_dis& zone_cl_dis,
                                           const Champ_Inc& ch_transporte)
{
  const Zone_PolyMAC& zvdf = ref_cast(Zone_PolyMAC,zone_dis.valeur());
  const Zone_Cl_PolyMAC& zclvdf = ref_cast(Zone_Cl_PolyMAC,zone_cl_dis.valeur());
  const Champ_P0_PolyMAC& inco = ref_cast(Champ_P0_PolyMAC,ch_transporte.valeur());

  iter->associer(zvdf, zclvdf, *this);

  Eval_centre_PolyMAC_Elem& eval_conv = (Eval_centre_PolyMAC_Elem&) iter.evaluateur();
  eval_conv.associer_zones(zvdf, zclvdf );          // Evaluateur_PolyMAC::associer
  eval_conv.associer_inconnue(inco );        // Eval_PolyMAC_Elem::associer_inconnue
}

// Description:
// associe le champ de vitesse a l'evaluateur
void Op_Conv_Centre_PolyMAC_Elem::associer_vitesse(const Champ_base& ch_vit)
{
  const Champ_Face_PolyMAC& vit = ref_cast(Champ_Face_PolyMAC, ch_vit);

  Eval_centre_PolyMAC_Elem& eval_conv = (Eval_centre_PolyMAC_Elem&) iter.evaluateur();
  eval_conv.associer(vit);                // Eval_Conv_PolyMAC::associer
}

const Champ_base& Op_Conv_Centre_PolyMAC_Elem::vitesse() const
{
  Eval_centre_PolyMAC_Elem& eval_conv = (Eval_centre_PolyMAC_Elem&) iter.evaluateur();
  return eval_conv.vitesse();
}

Champ_base& Op_Conv_Centre_PolyMAC_Elem::vitesse()
{
  Eval_centre_PolyMAC_Elem& eval_conv = (Eval_centre_PolyMAC_Elem&) iter.evaluateur();
  return eval_conv.vitesse();
}

//
// Fonctions inline de la classe Op_Conv_Centre_PolyMAC_Elem
//
// Description:
// constructeur
Op_Conv_Centre_PolyMAC_Elem::Op_Conv_Centre_PolyMAC_Elem() :
  Op_Conv_PolyMAC_iterateur_base(It_PolyMAC_Elem(Eval_centre_PolyMAC_Elem)())
{
}
