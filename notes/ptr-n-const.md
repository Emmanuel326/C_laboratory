 Pointers and Const in C

*Related source:* [intermediate/ptr-n-const.c](../intermediate/ptr-n-const.c)

---

## Overview
This note explains how the const keyword behaves when used with pointers.  
Understanding this relationship helps ensure safe memory operations and prevents unintended data modification.

---

## 1. Pointer to Constant Data
A pointer that can move around (change its target) but cannot modify the value it points to.  
Used when you want read-only access to existing data but still need flexibility to repoint the pointer elsewhere.

---

## 2. Constant Pointer to Data
A pointer whose address cannot change after initialization, but it can modify the data stored at that location.  
Used when a pointer should permanently reference one variable while still allowing updates to that variable’s value.

---

## 3. Constant Pointer to Constant Data
A fully immutable relationship — the pointer cannot move, and the value it points to cannot change.  
Used for defining truly fixed references, often seen in low-level or read-only contexts.

---

## 4. Casting Away Const
Although C allows removing the const qualifier using a cast, modifying such memory is undefined behavior.  
The compiler may optimize assuming the value never changes, leading to crashes or inconsistent results.  
This practice should be avoided entirely except in controlled, legacy, or hardware-specific cases.

---

## 5. Practical Uses
- Preventing accidental modification of function arguments.  
- Creating read-only buffers or message strings.  
- Protecting internal data structures by enforcing immutability.  
- Working safely with hardware registers in embedded systems (volatile const).

---

## 6. Key Insights
- const applies to what lies *immediately on its right* in a declaration.  
- Clarity and safety come before style — but consistent use improves readability.  
- The English-style form (const int x) is more readable and commonly preferred.  
- Avoid casting away constness unless absolutely necessary.

---

*For demonstrations and examples, see:*  
👉 [intermediate/ptr-n-const.c](../intermediate/ptr-n-const.c)
