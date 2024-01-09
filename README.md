<h1><p align="center"> The Monty Program </h1></p></font>

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
## The monty program consept
Usage: `monty file`
where file is `the path` to the file containing Monty byte code
If the user does not give any file or more than one argument to the program, we got an error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.

If, for any reason, it’s not possible to open the file, we got the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`.
where `<file>` is the name of the file.

If the file contains an invalid instruction, we got the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
where is the `<line number>` where the instruction appears.
Line numbers always start at 1.

The monty program runs the bytecodes line by line and stop if either:
- it executed properly every line of the file.
- it finds an error in the file.
- An error occured.

If there is a malloc problem, we got the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.

## Opcodes
| opcodes |  Description                | Errors |
| :-------- |  :------------------------- |----------------------|
| `push <int>` |pushes an element to the stack. |If `<int>` is not an integer or if there is no argument given to push, we got the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`|
| `pall` |prints all the values on the stack|No Errors |
| `pint` | prints the value at the top of the stack |If the stack is empty, we got the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`|
| `pop` |removes the top element of the stack. |If the stack is empty, we got the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`swap` |swaps the top two elements of the stack.|If the stack contains less than two elements, we got the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`add` |adds the top two elements of the stack.|If the stack contains less than two elements,we got the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`nop` |doesn’t do anything.| No Errors|
|`sub` |subtracts the top element of the stack from the second top element of the stack.|If the stack contains less than two elements, we got the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`div` | divides the second top element of the stack by the top element of the stack.|If the stack contains less than two elements, we got the error message `L<line_number>: can't div, stack too short`, followed by a new line and if the top element of the stack is `0`, we got the error message `L<line_number>: division by zero` and exit with the status `EXIT_FAILURE`.|
|`mul` |multiplies the second top element of the stack with the top element of the stack.|If the stack contains less than two elements, we got the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`mod` | computes the rest of the division of the second top element of the stack by the top element of the stack.| If the stack contains less than two elements, we got the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`. If the top element of the stack is `0`, we got the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`pchar` | prints the char at the top of the stack, followed by a new line.|If the value is not in the ascii table we got the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`. If the stack is empty, we got the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`|
|`pstr` |prints the string starting at the top of the stack, followed by a new line.| No Errors |
|`rotl` | rotates the stack to the top.|rotl never fails|
|`rotr` |  rotates the stack to the bottom.|rotr never fails|

`<line_number>`  is the line number where the instruction appears.

## Compilation & Output
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
## Files
| Files |  Description                |
| :-------- |  :------------------------- |
| `monty.h` | it's the header file that contain the prototypes of all the functions and all the useful libraries .|
| `00-main.c` | contain the main function : The entry point of the code. |
| `01-file_operations.c` | contain the three functions that handeles the file and its contents (opcodes)  |
| `02-find_R_function.c` | contain a function that find the appropriate function for the opcode |
|`03-call_function.c` |contain a function that calls the required function |
|`04-node_operations.c` |contain the three functions that handeles the nodes. |
|`05-Mandatory_Functions1.c` |contain the functions of the opcodes : push, pall, pint, pop and swap.|
|`06-Mandatory_Functions2.c` |contain the functions of the opcodes : add and nop. |
|`07-Advanced_Functions1.c` |contain the functions of the opcodes: sub, div, mul, mod and pchar.|
|`08-Advanced_Functions2.c` |contain the functions of the opcodes: pstr, rotl and rotr. |

# Authors

- [@ChaimaBSlima](https://github.com/ChaimaBSlima)


# 🚀 About Me
I'm a Machine Learning developer...
