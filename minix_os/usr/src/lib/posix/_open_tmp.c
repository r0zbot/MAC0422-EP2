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
  int mode = O_CREAT;
  if(strcmp(smode, "r") == 0){
    mode |= O_RDONLY;
  }
  else if(strcmp(smode, "r+") == 0){
    mode |= O_RDWR;
  }
  else if(strcmp(smode, "w") == 0){
    mode |= O_WRONLY | O_TRUNC;
  }
  else if(strcmp(smode, "w+") == 0){
    mode |= O_RDWR | O_TRUNC;
  }
  else if(strcmp(smode, "a") == 0){
    mode |= O_WRONLY | O_APPEND;
  }
  else if(strcmp(smode, "a+") == 0){
    mode |= O_RDWR | O_APPEND;
  }
  else{
    printf("Invalid mode!\n");
    return -1;
  }
  m.m3_i2 = mode;
  _loadname(name, &m);
  return(_syscall(FS, OPENTMP, &m));
}
/* ######################################################## */
