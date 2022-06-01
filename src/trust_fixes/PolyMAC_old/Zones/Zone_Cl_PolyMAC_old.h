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
// File:        Zone_Cl_PolyMAC_old.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Zones
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////

#ifndef Zone_Cl_PolyMAC_old_included
#define Zone_Cl_PolyMAC_old_included



//
// .DESCRIPTION class Zone_Cl_PolyMAC_old
//  Cette classe porte les tableaux qui servent a mettre en oeuvre
//  les condition aux limites dans la formulation PolyMAC_old

//
// .SECTION voir aussi
// Zone_Cl_dis_base


#include <Zone_Cl_dis_base.h>
#include <Champ_Don.h>


class Champ_Inc;
class Zone_PolyMAC_old;
class Matrice_Morse;

class Zone_Cl_PolyMAC_old : public Zone_Cl_dis_base
{

  Declare_instanciable(Zone_Cl_PolyMAC_old);

public :

  void associer(const Zone_PolyMAC_old& );
  void completer(const Zone_dis& ) override;
//  void mettre_a_jour(double );
  int initialiser(double temps) override;
  void imposer_cond_lim(Champ_Inc&, double) override;



  int nb_faces_sortie_libre() const;
  Zone_PolyMAC_old& zone_PolyMAC_old();
  const Zone_PolyMAC_old& zone_PolyMAC_old() const;

  int nb_bord_periodicite() const;
protected:

  // Attributs:

  int modif_perio_fait_;

  // Fonctions de creation des membres prives de la zone:

  void remplir_type_elem_Cl(const Zone_PolyMAC_old& );
};

//
// Fonctions inline de la classe Zone_Cl_PolyMAC_old
//





#endif
