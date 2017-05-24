#pragma once
#include <stdio.h>
#include <stdbool.h>
char* ensure_capacity(char *buf, int *sz, int pos);
char* fetchline(FILE *f);
void print_error(void);
void choose_commands(char *line);
bool wait_for_key_press(void);
void moving_forward(void);
int computeAverageLight(void);
void perform_file(FILE *file);
void perform_and_log_file(FILE *script_file, FILE *log_file);

