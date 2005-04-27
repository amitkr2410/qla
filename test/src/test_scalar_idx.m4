/* QLA test code */
/* for indexed scalar routines. */
/* C code generated by m4 from test_scalar_idx.m4 */

include(protocol_idx.m4)

`
#include <qla.h>
#include <qla_d.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "compare.h"

int main(){

  
  QLA_Real sR1[MAX] = { 61.88, -10.38,  73.59, -96.07,  50.32,
		92.37,   34.58, -21.10, -67.05, 104.01};

  QLA_Real sR2[MAX] = {.2359, .6106, .5588, .6899, .5000,
		.9789, .4457, .8602, .4282, .7920};
  
  QLA_Real sR3[MAX] = {-23.59, -56.32, -55.88, -11.55, 145.46, 
		 219.29, 71.47, -268.80, 42.82, 54.72};

  QLA_Real sR4       = -6.35;

  QLA_Real sC1re[MAX] = { 92.37,   34.58, -21.10, -67.05, 104.01,
		      61.88, -10.38,  73.59, -96.07,  50.32};

  QLA_Real sC2re[MAX] = { .9789, -.4457, .8602, .4282, .7920,
		     -.2359, -.6106, -.5588 -.6899, -.5000};
  
  QLA_Real sC3re[MAX] = {219.29, 71.47, -268.80, 42.82, 54.72,
		     -23.59, -56.32, -55.88, -11.55, 145.46}; 

  QLA_Real sC1im[MAX] = {-23.59, -61.06, -55.88 -68.99, -50.00,
		      92.37,   34.58, -21.10, -67.05, 104.01};

  QLA_Real sC2im[MAX] = { .6188, -.1038,  .7359, -.9607,  .5032,
		     2.1929, .7147, -2.6880, .4282, .5472};
  
  QLA_Real sC3im[MAX] = {-23.59, -56.32, -55.88, -11.55, 145.46, 
		      97.89, -44.57, 86.02, 42.82, 79.20};

  QLA_Real sC4re      = 831.2;
  QLA_Real sC4im      = -701.;

  QLA_Complex sC1[MAX],sC2[MAX],sC3[MAX];
  QLA_Complex sC4;

  QLA_RandomState sS1[MAX];

  int nI1[MAX] = { 3, 12, 7, 1, 5, 8, 3, 2, 1, 5};
  int zI1[MAX] = { 3, 0, 7, 1, 0, 0, 3, 2, 1, 0};

  QLA_Int sI1[MAX] = { 61, -10,  73, -96,  50,
		   92,  34, -21, -67, 104};

  QLA_Int sI2[MAX] = {-2359, -6106, -5588, -6899, -5000,
		9789, -4457, 8602, 4282, 7920};

  QLA_Int sI3[MAX] = { 92,  34, -21, -67, 104,
		   61, -10,  73, -96,  50};

  QLA_Int sI4      = 5001;
  QLA_Int sI5      = 13;

  int dRx[MAX]  = {8,5,6,7,1,2,9,0,3,4};
  int sR1x[MAX] = {3,0,1,8,2,4,5,9,7,6};
  int sR2x[MAX] = {4,9,0,2,1,3,7,8,5,6};
  int sR3x[MAX] = {8,3,2,5,6,9,7,4,0,1};

  int dCx[MAX]  = {8,3,2,5,6,9,7,4,0,1};
  int sC1x[MAX] = {8,5,6,7,1,2,9,0,3,4};
  int sC2x[MAX] = {4,9,0,2,1,3,7,8,5,6};

  int dIx[MAX]  = {8,3,2,5,6,9,7,4,0,1};
  int sI1x[MAX] = {4,9,0,2,1,3,7,8,5,6};
  int sI2x[MAX] = {4,9,0,2,1,3,7,8,5,6};
  int sI3x[MAX] = {8,3,2,5,6,9,7,4,0,1};

  int zI1x[MAX] = {8,5,6,7,1,2,9,0,3,4};

  int sS1x[MAX] = {1,3,8,5,9,4,7,6,0,2};

  QLA_Int *nI1p[MAX], *zI1p[MAX];
  QLA_Int *sI1p[MAX], *sI2p[MAX], *sI3p[MAX];
  QLA_Real *sR1p[MAX], *sR2p[MAX], *sR3p[MAX];
  QLA_Complex *sC1p[MAX], *sC2p[MAX], *sC3p[MAX];
  QLA_RandomState *sS1p[MAX];
  
  QLA_Real destR[MAX],chkR[MAX];
  QLA_Complex destC[MAX],chkC[MAX];
  QLA_D_Complex chkCD[MAX];
  QLA_Q_Complex chkCQ[MAX];
  QLA_Int destI[MAX],chkI[MAX];

  int i;
  QLA_Real destr,chkr;
  QLA_D_Real chkrD;
  QLA_Complex destc,chkc;
  QLA_D_Complex chkcD;
  QLA_Q_Real destrQ,chkrQ;
  QLA_Q_Complex destcQ,chkcQ;

  char name[64];

  /* Create pointer lists */

  for(i = 0; i < MAX; i++){
    sR1p[i] = &sR1[sR2x[i]];
    sR2p[i] = &sR2[sR3x[i]];
    sR3p[i] = &sR3[sR1x[i]];

    sC1p[i] = &sC1[sC1x[i]];
    sC2p[i] = &sC2[sC2x[i]];
    sC3p[i] = &sC3[sC2x[i]];

    sI1p[i] = &sI1[sI1x[i]];
    sI2p[i] = &sI2[sI2x[i]];
    sI3p[i] = &sI3[sI3x[i]];

    nI1p[i] = &nI1[sR3x[i]];
    zI1p[i] = &zI1[sR2x[i]];

    sS1p[i] = &sS1[sS1x[i]];
  }

  /* Create complex variables with known real and imaginary parts */

  for(i = 0; i < MAX; i++){
    QLA_c_eq_r_plus_ir(sC1[i],sC1re[i],sC1im[i]);
    QLA_c_eq_r_plus_ir(sC2[i],sC2re[i],sC2im[i]);
    QLA_c_eq_r_plus_ir(sC3[i],sC3re[i],sC3im[i]);
  }
  QLA_c_eq_r_plus_ir(sC4,sC4re,sC4im);

  /* Independent check of vector copy */

  strcpy(name,"QLA_R_veq_R");
  QLA_R_veq_R(destR,sR1,MAX);
  for(i = 0; i < MAX; i++){QLA_R_eq_R(&chkR[i],&sR1[i]);}
  checkeqidxRR(chkR,destR,name);

  strcpy(name,"QLA_C_veq_C");
  QLA_C_veq_C(destC,sC1,MAX);
  for(i = 0; i < MAX; i++){QLA_C_eq_C(&chkC[i],&sC1[i]);}
  checkeqidxCC(chkC,destC,name);

#if ( QLA_Precision != ''Q' )  /* Q precision is limited to assignments */

  /* Unary functions of real and complex */

unary(R,eq_cos,R)
unary(R,eq_sin,R)
unary(R,eq_tan,R)
unary(R,eq_acos,R)
unary(R,eq_asin,R)
unary(R,eq_atan,R)
unary(R,eq_sqrt,R)
unary(R,eq_fabs,R)
unary(R,eq_exp,R)
unary(R,eq_log,R)
unary(R,eq_sign,R)
unary(C,eq_cexpi,R)
unary(R,eq_norm,C)
unary(R,eq_arg,C)
unary(C,eq_cexp,C)
unary(C,eq_csqrt,C)
unary(C,eq_clog,C)
unary(R,eq_cosh,R)
unary(R,eq_sinh,R)
unary(R,eq_tanh,R)
unary(R,eq_log10,R)
unary(R,eq_ceil,R)
unary(R,eq_floor,R)

  /* Simple Binary functions */

binary(R,eq,R,mod,R,sR1,sR3)
binary(R,eq,R,max,R,sR1,sR3)
binary(R,eq,R,min,R,sR1,sR3)
binary(R,eq,R,pow,R,sR1,sR3)
binary(R,eq,R,atan2,R,sR1,sR3)
binary(R,eq,R,ldexp,I,sR1,sI3);

#endif /* QLA_Precision != Q */

  /* Assignments */

unary(R,eq,R)
unary(C,eq,C)
unary(R,peq,R)
unary(C,peq,C)
unary(R,eqm,R)
unary(C,eqm,C)
unary(R,meq,R)
unary(C,meq,C)

#if ( QLA_Precision != 'Q' )  /* Q precision is limited to assignments */


  /* Complex conjugate */

unarya(C,eq,C)
unarya(C,peq,C)
unarya(C,eqm,C)
unarya(C,meq,C)

unary(C,eq_conj,C)
unary(C,peq_conj,C)
unary(C,eqm_conj,C)
unary(C,meq_conj,C)

  /* Local squared norm */

unary(R,eq_norm2,C)

  /* Type conversion */

unary(C,eq,R)
binary(C,eq,R,plus_i,R,sR1,sR3)
unary(R,eq_re,C)
unary(R,eq_im,C)
unary(R,eq,I)
unary(I,eq_trunc,R)
unary(I,eq_round,R)

  /* Multiplication by real or complex constant */

binaryconst(R,eq_r_times,R,R)
binaryconst(C,eq_r_times,R,C)
binaryconst(R,peq_r_times,R,R)
binaryconst(C,peq_r_times,R,C)
binaryconst(R,eqm_r_times,R,R)
binaryconst(C,eqm_r_times,R,C)
binaryconst(R,meq_r_times,R,R)
binaryconst(C,meq_r_times,R,C)
binaryconst(C,eq_c_times,C,C)
binaryconst(C,peq_c_times,C,C)
binaryconst(C,eqm_c_times,C,C)
binaryconst(C,meq_c_times,C,C)
binaryconst(C,meq_r_times,R,C)
unarytimesi(C,eq_i,C)
unarytimesi(C,peq_i,C)
unarytimesi(C,eqm_i,C)
unarytimesi(C,meq_i,C)

  /* Division */

binary(R,eq,R,divide,R,sR1,sR2)
binary(C,eq,C,divide,C,sC1,sC2)

  /* Addition or subtraction */

binary(R,eq,R,plus,R,sR1,sR2)
binary(R,eq,R,minus,R,sR1,sR2)
binary(C,eq,C,plus,C,sC1,sC2)
binary(C,eq,C,minus,C,sC1,sC2)
binary(R,eq,R,times,R,sR1,sR2)
binary(C,eq,C,times,C,sC1,sC2)

  /* Multiplication */

binary(R,peq,R,times,R,sR1,sR2)
binary(C,peq,C,times,C,sC1,sC2)
binary(R,eqm,R,times,R,sR1,sR2)
binary(C,eqm,C,times,C,sC1,sC2)
binary(R,meq,R,times,R,sR1,sR2)
binary(C,meq,C,times,C,sC1,sC2)

  /* Local inner product - complex */

binary(C,eq,C,dot,C,sC1,sC2)
binary(R,eq_re,C,dot,C,sC1,sC2)

  /* Ternary operations */

ternaryconst(R,eq_r_times,R,R,plus,R)
ternaryconst(R,eq_r_times,R,R,minus,R)
ternaryconst(C,eq_r_times,R,C,plus,C)
ternaryconst(C,eq_r_times,R,C,minus,C)
ternaryconst(C,eq_c_times,C,C,plus,C)
ternaryconst(C,eq_c_times,C,C,minus,C)

  /* Boolean comparisons */

binary(I,eq,R,eq,R,sR1,sR2)
binary(I,eq,R,ne,R,sR1,sR2)
binary(I,eq,R,gt,R,sR1,sR2)
binary(I,eq,R,lt,R,sR1,sR2)
binary(I,eq,R,ge,R,sR1,sR2)
binary(I,eq,R,le,R,sR1,sR2)

  /* Copymask */

binary(R,eq,R,mask,I,sR1,zI1)
binary(C,eq,C,mask,I,sC1,zI1)

  /* Reductions */

unaryglobalnorm2real(r,eq_norm2,R,,,)
unaryglobalnorm2real(r,eq_norm2,I,,,)
unaryglobalnorm2(r,eq_norm2,C,,,)
binaryglobaldotreal(r,eq,R,dot,R,,,)
binaryglobaldotreal(r,eq,I,dot,I,,,)
binaryglobaldot(c,eq,C,dot,C,,,)
binaryglobaldotreal(r,eq_re,C,dot,C,,,)
unarysumreal(r,eq_sum,R,,,)
unarysumreal(r,eq_sum,I,,,)
unarysum(c,eq_sum,C,,,)

#endif /* QLA_Precision != Q */

  /* Fills */

unaryconstzero(R,eq_zero)
unaryconstzero(C,eq_zero)

#if ( QLA_Precision != 'Q' )  /* Q precision is limited to assignments */

unaryconst(R,eq_r)
unaryconst(C,eq_c)

  /* Random numbers */

unaryrand(R,eq_random)

#endif /* QLA_Precision != Q */

unaryrand(R,eq_gaussian)
unaryrand(C,eq_gaussian)

  return 0;
}


