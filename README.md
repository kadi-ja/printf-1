# Get_flags.c:




This code defines a function called get_flags that calculates the active flags for a given format string. The function takes two parameters: a const char* named format, which is the formatted string in which to print the arguments, and a pointer to an int named i, which is used to track the current index of the format string. The function returns an int value that represents the flags calculated.
The function iterates over the characters in the format string starting from the current index position i+1 until it finds a character that is not a flag character. The flag characters that are recognized by this function are -, +, 0, #, and space. These flag characters are stored in an array named FLAGS_CH. The corresponding flag values for these characters are stored in an integer array named FLAGS_ARR. The flags variable is a bitwise OR operation of these flag values.
The function uses a nested for loop to iterate over the flag characters array FLAGS_CH and check whether the current character of the format string matches any of these characters. If it matches, the corresponding flag value is added to the flags variable using the bitwise OR operator. If it doesn't match any of the flag characters, the loop is terminated and the current index position is stored in i.
Finally, the function returns the flags variable, which represents the bitwise OR operation of all the recognized flag values found in the format string.


# get_precision.c:




This code defines a function called get_precision that calculates the precision for printing a value. The function takes three parameters: a const char* named format, which is the formatted string in which to print the arguments, a pointer to an int named i, which is used to track the current index of the format string, and a va_list named list, which is a list of arguments to be printed. The function returns an int value that represents the precision calculated.
The function first checks whether the current character of the format string at index position i+1 is a period (.). If it's not a period, the function returns the default precision value of -1. Otherwise, the function sets the precision to 0 and starts iterating over the format string starting from the next character.
For each character, the function checks whether it's a digit using the is_digit function (not shown in the code snippet). If it's a digit, the function updates the precision value by multiplying it by 10 and adding the numerical value of the digit. This allows the function to handle multiple-digit precision values. If the character is an asterisk (*), the function reads the precision value from the list of arguments using the va_arg function and stores it in the precision variable. If the character is neither a digit nor an asterisk, the function terminates the loop and stores the current index position in i.
Finally, the function returns the precision value, which represents the precision calculated from the format string.



# get_size.c:




This code defines a function called get_size that calculates the size to cast the argument based on the format string. The function takes two parameters: a const char* named format, which is the formatted string in which to print the arguments, and a pointer to an int named i, which is used to track the current index of the format string. The function returns an int value that represents the size to cast the argument.
The function first initializes a local variable curr_i to the current index *i+1 and size to 0. Then it checks whether the character in the format string at index position curr_i is a lowercase letter 'l' or 'h'. If the character is 'l', the function sets the size variable to a constant value S_LONG (which is usually defined as a macro for the long data type). If the character is 'h', the function sets the size variable to S_SHORT (which is usually defined as a macro for the short data type). If the character is neither 'l' nor 'h', the function updates the value of i to curr_i-1 (i.e., it does not consume any character from the format string).
Finally, the function returns the size value, which represents the size to cast the argument based on the format string.




# get_width.c:




This code defines the function get_width which is used in a printf-like function to calculate the width to be printed.
The function takes three parameters:
format: a formatted string in which to print the arguments.
i: a pointer to an integer that represents the current position of the iteration over the format string.
list: a list of arguments to be printed.
The function iterates over the characters in the format string starting from the position indicated by the integer pointed to by i. For each character, if it is a digit, the function multiplies the current width by 10 and adds the numeric value of the character minus the ASCII value of '0' to it. If the character is a '' (which indicates that the width is provided as an argument in the list), the function uses va_arg to retrieve the next argument from the list as an integer and assigns it to width. If the character is not a digit or a '', the function breaks out of the loop.
Finally, the function updates the value of the integer pointed to by i to the current position of the iteration minus 1, and returns the calculated width.



# Handle_print.c:




This code defines the handle_print function, which is responsible for printing a single argument based on its type. The function takes in several parameters:
fmt: A formatted string in which to print the arguments.
ind: A pointer to an integer representing the current index in the format string.
list: A list of arguments to be printed.
buffer: A buffer array to handle printing.
flags: An integer representing the active flags for printing.
width: An integer representing the width of the printed output.
precision: An integer representing the precision of the printed output.
size: An integer representing the size of the printed output.
The function first defines an array of fmt_t structs, which each contain a character representing a valid format specifier and a corresponding function pointer to handle printing that type of argument. The function then loops through the fmt_types array to find the appropriate function to handle the current format specifier at the given index in the fmt string. If a matching specifier is found, the corresponding function is called with the given arguments to handle printing the argument.
If the current format specifier is not recognized, the function prints a percent sign followed by the unknown specifier. If the previous character in the format string was a space, the function also prints a space before the percent sign. If a width is specified but the current specifier is not recognized, the function attempts to back up the index to find the beginning of the width specification before returning.
The function returns either -1, 1, or 2 depending on whether a valid specifier was found and handled, an unknown specifier was encountered, or an error occurred, respectively.


# Utils.c



This is a file containing several utility functions used by a program to handle printf-like formatting and printing of strings.
is_printable(char c) is a function that evaluates if a character is printable, returning 1 if it is, and 0 otherwise. A character is considered printable if its ASCII code is between 32 and 126.
append_hexa_code(char ascii_code, char buffer[], int i) is a function that appends a representation of an ASCII code in hexadecimal format to a buffer. It receives an ASCII code, the buffer to which the representation is to be appended, and the index at which to start appending. It returns 3, since the hexadecimal representation will always be 2 digits long, preceded by a backslash and the letter "x".
is_digit(char c) is a function that verifies if a character is a digit, returning 1 if it is, and 0 otherwise.
convert_size_number(long int num, int size) is a function that casts a number to a specified size, receiving the number to be casted and the size to which it is to be casted. If the size is S_LONG, the function returns the number as a long int. If the size is S_SHORT, it returns the number as a short. Otherwise, it returns the number as an int.
convert_size_unsgnd(unsigned long int num, int size) is a function that casts an unsigned number to a specified size, receiving the number to be casted and the size to which it is to be casted. If the size is S_LONG, the function returns the number as an unsigned long int. If the size is S_SHORT, it returns the number as an unsigned short. Otherwise, it returns the number as an unsigned int.



# Write_handlers.c



This is a code for handling formatted printing in C. Specifically, it handles the writing of characters and numbers with padding and formatting options such as precision, width, and flags.
The code includes three functions: handle_write_char, write_number, and write_num, which work together to write characters and numbers with the specified formatting options.
handle_write_char takes in a single character c and a buffer buffer to handle printing. It also takes in several formatting options such as flags, width, and precision. The function first adds the character to the left of the buffer, then adds padding to the right of the buffer until the specified width is reached. If the F_MINUS flag is set, the function returns the result of writing the buffer with the character added to the left followed by the padded buffer. Otherwise, it returns the result of writing the padded buffer followed by the character added to the left.
write_number takes in a signed integer is_negative and an index ind indicating where the number starts in the buffer. It also takes in several formatting options such as flags, width, and precision. The function determines whether to add a sign character such as '-', '+', or ' ' based on the specified flags, and then calls write_num to write the number to the buffer with the specified formatting options.
write_num takes in the same formatting options as write_number, as well as the length of the number length, the padding character padd, and an extra character extra_c. The function first handles special cases such as when the precision is 0 and the number is 0, and then adds padding to the left of the number until the specified precision is reached. If an extra character is specified, it adds it to the left of the number. It then adds padding to the right of the number until the specified width is reached. Finally, it returns the result of writing the buffer with the number and extra character, if any.


