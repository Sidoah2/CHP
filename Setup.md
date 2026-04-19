# 📘 How to Compile and Run `exoTest.c` (GCC + OpenMP)

This document explains how to compile and run a C program named `exoTest.c` using GCC (MinGW-w64) on Windows.

---

# 🧾 1. Prerequisites

Before starting, make sure you have:

* GCC installed (MinGW-w64)
* `gcc` available in PATH
* A C file named:

```c
exoTest.c
```

---

# ⚙️ 2. Compile the program

Open PowerShell or CMD in the folder where your file is located:

```powershell
cd C:\Users\sidoa\Downloads\CHP
```

Then compile using:

```powershell
gcc -fopenmp exoTest.c -o exoTest.exe
```

---

# 📌 Explanation

* `gcc` → GNU Compiler
* `-fopenmp` → enables OpenMP (for parallel programming)
* `exoTest.c` → source file
* `-o exoTest.exe` → output executable file

⚠️ Important: Never use the same name for input and output.

---

# ▶️ 3. Run the program

After successful compilation:

```powershell
.\exoTest.exe
```

---

# 🧠 4. Full Workflow (One Line)

You can compile and run directly:

```powershell
gcc -fopenmp exoTest.c -o exoTest.exe && .\exoTest.exe
```

---

# ❌ Common Errors

## 1. Same input and output file

```text
gcc: fatal error: input file is the same as output file
```

✔ Fix:

```powershell
gcc exoTest.c -o exoTest.exe
```

---

## 2. gcc not recognized

✔ Fix:

* Add MinGW `bin` folder to PATH

Example:

```
C:\mingw64\bin
```

---

## 3. OpenMP not working

✔ Ensure you use:

```powershell
-fopenmp
```

---

# 🎯 Summary

| Step    | Command                                 |
| ------- | --------------------------------------- |
| Compile | `gcc -fopenmp exoTest.c -o exoTest.exe` |
| Run     | `./exoTest.exe`                         |

---

# 🚀 Done

Now you can compile and run any C O
