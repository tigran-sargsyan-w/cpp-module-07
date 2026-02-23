# cpp-module-07
This module is designed to help you understand templates in C++.

# 🧩 C++ Templates — Important Notes & Nuances (C++98)

Templates in C++ are **compile-time blueprints**.
They become real code only when the compiler sees a **concrete type** (`int`, `std::string`, your class, etc.).

---

## 🧠 Core Rule: “Template code must be visible”

### ✅ Why templates live in `.hpp`

The compiler must see the **full implementation** at the place where it instantiates the template.

If you put template definitions only in `.cpp`, you often get linker errors like:

* `undefined reference to swap<int>(...)`
* `undefined reference to Array<std::string>::operator[](...)`

✅ Typical solutions:

* Put everything in `.hpp`
* Or split into `.hpp` + `.tpp/.ipp` and `#include` the `.tpp` from the `.hpp`

---

## 🔧 Function Templates (swap / min / max)

Function templates generate functions for the used types.

**Key nuance (Module 07 ex00):**

* `min/max` usually must return **by const reference** (`T const &`)
* If values are equal, **subject may require returning the second argument**

  * Use `<=` / `>=` to guarantee that behavior

**Hidden requirement:**

* `min/max` need a valid comparison operator (`<`, `<=`, etc.)
* `swap` needs copy/assignment to exist

---

## 🧱 Class Templates (Array<T>, Vector<T>)

Class templates generate **different types**:

* `Array<int>` and `Array<std::string>` are two different classes.

**Where methods are implemented:**

* Usually in `.hpp` (or `.tpp` included from `.hpp`)

**Common pitfall:**

* putting methods in `.cpp` without explicit instantiation → linker errors

---

## 🧰 Member Function Templates

A class can have a method that is itself templated.

✅ Useful when:

* the class is “fixed”, but one method must accept many types

---

## 🚫 Variable Templates (Not in C++98)

Variable templates exist only since **C++14**.

In C++98, the old workaround is:

* `static const` inside a templated struct/class

---

## ⚠️ Template Compilation “Gotchas”

* Templates are generated **only for types actually used**
* Error messages can look scary because they show “instantiation traces”
* Template code often requires:

  * copy constructor / assignment
  * comparison operators (`<`, `<=`, `>`, `>=`)
  * stream output (`operator<<`) if you print the type

