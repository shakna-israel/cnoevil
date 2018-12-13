# CNoEvil - A Language Extension for C

---

Master: [![Build Status](https://travis-ci.org/shakna-israel/cnoevil.svg?branch=master)](https://travis-ci.org/shakna-israel/cnoevil)

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

You will need a C compiler capable of the C11 standard, and some optional features may require a GNU compiler.

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

## Versioning

I plan to have very feature and every bugfix have it's own number increment, so numbers may rapidly increase.

I'm roughly following semantic versioning.

Thus:

```MAJOR.FEATURE.BUGFIX```

```MAJOR``` will only change with breaking API behaviour, and will be avoided.

```FEATURE``` will bump every time something new is added to the library.

```BUGFIX``` will bump every time we get a new bugfix.

```FEATURE``` and ```BUGFIX``` will only ever revert to ```0``` if ```MAJOR``` increments. 

So, for example, this kind of version would be possible:

```1.256.893```

---

## License

... You actually want to use this?

Really?

Okay... See [LICENSE.md](LICENSE.md).
