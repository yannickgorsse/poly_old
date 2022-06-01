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
// File:        Iterateur_PolyMAC_old_base.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Operateurs/Conv_iterateur
// Version:     /main/9
//
//////////////////////////////////////////////////////////////////////////////

#include <Iterateur_PolyMAC_old_base.h>

Implemente_deriv(Iterateur_PolyMAC_old_base);
Implemente_base(Iterateur_PolyMAC_old_base,"Iterateur_PolyMAC_old_base",Objet_U);
Implemente_instanciable(Iterateur_PolyMAC_old,"Iterateur_PolyMAC_old",DERIV(Iterateur_PolyMAC_old_base));


//// printOn
//

Sortie& Iterateur_PolyMAC_old::printOn(Sortie& s ) const
{
  return s << que_suis_je() ;
}

Sortie& Iterateur_PolyMAC_old_base::printOn(Sortie& s ) const
{
  return s << que_suis_je() ;
}


//// readOn
void Iterateur_PolyMAC_old_base::calculer_flux_bord(const DoubleTab& inco) const
{
  Cerr<<que_suis_je()<<" must implement alculer_flux_bord"<<finl;
  assert(0);
  Process::exit();
}

Entree& Iterateur_PolyMAC_old_base::readOn(Entree& s )
{
  return s ;
}
Entree& Iterateur_PolyMAC_old::readOn(Entree& s )
{
  return s ;
}


void Iterateur_PolyMAC_old_base::associer(const Zone_dis& z,
                                          const Zone_Cl_dis& zcl, const Operateur_base& op)
{
  const Zone_PolyMAC_old& zone_vdf=ref_cast(Zone_PolyMAC_old, z.valeur());
  const Zone_Cl_PolyMAC_old& zone_cl_vdf=ref_cast(Zone_Cl_PolyMAC_old, zcl.valeur());
  associer(zone_vdf, zone_cl_vdf,op);
}
void Iterateur_PolyMAC_old_base::associer_zone_cl_dis(const Zone_Cl_dis_base& zcl)
{
  const Zone_Cl_PolyMAC_old& zone_cl_vdf=ref_cast(Zone_Cl_PolyMAC_old, zcl);
  la_zcl=zone_cl_vdf;

}
void Iterateur_PolyMAC_old_base::associer(const Zone_PolyMAC_old& zone_vdf,
                                          const Zone_Cl_PolyMAC_old& zone_cl_vdf, const Operateur_base& op)
{
  la_zone=zone_vdf;
  la_zcl=zone_cl_vdf;
  op_base=op;
  // completer_();
}

