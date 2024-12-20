#include <stdio.h>
// #include "ta_lib.h"
#include "110550171_lab10-2_lib.h"

void example_add(_CUSTOM_PARAMS_T params) {
    printf("Your answer is %d\n", params.arg1 + params.arg2);
}

void example_mul(_CUSTOM_PARAMS_T params) {
    printf("Sorry, I don't want to do anything\n");
}

void add(_CUSTOM_PARAMS_T params) {
    printf("HaHa my answer is %d\n", params.arg1+params.arg2);
}
void sub(_CUSTOM_PARAMS_T params) {
    printf("HaHa my answer is %d\n", params.arg1-params.arg2);
}
void mul(_CUSTOM_PARAMS_T params) {
    printf("HaHa my answer is %d\n", params.arg1*params.arg2);
}
void div(_CUSTOM_PARAMS_T params) {
    printf("HaHa my answer is %d\n", params.arg1/params.arg2);
}

int main(int argc, char **argv) {
    _CUSTOM_PARAMS_T m_params;
    m_params.arg1 = 1; 
    m_params.arg2 = 2;
/*
    ta_register_callback("add", example_add);
    ta_register_callback("mul", example_mul);
    
    // You can register more function by yourself, enjoy it
    // ta_register_callback("ohmygod", balabala_my_cb_func);

    printf("===== TA's example =====\n");

    // Add example
    printf("Action 1: ");
    ta_run("add", m_params);

    // Mul example
    printf("Action 2: ");
    m_params.arg1 = 2;
    m_params.arg2 = 3;
    ta_run("mul", m_params);

*/


    student_register_callback("add", add);
    student_register_callback("mul", mul);
    student_register_callback("sub", sub);
    student_register_callback("div", div);

    printf("===== Student example =====\n");
    printf("Action 1: ");
    student_run("add", m_params);

    printf("Action 2: ");
    m_params.arg1 = 2;
    m_params.arg2 = 3;
    student_run("mul", m_params);

    printf("Action 3: ");
    m_params.arg1 = 2;
    m_params.arg2 = 3;
    student_run("sub", m_params);

    printf("Action 4: ");
    m_params.arg1 = 2;
    m_params.arg2 = 3;
    student_run("div", m_params);

    return 0;
}
