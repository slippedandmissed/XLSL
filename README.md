# XLSL &mdash; The Excel Shader Language

This project aims to define a programming language (XLSL), and a compiler which converts XLSL source code into Excel formulae (with no VBA).

![Raytrace](https://github.com/slippedandmissed/XLSL/blob/main/docs/raytrace.png)
This is an example of a simple Excel ray tracer written in XLSL.

## Language features

### Data types

The standard data types in XLSL are:

 - `number`
 - `text`
 - `logical`

These correspond to built-in data types in Excel

### Functions

Functions are defined in a C-like way.

```c++
number addTen(number x) {
  return x + 10;
}
```

Functions can also be recursive using the `self` keyword

```c++
number factorial(number n) {
  return n <= 1 ? 1 : n * self(n-1);
}
```

### Structs

Custom data types can be defined using the `struct` keyword. A struct consists of several member declarations.

```c++
struct Vector3 {
  number x;
  number y;
  number z;
}
```

Structs can be instantiated as follows:

```c++
Vector3 position = Vector3 { 1, 7, 2 };
```

The arguments to a struct instantiation can be literals, function calls, or any other expression whose type is the same as that of the corresponding member of the struct;

Unfortunately, XLSL does not yet natively support functions which return instances of a struct (although passing an instance of a struct as an *argument* to a function works fine). Instead, structs can define `serialize` and `deserialize` methods which convert to and from `text` as follows:

```c++
struct Vector3 {
  number x;
  number y;
  number z;

  serialize {
    return Std.Typing.numberToText(x) + "," + Std.Typing.numberToText(y) + "," + Std.Typing.numberToText(x); 
  }

  deserialize {
    number x = Std.Typing.textToNumber(Std.Split.head(serialized, ","));
    number y = Std.Typing.textToNumber(Std.Split.nth(serialized, ",", 1));
    number z = Std.Typing.textToNumber(Std.Split.nth(serialized, ",", 2));
    return Vector3 { x, y, z };
  }
}
```

Note that in the `serialize` method, the fields of the struct are referred to by their names, and in the `deserialize` method, the `text` to deserialized can be referenced via the implicitly defined `serialized` variable.

These methods can be used as follows:

```c++
text scale(Vector3 vector, number scale) {
  Vector3 result = Vector3 {
    scale*vector.x,
    scale*vector.y,
    scale*vector.z
  };
  return serialize(result);
}

void main() {
  Vector3 p = Vector3 { 1, 2, 3 };
  Vector3 q = deserialize<Vector3>(scale(p, 2));
}
```

### Namespaces

Namespaces can be defined using the `namespace` keyword. Functions and structs can be defined within a namespace. Expressions which try to access these structs and functions from outside the namespace must include the namespace identifier. An example is:

```c++
namespace Math {
  number sqrt(number x) {
    // Something here
  }
}

number y = Math.sqrt(5);
```

Namespaces can be nested. An example is shown below of a nested namespace with a function `foo`, and how you would reference `foo` from different areas of the program.

```c++
namespace A {
  namespace B {
    void foo() {
      // Something here
    }

    //     foo();
    // or  B.foo();
    // or  A.B.foo();
  }

  //    B.foo();
  // or A.B.foo();

  namespace C {
    //    B.foo();
    // or A.B.foo();
  }

  namespace B {
    //     foo();
    // or  B.foo();
    // or  A.B.foo();
  }
}

// A.B.foo();
```

### Imports

Other XLSL scripts can be imported at the top of the program using the following syntax:

```c++
import "stdlib.xlsl" as Std;
```

The specified path can be relative to the current XLSL file, or can be an absolute path to a file. All of the structs and functions available in the global scope of the specified file will be placed into a namespace in the current program (in this case, the namespace would be called `Std`).

### Ternary operators

XLSL does not have `if`, `else`, `while`, or `for` loops. In fact, the only conditional operation is the ternary operator. Much like in other languages, this can be used as an expression in XLSL as follows:

```c++
condition ? expressionIfTrue : expressionIfFalse
```

The only way to create loops in XLSL is to use the ternary operator in conjunction with recursive functions.

### Literals

`text` literals can be single-quoted or double-quoted strings:

```c++
text x = "Lorem ipsum";
```

`number` literals can be any decimal number:

```c++
number x = 1.729;
```

`logical` literals are either `true` or `false`:

```c++
logical x = true;
```

### Direct formula access

Excel has a lot of built-in functions which you wouldn't want to rewrite from scratch. These can be called like normal `XLSL` functions by prepending their names with a dollar sign (`$`):

```c++
number factorial(number x) {
  return $FACT(x);
}
```

It's important to put this in its own function because the XLSL compiler cannot determine its return type, and so must rely on the return type of the enclosing XLSL funciton.

## Using the compiler

After cloning the repo, run

```bash
make
```

to build the compiler.

Instead of using the compiler (`build/compile`) directly, it is recommended that you use the wrapper script `render.py`.

This script takes an XLSL source code file and outputs a `.xlsx` Excel spreadsheet file.

The formula in the specified output cells of the spreadsheet will be the compiled version of the `main` function in the XLSL source code file provided. Any inputs required for the `main` function will be taken from a set of cells specified from the command line.

Example usage:

```bash
./render.py ./examples/greeting.xlsl -i B1:B2 -l left D1
```

You can specify multiple output cells on the command line, and the same formula will be put into each of them. The behaviour of the cells can be customised by using Direct Formula Access with the `$ROW()` and `$COLUMN()` excel formulae. This is what makes XLSL a "shader" language &mdash; each output cell is executing the same formula, based on its coordinates it can produce a different result.

A template spreadsheet can also be specified on the command line, and the render script will use this file as a starting point. This allows you to customise the formatting of your spreadsheet in a way that won't be lost every time you recompile the XLSL code.

```bash
./render.py ./examples/raytrace.xlsl A1:CB45 -i CE47:CE60 -l left -t ./examples/templates/raytrace_template.xlsx
```

## Future work

There are lots of improvements I'd like to make to the XLSL compiler in the future. If you feel so inclined, feel free to submit a pull request!

- XLSL is very unoptimized. The formulae it outputs are nowhere near the simplest/shortest which would achieve the same result. In the future I'd like to improve this.

- The lexer and parser errors are very unhelpful. Often they are just `syntax error` with no further explanation. I'd like to improve error reporting.

- There are several bugs in the lexer and parser I'd like to address:

  - Order of operations is somewhat broken. While `1+2*3` correctly gets parsed, the expression `(1+2)*3` results in a syntax error.

  - Nested structs access is broken. Suppose you had a struct instance `foo` with a member named `bar` which in turn was a struct instance with a member named `baz`. The expression `foo.bar.baz` is not handled correctly. Similarly, `MyStruct x = foo.bar; x.baz` fails, but seemingly for a different reason. Further investigation is required.

  - Variables cannot be used as conditions in a ternary operator. The expression `someLogicalVar ? 1 : 0` results in a syntax error. Instead, the programmer must use `(someLogicalVar == true) ? 1 : 0` which isn't ideal.

- There's a limit on function complexity. Due to Excel's limit of 8192 characters per formula, if an individual XLSL function compiles to a formula that is too long, while the compiler throws no warnings or errors, Excel will refuse to open the resulting spreadsheet. This is not necessarily an awful thing, as the XLSL programmer can simply split their function into multiple smaller functions, but it would be nice for the compiler to throw a warning.

- Import file paths aren't unescaped properly. This could cause a problem when a referenced file path contains a character which must be escaped in a string literal.