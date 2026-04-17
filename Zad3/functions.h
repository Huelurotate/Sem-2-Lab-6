#pragma once

#include "queue.h"

#define CAPACITY 10

// MENU
void menu(Node** tail1, Node** tail2, Node** tail3, Node** tail4);
void print_menu();
void menu_option_choice(int* choice);

// INPUT
void input_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4, int* length);
void input_queue_values(Node** tail1, Node** tail2, Node** tail3, int* length);
void input_single_queue_value(char** temp_var, Node** tail);
void continue_request(int* choice);

void str_input(char** str);
void int_input(int* var);

// OUTPUT
void output_queues(Node* tail1, Node* tail2, Node* tail3, Node* tail4);

// INPUT 4TH QUEUE
void input_4th_queue(Node** tail, int length);

// FREEING AND CHECKS
void free_all_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4);
void check_char_alloc(char* memory_block);