#include <stdio.h>
#include "configiniread.h"

#define TEST_TAG_CONFIG "confInt"
#define TEST_BOOL_TAG   "confbool"
#define TEST_BOOL2_TAG  "conftrue"
#define TEST_BOOL3_TAG  "conftue"
#define TEST_OTHER_TAG  "dupa1"

void demoConfig(){
  char val[10];
  bool val_bool;
  int32_t val_int = 0;
  getConfigFromFile(TEST_TAG_CONFIG, val);
  printf("return val str = %s\n", val);
  getIntConfigFromFile(TEST_TAG_CONFIG, &val_int);
  printf("return val int = %d\n", val_int);
  getIntConfigFromFile(TEST_OTHER_TAG, &val_int);
  getBoolConfigFromFile(TEST_BOOL_TAG, &val_bool);
  printf("return val bool 1 = %d\n", val_bool);
  getBoolConfigFromFile(TEST_BOOL2_TAG, &val_bool);
  printf("return val bool 2 = %d\n", val_bool);
  getBoolConfigFromFile(TEST_BOOL3_TAG, &val_bool);
  //printf("return val = %d", val);
}

void app_main(void)
{
  printf("Hello world!\n");
  demoConfig();
}

