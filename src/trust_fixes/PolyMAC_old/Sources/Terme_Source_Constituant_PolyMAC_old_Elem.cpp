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
// File:        Terme_Source_Constituant_PolyMAC_old_Elem.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Sources
// Version:     /main/20
//
//////////////////////////////////////////////////////////////////////////////

#include <Terme_Source_Constituant_PolyMAC_old_Elem.h>
#include <Milieu_base.h>
#include <Convection_Diffusion_Concentration.h>
#include <Discretisation_base.h>
#include <Probleme_base.h>

Implemente_instanciable_sans_constructeur(Terme_Source_Constituant_PolyMAC_old_Elem,"Source_Constituant_P0_PolyMAC_old",Terme_Source_PolyMAC_old_base);
implemente_It_Sou_PolyMAC_old_Elem(Eval_Source_C_PolyMAC_old_Elem)

//// printOn
//

Sortie& Terme_Source_Constituant_PolyMAC_old_Elem::printOn(Sortie& s ) const
{
  return s << que_suis_je() ;
}

//// readOn
//

Entree& Terme_Source_Constituant_PolyMAC_old_Elem::readOn(Entree& s )
{
  Terme_Source_Constituant::lire_donnees(s);
  set_fichier("Source_Constituant");
  set_description("Injection rate = Integral(source_C*dv) [mol/s]");
  return s;
}


void Terme_Source_Constituant_PolyMAC_old_Elem::associer_domaines(const Domaine_dis& domaine_dis,
                                                                  const Domaine_Cl_dis& domaine_cl_dis)
{
  const Domaine_PolyMAC_old& zvdf = ref_cast(Domaine_PolyMAC_old,domaine_dis.valeur());
  const Domaine_Cl_PolyMAC_old& zclvdf = ref_cast(Domaine_Cl_PolyMAC_old,domaine_cl_dis.valeur());

  iter->associer_domaines(zvdf, zclvdf);

  Eval_Source_C_PolyMAC_old_Elem& eval_puis = (Eval_Source_C_PolyMAC_old_Elem&) iter.evaluateur();
  eval_puis.associer_domaines(zvdf, zclvdf );
}


void Terme_Source_Constituant_PolyMAC_old_Elem::associer_pb(const Probleme_base& pb)
{
  const Equation_base& eqn = pb.equation(0);
  eqn.discretisation().nommer_completer_champ_physique(eqn.domaine_dis(),la_source_constituant.le_nom(),"",la_source_constituant,pb);
  Eval_Source_C_PolyMAC_old_Elem& eval_puis = (Eval_Source_C_PolyMAC_old_Elem&) iter.evaluateur();
  eval_puis.associer_champs(la_source_constituant);
}


