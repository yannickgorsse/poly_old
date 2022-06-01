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
// File:        ItPolyMACEl.h
// Directory:   $TRUST_ROOT/src/PolyMAC/Operateurs/Conv_iterateur
// Version:     /main/5
//
//////////////////////////////////////////////////////////////////////////////

#ifndef It_PolyMACEl_H
#define It_PolyMACEl_H

#include <Config_Template_Version_PolyMAC_Operateur.h>
#define It_PolyMAC_Elem(_TYPE_) name2(Iterateur_PolyMAC_Elem, _TYPE_)

#ifdef Template_Version_PolyMAC
#include <T_It_PolyMAC_Elem.h>
#define declare_It_PolyMAC_Elem(_TYPE_)

#define implemente_It_PolyMAC_Elem(_TYPE_) \
  typedef T_It_PolyMAC_Elem<_TYPE_> It_PolyMAC_Elem(_TYPE_);
#else
#include <MItPolyMACEl.h>
#endif

#endif
