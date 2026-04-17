#pragma once

#include "queue.h"

#define MAX_QUEUES_LENGTH 100
#define CAPACITY 10

// MENU
void menu(Node** tail1, Node** tail2, Node** tail3, Node** tail4);
void print_menu();
void menu_option_choice(int* choice);

// INPUT
void input_queues(Node** tail1, Node** tail2, Node** tail3, int* length);
void input_queue_values(Node** tail1, Node** tail2, Node** tail3, int* length);
void continue_request(int* choice);

void str_input(char** str);
void int_input(int* var);

// OUTPUT
void output_queues(Node* tail1, Node* tail2, Node* tail3, Node* tail4);

// FREEING AND CHECKS
void free_all_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4);
void check_char_alloc(char* memory_block);