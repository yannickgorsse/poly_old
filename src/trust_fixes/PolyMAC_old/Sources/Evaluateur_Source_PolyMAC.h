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
// File:        Evaluateur_Source_PolyMAC.h
// Directory:   $TRUST_ROOT/src/PolyMAC/Sources
// Version:     /main/8
//
//////////////////////////////////////////////////////////////////////////////

#ifndef Evaluateur_Source_PolyMAC_included
#define Evaluateur_Source_PolyMAC_included

#include <Ref_Zone_Cl_PolyMAC.h>
#include <TRUSTTabs_forward.h>
#include <Ref_Zone_PolyMAC.h>
#include <Zone_Cl_PolyMAC.h>
#include <Zone_PolyMAC.h>

class Evaluateur_Source_PolyMAC
{
public:
  inline Evaluateur_Source_PolyMAC();
  inline virtual ~Evaluateur_Source_PolyMAC() {};
  inline Evaluateur_Source_PolyMAC(const Evaluateur_Source_PolyMAC& );
  inline void associer_zones(const Zone_dis_base&,const Zone_Cl_dis_base&);
  virtual void mettre_a_jour( ) =0;
  virtual void completer() = 0;
  virtual double calculer_terme_source(int ) const =0;
  virtual void calculer_terme_source(int , DoubleVect&  ) const =0;

protected:
  REF(Zone_PolyMAC) la_zone;
  REF(Zone_Cl_PolyMAC) la_zcl;
};

inline Evaluateur_Source_PolyMAC::Evaluateur_Source_PolyMAC() {}

inline Evaluateur_Source_PolyMAC::Evaluateur_Source_PolyMAC(const Evaluateur_Source_PolyMAC& eval)
  : la_zone(eval.la_zone),la_zcl(eval.la_zcl) {}

inline void Evaluateur_Source_PolyMAC::associer_zones(const Zone_dis_base& zone_vdf, const Zone_Cl_dis_base& zone_cl_vdf)
{
  la_zone = ref_cast(Zone_PolyMAC, zone_vdf);
  la_zcl = ref_cast(Zone_Cl_PolyMAC, zone_cl_vdf);
  completer();
}

#endif
