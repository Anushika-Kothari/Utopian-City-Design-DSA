#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// Flog file pointer is used to write the log files
FILE *flog;

// Below mentioned are error status/status codes
#define SUCCESS                     1
#define FAILURE                     -1
#define FILE_OPEN_ERROR             1001
#define MEMORY_ALLOCATION_ERROR     1002
#define FILE_DELETE_ERROR           1003
#define COUNT_EXCEED_ERROR          1004
#define RESULT_NOT_FOUND            1005
#define FILE_EMPTY_ERROR            1006

#endif // SETTINGS_H_INCLUDED
