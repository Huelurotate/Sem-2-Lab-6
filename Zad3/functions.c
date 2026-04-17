#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "queue.h"

void menu(Node** tail1, Node** tail2, Node** tail3, Node** tail4)
{
	int menu_choice, is_running = 1;
	int length = 0;

	while (is_running)
	{
		print_menu();
		menu_option_choice(&menu_choice);
		switch (menu_choice)
		{
		case 1:
			input_queues(tail1, tail2, tail3, tail4, &length);
			break;
		case 2:
			if (is_empty(*tail1) || is_empty(*tail2) || is_empty(*tail3))
				puts("\nQueue(s) is empty.");
			else
				output_queues(*tail1, *tail2, *tail3, *tail4);
			break;
		case 3:
			if (is_empty(*tail1) || is_empty(*tail2) || is_empty(*tail3))
				puts("\nQueue(s) is empty.");
			else if (!is_empty(*tail4))
				puts("\nYou have already filled the 4th queue.");
			else
				input_4th_queue(tail4, length);
			break;
		case 4:
			is_running = 0;
			break;
		}
	}
}

void print_menu()
{
	puts("\n      MENU\n"
		"Choose an option:\n"
		"1 - Input Queues\n"
		"2 - Print Queues\n"
		"3 - Input 4th Queue\n"
		"4 - Exit Program");
}

void menu_option_choice(int* choice)
{
	while (1)
	{
		int_input(choice);
		if (*choice < 1 || *choice > 4)
			puts("\nChoose an option(1-4).");
		else
			break;
	}
}

void input_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4, int* length)
{
	if (!is_empty(*tail1) || !is_empty(*tail2) || !is_empty(*tail3) || !is_empty(*tail4))
	{
		free_all_queues(tail1, tail2, tail3, tail4);
		*length = 0;
	}

	input_queue_values(tail1, tail2, tail3, length);
}

void input_queue_values(Node** tail1, Node** tail2, Node** tail3, int* length)
{
	char* temp = NULL;
	int continue_choice = 1;
	while (continue_choice)
	{
		printf("\nEnter name number %d:\n", *length + 1);
		input_single_queue_value(&temp, tail1);

		printf("\nEnter middle name number %d:\n", *length + 1);
		input_single_queue_value(&temp, tail2);

		printf("\nEnter surname number %d:\n", *length + 1);
		input_single_queue_value(&temp, tail3);

		continue_request(&continue_choice);

		(*length)++;
	}
}

void input_single_queue_value(char** temp_var, Node** tail)
{
	*temp_var = NULL;
	str_input(temp_var);
	enqueue(tail, *temp_var);
}

void continue_request(int* choice)
{
	puts("\nContinue(1 - Yes, 0 - No)?:");
	while (1)
	{
		int_input(choice);
		if (*choice != 1 && *choice != 0)
			puts("\nChoose 1 or 0.");
		else
			break;
	}
}

void str_input(char** str)
{
	int length = 0;
	char c;

	while ((c = getchar()) == '\n')
		puts("\nYou cannot enter an empty string.");

	ungetc(c, stdin);
	while ((c = getchar()) != '\n')
	{
		length++;
		*str = realloc(*str, (length + 1) * sizeof(char));
		check_char_alloc(*str);
		(*str)[length - 1] = c;
	}

	(*str)[length] = '\0';
}

void int_input(int* var)
{
	char buffer[100];
	char* endptr;
	long temp;

	while (1)
	{
		fgets(buffer, sizeof(buffer), stdin);

		buffer[strcspn(buffer, "\n")] = '\0';

		if (buffer[0] != '\0')
		{
			temp = strtol(buffer, &endptr, CAPACITY);

			if (*endptr == '\0')
			{
				*var = (int)temp;
				return;
			}
		}

		puts("\nInvalid Input. Please, enter a single integer.");
	}
}

void output_queues(Node* tail1, Node* tail2, Node* tail3, Node* tail4)
{
	Node* temp1 = tail1->next;
	Node* temp2 = tail2->next;
	Node* temp3 = tail3->next;
	Node* temp4 = (!is_empty(tail4)) ? tail4->next : NULL;

	printf("\n NAME:            MIDDLE NAME:     SURNAME:         ");
	if (!is_empty(tail4))
		printf("CITY:");
	puts("");

	do
	{
		printf("|%-16s|%-16s|%-16s|", temp1->data, temp2->data, temp3->data);
		if (!is_empty(tail4))
			printf("%-16s|", temp4->data);
		puts("");
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp3 = temp3->next;
		if(!is_empty(tail4)) temp4 = temp4->next;
	} while (temp1 != tail1->next);

	puts("");
}

void input_4th_queue(Node** tail, int length)
{
	char* temp = NULL;
	for(int i = 0; i < length; i++)
	{
		printf("\nEnter city number %d:\n", i + 1);
		input_single_queue_value(&temp, tail);
	}
}

void free_all_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4)
{
	free_queue(tail1);
	free_queue(tail2);
	free_queue(tail3);
	free_queue(tail4);
}

void check_char_alloc(char* memory_block)
{
	if (memory_block == NULL)
	{
		puts("Memory allocation error.");
		exit(1);
	}
}