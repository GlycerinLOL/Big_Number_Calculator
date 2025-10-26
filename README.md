# Big Number Calculator

Big Number Calculator is a C++ project that implements arithmetic on arbitrarily large integers (integers that are larger than the built-in types like `long long`).  
It includes:
- a console version (`Project1`)
- a Windows GUI version (`Project1_GUI`)

## Features

- Support for very large integers (not limited by 32-bit or 64-bit ranges)
- Core operations:
  - Addition
  - Subtraction
  - Multiplication
  - Division
- Internal `Number` class to store and manipulate big integers as strings / digit arrays
- `Calculator` class that handles the arithmetic logic between two `Number` objects
- Simple calculator-style GUI using Windows Forms (C++/CLI)

## Project Structure

```text
.
├─ Project1/                # Console / core implementation in standard C++
│  ├─ Number.h / Number.cpp       # Big integer class
│  ├─ Calculator.h / Calculator.cpp  # Operations using Number
│  ├─ mian.cpp                # Demo / entry point (main)
│  └─ Project1.vcxproj        # Visual Studio project file

├─ Project1_GUI/             # GUI version (C++/CLI, Windows Forms)
│  ├─ Project1_GUI.sln
│  ├─ Project1_GUI.vcxproj
│  ├─ MyForm.h / MyForm.cpp   # UI logic and event handlers
│  ├─ Calculator.*            # Same arithmetic logic adapted for GUI
│  ├─ Number.*                # Same big integer class
│  └─ MyForm.resx             # Form layout/resources

└─ Project1.sln              # Top-level Visual Studio solution
```

## Build Instructions

### Requirements
- Windows
- Visual Studio (tested with MSVC toolchain)
- .NET Desktop Development workload (for the GUI project)

### Console Version (`Project1`)
1. Open `Project1.sln` in Visual Studio.
2. Set `Project1` as the startup project.
3. Build and run.

This will run a console program that performs big integer operations.

### GUI Version (`Project1_GUI`)
1. Open `Project1_GUI/Project1_GUI.sln` in Visual Studio.
2. Make sure C++/CLI is enabled in your Visual Studio installation.
3. Build and run.

This launches a Windows Forms calculator that lets you type very large numbers and perform operations through buttons / input fields.

## How It Works (Core Idea)

- **Number class**  
  Represents an arbitrarily large integer.  
  Typical responsibilities:
  - Store digits (usually as a string or vector)
  - Handle sign (+ / -)
  - Normalize representation (remove leading zeros, etc.)

- **Calculator class**  
  Implements operations like `add(Number a, Number b)` and returns a new `Number`.

Because everything is implemented in software, there's no limit like `2^63 - 1`. You can calculate with numbers hundreds or thousands of digits long.

## Status / Notes

- This project is mainly for learning / demonstration: implementing big integer math manually and connecting it to a basic UI.
- Error handling and edge cases (invalid input, divide by zero, etc.) may still need improvement.
- `mian.cpp` in `Project1` is the test driver for the console version.

## License

No explicit license is provided yet.  
If you plan to use or modify this code, please add a license file (for example MIT, GPL, etc.) to clarify reuse terms.
