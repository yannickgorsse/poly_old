//
// Warning : DO NOT EDIT !
// To update this file, run: make depend
//
#include <verifie_pere.h>
#include <Op_Conv_Amont_PolyMAC_old_Face.h>
#include <Op_Conv_Centre_PolyMAC_old_Face.h>
#include <Op_Conv_EF_Stab_PolyMAC_old_Face.h>
#include <Op_Diff_PolyMAC_old_Elem.h>
#include <Op_Diff_PolyMAC_old_Face.h>
#include <Op_Div_PolyMAC_old.h>
#include <Op_Grad_PolyMAC_old_Face.h>
void instancie_src_PolyMAC_old_Operateurs() {
Cerr << "src_PolyMAC_old_Operateurs" << finl;
Op_Conv_Amont_PolyMAC_old_Face inst1;verifie_pere(inst1);
Op_Conv_Centre_PolyMAC_old_Face inst2;verifie_pere(inst2);
Op_Conv_EF_Stab_PolyMAC_old_Face inst3;verifie_pere(inst3);
Op_Diff_PolyMAC_old_Elem inst4;verifie_pere(inst4);
Op_Diff_Nonlinear_PolyMAC_old_Elem inst5;verifie_pere(inst5);
Op_Dift_PolyMAC_old_Elem inst6;verifie_pere(inst6);
Op_Dift_Nonlinear_PolyMAC_old_Elem inst7;verifie_pere(inst7);
Op_Diff_PolyMAC_old_Face inst8;verifie_pere(inst8);
Op_Div_PolyMAC_old inst9;verifie_pere(inst9);
Op_Grad_PolyMAC_old_Face inst10;verifie_pere(inst10);
}
