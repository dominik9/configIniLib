#ifndef _CONFIG_INI_READ_H
#define _CONFIG_INI_READ_H

#include <stdio.h>


typedef enum Config_ini_error_t{
    CONFIG_OK               =   0,
    CONFIG_ERROR_FILE_INI   =   1,
    CONFIG_ERROR_CONFIG_TAG =   2,
};



Config_ini_error_t getConfigFromFile(char * file, char * configTag, char * value);

Config_ini_error_t getIntConfigFromFile(char * file, char * configTag, __int32_t * value);

Config_ini_error_t getBoolConfigFromFile(char * file, char * configTag, bool_t * value);

Config_ini_error_t getListConfigFromFile(char * file, char * configTag, __int32_t * value);

void configIniErrorDisplay(error); 

#endif