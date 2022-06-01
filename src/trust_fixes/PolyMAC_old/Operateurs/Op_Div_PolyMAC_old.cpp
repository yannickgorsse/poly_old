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
// File:        Op_Div_PolyMAC_old.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs
// Version:     /main/18
//
//////////////////////////////////////////////////////////////////////////////

#include <Op_Div_PolyMAC_old.h>
#include <Zone_Cl_PolyMAC_old.h>
//#include <Les_Cl.h>
#include <Probleme_base.h>
#include <Navier_Stokes_std.h>
#include <Schema_Temps_base.h>
#include <Check_espace_virtuel.h>
#include <EcrFicPartage.h>
#include <SFichier.h>
#include <Matrice_Morse.h>
#include <Matrix_tools.h>
#include <Array_tools.h>
#include <Debog.h>

Implemente_instanciable(Op_Div_PolyMAC_old,"Op_Div_PolyMAC_old",Operateur_Div_base);


//// printOn
//

Sortie& Op_Div_PolyMAC_old::printOn(Sortie& s) const
{
  return s << que_suis_je() ;
}

//// readOn
//

Entree& Op_Div_PolyMAC_old::readOn(Entree& s)
{
  return s ;
}



// Description:
void Op_Div_PolyMAC_old::associer(const Zone_dis& zone_dis,
                              const Zone_Cl_dis& zone_Cl_dis,
                              const Champ_Inc&)
{
  const Zone_PolyMAC_old& zPolyMAC_old = ref_cast(Zone_PolyMAC_old, zone_dis.valeur());
  const Zone_Cl_PolyMAC_old& zclPolyMAC_old = ref_cast(Zone_Cl_PolyMAC_old, zone_Cl_dis.valeur());
  la_zone_PolyMAC_old = zPolyMAC_old;
  la_zcl_PolyMAC_old = zclPolyMAC_old;
}

DoubleTab& Op_Div_PolyMAC_old::ajouter(const DoubleTab& vit, DoubleTab& div) const
{
  Debog::verifier("div in",div);


  Debog::verifier("vit in div",vit);
  const Zone_PolyMAC_old& zone_PolyMAC_old = la_zone_PolyMAC_old.valeur();
  const DoubleVect& surface=zone_PolyMAC_old.face_surfaces();
  const IntTab& face_voisins = zone_PolyMAC_old.face_voisins();
  const DoubleVect& porosite_surf = zone_PolyMAC_old.porosite_face();


  Debog::verifier("poro",porosite_surf);
  Debog::verifier("surf",surface);

  // L'espace virtuel du tableau div n'est pas mis a jour par l'operateur,
  //  assert(invalide_espace_virtuel(div));
  declare_espace_virtuel_invalide(div);
  // calcul de flux bord

  DoubleTab& tab_flux_bords = flux_bords_;
  tab_flux_bords.resize(zone_PolyMAC_old.nb_faces_bord(),1);
  tab_flux_bords=0;


  int premiere_face_int=zone_PolyMAC_old.premiere_face_int();
  int nb_faces=zone_PolyMAC_old.nb_faces();
  for (int face=0; face<premiere_face_int; face++)
    {

      double flux=porosite_surf[face]*vit[face]*surface[face];
      tab_flux_bords(face,0)+=flux;
      int elem1=face_voisins(face,0);
      if (elem1!=-1)
        div(elem1)+=flux;
      int elem2=face_voisins(face,1);
      if (elem2!=-1)
        div(elem2)-=flux;

    }

  for (int face=premiere_face_int; face<nb_faces; face++)
    {
      double flux=porosite_surf[face]*vit[face]*surface[face];
      int elem1=face_voisins(face,0);
      assert(zone_PolyMAC_old.oriente_normale(face,elem1)==1);

      div(elem1)+=flux;
      int elem2=face_voisins(face,1);

      div(elem2)-=flux;
    }
  div.echange_espace_virtuel();

  Debog::verifier("div out",div);
  return div;
}
void Op_Div_PolyMAC_old::contribuer_a_avec(const DoubleTab&,Matrice_Morse& matrice) const
{
  const Zone_PolyMAC_old& zone_PolyMAC_old = la_zone_PolyMAC_old.valeur();
  const DoubleVect& surface=zone_PolyMAC_old.face_surfaces();
  const IntTab& face_voisins = zone_PolyMAC_old.face_voisins();
  const DoubleVect& porosite_surf = zone_PolyMAC_old.porosite_face();


  int nb_faces=zone_PolyMAC_old.nb_faces();

  for (int face=0; face<nb_faces; face++)
    {
      // flux * -1 car contribuer_a_avec renvoie  -d/dI
      double flux=-porosite_surf[face]*surface[face];

      int elem1=face_voisins(face,0);
      if (elem1!=-1)
        matrice(elem1,face)+=flux;
      int elem2=face_voisins(face,1);
      if (elem2!=-1)
        matrice(elem2,face)-=flux;

    }
}

void Op_Div_PolyMAC_old::dimensionner(Matrice_Morse& matrice) const
{

  const Zone_PolyMAC_old& zone_PolyMAC_old = la_zone_PolyMAC_old.valeur();
  int nb_faces=zone_PolyMAC_old.nb_faces();
  int nb_faces_tot=zone_PolyMAC_old.nb_faces_tot();
  int nb_elem_tot=zone_PolyMAC_old.nb_elem_tot();
  IntTab stencyl(0,2);
  stencyl.set_smart_resize(1);
  const IntTab& face_voisins = zone_PolyMAC_old.face_voisins();

  int nb_coef=0;
  for (int face=0; face<nb_faces; face++)
    {
      for (int dir=0; dir<2; dir++)
        {
          int elem=face_voisins(face,dir);
          if (elem!=-1)
            {
              stencyl.resize(nb_coef+1,2);
              stencyl(nb_coef,0)=elem;
              stencyl(nb_coef,1)=face;
              nb_coef++;
            }
        }
    }
  tableau_trier_retirer_doublons(stencyl);
  Matrix_tools::allocate_morse_matrix(nb_elem_tot,nb_faces_tot,stencyl,matrice);

}

DoubleTab& Op_Div_PolyMAC_old::calculer(const DoubleTab& vit, DoubleTab& div) const
{
  div = 0;
  return ajouter(vit,div);

}

int Op_Div_PolyMAC_old::impr(Sortie& os) const
{

  const int impr_bord=(la_zone_PolyMAC_old->zone().Bords_a_imprimer().est_vide() ? 0:1);
  SFichier Flux_div;
  ouvrir_fichier(Flux_div,"",je_suis_maitre());
  EcrFicPartage Flux_face;
  ouvrir_fichier_partage(Flux_face,"",impr_bord);
  const Schema_Temps_base& sch = equation().probleme().schema_temps();
  double temps = sch.temps_courant();
  if (je_suis_maitre()) Flux_div.add_col(temps);

  int nb_compo=flux_bords_.dimension(1);
  // On parcours les frontieres pour sommer les flux par frontiere dans le tableau flux_bord
  DoubleVect flux_bord(nb_compo);
  DoubleVect bilan(nb_compo);
  bilan = 0;
  for (int num_cl=0; num_cl<la_zone_PolyMAC_old->nb_front_Cl(); num_cl++)
    {
      flux_bord=0;
      const Cond_lim& la_cl = la_zcl_PolyMAC_old->les_conditions_limites(num_cl);
      const Front_VF& frontiere_dis = ref_cast(Front_VF,la_cl.frontiere_dis());
      int ndeb = frontiere_dis.num_premiere_face();
      int nfin = ndeb + frontiere_dis.nb_faces();
      for (int face=ndeb; face<nfin; face++)
        for(int k=0; k<nb_compo; k++)
          flux_bord(k)+=flux_bords_(face, k);
      for(int k=0; k<nb_compo; k++)
        flux_bord(k)=Process::mp_sum(flux_bord(k));

      if(je_suis_maitre())
        {
          for(int k=0; k<nb_compo; k++)
            {
              //Ajout pour impression sur fichiers separes
              Flux_div.add_col(flux_bord(k));
              bilan(k)+=flux_bord(k);
            }
        }
    }

  if(je_suis_maitre())
    {
      for(int k=0; k<nb_compo; k++)
        {
          Flux_div.add_col(bilan(k));
        }
      Flux_div << finl;
    }

  for (int num_cl=0; num_cl<la_zone_PolyMAC_old->nb_front_Cl(); num_cl++)
    {
      const Frontiere_dis_base& la_fr = la_zcl_PolyMAC_old->les_conditions_limites(num_cl).frontiere_dis();
      const Cond_lim& la_cl = la_zcl_PolyMAC_old->les_conditions_limites(num_cl);
      const Front_VF& frontiere_dis = ref_cast(Front_VF,la_cl.frontiere_dis());
      int ndeb = frontiere_dis.num_premiere_face();
      int nfin = ndeb + frontiere_dis.nb_faces();
      if (la_zone_PolyMAC_old->zone().Bords_a_imprimer().contient(la_fr.le_nom()))
        {
          Flux_face << "# Flux par face sur " << la_fr.le_nom() << " au temps " << temps << " : " << finl;
          for (int face=ndeb; face<nfin; face++)
            {
              if (dimension==2)
                Flux_face << "# Face a x= " << la_zone_PolyMAC_old->xv(face,0) << " y= " << la_zone_PolyMAC_old->xv(face,1) << " flux=" ;
              else if (dimension==3)
                Flux_face << "# Face a x= " << la_zone_PolyMAC_old->xv(face,0) << " y= " << la_zone_PolyMAC_old->xv(face,1) << " z= " << la_zone_PolyMAC_old->xv(face,2) << " flux=" ;
              for(int k=0; k<nb_compo; k++)
                Flux_face << " " << flux_bords_(face, k);
              Flux_face << finl;
            }
          Flux_face.syncfile();
        }
    }

  return 1;
}


void Op_Div_PolyMAC_old::volumique(DoubleTab& div) const
{
  const Zone_PolyMAC_old& zone_PolyMAC_old = la_zone_PolyMAC_old.valeur();
  const DoubleVect& vol = zone_PolyMAC_old.volumes();
  int nb_elem=zone_PolyMAC_old.zone().nb_elem_tot();
  int num_elem;

  for(num_elem=0; num_elem<nb_elem; num_elem++)
    div(num_elem)/=vol(num_elem);
}