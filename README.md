
# Simple Miscellaneous Library

This is my custom library with miscellaneous functions. It is written in C++. All functions are part of `SML` namespace.
Library contains:

- Bit functions
- Math functions
- String functions
- Conversion functions
- Generic parser
- Ring buffer
- Data object
- Logger
- Copier
- Time and Date functions
- Various enum classes, including return statuses


# How to use

This is header-only library and defines and delcarations are separated with `SML_IMPLEMENTATION` macro.
Only one translation unit must have defined `SML_IMPLEMENTATION` before `#include "SML.hpp"`.

Example:

`Main.cpp`
```cpp
#define SML_IMPLEMENTATION
#include "SML.hpp"

// Code here

```

`Other.cpp`
```cpp
#include "SML.hpp"

// Code here

```

# Documentation

Library documentation is available at `Documentation/html/index.html`.


# Examples

Example applications are available at `Examples` folder. All examples are made with STM HAL framework.

# License

Copyright (c) 2023, silvio3105 (www.github.com/silvio3105)

Access and use of this Project and its contents are granted free of charge to any Person.
The Person is allowed to copy, modify and use The Project and its contents only for non-commercial use.
Commercial use of this Project and its contents is prohibited.
Modifying this License and/or sublicensing is prohibited.

THE PROJECT AND ITS CONTENT ARE PROVIDED "AS IS" WITH ALL FAULTS AND WITHOUT EXPRESSED OR IMPLIED WARRANTY.
THE AUTHOR KEEPS ALL RIGHTS TO CHANGE OR REMOVE THE CONTENTS OF THIS PROJECT WITHOUT PREVIOUS NOTICE.
THE AUTHOR IS NOT RESPONSIBLE FOR DAMAGE OF ANY KIND OR LIABILITY CAUSED BY USING THE CONTENTS OF THIS PROJECT.

This License shall be included in all functional textual files.

---

Copyright (c) 2023, silvio3105