//
// Warning : DO NOT EDIT !
// To update this file, run: make depend
//
#include <verifie_pere.h>
#include <Assembleur_P_PolyMAC.h>
#include <Elem_PolyMAC.h>
#include <Hexa_PolyMAC.h>
#include <Masse_PolyMAC_Elem.h>
#include <Masse_PolyMAC_Face.h>
#include <PolyMAC_discretisation.h>
#include <Polyedre_PolyMAC.h>
#include <Polygone_PolyMAC.h>
#include <Quadri_PolyMAC.h>
#include <Segment_PolyMAC.h>
#include <Tetra_PolyMAC.h>
#include <Tri_PolyMAC.h>
#include <Zone_Cl_PolyMAC.h>
#include <Zone_PolyMAC.h>
void instancie_src_PolyMAC_Zones() {
Cerr << "src_PolyMAC_Zones" << finl;
Assembleur_P_PolyMAC inst1;verifie_pere(inst1);
Elem_PolyMAC inst2;verifie_pere(inst2);
Hexa_PolyMAC inst3;verifie_pere(inst3);
Masse_PolyMAC_Elem inst4;verifie_pere(inst4);
Masse_PolyMAC_Face inst5;verifie_pere(inst5);
PolyMAC_discretisation inst6;verifie_pere(inst6);
Polyedre_PolyMAC inst7;verifie_pere(inst7);
Polygone_PolyMAC inst8;verifie_pere(inst8);
Quadri_PolyMAC inst9;verifie_pere(inst9);
Segment_PolyMAC inst10;verifie_pere(inst10);
Tetra_PolyMAC inst11;verifie_pere(inst11);
Tri_PolyMAC inst12;verifie_pere(inst12);
Zone_Cl_PolyMAC inst13;verifie_pere(inst13);
Zone_PolyMAC inst14;verifie_pere(inst14);
}
