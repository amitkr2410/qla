/**************** QLA_F3_D_veq_zero.c ********************/

#include <qla_types.h>
#include <qla_random.h>
#include <qla_cmath.h>
#include <math.h>

void QLA_F3_D_veq_zero ( QLA_F3_DiracFermion *__restrict__ r , int n )
{
  int i;
  for(i=0;i<n;i++)
    {
      int i_s;
      for(i_s=0;i_s<4;i_s++)
	{
	  int i_c;
	  for(i_c=0;i_c<3;i_c++)
	    {
              QLA_c_eq_r(QLA_F3_elem_D(r[i],i_c,i_s),0.)
            }
        }
    }
}
