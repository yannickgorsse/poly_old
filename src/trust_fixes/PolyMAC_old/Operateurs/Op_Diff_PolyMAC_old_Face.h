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
// File:        Op_Diff_PolyMAC_old_Face.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////

#ifndef Op_Diff_PolyMAC_old_Face_included
#define Op_Diff_PolyMAC_old_Face_included

#include <Op_Diff_PolyMAC_old_base.h>

/////////////////////////////////////////////////////////////////////////////
//
// .DESCRIPTION : class Op_Diff_PolyMAC_old_Face
//
// <Description of class Op_Diff_PolyMAC_old_Face>
//
/////////////////////////////////////////////////////////////////////////////

class Op_Diff_PolyMAC_old_Face : public Op_Diff_PolyMAC_old_base
{

  Declare_instanciable( Op_Diff_PolyMAC_old_Face ) ;

public :
  void completer() override;
  DoubleTab& ajouter(const DoubleTab& inco, DoubleTab& resu) const override;
  void contribuer_a_avec(const DoubleTab&, Matrice_Morse&) const override;
  void contribuer_au_second_membre(DoubleTab& ) const override;
  void modifier_pour_Cl(Matrice_Morse&, DoubleTab&) const override { };
  void dimensionner(Matrice_Morse& mat) const override;
};

#endif /* Op_Diff_PolyMAC_old_Face_included */
