# C++ Module 07 – Templates 🧩📦

✅ **Status**: Completed – all mandatory exercises  
🏫 **School**: 42 – C++ Modules (Module 07)  
🏅 **Score**: (score)/100  

> *Function templates, template parameters, generic utilities (`swap/min/max`), applying a function to array elements (`iter`), and building a safe dynamic array class template (`Array<T>`).*

---

## 📚 Table of Contents

* [Description](#-description)
* [Goals of the Module](#-goals-of-the-module)
* [Templates Notes & Nuances](#-c-templates--important-notes--nuances-c98)
* [Exercises Overview](#-exercises-overview)

  * [ex00 – Start with a few functions](#ex00--start-with-a-few-functions)
  * [ex01 – Iter](#ex01--iter)
  * [ex02 – Array](#ex02--array)
* [Requirements](#-requirements)
* [Build & Run](#-build--run)
* [Repository Layout](#-repository-layout)
* [Testing Tips](#-testing-tips)
* [42 Notes](#-42-notes)

---

## 📝 Description

This repository contains my solutions to **42’s C++ Module 07 (C++98)**.

Module 07 is dedicated to **C++ templates** — writing code that works with **any type** as long as the type supports the required operations (comparisons, assignments, etc.).
It introduces both **function templates** and **class templates**, and focuses on building safe and reusable generic components.

All exercises are written in **C++98** and compiled with strict flags (`-Wall -Wextra -Werror -std=c++98`).

---

## 🎯 Goals of the Module

Concepts covered:

* **Function templates** and type deduction
* Writing generic utilities (`swap`, `min`, `max`)
* Template functions that accept **function pointers**
* Supporting both **const** and **non-const** contexts
* **Class template** design and memory ownership
* **Deep copy** (copy constructor + assignment operator)
* Implementing `operator[]` with **bounds checking + exceptions**
* Avoiding memory leaks with correct allocation/deallocation (`new[]` / `delete[]`)

---

## 🧩 C++ Templates — Important Notes & Nuances (C++98)

Templates in C++ are **compile-time blueprints**.
They become real code only when the compiler sees a **concrete type** (`int`, `std::string`, your own class, etc.).

---

### 🧠 Core Rule: “Template code must be visible”

#### ✅ Why templates live in `.hpp`

The compiler must see the **full implementation** at the place where it instantiates the template.

If you put template definitions only in `.cpp`, you often get linker errors like:

* `undefined reference to swap<int>(...)`
* `undefined reference to Array<std::string>::operator[](...)`

✅ Typical solutions:

* Put everything in `.hpp`
* Or split into `.hpp` + `.tpp/.ipp` and `#include` the `.tpp` from the `.hpp`

---

### 🔧 Function Templates (swap / min / max)

Function templates generate functions for the used types.

**Key nuance (Module 07 ex00):**

* `min/max` should return **by const reference** (`T const &`)
* If values are equal, the subject requires returning the **second argument**

  * Use `<=` / `>=` to guarantee that behavior

**Hidden requirement:**

* `min/max` require a valid comparison operator (`<`, `<=`, etc.)
* `swap` requires copy/assignment to exist for the type

---

### 🧱 Class Templates (Array<T>)

Class templates generate **different types**:

* `Array<int>` and `Array<std::string>` are two different classes.

**Where methods are implemented:**

* Usually in `.hpp` (or `.tpp` included from `.hpp`) — because the implementation must be visible at instantiation time.

**Common pitfall:**

* putting methods in `.cpp` without explicit instantiation → linker errors

---

### 🧰 Member Function Templates

A class can have a method that is itself templated.

✅ Useful when:

* the class type is “fixed”, but one method must accept many different types.

---

### 🚫 Variable Templates (Not in C++98)

Variable templates exist only since **C++14**.

In C++98, the classic workaround is:

* `static const` inside a templated struct/class

---

### ⚠️ Template Compilation “Gotchas”

* Templates are generated **only for types actually used**
* Error messages can look scary because they show “instantiation traces”
* Template code often requires the type to support:

  * copy constructor / assignment
  * comparison operators (`<`, `<=`, `>`, `>=`)
  * stream output (`operator<<`) if you print the type

---

## 📦 Exercises Overview

### ex00 – Start with a few functions

> Implement classic generic helpers as function templates.

**Goal:**
Implement these **function templates**:

* `swap(T &a, T &b)` — swaps values (no return)
* `min(const T &a, const T &b)` — returns the **smaller** one

  * If equal → returns the second argument
* `max(const T &a, const T &b)` — returns the **greater** one

  * If equal → returns the second argument

**Example usage (from subject):**

```bash
$ ./whatever
a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2
```

**Concepts practiced:**

* Template implementation must be visible (header-only)
* Type deduction and generic behavior
* Correct equality rule (equal → return the second)

---

### ex01 – Iter

> Apply a function to each element of an array.

**Goal:**
Implement a function template:

```cpp
iter(arrayPtr, length, function);
```

* 1st param: **address of an array**
* 2nd param: **length** (passed as const)
* 3rd param: **function** called on every element

**Key requirement:**
Your `iter` must support both:

* arrays of **non-const** elements (function takes `T&`)
* arrays of **const** elements (function takes `const T&`)

**Concepts practiced:**

* Function pointer as template parameter
* Const-correctness in generic code
* Reusable iteration over raw arrays

---

### ex02 – Array

> Build a minimal safe dynamic array class template.

**Goal:**
Implement a class template `Array<T>` with:

* Default constructor → **empty array**
* Constructor `(unsigned int n)` → array of **n default-initialized elements**
* Copy constructor + assignment operator (**deep copy**)
* `operator[]` for element access

  * If index is out of bounds → throw `std::exception`
* `size()` → returns number of elements, does not modify the instance

**Constraints:**

* Must allocate using **`new[]`**
* No “preventive allocation” (no extra capacity)
* Must never access non-allocated memory

**Concepts practiced:**

* Class templates + optional `.tpp`
* Rule of Three and ownership safety
* Exception-safe bounds checking

---

## 🛠 Requirements

From the official rules:

* **Compiler**: `c++`
* **Flags**: `-Wall -Wextra -Werror` and compatible with `-std=c++98`
* **No external libraries**, no C++11/Boost
* Template implementations must be available in headers (or included `.tpp`)

---

## ▶️ Build & Run

Clone the repository and build each exercise separately.

```bash
git clone <this-repo-url>
cd cpp-module-07
```

### ex00

```bash
cd ex00
make
./whatever
```

### ex01

```bash
cd ex01
make
./iter
```

### ex02

```bash
cd ex02
make
./array
```

> Executable names can differ depending on implementation.

---

## 📂 Repository Layout

```text
cpp-module-07/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   └── whatever.hpp
│
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   └── iter.hpp
│
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── Array.hpp
    └── Array.tpp      # optional (template implementation)
```

---

## 🔍 Testing Tips

* **ex00**

  * Test with `int`, `std::string`, and custom types (with comparison operators)
  * Verify the **equal → return second** rule for `min/max`

* **ex01**

  * Test with `int[]`, `std::string[]`
  * Test both:

    * function that takes `T&` (can modify elements)
    * function that takes `const T&` (read-only)
  * Also test with a `const` array to confirm const correctness

* **ex02**

  * Check deep copy:

    * copy an array, modify original, verify copy does not change
  * Check bounds:

    * `arr[size]` must throw
  * Check default initialization:

    * `Array<int>(n)` contains default values (typically 0)

---

## 🧾 42 Notes

* C++ modules do not use Norminette, but clean and readable code is still expected during evaluation.
* Template rule: implementations must be visible at compile time (header or included `.tpp`).
* Module 07 is meant to practice the “core” template mechanics without relying on STL containers.

---

If you’re a 42 student working on the same module, feel free to explore the code, get inspired, but **write your own implementation** — that’s where the real learning happens. 🚀
