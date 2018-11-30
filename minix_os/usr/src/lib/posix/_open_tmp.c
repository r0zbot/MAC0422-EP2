/* ######################################################## */
/* ###########----------Codigo Adicionado---------######### */
#include <lib.h>
#define open_tmp _open_tmp
#include <fcntl.h>
#include <string.h>

PUBLIC int open_tmp(name, smode)
_CONST char *name;
_CONST char *smode;
{
  
  message m;
  int mode = 0;
  if(strcmp(smode, "r") == 0){
    mode = 1;
  }
  else if(strcmp(smode, "r+") == 0){
    mode = 2;
  }
  else if(strcmp(smode, "w") == 0){
    mode = 3;
  }
  else if(strcmp(smode, "w+") == 0){
    mode = 4;
  }
  else if(strcmp(smode, "a") == 0){
    mode = 5;
  }
  else if(strcmp(smode, "a+") == 0){
    mode = 6;
  }
  else{
    printf("Invalid mode!\n");
    return -1;
  }
  m.m3_i2 = smode;
  _loadname(name, &m);
  return(_syscall(FS, CREAT, &m));
}
/* ######################################################## */
