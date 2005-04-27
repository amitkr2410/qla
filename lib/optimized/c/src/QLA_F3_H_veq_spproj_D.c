/**************** QLA_F3_H_veq_spproj_D.c ********************/

#include <qla_types.h>
#include <qla_random.h>
#include <qla_cmath.h>
#include <math.h>

void
QLA_F3_H_veq_spproj_D ( QLA_F3_HalfFermion *__restrict__ r , QLA_F3_DiracFermion  *a , int mu, int sign , int n )
{
  int i;
  if(sign==1) {
    switch(mu) {
    case 0:
      for(i=0; i<n; i++) {
	int i_c;
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_ic( QLA_F3_elem_H(r[i],i_c,0), QLA_F3_elem_D(a[i],i_c,0), QLA_F3_elem_D(a[i],i_c,3) );
	}
	for(i_c=0; i_c<3; i_c++) {
	  QLA_c_eq_c_plus_ic( QLA_F3_elem_H(r[i],i_c,1), QLA_F3_elem_D(a[i],i_c,1), QLA_F3_elem_D(a[i],i_c,2) );
	}
      }
      break;
    case 1:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_plus_c(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,3));
	    QLA_c_eq_c_minus_c(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,2));
	  }
      }
      break;
    case 2:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_plus_ic(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,2));
	    QLA_c_eq_c_minus_ic(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,3));
	  }
      }
      break;
    case 3:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_plus_c(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,2));
	    QLA_c_eq_c_plus_c(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,3));
	  }
      }
      break;
    }
  }
  else{
    switch(mu){
    case 0:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_minus_ic(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,3));
	    QLA_c_eq_c_minus_ic(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,2));
	  }
      }
      break;
    case 1:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_minus_c(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,3));
	    QLA_c_eq_c_plus_c(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,2));
	  }
      }
      break;
    case 2:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_minus_ic(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,2));
	    QLA_c_eq_c_plus_ic(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,3));
	  }
      }
      break;
    case 3:
      for(i=0;i<n;i++) {
	int i_c;
	for(i_c=0;i_c<3;i_c++)
	  {
	    QLA_c_eq_c_minus_c(QLA_F3_elem_H(r[i],i_c,0),              QLA_F3_elem_D(a[i],i_c,0),QLA_F3_elem_D(a[i],i_c,2));
	    QLA_c_eq_c_minus_c(QLA_F3_elem_H(r[i],i_c,1),              QLA_F3_elem_D(a[i],i_c,1),QLA_F3_elem_D(a[i],i_c,3));
	  }
      }
      break;
    }
  }
}
