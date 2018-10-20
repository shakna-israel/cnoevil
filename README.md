# CNoEvil - A Language Extension for C

---

This is a pet project of mine, abusing the hell out of the C pre-processor, and other C language features, to create a language that is still technically C, but looks and behaves differently, whilst remaining fully compatible with C.

It takes a whole lot of bad ideas and mashes them into an abhorrent monstrosity.

```
#define EVIL_IO
#include "evil.h"

Main then
  displayln("Hello, World!");
end
```

---

## Usage

CNoEvil is contained into a single C header file, [evil.h](evil.h). Drop that file somewhere in your include path.

Define which modules you want to use, or not use, and then include it.

```
#define EVIL_IO
#define EVIL_NO_CONSTANT
#include "evil.h"

Main then
  displayln("It works!");
end
```

For the full usage, compile and run:

```
#define EVIL_HELP
#include "evil.h"

Main then
  evil_manual();
end
```

For individual help, compile and run:

```
#define EVIL_HELP
#include "evil.h"

Main then
  evil_explain("constant");
end
```

Where the string is the name of what you wish to look up.

If that still fails you, open an [Issue on GitHub](https://github.com/shakna-israel/cnoevil/issues), and I'll try and help.

---

## License

... You actually want to use this?

Really?

Okay... See [LICENSE.md](LICENSE.md).
