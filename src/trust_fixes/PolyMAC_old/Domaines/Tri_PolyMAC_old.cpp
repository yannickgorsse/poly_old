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
// File:        Tri_PolyMAC_old.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Domaines
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////

#include <Tri_PolyMAC_old.h>
#include <Domaine.h>
#include <Domaine_PolyMAC_old.h>
#include <Champ_P1_PolyMAC_old.h>

Implemente_instanciable_sans_constructeur(Tri_PolyMAC_old,"Tri_PolyMAC_old",Elem_PolyMAC_old_base);

// printOn et readOn


Sortie& Tri_PolyMAC_old::printOn(Sortie& s ) const
{
  return s << que_suis_je() << "\n";
}

Entree& Tri_PolyMAC_old::readOn(Entree& s )
{
  return s ;
}

Tri_PolyMAC_old::Tri_PolyMAC_old()
{
}

// Description:
// remplit le tableau face_normales dans la Domaine_PolyMAC_old
void Tri_PolyMAC_old::normale(int num_Face,DoubleTab& Face_normales,
                              const  IntTab& Face_sommets,
                              const IntTab& Face_voisins,
                              const IntTab& elem_faces,
                              const Domaine& domaine_geom) const
{
  const DoubleTab& les_coords = domaine_geom.coord_sommets();

  double x1,y1;
  double nx,ny;
  int no3;
  int f0;
  int n0 = Face_sommets(num_Face,0);
  int n1 = Face_sommets(num_Face,1);
  x1 = les_coords(n0,0)-les_coords(n1,0);
  y1 = les_coords(n0,1)-les_coords(n1,1);
  nx = -y1;
  ny = x1;

  // Orientation de la normale de elem1 vers elem2
  // pour cela recherche du sommet de elem1 qui n'est pas sur la Face
  int elem1 = Face_voisins(num_Face,0);
  if ( (f0 = elem_faces(elem1,0)) == num_Face )
    f0 = elem_faces(elem1,1);
  if ( (no3 = Face_sommets(f0,0)) != n0 && no3 != n1 )
    ;
  else
    no3 = Face_sommets(f0,1);

  x1 = les_coords(no3,0) - les_coords(n0,0);
  y1 = les_coords(no3,1) - les_coords(n0,1);

  if ( (nx*x1+ny*y1) > 0 )
    {
      Face_normales(num_Face,0) = - nx;
      Face_normales(num_Face,1) = - ny;
    }
  else
    {
      Face_normales(num_Face,0) = nx;
      Face_normales(num_Face,1) = ny;
    }
}

