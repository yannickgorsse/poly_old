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
// File:        ItSouPolyMAC_oldFa.h
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Sources
// Version:     /main/4
//
//////////////////////////////////////////////////////////////////////////////

#ifndef ItSouPolyMAC_oldFa_H
#define ItSouPolyMAC_oldFa_H


#include <Config_Template_Version_Sources_PolyMAC_old.h>
#define It_Sou_PolyMAC_old_Face(_TYPE_) name2(Iterateur_Source_PolyMAC_old_Face, _TYPE_)

#ifdef Template_Version_PolyMAC_old
#include <T_It_Sou_PolyMAC_old_Face.h>

#define declare_It_Sou_PolyMAC_old_Face(_TYPE_)				\
  typedef T_It_Sou_PolyMAC_old_Face<_TYPE_> It_Sou_Poly_MAC_Face(_TYPE_);
#define implemente_It_Sou_PolyMAC_old_Face(_TYPE_)

#else
#include <MItSouPolyMAC_oldFa.h>
#endif

#endif
