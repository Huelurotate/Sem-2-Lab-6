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
			input_queues(tail1, tail2, tail3, &length);
			break;
		case 2:
			if (is_empty(*tail1) || is_empty(*tail2) || is_empty(*tail3))
				puts("\nQueue(s) is empty.");
			else
				input_queues(*tail1, *tail2, *tail3, *tail4);
			break;
		case 3:
			/*if (!is_empty(*tail))
				alt_input_queue(tail);
			else
				puts("\nQueue is empty.");*/
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

void input_queues(Node** tail1, Node** tail2, Node** tail3, int* length)
{
	/*if (!is_empty(*tail1) || !is_empty(*tail2) || !is_empty(*tail3))
		free_all_queues(tail1, tail2, tail3, NULL);*/

	input_queue_values(tail1, tail2, tail3, length);
}

void input_queue_values(Node** tail1, Node** tail2, Node** tail3, int* length)
{
	char* temp = NULL;
	int continue_choice = 1;
	while (continue_choice)
	{
		temp = NULL;
		printf("\nEnter name number %d(Enter - Stop):\n", *length + 1);
		str_input(&temp);
		enqueue(tail1, temp);

		temp = NULL;
		printf("\nEnter middle name number %d(Enter - stop):\n", *length + 1);
		str_input(&temp);
		enqueue(tail2, temp);

		temp = NULL;
		printf("\nEnter surname number %d(Enter - stop):\n", *length + 1);
		str_input(&temp);
		enqueue(tail3, temp);

		continue_request(&continue_choice);

		(*length)++;
	}
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
	Node* temp4 = (is_empty(tail4)) ? NULL : tail4->next;

	printf("\nNAME:            MIDDLE NAME:     SURNAME:         ");
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

void free_all_queues(Node** tail1, Node** tail2, Node** tail3, Node** tail4)
{
	if (tail1 != NULL)
		free_queue(tail1);
	if (tail2 != NULL)
		free_queue(tail2);
	if (tail3 != NULL)
		free_queue(tail3);
	if (tail4 != NULL)
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