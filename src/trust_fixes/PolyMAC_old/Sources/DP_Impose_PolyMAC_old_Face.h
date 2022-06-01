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
// File:        DP_Impose_PolyMAC_old_Face.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Sources
// Version:     /main/9
//
//////////////////////////////////////////////////////////////////////////////


#ifndef DP_Impose_PolyMAC_old_Face_included
#define DP_Impose_PolyMAC_old_Face_included

#include <Perte_Charge_PolyMAC_old_Face.h>
#include <DP_Impose.h>

class Domaine;
#include <TRUSTList.h>

//
// .DESCRIPTION class DP_Impose_PolyMAC_old_Face
//

//
// .SECTION voir aussi Perte_Charge_PolyMAC_old_Face
//
//

class DP_Impose_PolyMAC_old_Face : public Perte_Charge_PolyMAC_old_Face,
  public DP_Impose
{

  Declare_instanciable(DP_Impose_PolyMAC_old_Face);

public:

  DoubleTab& ajouter(DoubleTab& ) const override;
  DoubleTab& calculer(DoubleTab& ) const override ;
  void contribuer_a_avec(const DoubleTab&, Matrice_Morse&) const override;
  void remplir_num_faces(Entree& );
  void mettre_a_jour(double temps) override;

protected:
  IntVect sgn;
  double surf;//surface totale
};
#endif
