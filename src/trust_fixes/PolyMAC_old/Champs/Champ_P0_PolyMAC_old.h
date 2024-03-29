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
// File:        Champ_P0_PolyMAC_old.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Champs
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////

#ifndef Champ_P0_PolyMAC_old_included
#define Champ_P0_PolyMAC_old_included

#include <Champ_Inc_P0_base.h>
#include <Domaine_PolyMAC_old.h>
#include <Operateur.h>
#include <Op_Diff_PolyMAC_old_base.h>
#include <TRUST_Ref.h>
class Domaine_VF;
class Domaine_PolyMAC_old;

/////////////////////////////////////////////////////////////////////////////
// .NAME        : Champ_P0_PolyMAC_old
// .DESCRIPTION : class Champ_P0_PolyMAC_old
//
// Champ correspondant a une inconnue scalaire (type temperature ou pression)
// Degres de libertes : valeur aux elements + flux aux faces
/////////////////////////////////////////////////////////////////////////////

class Champ_P0_PolyMAC_old : public Champ_Inc_P0_base
{
  Declare_instanciable(Champ_P0_PolyMAC_old);

public :

  const Domaine_PolyMAC_old&        domaine_PolyMAC_old() const;
  void                         associer_domaine_dis_base(const Domaine_dis_base&) override;
  const Domaine_dis_base& domaine_dis_base() const override;
  Champ_base& affecter_(const Champ_base& ch) override;
  int                       imprime(Sortie& , int ) const override;

  int fixer_nb_valeurs_nodales(int n) override;

  /* fonctions reconstruisant de maniere plus precise le champ aux faces */
  DoubleTab& valeur_aux_faces(DoubleTab& vals) const override;
  inline DoubleTab& trace(const Frontiere_dis_base& fr, DoubleTab& x, double t, int distant) const override;

  //tableaux utilitaires sur les CLs
  //types de CL : 0 -> pas de CL
  //              1 -> Echange_externe_impose
  //              2 -> Echange_global_impose
  //              3 -> Echange_contact_PolyMAC_old gere en monolithique
  //              4 -> Neumann_paroi
  //              5 -> Neumann_sortie_libre
  //              6 -> Dirichlet
  //              7 -> Dirichlet_homogene
  void init_cl() const;
  mutable IntTab icl; //icl(f, .) = (type de la CL, no de la CL, indice dans la CL)

protected :

  REF(Domaine_VF) la_domaine_VF;


};

inline DoubleTab& Champ_P0_PolyMAC_old::trace(const Frontiere_dis_base& fr, DoubleTab& x, double t, int distant) const
{
  /* dimensionnement du tableau de destination x si necessaire */
  const DoubleTab& src = valeurs();
  const Front_VF& fvf = ref_cast(Front_VF, fr);
  const Domaine_PolyMAC_old& domaine = ref_cast(Domaine_PolyMAC_old, domaine_dis_base());
  const IntTab& f_e = domaine.face_voisins();

  DoubleTrav dst; //reconstruction du champ aux faces (on ne le remplit que sur le bord concerne)
  int i, n, e, f, N = src.nb_dim() > 1 ? src.dimension(1): 1, has_faces = src.dimension_tot(0) > domaine.nb_elem_tot();
  if (!x.dimension(0) && !x.get_md_vector().non_nul()) x.resize(fvf.nb_faces(), N);
  N > 1 ? dst.resize(domaine.nb_faces(), N) : dst.resize(domaine.nb_faces()); //aargh
  for (i = 0; i < fvf.nb_faces(); i++)
    for (n = 0, f = fvf.num_face(i), e = f_e(f, 0); n < N; n++)
      dst(f, n) = src(has_faces ? domaine.nb_elem_tot() + f : e, n);

  if (distant) fr.frontiere().trace_face_distant(dst, x);
  else fr.frontiere().trace_face_local(dst, x);

  return x;
}

#endif
