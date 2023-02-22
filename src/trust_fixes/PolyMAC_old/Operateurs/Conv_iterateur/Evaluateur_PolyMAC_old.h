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
// File:        Evaluateur_PolyMAC_old.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs/Conv_iterateur
// Version:     /main/12
//
//////////////////////////////////////////////////////////////////////////////


#ifndef Evaluateur_PolyMAC_old_included
#define Evaluateur_PolyMAC_old_included

#include <TRUSTTab.h>
#include <TRUST_Ref.h>
class Champ_base;
class Domaine_Cl_PolyMAC_old;
class Domaine_PolyMAC_old;

//
// .DESCRIPTION class Evaluateur_PolyMAC_old
//
// Classe de base des evaluateurs PolyMAC_old. Cette classe n'appartient pas a la
// hierarchie des Objet_U.
// Cette classe porte une reference a un objet de type Domaine_PolyMAC_old et une
// reference a un objet de type Domaine_Cl_PolyMAC_old. Elle porte des tableaux locaux
// qui sont en fait des references aux tableaux de l'objet de type Domaine_PolyMAC_old
// (ces tableaux locaux n'existent pas en memoire).

//
// .SECTION voir aussi
//
//


class Evaluateur_PolyMAC_old
{

public:

  inline Evaluateur_PolyMAC_old();
  inline virtual ~Evaluateur_PolyMAC_old() {};

  Evaluateur_PolyMAC_old(const Evaluateur_PolyMAC_old& );
  virtual void associer_domaines(const Domaine_PolyMAC_old& , const Domaine_Cl_PolyMAC_old& );
  virtual void associer_porosite(const DoubleVect&);

protected:

  REF(Domaine_PolyMAC_old) la_domaine;
  REF(Domaine_Cl_PolyMAC_old) la_zcl;
  int dimension;
  int premiere_face_bord;
  IntTab elem_;                       // les 2 elements voisins d'une face
  DoubleVect surface;          // surfaces des faces
  DoubleVect porosite;               // porosites surfaciques
  DoubleVect volume_entrelaces;//
  DoubleTab xv;                // coord des centres des faces


};

//
//   Fonctions inline de Evaluateur_PolyMAC_old
//

inline Evaluateur_PolyMAC_old::Evaluateur_PolyMAC_old()
{}


#endif
