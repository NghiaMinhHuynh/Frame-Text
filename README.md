Text Alignment Utility

This program provides a text alignment utility that can format text files by applying three different alignment options: flush left, flush right, and full justify. The utility reads input text from a file, processes it, and writes the formatted output to another file. 

Description
The utility provides three text alignment functions: flush_left, flush_right, and full_justify. Each function takes as input the desired line length and the path to the input text file. It processes the text according to the specified alignment and returns a formatted string.

Usage
The utility can be run from the command line with the following syntax:

Copy code
alignment_utility input_file output_file line_length alignment_option
input_file: Path to the input text file.
output_file: Path to the output file where the formatted text will be written.
line_length: The desired line length for formatting.
alignment_option: Choose one of the alignment options: flush_left, flush_right, or full_justify.
Alignment Options

Flush Left (flush_left): Text is aligned to the left within the specified line length. Extra spaces are added to the right of each line if needed.

Flush Right (flush_right): Text is aligned to the right within the specified line length. Extra spaces are added to the left of each line if needed.

Full Justify (full_justify): Text is aligned to both the left and right within the specified line length. Extra spaces are added evenly between words to fill each line.

File Formats
The input text file is expected to contain the text that needs to be formatted. The output file will contain the formatted text according to the specified alignment option.

Examples

Copy code

alignment_utility input.txt output.txt 80 flush_left

alignment_utility input.txt output.txt 120 flush_right

alignment_utility input.txt output.txt 100 full_justify

Dependencies

The program utilizes standard C++ libraries, including <fstream>, <iostream>, <string>, and <vector>.

Compilation

To compile the utility, use a C++ compiler such as g++:

Copy code

g++ -o alignment_utility alignment_utility.cpp

License

This program is provided under the MIT License. 
