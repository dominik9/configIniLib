#include "configiniread.h"

//get ini configuration
//file.ini, config name, * char

int32_t convertCharToInt(char value){
    return value - '0';
}

void getConfigTag(char * line_buffer, char * tag, char * val){
  //Rozdzielic tag od wartości
  //zwrucic
}

//file = np.: text_ini
Config_ini_error_t getConfigFromFile(char * file, char * configTag, char * value){
  extern const unsigned char configString[] asm(CONFIG_FILE_START);
  printf("%s\n", configString);
  int i = 0;
  char line_buffer[50] = "\0";
  char lineTag[40] = "\0";
  int buff_iter = 0;
  while (configString[i] - '\0'){
    line_buffer[buff_iter] = configString[i];
    buff_iter++;
    if (configString[i] == '\n'){
      line_buffer[buff_iter-1] = '\0';
      printf("Buffer line: %s\n", line_buffer);
      getConfigTag(line_buffer, lineTag, value);
      if (!strcmp(configTag, lineTag)){ //Czy to jest ten config
        //wyciągnąć wartość zapisać i skończyć funkcję sukcesem
      }    
      buff_iter = 0;
    }
    i++;
  }
  //szukanie linijki podobnej do configTag
  //zwrot jeżeli jest jesli nie ma to error
  strcpy(value, "2");
  return CONFIG_OK;
}

Config_ini_error_t getIntConfigFromFile(char * file, char * configTag, int32_t * value){
    char value_buff[30];
    Config_ini_error_t error = getConfigFromFile(file, configTag, value_buff);
    if(error){ 
        configIniErrorDisplay(error); 
        return error;       
    }
    int buff_iter = 0;
    //printf("*value przed zmianami = %d\n", *value);
    *value = 0;
    //printf("value_buff = %s\n",value_buff);
    while(value_buff[buff_iter] != '\0'){
      *value = (*value * 10) + convertCharToInt(value_buff[buff_iter]);
      //printf("*value petla = %d, iter = %d\n", *value, buff_iter);
      buff_iter++;
    }
    return CONFIG_OK;
}

Config_ini_error_t getBoolConfigFromFile(char * file, char * configTag, bool * value){
  return CONFIG_OK;
}

Config_ini_error_t getListConfigFromFile(char * file, char * configTag, int32_t * value){
  return CONFIG_OK;
}

void configIniErrorDisplay(Config_ini_error_t error){
    printf("error %d", error);
}
// void getAllConfigurations(char * configString){
//   int i = 0;
//   char line_buffer[50];
//   int buff_iter = 0;
//   while (configString[i] - '\0'){
//     if (configString[i] == '\n'){
//       line_buffer[buff_iter] = '\0';
//       printf("Buffer line: %s\n", line_buffer);
//       printLineConfig(line_buffer);
//       buff_iter = 0;
//       i++;
//     }
//     line_buffer[buff_iter] = configString[i];
//     i++;
//   }
// }