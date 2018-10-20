/* ######################################################################### */
/* ##################----------Codigo Adicionado---------################### */
/* The kernel call implemented in this file:
 *   m_type:	SYS_PRIORITY
 *
 * The parameters for this kernel call are:
 *    m1_i1:	PR_ENDPT   	process number to change priority
 *    m1_i2:	PR_PRIORITY	the new priority
 */

#include "../system.h"
#include <minix/type.h>
#include <sys/resource.h>

#if USE_PRIORITY

/*===========================================================================*
 *				  do_priority				     *
 *===========================================================================*/
PUBLIC int do_priority(message *m_ptr)
{
/* Change process priority or stop the process. */
  int proc_nr, pri, new_q ;
  register struct proc *rp;

  /* Extract the message parameters and do sanity checking. */
  if(!isokendpt(m_ptr->PR_ENDPT, &proc_nr)) return EINVAL;
  if (iskerneln(proc_nr)) return(EPERM);
  pri = m_ptr->PR_PRIORITY;
  rp = proc_addr(proc_nr);

  lock_dequeue(rp);
  rp->p_priority = pri;
  rp->p_max_priority = pri;
  if (! rp->p_rts_flags) lock_enqueue(rp);
  return(OK);
}
#endif /* USE_PRIORITY */

/* ######################################################################### */