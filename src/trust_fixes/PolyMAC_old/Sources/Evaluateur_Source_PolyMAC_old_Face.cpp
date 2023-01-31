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
// File:        Evaluateur_Source_PolyMAC_old_Face.cpp
// Directory:   $TRUST_ROOT/src/PolyMAC_old/Sources
// Version:     /main/3
//
//////////////////////////////////////////////////////////////////////////////

#include <Evaluateur_Source_PolyMAC_old_Face.h>
#include <Equation_base.h>
#include <Milieu_base.h>

//
//   Fonctions de Evaluateur_Source_PolyMAC_old_Face
//

Evaluateur_Source_PolyMAC_old_Face::Evaluateur_Source_PolyMAC_old_Face(const Evaluateur_Source_PolyMAC_old_Face& eval)
  : Evaluateur_Source_PolyMAC_old(eval)
{
  orientation.ref(eval.orientation);
  volumes_entrelaces.ref(eval.volumes_entrelaces);
  porosite_surf.ref(eval.porosite_surf);
}

void Evaluateur_Source_PolyMAC_old_Face::completer()
{
  orientation.ref(la_zone->orientation());
  volumes_entrelaces.ref(la_zone->volumes_entrelaces());
  porosite_surf.ref(la_zcl->equation().milieu().porosite_face());
}
