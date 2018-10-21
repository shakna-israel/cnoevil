#ifndef CNOEVIL

// Programmer's Notes
//
// Every part of CNOEvil must be able to do one of:
// * Be excluded by a preprocessor definition (e.g. #define EVIL_NO_MODULE)
// * Be included by a preprocessor definition (e.g. #define EVIL_MODULE)
//
// We reserve EVIL_ for module names.
// Long module names are discouraged.
//
// We don't break C. We extend only.
//
// CNoEvil is intended to be intuitive to write,
// and clear to read.
//
// C11 features are fine. We assume a modern compiler.
//
// GNU features are discouraged, but I could be convinced to switch only to them.
// If you really need it, consider having both GNU and Clang extensions.
// If that's not possible - the module *must* be optional, and *must* have an #error directive
// for if the needed feature is unavailable.
//
// Whitespace sensitivity is abhorrent, and should never be introduced.
//
// Your code should make sense once it's expanded.
//
// Only include libraries conditionally, once needed.
//
// CNoEvil is a 1-file header library.
// That doesn't mean we're bound to macros-only, but it's probably a good
// idea to limit the number of functions.
//
// CNoEvil aims to be a language atop C, aimed at making the programmer's life
// *simpler*.
//

// Functions that explains CNoEvil, and it's parts.
#ifdef EVIL_HELP
  #include <stdio.h>
  void evil_manual(void);
  void evil_explain(char* token);

  #include <string.h>
  void evil_explain(char* token) {
    if(strcmp(token, "Main") == 0) {
      printf("%s\n", "This implements the beginning of a main function, and provides argc and argv. It expects that `then` will follow it.");
      printf("%s\n", "Mostly, it's a convenience function.");
    } else if(strcmp(token, "then") == 0) {
      printf("%s\n", "Follows several syntactic structures. Basically just `){` but worded.");
      printf("%s\n", "e.g.");
      printf("%s\n\n", "If x == y then return x; end");
      printf("%s\n\n", "Main then return 0; end");
    } else if(strcmp(token, "constant") == 0) {
      printf("%s\n", "Declares a constant.");
      printf("%s\n", "constant(Type, Name, Value)");
      printf("%s\n", "e.g.");
      printf("%s\n", "constant(int, pi, 3.14);");
    } else if(strcmp(token, "lambda") == 0) {
      printf("%s\n", "This macro allows you to generate function-like objects. You will need to know the signature, before you can pass it to another function, however.");
      printf("%s\n", "e.g.");
      printf("%s\n", "int (*max)(int, int) = lambda (int, (int x, int y) { return x > y ? x : y; });");
      printf("%s\n", "max(10, 20);");
      printf("\n%s\n\n", "int something(int (*x)(int, int), int y, int z) { return x(y, z); }");
    } else {
      printf("%s\n", "Sorry, that option could not be found.");
    }
  }

  void evil_manual(void) {
    printf("%s\n\n", "CNoEvil - A Language Extension for C");
    printf("%s\n", "Definitions are expected to be created before the `evil.h` file is included.");
    printf("%s\n%s\n%s\n", "e.g.", "#define EVIL_IO", "#include \"evil.h\"");
    printf("\n%s\n\n", "Available by default:");
    printf("%s\n", "The equivalent of including stdbool.h. Exclude by defining EVIL_NO_BOOL.");
    printf("%s\n", "Main - A keyword, expected to be followed by keyword `then`. Automatically makes argc and argv available. Use instead of the `main` function. Exclude by defining `EVIL_NO_MAIN`.");
    printf("%s\n", "then - A keyword, used to follow some constructs (such as If, While, etc.) Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "end - A keyword, used to close functions, and some other constructs. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "If - A keyword, used to replace C's bracket'd `if`. i.e. Equivalent to `if(`. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "For - A keyword, used to replace C's bracket'd `for`. i.e. Equivalent to `for(`. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "While - A keyword, used to replace C's bracket'd `while`. i.e. Equivalent to `while(`. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "Do - A keyword, replaces C's `do`, and opens the block automatically. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "Switch(T) - A macro, creates and opens the block of a switch statement. Exclude by defining `EVIL_NO_FLOW`.");
    printf("%s\n", "contant(Type, Name, Value) - A macro, generates a `const`. Exclude by defining `EVIL_NO_SPECIFIER`.");
    printf("%s\n", "storage(Type, Name, Value) - A macro, generates a `static`. Exclude by defining `EVIL_NO_SPECIFIER`.");
    printf("%s\n", "proc(Name, ReturnType, ...) - A variadic macro. Arguments are as in C function arguments. Creates the start of a C function, that is, it is followed by a function body. Exclude by defining `EVIL_NO_PROC`.");
    printf("%s\n", "CNOEVIL - A macro that is defined if this library is available.");
    printf("\n%s\n\n", "Available if EVIL_IO defined:");
    printf("%s\n", "The equivalent of including stdio.h");
    printf("%s\n", "display(T) - Prints a representation of the given value to stdout.");
    printf("%s\n", "displayf(F, T) - Prints a representation of the given value to F, a `FILE*`.");
    printf("%s\n", "displayln(T) - Prints a representation of the given value to stdout, followed by a system-compatible line ending.");
    printf("%s\n", "displayfln(F, T) - Prints a representation of the given value to F, a `FILE*`, followed by a system-compatible line ending.");
    printf("%s\n", "endl - A keyword. Prints a system-comaptible line ending to stdout.");
    printf("%s\n", "endlf(F) - Prints a system-comaptible line ending to F, a `FILE*`.");
    printf("%s\n", "repr_type(T) - Returns a `char*` containing a text representation of the type. Optimisation may effect results. Returns \"Unknown\" for any type that cannot be accounted for.");
    printf("\n%s\n\n", "Available if EVIL_STRUCT defined:");
    printf("%s\n", "Struct(Name) - Starts a struct definition.");
    printf("%s\n", "Union(Name) - Start a union definition.");
    printf("%s\n", "Typedef - A keyword, exactly equivalent to `typedef`.");
    printf("%s\n", "BitField(Name, Type, Width) - Used for defining a Bitfield inside a struct.");
    printf("\n%s\n\n", "Available if EVIL_COROUTINE defined:");
    printf("%s\n", "coroutine() - A macro that marks the beginning of a coroutine body.");
    printf("%s\n", "co_return(T) - A macro that marks a return from a coroutine.");
    printf("%s\n", "co_end() - A macro that closes a coroutine body.");
    printf("\n%s\n\n", "Available if EVIL_HELP defined:");
    printf("%s\n", "evil_manual() - Prints this.");
    printf("%s\n", "evil_explain(char*) - Prints further information on a single item. (Under heavy development.)");
    printf("\n%s\n\n", "Available if EVIL_LAMBDA defined:");
    printf("%s\n", "lambda(Type, Body) - A simple macro to construct an anonymous function-like object");
    printf("\n%s\n\n", "Available if EVIL_CLI defined:");
    printf("\n%s\n\n", "Note: None of the module's functions check if function supported by current terminal.");
    printf("%s\n", "cli_reset() - Removes any active effects and colors from the terminal.");
    printf("%s\n", "cli_fg_256(N) - Takes a number between 0-255, and applies the corresponding color to the terminal text.");
    printf("%s\n", "cli_bg_256(N) - Takes a number between 0-255, and applies the corresponding color to the terminal background.");
    printf("%s\n", "cli_fg_rgb(R,G,B) - Takes three values (Red, Green, Blue), and applies the corresponding truecolor to the terminal text.");
    printf("%s\n", "cli_bg_rgb(R,G,B) - Takes three values (Red, Green, Blue), and applies the corresponding truecolor to the terminal background.");
    printf("%s\n", "cli_cursor_up(N) - Moves the console cursor up N lines.");
    printf("%s\n", "cli_cursor_down(N) - Moves the console cursor down N lines.");
    printf("%s\n", "cli_cursor_right(N) - Moves the console cursor right N characters.");
    printf("%s\n", "cli_cursor_left(N) - Moves the console cursor left N characters.");
    printf("%s\n", "cli_cursor_save() - Saves the current cursor position.");
    printf("%s\n", "cli_cursor_restore() - Moves the cursor to the last saved position.");
    printf("%s\n", "cli_screen_clear() - Clears the current terminal screen.");
    printf("%s\n", "cli_screen_clear_before() - Clears the current terminal screen, before the cursor.");
    printf("%s\n", "cli_screen_clear_after() - Clears the current terminal screen, after the cursor.");
    printf("%s\n", "cli_line_clear() - Clears the current terminal line.");
    printf("%s\n", "cli_line_clear_before() - Clears the current terminal line, before the cursor.");
    printf("%s\n", "cli_line_clear_after() - Clears the current terminal line, after the cursor.");
    printf("%s\n", "cli_effect_reset() - Removes any active effects from the terminal.");
    printf("%s\n", "cli_effect_bold() - Activates the bold text terminal effect.");
    printf("%s\n", "cli_effect_underline() - Activates the underlined text terminal effect.");
    printf("%s\n", "cli_effect_reverse() - Activates the reversed text terminal effect.");
    printf("%s\n", "cli_effect_blink() - Activates the blinking text terminal effect.");
    printf("%s\n", "cli_effect_invisible() - Activates the invisible text terminal effect.");
    printf("%s\n", "cli_fg_black() - Sets the terminal text to simple black.");
    printf("%s\n", "cli_fg_red() - Sets the terminal text to simple red.");
    printf("%s\n", "cli_fg_green() - Sets the terminal text to simple green.");
    printf("%s\n", "cli_fg_yellow() - Sets the terminal text to simple yellow.");
    printf("%s\n", "cli_fg_blue() - Sets the terminal text to simple blue.");
    printf("%s\n", "cli_fg_magenta() - Sets the terminal text to simple magenta.");
    printf("%s\n", "cli_fg_cyan() - Sets the terminal text to simple cyan.");
    printf("%s\n", "cli_fg_white() - Sets the terminal text to simple white.");
    printf("%s\n", "cli_fg_bright_black() - Sets the terminal text to complex black.");
    printf("%s\n", "cli_fg_bright_red() - Sets the terminal text to complex red.");
    printf("%s\n", "cli_fg_bright_green() - Sets the terminal text to complex green.");
    printf("%s\n", "cli_fg_bright_yellow() - Sets the terminal text to complex yellow.");
    printf("%s\n", "cli_fg_bright_blue() - Sets the terminal text to complex blue.");
    printf("%s\n", "cli_fg_bright_magenta() - Sets the terminal text to complex magenta.");
    printf("%s\n", "cli_fg_bright_cyan() - Sets the terminal text to complex cyan.");
    printf("%s\n", "cli_fg_bright_white() - Sets the terminal text to complex white.");
    printf("%s\n", "cli_bg_black() - Sets the terminal background to simple black.");
    printf("%s\n", "cli_bg_red() - Sets the terminal background to simple red.");
    printf("%s\n", "cli_bg_green() - Sets the terminal background to simple green.");
    printf("%s\n", "cli_bg_yellow() - Sets the terminal background to simple yellow.");
    printf("%s\n", "cli_bg_blue() - Sets the terminal background to simple blue.");
    printf("%s\n", "cli_bg_magenta() - Sets the terminal background to simple magenta.");
    printf("%s\n", "cli_bg_cyan() - Sets the terminal background to simple cyan.");
    printf("%s\n", "cli_bg_white() - Sets the terminal background to simple white.");
    printf("%s\n", "cli_bg_bright_black() - Sets the terminal background to complex black.");
    printf("%s\n", "cli_bg_bright_red() - Sets the terminal background to complex red.");
    printf("%s\n", "cli_bg_bright_green() - Sets the terminal background to complex green.");
    printf("%s\n", "cli_bg_bright_yellow() - Sets the terminal background to complex yellow.");
    printf("%s\n", "cli_bg_bright_blue() - Sets the terminal background to complex blue.");
    printf("%s\n", "cli_bg_bright_magenta() - Sets the terminal background to complex magenta.");
    printf("%s\n", "cli_bg_bright_cyan() - Sets the terminal background to complex cyan.");
    printf("%s\n", "cli_bg_bright_white() - Sets the terminal background to complex white.");
    printf("\n%s\n\n", "Available if EVIL_HASH defined:");
    printf("%s\n", "jenkins64(char* key, size_t length) - Hash a given string into a uint64_t. Only defined if 64bit numbers are supported. Based on Jenkins One-At-A-Time hash.");
    printf("%s\n", "fletcher64(char* key, size_t length) - Hash a given string into a uint64_t. Only defined if 64bit numbers are supported. Based on Fletcher's checksum.");
    printf("%s\n", "fletcher32(char* key, size_t length) - Hash a given string into a uint32_t. Based on Fletcher's checksum.");
    printf("%s\n", "jenkins32(char* key, size_t length) - Hash a given string into a uint32_t. Based on Jenkins One-At-A-Time hash.");
    printf("%s\n", "adler32(char* key, size_t length) - Hash a given string into a uint32_t. Based on Adler-32.");
    printf("%s\n", "fletcher16(char* key, size_t length) - Hash a given string into a uint16_t. Based on Fletcher's checksum.");
    printf("\n%s\n\n", "EVIL_MATH module under heavy development.");
    printf("\n%s\n\n", "EVIL_ARGPARSE module under heavy development.");
    printf("\n%s\n\n", "EVIL_INT module under heavy development.");
    printf("\n%s\n\n", "EVIL_RANDOM module under heavy development.");
    printf("\n%s\n\n", "EVIL_LIST module under heavy development.");
    printf("\n%s\n\n", "EVIL_SORT module under heavy development.");
    printf("\n%s\n\n", "EVIL_GC module under heavy development.");
    printf("\n%s\n\n", "EVIL_LOG module under heavy development.");
  }
#endif

// The IO Module.
#ifdef EVIL_IO
  // User wants IO, give the all the IO.
  #include <stdio.h>

  // Yes, Generics. (aka type-switch). It's C11 only,
  // but who cares.
  // stdint identifiers (inttypes.h) should be catered for by the below.
  // Original display_format macro by Robert Gamble, (c) 2012
  // used with permission.
  // Expanded upon to incorporate const, volatile and const volatile types,
  // as they don't get selected for.
  #define display_format(x) _Generic((0,x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p", \
    volatile char: "%c", \
    volatile signed char: "%hhd", \
    volatile unsigned char: "%hhu", \
    volatile signed short: "%hd", \
    volatile unsigned short: "%hu", \
    volatile signed int: "%d", \
    volatile unsigned int: "%u", \
    volatile long int: "%ld", \
    volatile unsigned long int: "%lu", \
    volatile long long int: "%lld", \
    volatile unsigned long long int: "%llu", \
    volatile float: "%f", \
    volatile double: "%f", \
    volatile long double: "%Lf", \
    volatile char *: "%s", \
    volatile void *: "%p", \
    const char: "%c", \
    const signed char: "%hhd", \
    const unsigned char: "%hhu", \
    const signed short: "%hd", \
    const unsigned short: "%hu", \
    const signed int: "%d", \
    const unsigned int: "%u", \
    const long int: "%ld", \
    const unsigned long int: "%lu", \
    const long long int: "%lld", \
    const unsigned long long int: "%llu", \
    const float: "%f", \
    const double: "%f", \
    const long double: "%Lf", \
    const char *: "%s", \
    const void *: "%p", \
    const volatile char: "%c", \
    const volatile signed char: "%hhd", \
    const volatile unsigned char: "%hhu", \
    const volatile signed short: "%hd", \
    const volatile unsigned short: "%hu", \
    const volatile signed int: "%d", \
    const volatile unsigned int: "%u", \
    const volatile long int: "%ld", \
    const volatile unsigned long int: "%lu", \
    const volatile long long int: "%lld", \
    const volatile unsigned long long int: "%llu", \
    const volatile float: "%f", \
    const volatile double: "%f", \
    const volatile long double: "%Lf", \
    const volatile char *: "%s", \
    const volatile void *: "%p", \
    default: "%d")

  // The main printing function.
  #define display(x) printf(display_format(x), x)
  #define displayf(f, x) fprintf(f, display_format(x), x)

  // Windows has a different line ending.
  #if defined(_WIN32) || defined(__WIN32) || defined(WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WIN64) || defined(WIN64) || defined(__WIN64__) || defined(__WINNT) || defined(__WINNT__) || defined(WINNT)
    #define displayln(x) printf(display_format(x), x); printf("%s", "\r\n")
    #define displayfln(f, x) fprintf(f, display_format(x), x); printf("%s", "\r\n")
  #else
    #define displayln(x) printf(display_format(x), x); printf("%c", '\n')
    #define displayfln(f, x) fprintf(f, display_format(x), x); printf("%c", '\n')
  #endif

  // Basically a _Generic.
  #define repr_type(x) _Generic((x), \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    signed short: "signed short", \
    unsigned short: "unsigned short", \
    signed int: "signed int", \
    unsigned int: "unsigned int", \
    long int: "long int", \
    unsigned long int: "unsigned long int", \
    long long int: "long long int", \
    unsigned long long int: "unsigned long long int", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    char *: "char pointer", \
    void *: "void pointer", \
    volatile char: "volatile char", \
    volatile signed char: "volatile signed char", \
    volatile unsigned char: "volatile unsigned char", \
    volatile signed short: "volatile signed short", \
    volatile unsigned short: "volatile unsigned short", \
    volatile signed int: "volatile signed int", \
    volatile unsigned int: "volatile unsigned int", \
    volatile long int: "volatile long int", \
    volatile unsigned long int: "volatile unsigned long int", \
    volatile long long int: "volatile long long int", \
    volatile unsigned long long int: "volatile unsigned long long int", \
    volatile float: "volatile float", \
    volatile double: "volatile double", \
    volatile long double: "volatile long double", \
    volatile char *: "volatile char pointer", \
    volatile void *: "volatile void pointer", \
    const char: "const char", \
    const signed char: "const signed char", \
    const unsigned char: "const unsigned char", \
    const signed short: "const signed short", \
    const unsigned short: "const unsigned short", \
    const signed int: "const signed int", \
    const unsigned int: "const unsigned int", \
    const long int: "const long int", \
    const unsigned long int: "const unsigned long int", \
    const long long int: "const long long int", \
    const unsigned long long int: "const unsigned long long int", \
    const float: "const float", \
    const double: "const double", \
    const long double: "const long double", \
    const char *: "const char pointer", \
    const void *: "const void pointer", \
    const volatile char: "const volatile char", \
    const volatile signed char: "const volatile signed char", \
    const volatile unsigned char: "const volatile unsigned char", \
    const volatile signed short: "const volatile signed short", \
    const volatile unsigned short: "const volatile unsigned short", \
    const volatile signed int: "const volatile signed int", \
    const volatile unsigned int: "const volatile unsigned int", \
    const volatile long int: "const volatile long int", \
    const volatile unsigned long int: "const volatile unsigned long int", \
    const volatile long long int: "const volatile long long int", \
    const volatile unsigned long long int: "const volatile unsigned long long int", \
    const volatile float: "const volatile float", \
    const volatile double: "const volatile double", \
    const volatile long double: "const volatile long double", \
    const volatile char *: "const volatile char pointer", \
    const volatile void *: "const volatile void pointer", \
    default: "Unknown")


  // endl, just a symbol that can be used to produce the normal
  // line ending.
  // endlf can take a file to print to.
  // e.g. ```display(x); display(y); endl;```
  //  ```endlf(FILE* x);```
  // Windows has a different line ending.
  #if defined(_WIN32) || defined(__WIN32) || defined(WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WIN64) || defined(WIN64) || defined(__WIN64__) || defined(__WINNT) || defined(__WINNT__) || defined(WINNT)
    #define endl printf("%s", "\r\n")
    #define endlf(f) fprintf(f, "%s", "\r\n")
  #else
    #define endl printf("%c", '\n')
    #define endlf(f) fprintf(f, "%c", '\n')
  #endif

#endif

// Allow users to not use Main
#ifndef EVIL_NO_MAIN
  #define Main int main(int argc, char** argv
#endif

#ifndef EVIL_NO_BOOL
  #include <stdbool.h>
#endif

// Allow users to not use CNOEvil's decision
// macros.
#ifndef EVIL_NO_FLOW
  #define then ){
  #define end }
  #define If if(
  #define Else } else {
  #define For for(
  #define While while(
  #define Do do{
  #define Switch(x) switch(x){
  #define Case(x) case x:
#endif

// constant is an optionally-exluded definition
#ifndef EVIL_NO_SPECIFIER
  #define constant(_type, _name, _value) const _type _name = _value

  // Static vars are usually referred to as storage-class
  // specifiers in the C standard.
  #define storage(_type, _name, _value) static _type _name = _value
#endif

// Allow users not to use our procedure definition.
#ifndef EVIL_NO_PROC
  #define proc(_name, _ret, ...) _ret _name(__VA_ARGS__){
#endif

// Structures module
#ifdef EVIL_STRUCTS
  #define BitField(_name, _type, _width) _type _name : _width
  #define Struct(_name) struct _name {
  #define Union(_name) union __name {
  #define Typedef typedef
#endif

// Math module.
#ifdef EVIL_MATH
  // This library does the heavy lifting.
  #include <math.h>
  // TODO: Make math.h functions use _Generic to
  // handle multiple types.
  #define add(_a, _b) _a + _b
  #define take(_a, _b) _a - _b
  #define multiply(_a, _b) _a * _b
  #define divide(_a, _b) _a / _b
#endif

// Lambda Module. Optional include.
#ifdef EVIL_LAMBDA
  // This requires nested functions to be allowed.
  // Only GCC supports it.
  // ... Unconfirmed if Clang does. It might.
  #if defined(__clang__) || !defined(__GNUC__)
    #error "Lambda requires a GNU compiler."
  #endif
  // A cleaner, but slightly more cumbersome lambda:
  #define lambda(ret_type, _body) ({ ret_type _ _body _; })
  // e.g. int (*max)(int, int) = lambda (int, (int x, int y) { return x > y ? x : y; });
  // Pros:
  // * Woot, easier to pass, as the user has to know the signature anyway.
  // * Name not part of lambda definition. More lambda-y.
  // * Body of function inside macro, feels more like a lambda.
  // * Uses expression disgnator (GCC-only), which creates a properly constructed function pointer.
  // * It *may* work under Clang too!
  // Cons:
  // * The signature isn't constructed for the user, they have to both know and understand it.
#endif

#ifdef EVIL_CLI
  //Taken from my library, colors.h (https://github.com/shakna-israel/colors)
  //Also taken from my library, damned (curses for shell) (https://github.com/shakna-israel/damned)
  #include <stdio.h>
  #include <assert.h>
  #define cli_reset() printf("%s", "\x1b[0m"); fflush(stdout)

  #define cli_fg_256(num) assert(num < 256); printf("%s%d%s", "\x1b[38;5;", num, "m")
  #define cli_bg_256(num) assert(num < 256); printf("%s%d%s", "\x1b[48;5;", val, "m")

  // Also known as truecolor.
  #define cli_fg_rgb(a, b, c) printf("\x1b[38;2;%d;%d;%d", a, b, c)
  #define cli_bg_rgb(a, b, c) printf("\x1b[48;2;%d;%d;%d", a, b, c)

  #define cli_fg_black() printf("%s", "\x1b[30m");
  #define cli_fg_red() printf("%s", "\x1b[31m");
  #define cli_fg_green() printf("%s", "\x1b[32m");
  #define cli_fg_yellow() printf("%s", "\x1b[33m");
  #define cli_fg_blue() printf("%s", "\x1b[34m");
  #define cli_fg_magenta() printf("%s", "\x1b[35m");
  #define cli_fg_cyan() printf("%s", "\x1b[36m");
  #define cli_fg_white() printf("%s", "\x1b[37m");

  #define cli_fg_bright_black() printf("%s", "\x1b[30;1m");
  #define cli_fg_bright_red() printf("%s", "\x1b[31;1m");
  #define cli_fg_bright_green() printf("%s", "\x1b[32;1m");
  #define cli_fg_bright_yellow() printf("%s", "\x1b[33;1m");
  #define cli_fg_bright_blue() printf("%s", "\x1b[34;1m");
  #define cli_fg_bright_magenta() printf("%s", "\x1b[35;1m");
  #define cli_fg_bright_cyan() printf("%s", "\x1b[36;1m");
  #define cli_fg_bright_white() printf("%s", "\x1b[37;1m");

  #define cli_bg_black() printf("%s", "\x1b[40m");
  #define cli_bg_red() printf("%s", "\x1b[41m");
  #define cli_bg_green() printf("%s", "\x1b[42m");
  #define cli_bg_yellow() printf("%s", "\x1b[43m");
  #define cli_bg_blue() printf("%s", "\x1b[44m");
  #define cli_bg_magenta() printf("%s", "\x1b[45m");
  #define cli_bg_cyan() printf("%s", "\x1b[46m");
  #define cli_bg_white() printf("%s", "\x1b[47m");

  #define cli_bg_bright_black() printf("%s", "\x1b[40;1m");
  #define cli_bg_bright_red() printf("%s", "\x1b[41;1m");
  #define cli_bg_bright_green() printf("%s", "\x1b[42;1m");
  #define cli_bg_bright_yellow() printf("%s", "\x1b[43;1m");
  #define cli_bg_bright_blue() printf("%s", "\x1b[44;1m");
  #define cli_bg_bright_magenta() printf("%s", "\x1b[45;1m");
  #define cli_bg_bright_cyan() printf("%s", "\x1b[46;1m");
  #define cli_bg_bright_white() printf("%s", "\x1b[47;1m");

  #define cli_cursor_up(num) printf("\x1b%dA", num)
  #define cli_cursor_down(num) printf("\x1b%dB", num)
  #define cli_cursor_left(num) printf("\x1b%dC", num)
  #define cli_cursor_right(num) printf("\x1b%dD", num)
  #define cli_cursor_save() printf("\x1bs")
  #define cli_cursor_restore() printf("\x1bu")

  #define cli_screen_clear() printf("%s", "\x1b[2J\x1b[1;1H"); fflush(stdout)
  #define cli_screen_clear_before() printf("%s", "\x1b[1J"); fflush(stdout)
  #define cli_screen_clear_after() printf("%s", "\x1b[0J"); fflush(stdout)

  #define cli_line_clear() printf("%s", "\x1b[2K"); fflush(stdout)
  #define cli_line_clear_before() printf("%s", "\x1b[1K"); fflush(stdout)
  #define cli_line_clear_after() printf("%s", "\x1b[0K"); fflush(stdout)

  #define cli_effect_bold() printf("%s", "\x1b[1m")
  #define cli_effect_underline() printf("%s", "\x1b[4m")
  #define cli_effect_reverse() printf("%s", "\x1b[7m")
  #define cli_effect_blink() printf("%s", "\x1b[5m")
  #define cli_effect_invisible() printf("%s", "\x1b[8m")
  #define cli_effect_reset() printf("%s", "\x1b[0m")
#endif

// TODO: argparser module.
//#ifdef EVIL_ARGPARSE
//#endif

#ifdef EVIL_INT
  #include <stdint.h>
  #ifdef INT64_MAX
    #define Number(x) int64_t x
  #endif
  #define Decimal(x) long double x
  // TODO: itoa, convenience.
#endif

// TODO: random module.
//#ifdef EVIL_RANDOM
  // TODO: Random seeder
  // TODO: Mersenne Twister
//#endif

#ifdef EVIL_HASH
  #include <stdint.h>
  #ifdef INT64_MAX
  uint64_t jenkins64(const uint8_t* key, size_t length) {
    size_t i = 0;
    uint64_t hash = 0;
    while(i != length) {
      hash += key[i++];
      hash += hash << 10;
      hash += hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
  }
  uint64_t fletcher64(const uint8_t* key, size_t length) {
    uint64_t a = 0;
    uint64_t b = 0;
    for(size_t i = 0; i < length; i++) {
      a = (a + key[i]) % 4294967295;
      b = (b + a) % 4294967295;
    }
    return (b << 16) | a;
  }
  #endif
  uint32_t jenkins32(const uint8_t* key, size_t length) {
    size_t i = 0;
    uint32_t hash = 0;
    while(i != length) {
      hash += key[i++];
      hash += hash << 10;
      hash += hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
  }
  uint32_t adler32(const uint8_t* key, size_t length) {
    uint32_t sa = 1;
    uint32_t sb = 0;
    for(size_t i = 0; i < length; i++) {
      sa = (sa + key[i]) % 65521;
      sb = (sb + sa) % 65521;
    }
    return (sb << 16) | a;
  }
  uint32_t fletcher32(const uint8_t* key, size_t length) {
    uint32_t a = 0;
    uint32_t b = 0;
    for(size_t i = 0; i < length; i++) {
      a = (a + key[i]) % 65535;
      b = (b + a) % 65535;
    }
    return (b << 16) | a;
  }
  uint16_t fletcher16(const uint8_t* key, size_t length) {
    uint16_t a = 0;
    uint16_t b = 0;
    for(size_t i = 0; i < length; i++) {
      a = (a + key[i]) % 255;
      b = (b + a) % 255;
    }
    return (b << 16) | a;
  }
#endif

// TODO: list module.
//#ifdef EVIL_LIST
  // TODO: singly-linked list
  // TODO: doubly-linked list
  // TODO: cicular doubly-linked list

  // TODO: sort module. Sorts lists from EVIL_LIST,
  // so only available as a submodule.
  //#ifdef EVIL_SORT
    // TODO: insertion sort
    // TODO: bubble sort
    // TODO: merge sort
    // TODO: quicksort
  //#endif
//#endif

// TODO: GC module
// Might not be possible.
// See https://github.com/orangeduck/tgc/ for minimal example.
//#define EVIL_GC
//#endif

// TODO: coroutine library
#ifdef EVIL_COROUTINE
  // This lovely hack makes use of switch statements,
  // And the __LINE__ C macro
  // It tracks the current state, and switches case.
  // But... I imagine awful things may happen with an extra semi-colon.
  // Which would be hard to debug.
  #if defined(EVIL_LAMBDA) && !defined(EVIL_NO_WARN)
    // And bad things happen with expression statements.
    #warning "Lambda's don't play well with Coroutines. Avoid using them in the body of a coroutine."
  #endif
  #ifndef EVIL_NO_WARN
    #warning "Coroutine's don't support nesting. It may work sometimes, other times it may explode."
  #endif

  // Original macro hack by Robert Elder (c) 2016. Used against their advice, but with their permission.
  #define coroutine() static int state=0; switch(state) { case 0:
  #define co_return(x) { state=__LINE__; return x; case __LINE__:; }
  #define co_end() }
#endif

// TODO: Logging module

#define CNOEVIL
#endif
