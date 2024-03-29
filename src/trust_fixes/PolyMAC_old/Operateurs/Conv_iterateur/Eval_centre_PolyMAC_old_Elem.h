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
// File:        Eval_centre_PolyMAC_old_Elem.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs/Conv_iterateur
// Version:     /main/8
//
//////////////////////////////////////////////////////////////////////////////



#ifndef Eval_centre_PolyMAC_old_Elem_included
#define Eval_centre_PolyMAC_old_Elem_included

#include <Eval_Conv_PolyMAC_old.h>
#include <Eval_PolyMAC_old_Elem.h>
#include <Domaine_PolyMAC_old.h>
#include <Champ_P0_PolyMAC_old.h>
//
// .DESCRIPTION class Eval_centre_PolyMAC_old_Elem
//
// Evaluateur PolyMAC_old pour la convection
// Le champ convecte est scalaire (Champ_P0_PolyMAC_old)
// Schema de convection Centre
// Rq:Les evaluateurs de flux convectifs calculent en fait le terme
// convectif qui figure au second membre de l'equation d'evolution
// c.a.d l'oppose du flux convectif

//
// .SECTION voir aussi Eval_Conv_PolyMAC_old


class Eval_centre_PolyMAC_old_Elem : public Eval_Conv_PolyMAC_old, public Eval_PolyMAC_old_Elem
{

public:

  inline Eval_centre_PolyMAC_old_Elem();

  inline int calculer_flux_faces_echange_externe_impose() const override;
  inline int calculer_flux_faces_echange_global_impose() const override;
  inline int calculer_flux_faces_entree_fluide() const override;
  inline int calculer_flux_faces_paroi() const override;
  inline int calculer_flux_faces_paroi_adiabatique() const override;
  inline int calculer_flux_faces_paroi_defilante() const override;
  inline int calculer_flux_faces_paroi_fixe() const override;
  inline int calculer_flux_faces_sortie_libre() const override;
  inline int calculer_flux_faces_symetrie() const override;
  inline int calculer_flux_faces_periodique() const override;

  // Fonctions qui servent a calculer le flux de grandeurs scalaires
  // Elles sont de type double et renvoient le flux

  inline double flux_face(const DoubleTab&, int , const Dirichlet_entree_fluide&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Dirichlet_paroi_defilante&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Dirichlet_paroi_fixe&, int ) const override;
  inline double flux_face(const DoubleTab&, int , int, int, const Echange_externe_impose&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Echange_global_impose&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Neumann_paroi&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Neumann_paroi_adiabatique&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Neumann_sortie_libre&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Symetrie&, int ) const override;
  inline double flux_face(const DoubleTab&, int , const Periodique&, int ) const override;
  inline double flux_faces_interne(const DoubleTab&, int ) const override;

  // Fonctions qui servent a calculer le flux de grandeurs vectorielles
  // Elles sont de type void et remplissent le tableau flux

  inline void flux_face(const DoubleTab&, int , const Symetrie&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Periodique&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Neumann_sortie_libre&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Dirichlet_entree_fluide&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Dirichlet_paroi_fixe&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Dirichlet_paroi_defilante&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Neumann_paroi_adiabatique&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Neumann_paroi&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , int, int, const Echange_externe_impose&,
                        int, DoubleVect& flux) const override;
  inline void flux_face(const DoubleTab&, int , const Echange_global_impose&,
                        int, DoubleVect& flux) const override;

  inline void flux_faces_interne(const DoubleTab&, int ,
                                 DoubleVect& flux) const override;


  // Fonctions qui servent a calculer les coefficients de la matrice pour des grandeurs
  // scalaires.

  inline void coeffs_face(int, int,const Symetrie&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Neumann_sortie_libre&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_entree_fluide&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_paroi_fixe&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_paroi_defilante&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Neumann_paroi_adiabatique&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Neumann_paroi&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int, int, int, const Echange_externe_impose&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Echange_global_impose&, double& aii, double& ajj ) const override;
  inline void coeffs_face(int, int,const Periodique&, double& aii, double& ajj ) const override;
  inline void coeffs_faces_interne(int, double& aii, double& ajj ) const override;

  // Fonctions qui servent a calculer la contribution des conditions limites
  // au second membre pour l'implicite pour les grandeurs scalaires.

  inline double secmem_face(int, const Symetrie&, int ) const override;
  inline double secmem_face(int, const Neumann_sortie_libre&, int ) const override;
  inline double secmem_face(int, const Dirichlet_entree_fluide&, int ) const override;
  inline double secmem_face(int, const Dirichlet_paroi_fixe&, int ) const override;
  inline double secmem_face(int, const Dirichlet_paroi_defilante&, int ) const override;
  inline double secmem_face(int, const Neumann_paroi_adiabatique&, int ) const override;
  inline double secmem_face(int, const Neumann_paroi&, int ) const override;
  inline double secmem_face(int, int, int, const Echange_externe_impose&, int ) const override;
  inline double secmem_face(int, const Echange_global_impose&, int ) const override;
  inline double secmem_face(int, const Periodique&, int ) const override;
  inline double secmem_faces_interne(int ) const override;

  // Fonctions qui servent a calculer les coefficients de la matrice pour des grandeurs
  // vectorielles.

  inline void coeffs_face(int,int, const Symetrie&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int,int, const Neumann_sortie_libre&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_entree_fluide&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_paroi_fixe&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Dirichlet_paroi_defilante&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Neumann_paroi_adiabatique&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Neumann_paroi&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int, int, int, const Echange_externe_impose&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Echange_global_impose&, DoubleVect& aii, DoubleVect& ajj ) const override;
  inline void coeffs_face(int, int,const Periodique&, DoubleVect& aii, DoubleVect& ajj ) const override;

  //virtual void coeffs_face(const DoubleTab&, int ,int, const Nouvelle_Cl_PolyMAC_old&, int,
  //                           DoubleVect& aii, DoubleVect& ajj ) const;

  inline void coeffs_faces_interne(int, DoubleVect& aii, DoubleVect& ajj ) const override;

  // Fonctions qui servent a calculer la contribution des conditions limites
  // au second membre pour l'implicite pour les grandeurs vectorielles.

  inline void secmem_face(int, const Symetrie&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Neumann_sortie_libre&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Dirichlet_entree_fluide&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Dirichlet_paroi_fixe&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Dirichlet_paroi_defilante&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Neumann_paroi_adiabatique&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Neumann_paroi&, int, DoubleVect& ) const override;
  inline void secmem_face(int, int, int, const Echange_externe_impose&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Echange_global_impose&, int, DoubleVect& ) const override;
  inline void secmem_face(int, const Periodique&, int, DoubleVect& ) const override;
  inline void secmem_faces_interne(int, DoubleVect& ) const override;

protected:

  inline int amont_amont(int , int ) const;
  inline double qcentre(const double, const int,
                        const int, const int, const int,
                        const int, const DoubleTab& ) const;
  inline void qcentre(const double, const int,
                      const int, const int, const int,
                      const int, const DoubleTab&, ArrOfDouble& ) const;

};

/////////////////////////////////////////////////////////////
// Fonctions inline de la classe Eval_centre_PolyMAC_old_Elem
////////////////////////////////////////////////////////////

inline Eval_centre_PolyMAC_old_Elem::Eval_centre_PolyMAC_old_Elem()
{
}


//// calculer_flux_faces_echange_externe_impose
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_echange_externe_impose() const
{
  return 0;
}


//// calculer_flux_faces_echange_global_impose
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_echange_global_impose() const
{
  return 0;
}


//// calculer_flux_faces_entree_fluide
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_entree_fluide() const
{
  return 1;
}


//// calculer_flux_faces_paroi
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_paroi() const
{
  return 0;
}


//// calculer_flux_faces_paroi_adiabatique
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_paroi_adiabatique() const
{
  return 0;
}


//// calculer_flux_faces_paroi_defilante
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_paroi_defilante() const
{
  return 0;
}


//// calculer_flux_faces_paroi_fixe
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_paroi_fixe() const
{
  return 0;
}


//// calculer_flux_faces_sortie_libre
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_sortie_libre() const
{
  return 1;
}


//// calculer_flux_faces_symetrie
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_symetrie() const
{
  return 0;
}

//// calculer_flux_faces_periodique
//

inline int Eval_centre_PolyMAC_old_Elem::calculer_flux_faces_periodique() const
{
  return 1;
}

//////////////////////////////////////////////////////////////
//  Fonctions de calcul des flux pour une grandeur scalaire
//////////////////////////////////////////////////////////////

//// flux_face avec Dirichlet_entree_fluide
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                      const Dirichlet_entree_fluide& la_cl,
                                                      int num1) const
{
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  double flux;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  double T_imp = la_cl.val_imp(face-num1);
  if (n0 != -1)
    {
      if (psc > 0)
        flux= psc*inco[n0];
      else
        flux= psc*T_imp;
    }
  else   // n1 != -1
    {
      if (psc>0)
        flux= psc*T_imp;
      else
        flux= psc*inco[n1];
    }
  return -flux;
}

//// coeffs_face avec Dirichlet_entree_fluide
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face, int num1,const Dirichlet_entree_fluide& la_cl,
                                                      double& aii, double& ajj) const
{
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];

  if (i != -1)
    {
      if (psc > 0)
        aii = -psc;
    }
  else   // j != -1
    {
      if (psc<0)
        ajj = -psc;
    }
}

//// secmem_face avec Dirichlet_entree_fluide
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int face, const Dirichlet_entree_fluide& la_cl,
                                                        int num1) const
{
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];
  double flux=0;
  double T_imp = la_cl.val_imp(face-num1);
  if (i != -1)
    {
      if (psc < 0)
        flux = psc*T_imp;
    }
  else   // j != -1
    {
      if (psc>0)
        flux = psc*T_imp;
    }
  return -flux;
}

//// flux_face avec Dirichlet_paroi_defilante
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Dirichlet_paroi_defilante&, int ) const
{
  return 0;
}


//// coeffs_face avec Dirichlet_paroi_defilante
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int,int, const Dirichlet_paroi_defilante&, double&, double&) const
{
  ;
}

//// secmem_face avec Dirichlet_paroi_defilante
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Dirichlet_paroi_defilante&, int ) const
{
  return 0;
}

//// flux_face avec Dirichlet_paroi_fixe
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Dirichlet_paroi_fixe&, int ) const
{
  return 0;
}

//// coeffs_face avec Dirichlet_paroi_fixe
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int ,int,const Dirichlet_paroi_fixe&, double&, double&) const
{
  ;
}

//// secmem_face avec Dirichlet_paroi_fixe
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int ,const Dirichlet_paroi_fixe&, int ) const
{
  return 0;
}


//// flux_face avec Echange_externe_impose
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int , int, int,
                                                      const Echange_externe_impose&, int ) const
{
  return 0;
}

//// coeffs_face avec Echange_externe_impose
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int,int,int,int, const Echange_externe_impose&, double&, double&) const
{
  ;
}

//// secmem_face avec Echange_externe_impose
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int,int,int, const Echange_externe_impose&, int ) const
{
  return 0;
}

//// flux_face avec Echange_global_impose
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Echange_global_impose&, int ) const
{
  return 0;
}

//// coeffs_face avec Echange_global_impose
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int, int,const Echange_global_impose&, double&, double&) const
{
  ;
}

//// secmem_face avec Echange_global_impose
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Echange_global_impose&, int ) const
{
  return 0;
}

//// flux_face avec Neumann_paroi
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Neumann_paroi&, int ) const
{
  return 0;
}

//// coeffs_face avec Neumann_paroi
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int , int,const Neumann_paroi&, double&, double&) const
{
  ;
}

//// secmem_face avec Neumann_paroi
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Neumann_paroi&, int ) const
{
  return 0;
}

//// flux_face avec Neumann_paroi_adiabatique
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Neumann_paroi_adiabatique&, int ) const
{
  return 0;
}

//// coeffs_face avec Neumann_paroi_adiabatique
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int,int, const Neumann_paroi_adiabatique&, double&, double&) const
{
  ;
}

//// secmem_face avec Neumann_paroi_adiabatique
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Neumann_paroi_adiabatique&, int ) const
{
  return 0;
}

//// flux_face avec Neumann_sortie_libre
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                      const Neumann_sortie_libre& la_cl, int num1) const
{
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  double flux;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (n0 != -1)
    {
      if (psc > 0)
        flux= psc*inco[n0];
      else
        flux= psc*la_cl.val_ext(face-num1);
    }
  else   // n1 != -1
    {
      if (psc > 0)
        flux=psc*la_cl.val_ext(face-num1);
      else
        flux= psc*inco[n1];
    }
  return -flux;
}

//// coeffs_face avec Neumann_sortie_libre
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face,int num1, const Neumann_sortie_libre& la_cl,
                                                      double& aii, double& ajj) const
{
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc > 0)
        aii = -psc;
    }
  else   // n1 != -1
    {
      if (psc < 0)
        ajj = -psc;
    }
}

//// secmem_face avec Neumann_sortie_libre
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int face, const Neumann_sortie_libre& la_cl, int num1) const
{
  double flux=0;
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc < 0)
        flux = psc*la_cl.val_ext(face-num1);
    }
  else   // j != -1
    {
      if (psc > 0)
        flux = psc*la_cl.val_ext(face-num1);
    }
  return -flux;
}

//// flux_face avec Symetrie
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                      const Symetrie&, int ) const
{
  return 0;
}


//// coeffs_face avec Symetrie
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int, int,const Symetrie&, double&, double&) const
{
  ;
}

//// secmem_face avec Symetrie
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Symetrie&, int ) const
{
  return 0;
}

//// flux_face avec Periodique
//

inline double Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                      const Periodique& la_cl, int ) const
{
  // 30/05/2002 : Codage Periodicite.
  // ALEX C.
  double flux;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  int n0_0 = amont_amont(face,0);
  int n1_1 = amont_amont(face,1);

  // on applique le schema centre2
  flux = qcentre(psc,n0,n1,n0_0,n1_1,face,inco);
  return -flux;
}

//// coeffs_face avec Periodique
//
inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face, int,const Periodique& la_cl, double& aii, double& ajj) const
{
  // 30/05/2002 : Codage Periodicite.
  // // ALEX C.
  int i = elem_(face,0);
  int j = elem_(face,1);
  int i0_0 = amont_amont(face,0);
  int j1_1 = amont_amont(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];

  // on applique le schema centre
  if (psc > 0)
    aii = -qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs());
  else
    ajj = -qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs());
}

//// secmem_face avec Periodique
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Periodique&, int ) const
{
  return 0;
}

//// flux_faces_interne
//

inline double Eval_centre_PolyMAC_old_Elem::flux_faces_interne(const DoubleTab& inco, int face) const
{
  double flux;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  int n0_0 = amont_amont(face,0);
  int n1_1 = amont_amont(face,1);

  flux = qcentre(psc,n0,n1,n0_0,n1_1,face,inco);
  return -flux;
}

//// coeffs_faces_interne
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_faces_interne(int face, double& aii, double& ajj ) const
{
  int i = elem_(face,0);
  int j = elem_(face,1);
  int i0_0 = amont_amont(face,0);
  int j1_1 = amont_amont(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];

  if ( (i0_0 == -1) || (j1_1 == -1) ) // on applique le schema amont
    if (psc > 0)
      aii = -psc;
    else
      ajj = -psc;

  else  // on applique le schema centre
    if (psc > 0)
      aii = -qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs());
    else
      ajj = -qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs());
}

//// secmem_faces_interne
//

inline double Eval_centre_PolyMAC_old_Elem::secmem_faces_interne(int) const
{
  return 0;
}


////////////////////////////////////////////////////////////////
// Fonctions de calcul des flux pour une grandeur vectorielle
////////////////////////////////////////////////////////////////

//// flux_face avec Dirichlet_entree_fluide
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                    const Dirichlet_entree_fluide& la_cl,
                                                    int num1, DoubleVect& flux) const
{
  int k;
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  double psc = dt_vitesse(face)*surface(face)*porosite(face);

  if (n0 != -1)
    {
      if (psc > 0)
        for (k=0; k<flux.size(); k++)
          flux(k) = -psc*inco(n0,k);
      else
        for (k=0; k<flux.size(); k++)
          flux(k)= -psc*la_cl.val_imp(face-num1,k);
    }
  else // n1 != -1
    {
      if (psc>0)
        for (k=0; k<flux.size(); k++)
          flux(k)= -psc*la_cl.val_imp(face-num1,k);
      else
        for (k=0; k<flux.size(); k++)
          flux(k)= -psc*inco(n1,k);
    }
}

//// coeffs_face avec Dirichlet_entree_fluide
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face, int num1,const Dirichlet_entree_fluide& la_cl,
                                                      DoubleVect& aii, DoubleVect& ajj) const
{
  int k;
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc > 0)
        for(k=0; k<aii.size(); k++)
          aii(k) = -psc;
    }
  else   // j != -1
    {
      if (psc < 0)
        for(k=0; k<ajj.size(); k++)
          ajj(k) = -psc;
    }
}

//// secmem_face avec Dirichlet_entree_fluide
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int face, const Dirichlet_entree_fluide& la_cl, int num1, DoubleVect& flux) const
{
  int k;
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc < 0)
        for(k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_imp(face-num1);
    }
  else   // j != -1
    {
      if (psc > 0)
        for(k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_imp(face-num1);
    }
}

//// flux_face avec Dirichlet_paroi_defilante
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Dirichlet_paroi_defilante&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Dirichlet_paroi_defilante
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int , int,const Dirichlet_paroi_defilante&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Dirichlet_paroi_defilante
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int , const Dirichlet_paroi_defilante& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Dirichlet_paroi_fixe
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Dirichlet_paroi_fixe&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Dirichlet_paroi_fixe
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int,int, const Dirichlet_paroi_fixe&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Dirichlet_paroi_fixe
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Dirichlet_paroi_fixe& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Echange_externe_impose
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int , int, int,
                                                    const Echange_externe_impose&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Echange_externe_impose
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int, int, int, int, const Echange_externe_impose&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Echange_externe_impose
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int , int, int, const Echange_externe_impose& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Echange_global_impose
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Echange_global_impose&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Echange_global_impose
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int , int,const Echange_global_impose&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Echange_global_impose
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int , const Echange_global_impose& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Neumann_paroi
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Neumann_paroi&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Neumann_paroi
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int, int,const Neumann_paroi&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Neumann_paroi
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Neumann_paroi& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Neumann_paroi_adiabatique
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Neumann_paroi_adiabatique&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Neumann_paroi_adiabatique
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int, int,const Neumann_paroi_adiabatique&, DoubleVect& , DoubleVect& ) const
{
  ;
}

//// secmem_face avec Neumann_paroi_adiabatique
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int , const Neumann_paroi_adiabatique& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Neumann_sortie_libre
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                    const Neumann_sortie_libre& la_cl,
                                                    int num1, DoubleVect& flux) const
{
  int k;
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (n0 != -1)
    {
      if (psc > 0)
        for (k=0; k<flux.size(); k++)
          flux(k) = -psc*inco(n0,k);
      else
        for (k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_ext(face-num1,k);
    }
  else  // n1 != -1
    {
      if (psc > 0)
        for (k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_ext(face-num1,k);
      else
        for (k=0; k<flux.size(); k++)
          flux(k) = -psc*inco(n1,k);
    }
}

//// coeffs_face avec Neumann_sortie_libre
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face,int num1, const Neumann_sortie_libre& la_cl,
                                                      DoubleVect& aii, DoubleVect& ajj) const
{
  int k;
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc > 0)
        for(k=0; k<aii.size(); k++)
          aii(k) = -psc;
    }
  else   // n1 != -1
    {
      if (psc < 0)
        for(k=0; k<ajj.size(); k++)
          ajj(k) = -psc;
    }
}

//// secmem_face avec Neumann_sortie_libre
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int face, const Neumann_sortie_libre& la_cl, int num1, DoubleVect& flux) const
{
  int k;
  int i = elem_(face,0);
  //int j = elem(face,1);
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  if (i != -1)
    {
      if (psc < 0)
        for(k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_ext(face-num1);
    }
  else   // j != -1
    {
      if (psc > 0)
        for(k=0; k<flux.size(); k++)
          flux(k) = -psc*la_cl.val_ext(face-num1);
    }
}

//// flux_face avec Symetrie
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab&, int ,
                                                    const Symetrie&,
                                                    int , DoubleVect& ) const
{
  ;
}

//// coeffs_face avec Symetrie
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int , int,const Symetrie&, DoubleVect&, DoubleVect& ) const
{
  ;
}

//// secmem_face avec Symetrie
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int , const Symetrie& ,
                                                      int, DoubleVect& ) const
{
  ;
}

//// flux_face avec Periodique
//

inline void Eval_centre_PolyMAC_old_Elem::flux_face(const DoubleTab& inco, int face,
                                                    const Periodique& la_cl,
                                                    int, DoubleVect& flux) const
{
  int k;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  int n0_0 = amont_amont(face,0);
  int n1_1 = amont_amont(face,1);

  // on applique le schema centre
  qcentre(psc,n0,n1,n0_0,n1_1,face,inco,flux);
  for (k=0; k<flux.size(); k++)
    flux(k) *= -1;

}

//// coeffs_face avec Periodique
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_face(int face,int, const Periodique& la_cl,
                                                      DoubleVect& aii, DoubleVect& ajj) const
{
  int k;
  int i = elem_(face,0);
  int j = elem_(face,1);
  int i0_0 = amont_amont(face,0);
  int j1_1 = amont_amont(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];
  ArrOfDouble flux(aii.size());

  // on applique le schema centre2
  qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs(),flux);
  if (psc > 0)
    for (k=0; k<aii.size(); k++)
      aii(k) = -flux[k];
  else
    for (k=0; k<ajj.size(); k++)
      ajj(k) = -flux[k];
}

//// secmem_face avec Periodique
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_face(int, const Periodique&,
                                                      int, DoubleVect&) const
{
  ;
}

//// flux_faces_interne
//

inline void Eval_centre_PolyMAC_old_Elem::flux_faces_interne(const DoubleTab& inco,
                                                             int face,DoubleVect& flux) const
{
  int k;
  double psc = dt_vitesse[face]*surface(face)*porosite(face);
  int n0 = elem_(face,0);
  int n1 = elem_(face,1);
  int n0_0 = amont_amont(face,0);
  int n1_1 = amont_amont(face,1);

  /*   if ( (n0_0 == -1) || (n1_1 == -1) ) // on applique le schema amont */
  /*     if (psc > 0) */
  /*       for (k=0; k<flux.size(); k++) */
  /*         flux(k) = -psc*inco(n0,k); */
  /*     else */
  /*       for (k=0; k<flux.size(); k++) */
  /*         flux(k) = -psc*inco(n1,k); */
  /*   else // on applique le schema centre */
  /*     { */
  qcentre(psc,n0,n1,n0_0,n1_1,face,inco,flux);
  for (k=0; k<flux.size(); k++)
    flux(k) *= -1;
  /*     } */
}

//// coeffs_faces_interne
//

inline void Eval_centre_PolyMAC_old_Elem::coeffs_faces_interne(int face, DoubleVect& aii, DoubleVect& ajj ) const
{
  int k;
  int i = elem_(face,0);
  int j = elem_(face,1);
  int i0_0 = amont_amont(face,0);
  int j1_1 = amont_amont(face,1);
  double psc = dt_vitesse[face]*surface[face]*porosite[face];
  ArrOfDouble flux(aii.size());

  /*   if ( (i0_0 == -1) || (j1_1 == -1) ) // on applique le schema amont  */
  /*     if (psc > 0) */
  /*       for (k=0; k<aii.size(); k++) */
  /*         aii(k) = -psc; */
  /*     else */
  /*       for (k=0; k<ajj.size(); k++) */
  /*         ajj(k) = -psc; */

  /*   else  // on applique le schema centre_Fram4 */
  /*     { */
  qcentre(psc,i,j,i0_0,j1_1,face,inconnue->valeurs(),flux);
  if (psc > 0)
    for (k=0; k<aii.size(); k++)
      aii(k) = -flux[k];
  else
    for (k=0; k<ajj.size(); k++)
      ajj(k) = -flux[k];
  /*     } */
}


//// secmem_faces_interne
//

inline void Eval_centre_PolyMAC_old_Elem::secmem_faces_interne(int, DoubleVect& ) const
{
  ;
}

//// Fram4
//

/* inline double Fram4(const double& s1,const double& s2, */
/*                    const double& s3,const double& s4) */
/* { */
/*   double smin0 = dmin(s4,s2); */
/*   double smax0 = std::max(s4,s2); */
/*   double smin1 = dmin(s3,s1); */
/*   double smax1 = std::max(s3,s1); */
/*   double sr0 = (s3-smin0)/(smax0-smin0+DMINFLOAT); */
/*   double sr1 = (s2-smin1)/(smax1-smin1+DMINFLOAT); */
/*   double fr = 2.*std::max(std::fabs(sr0-0.5),std::fabs(sr1-0.5)); */
/*   fr *= fr; */
/*   fr *= fr; */
/*   return dmin(fr,1.0); */
/* } */


//// amont_amont
//

inline int Eval_centre_PolyMAC_old_Elem::amont_amont(int face, int i) const
{
  return 0;//la_domaine->amont_amont(face, i);
}


//// qcentre pour un champ transporte scalaire
//

inline double Eval_centre_PolyMAC_old_Elem::qcentre(const double psc, const int num0, const int num1,
                                                    const int num0_0, const int num1_1, const int face,
                                                    const DoubleTab& transporte) const
{
  double flux;
  //int ori = orientation(face);

  double T0 = transporte[num0];
  double T1 = transporte[num1];


  flux =  0.5*(T0+T1);


  // On applique le filtre Fram4:

  //  fr = Fram4(T0_0,T0,T1,T1_1);
  //  flux = ((1.-fr)*flux + fr*trans_amont)*psc;

  return flux*psc;
}


//// qcentre pour un champ transporte vectoriel
//

inline void Eval_centre_PolyMAC_old_Elem::qcentre(const double psc, const int num0, const int num1,
                                                  const int num0_0, const int num1_1, const int face,
                                                  const DoubleTab& transporte,ArrOfDouble& flux) const
{

  int k;
  int ncomp = flux.size_array();

  ArrOfDouble T0(ncomp);
  ArrOfDouble T0_0(ncomp);
  ArrOfDouble T1(ncomp);
  ArrOfDouble T1_1(ncomp);

  for (k=0; k<ncomp; k++)
    {
      T0[k] = transporte(num0,k);
      T0_0[k] = transporte(num0_0,k);
      T1[k] = transporte(num1,k);
      T1_1[k] = transporte(num1_1,k);
    }

  //double g1 = -dx*dx*(dx/2+dxav)/(4*(dx+dxam+dxav)*(dx+dxam)*dxam);
  //double g2 =  (dx+2*dxam)*(dx+2*dxav)/(8*dxam*(dx+dxav));
  //double g3 = (dx+2*dxam)*(dx+2*dxav)/(8*dxav*(dx+dxam));
  //double g4 = -dx*dx*(dx/2+dxam)/(4*(dx+dxam+dxav)*dxav*(dx+dxav));

  for (k=0; k<ncomp; k++)
    {
      flux[k] =0.5*(  T0[k] + T1[k])   *   psc ;
    }

  // On applique le filtre Fram4:

  //for (k=0; k<ncomp; k++)
  // {
  //    fr = Fram4(T0_0(k),T0(k),T1(k),T1_1(k));
  // flux(k) = ((1.-fr)*flux(k) + fr*trans_amont(k))*psc;
}

#endif
