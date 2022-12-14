# STACKS, QUEUES - LIFO, FIFO

![img](https://data-flair.training/blogs/wp-content/uploads/sites/2/2019/06/Stacks-and-queues-in-C.jpg)

## Description
A **stack** in C is nothing but a linear data structure that follows the LIFO rule (Last In First Out). In a stack, both insertion and deletion take place from just one end, that is, from the top.
In contrast to a **stack**, a queue in C is nothing but a linear data structure that follows the FIFO rule (First In First Out). Insertion is done from the back (the rear end) and deletion is done from the front.
**Monty 0.98** is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic *.c monty`
- Use `malloc` and `free` only.

## More Info
### Data Structures
```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```
```c
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

-------------------------

## Files
All of the following files are scripts and programs written in C:

| Filename | Description |
| -------- | ----------- |
| `monty.c` | main function, declaration of extern global variable and call interpreter of Monty language |
| `interpret.c` | function intp_monty & cmp_op to start function associated |
| `opt_func1.c` | opcode function :  `PUSH`  `PALL`  `PINT`  `POP`  `SWAP` |
| `opt_func2.c` | opcode function :  `NOP`  `ADD` |
| `str-lkdl.c` | function associated to test string and manipulate double linked list |

## Authors

**Pauline Parmentier**
GitHub: [@paulinepar](https://github.com/paulinepar)

**Marianne Arrué**
GitHub: [@MarianneHolbie](https://github.com/MarianneHolbie)


