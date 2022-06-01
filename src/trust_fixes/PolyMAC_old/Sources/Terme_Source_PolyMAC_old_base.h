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
// File:        Terme_Source_PolyMAC_old_base.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Sources
// Version:     /main/11
//
//////////////////////////////////////////////////////////////////////////////

#ifndef Terme_Source_PolyMAC_old_base_included
#define Terme_Source_PolyMAC_old_base_included

// .DESCRIPTION
// PolyMAC_old implementation of Source_base class

#include <Source_base.h>
#include <Iterateur_Source_PolyMAC_old.h>

//////////////////////////////////////////////////////////////////////////////
//
// CLASS: Terme_Source_PolyMAC_old_base
//
//////////////////////////////////////////////////////////////////////////////

class Terme_Source_PolyMAC_old_base : public Source_base
{

  Declare_base(Terme_Source_PolyMAC_old_base);

public:

  inline Terme_Source_PolyMAC_old_base(const Iterateur_Source_PolyMAC_old_base&);
  inline DoubleTab& ajouter(DoubleTab& ) const override ;
  inline DoubleTab& calculer(DoubleTab& ) const override ;
  void completer() override;

protected:

  Iterateur_Source_PolyMAC_old iter;
};

//
//   Fonctions inline de la classe Terme_Source_PolyMAC_old_base
//

// Description:
// constructeur
inline Terme_Source_PolyMAC_old_base::Terme_Source_PolyMAC_old_base(const Iterateur_Source_PolyMAC_old_base& iter_base) :
  iter(iter_base)
{}

inline DoubleTab& Terme_Source_PolyMAC_old_base::ajouter(DoubleTab& resu) const
{
  return iter.ajouter(resu);
}

inline DoubleTab& Terme_Source_PolyMAC_old_base::calculer(DoubleTab& resu) const
{
  return iter.calculer(resu);
}
#endif
