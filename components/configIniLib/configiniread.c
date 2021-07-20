#include "configiniread.h"

# get ini configuration
# file.ini, config name, * char

__int32_t convertCharToInt(char value){
    return c - '0';
}

Config_ini_error_t getConfigFromFile(char * file, char * configTag, char * value){

}

Config_ini_error_t getIntConfigFromFile(char * file, char * configTag, __int32_t * value){
    char value_buff[30];
    Config_ini_error_t error = getConfigFromFile(file, configTag, value_buff)
    if(error){ 
        configIniError(error); 
        return error;       
    }
    int buff_iter = 0
    *value = 0;
    while(value_buff[buff_iter] != '\0'){
        
        *value = *value + convertCharToInt(value_buff);
    }
}

Config_ini_error_t getBoolConfigFromFile(char * file, char * configTag, bool_t * value){

}

Config_ini_error_t getListConfigFromFile(char * file, char * configTag, __int32_t * value){

}

void getAllConfigurations(char * configString){
  int i = 0;
  char line_buffer[50];
  int buff_iter = 0;
  while (configString[i] - '\0'){
    if (configString[i] == '\n'){
      line_buffer[buff_iter] = '\0';
      printf("Buffer line: %s\n", line_buffer);
      printLineConfig(line_buffer);
      buff_iter = 0;
      i++;
    }
    line_buffer[buff_iter] = configString[i];
    i++;
  }
}