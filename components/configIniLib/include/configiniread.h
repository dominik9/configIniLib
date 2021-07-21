#ifndef _CONFIG_INI_READ_H
#define _CONFIG_INI_READ_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "string.h"

#define FILE_NAME_SIZE      50
//#define CONFIG_FILE_START "_binary_%s_start"
#define CONFIG_FILE_START "_binary_config_ini_start"

typedef enum {
    CONFIG_OK               =   0,
    CONFIG_ERROR_FILE_INI   =   1,
    CONFIG_ERROR_CONFIG_TAG =   2,
}Config_ini_error_t;



Config_ini_error_t getConfigFromFile(char * file, char * configTag, char * value);

Config_ini_error_t getIntConfigFromFile(char * file, char * configTag, int32_t * value);

Config_ini_error_t getBoolConfigFromFile(char * file, char * configTag, bool * value);

Config_ini_error_t getListConfigFromFile(char * file, char * configTag, int32_t * value);

void configIniErrorDisplay(Config_ini_error_t error);

#endif