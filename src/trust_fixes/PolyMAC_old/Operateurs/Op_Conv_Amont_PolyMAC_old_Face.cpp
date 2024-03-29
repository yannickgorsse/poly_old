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
// File:        Op_Conv_Amont_PolyMAC_old_Face.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs
// Version:     1
//
//////////////////////////////////////////////////////////////////////////////

#include <Op_Conv_Amont_PolyMAC_old_Face.h>

Implemente_instanciable( Op_Conv_Amont_PolyMAC_old_Face, "Op_Conv_Amont_PolyMAC_old_Face_PolyMAC_old", Op_Conv_EF_Stab_PolyMAC_old_Face ) ;

Sortie& Op_Conv_Amont_PolyMAC_old_Face::printOn( Sortie& os ) const
{
  Op_Conv_PolyMAC_old_base::printOn( os );
  return os;
}

Entree& Op_Conv_Amont_PolyMAC_old_Face::readOn( Entree& is )
{
  Op_Conv_PolyMAC_old_base::readOn( is );
  alpha = 1;
  return is;
}
