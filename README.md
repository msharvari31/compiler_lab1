README – Part 3: Tokenizer Implementation

Name: Sharvari Mirge     
Roll Number: 23110298    
Email: sharvari.mirge@iitgn.ac.in     
Programming Language Used (Part 3): C    

Compilation Instructions:
1. Compile the program using:      
   gcc tokenizer.c -o tokenizer

2. Run the tokenizer with an input file:     
   ./tokenizer < public_test1.txt

3. Run the tokenizer interactively:     
   ./tokenizer     
   (Type input and press Ctrl+D on Linux/Mac or Ctrl+Z followed by Enter on Windows)

Known Issues / Limitations:
- Only integer numbers are supported.
- Relational operators such as '>' and '<' are classified as UNKNOWN.
- Multi-character operators (e.g., ==, >=) are not supported.
- Comment handling is not implemented.
