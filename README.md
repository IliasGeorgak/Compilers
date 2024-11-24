## This is a simple compiler written in flex and bison for the semester project of the THEORY OF COMPUTATION course

### Compiler
This is a compiler (source-to-source) that takes a source file in Lambda (sample language created by the professor for this project) and produces a C file with the equivalent code that can then be compiled into an executable with gcc.
To generate the compiler simply run
```bash
    make
```
An executable named compiler will be generated. To complile a lambda file(.la) run:
```bash
    ./compiler < yourfile.la
```
### Lambda
Lambda is a simple language specifically created for this project. It supports logical and mathematical operations, conditionals, loops, functions, multiple data types, simple strings, arrays and complex types that are essentially C structs that also include executable functions.
I am currently in the process of translating the project handout to provide a more detailed and proper specification of the lambda language.

### Flex
The lexical analysis is done with the help of flex and all related code can be found in lexer.l

### Bison
The parser was generated with the help of bison and all related code can be found in parser.y

### Testing
In order to test the full capabilities of this compiler multiple sample test files (all .la files) have been included with the project.
