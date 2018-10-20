#include "syslib.h"

/*===========================================================================*
 *                                sys_nice			     	     *
 *===========================================================================*/
PUBLIC int sys_nice(int proc, int prio)
{
  message m;

  m.m1_i1 = proc;
  m.m1_i2 = prio;
  return(_taskcall(SYSTASK, SYS_NICE, &m));
}

/* ######################################################## */
/* ###########----------Codigo Adicionado---------######### */
PUBLIC int sys_priority(int proc, int prio)
{
  message m;

  m.m1_i1 = proc;
  m.m1_i2 = prio;
  return(_taskcall(SYSTASK, SYS_PRIORITY, &m));
}
/* ######################################################## */