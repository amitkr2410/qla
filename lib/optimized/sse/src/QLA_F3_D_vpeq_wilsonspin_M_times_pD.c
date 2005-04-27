/**************** QLA_F3_D_vpeq_wilsonspin_M_times_pD.c ********************/

#include <qla_types.h>
#include <qla_random.h>
#include <qla_cmath.h>
#include <math.h>
#include "inline_sse.h"

static QLA_F3_HalfFermion t1;
static QLA_F3_HalfFermion t2;

void QLA_F3_D_vpeq_wilsonspin_M_times_pD ( QLA_F3_DiracFermion *__restrict__ r , QLA_F3_ColorMatrix  *a , QLA_F3_DiracFermion  **b , int mu, int sign , int n )
{
  if(sign==1) {
    int i;
    switch(mu){
    case 0:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_ic(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,3));
	  QLA_c_eq_c_plus_ic(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,2));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0; i_c<3; i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_ic(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_ic(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,0));
        }
      }
      break;
    case 1:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_c(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,3));
	  QLA_c_eq_c_minus_c(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,2));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0; i_c<3; i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_c(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,0));
        }
      }
      break;
    case 2:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_ic(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,2));
	  QLA_c_eq_c_minus_ic(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,3));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0;i_c<3;i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_ic(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_ic(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,1));
        }
      }
      break;
    case 3:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_c(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,2));
	  QLA_c_eq_c_plus_c(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,3));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0;i_c<3;i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,1));
        }
      }
      break;
    }
  } else{
    int i;
    switch(mu) {
    case 0:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_minus_ic(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,3));
	  QLA_c_eq_c_minus_ic(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,2));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0; i_c<3; i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_ic(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_ic(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,0));
        }
      }
      break;
    case 1:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_minus_c(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,3));
	  QLA_c_eq_c_plus_c(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,2));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0;i_c<3;i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_c(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,0));
        }
      }
      break;
    case 2:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_minus_ic(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,2));
	  QLA_c_eq_c_plus_ic(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,3));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0;i_c<3;i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_peq_ic(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_meq_ic(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,1));
        }
      }
      break;
    case 3:
      for(i=0; i<n; i++) {
        int i_c;
        QLA_F3_DiracFermion *ri = &r[i];
	QLA_F3_ColorMatrix *ai = &a[i];
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_minus_c(QLA_F3_elem_H(t1,i_c,0),QLA_F3_elem_D(*b[i],i_c,0),QLA_F3_elem_D(*b[i],i_c,2));
	  QLA_c_eq_c_minus_c(QLA_F3_elem_H(t1,i_c,1),QLA_F3_elem_D(*b[i],i_c,1),QLA_F3_elem_D(*b[i],i_c,3));
	}
        QLA_F3_H_eq_M_times_H(&t2, ai, &t1);
        for(i_c=0;i_c<3;i_c++) {
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,0),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_peq_c(QLA_F3_elem_D(*ri,i_c,1),QLA_F3_elem_H(t2,i_c,1));
          QLA_c_meq_c(QLA_F3_elem_D(*ri,i_c,2),QLA_F3_elem_H(t2,i_c,0));
          QLA_c_meq_c(QLA_F3_elem_D(*ri,i_c,3),QLA_F3_elem_H(t2,i_c,1));
        }
      }
      break;
    }
  }
}
