# Concept: 0x19. C - Stacks, Queues - LIFO, FIFO
## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files. (Read a monty file, intepret the code and execute if it is a valid instruction)

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

### compilation
The code is compiled this way:
> $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

## The monty program
Once compiled, we can now use our `monty` program to run the instructions in a monty file:

- Usage: `monty file`

where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message` USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status EXIT_FAILURE
where `<file>` is the name of the file
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`,
where `line_number` is the line number where the instruction appears.
Line numbers always start at 1
<ul> 
<li> The monty program runs the bytecodes line by line and stop if either:
<ul> <li> it executed properly every line of the file
<li> it finds an error in the file
<li> an error occured </ul></li>
</ul>

- If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
- You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (`realloc`, `calloc`, …)