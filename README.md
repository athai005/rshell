#Rshell
##The mandatory brainchild of all UCR cs-100 students.

###What is rshell? 
Rshell is a simple shell for unix systems that students in the UCR CS100 course are required to create.
It is essentially an unfinished, more limited version of Bash.

###Current Features (Rshell)
* Executes commands (e.g. ls, mkdir, etc.)
* Supports comments (commands entered in as a comment will not be executed)
* handles "exit".
* can also be terminated using ctrl+d.
* prints a "Goodbye" message when terminated.
* ^C does not terminate Rshell.
* ^Z does not background Rshell.
* A syntax error message will be printed when one is detected. (e.g. ls &&&&&&& ; ||||)
* i/o redirection symbols and piping symbols entered as the first or last character of the input will be treated as syntax errors.
* somewhat supports piping (see bugs)

###Known bugs (Rshell)
* Any command entered that begins with a semicolon or forward slash causes an error. (e.g. ;ls)
* piping does work, but cannot be chained with multiple pipes. (it does, however support piping with i/o redirection)

###Current features (ls)
* parameters and flags are accepted in any arbitrary order.
* -a, -l, and -R are accepted as flags

###Known Bugs (ls)
* ls will list all hidden files (alphabetized) before not hidden files. (as opposed to the GNU ls sorting them alphabetically regardless of whether it is a hidden file or not)
* The -R flag calls ls, but will not recursively call itself on other directories within a directory.
* calling ls on a file instead of a directory causes an error (as opposed to the GNU ls outputting the name of the file passed in)
(the following are not exactly bugs but are steps that need to be taken to finish the ls program)
* currently does not output colored text 
