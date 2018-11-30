/* ######################################################## */
/* ###########----------Codigo Adicionado---------######### */
#include <lib.h>
#define open_tmp _open_tmp
#include <fcntl.h>

PUBLIC int open_tmp(name, mode)
_CONST char *name;
_CONST char *mode;
{
  printf("Funcionei legal! %s %s \n", name, mode);
  /*message m;

  m.m3_i2 = mode;
  _loadname(name, &m);
  return(_syscall(FS, CREAT, &m));*/
}
/* ######################################################## */
