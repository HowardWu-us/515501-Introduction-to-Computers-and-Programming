#include "110550171_lab10-2_lib.h"
#include <stdio.h>

#define MAX_CALLBACKS 100
typedef struct {
    char tag_name[100];
    void (*callback)(_CUSTOM_PARAMS_T params);
} CallbackEntry;

int callback_count = 0;
CallbackEntry callbacks[MAX_CALLBACKS];

void student_register_callback(char tag_name[], void (*FPTR)(_CUSTOM_PARAMS_T params)) {
    // if CallbackEntry still has space
    if (callback_count < MAX_CALLBACKS) {
        // copy tag_name to CallbackEntry
        // copy FPTR to CallbackEntry
        strcpy(callbacks[callback_count].tag_name, tag_name);
        callbacks[callback_count++].callback = FPTR;
        // What should you do else?
    }
}
void student_run(char tag_name[], _CUSTOM_PARAMS_T params) {
    // Find the callback function by tag_name
    for (int i=0;i<callback_count;++i) {
        if(strcmp(callbacks[i].tag_name, tag_name)==0) {
            callbacks[i].callback(params); // Call the callback function
            break;
        }
    }
}
