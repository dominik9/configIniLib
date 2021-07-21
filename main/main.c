#include <stdio.h>
#include "configiniread.h"


void app_main(void)
{
  printf("Hello world!\n");
  char val[6];
  //getIntConfigFromFile("file","config", &val);
  getConfigFromFile("config_ini","confInt", val);
  printf("eloelo = %s\n", val);
}

