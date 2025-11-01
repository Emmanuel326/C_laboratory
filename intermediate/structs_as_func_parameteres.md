# 🧱 Structs as Function Parameters in C

Structs are user-defined data types that let you group multiple related variables into a single unit.  
When working with structs inside functions, there are **two main ways** to pass them:

1. **By Value**  
2. **By Reference (Pointer)**

---

## 🧩 1. Passing Structs by Value

When you pass a struct **by value**, the function receives a **copy** of the original struct.  
This means any modification done inside the function affects **only the copy**, not the original data.

**Conceptually:**

function process(copy_of_struct)
copy_of_struct.member += something
end

main:
original_struct = {...}
process(original_struct)
// original_struct remains unchanged




**Characteristics:**
- Each member of the struct is duplicated when passed.
- Memory consumption increases with large structs.
- Useful when you want to protect the original data.

**Analogy:**  
Think of it as giving someone a **photocopy** of your document.  
They can scribble on it all they want — your original remains safe.

---

## ⚙️ 2. Passing Structs by Reference (Using Pointers)

When you pass a struct **by reference**, you give the function the **address** of the original struct.  
This allows direct access and modification of the real data.

**Conceptually:**

function process(reference_to_struct)
reference_to_struct->member += something
end

main:
original_struct = {...}
process(&original_struct)
// original_struct is modified





**Characteristics:**
- Only the **address** (pointer) is passed — not the full data.
- More **memory-efficient**, especially for large structs.
- Changes inside the function **affect the original**.

**Analogy:**  
Think of it as giving someone the **actual folder** — they can edit the real document inside.

---

## 🧠 When to Use Each

| Scenario | Recommended Method | Reason |
|-----------|--------------------|--------|
| Struct is small and temporary | Pass by Value | Simpler and safer |
| Struct is large or reused | Pass by Reference | Saves memory and time |
| You need to protect the original data | Pass by Value | Avoids unintended changes |
| You want to update original values | Pass by Reference | Allows modification |

---

## 🧩 3. Real-World Example Concept

Imagine you have a struct `Book` with fields like title, author, year, and price.  
You might:

- **Display** book details (read-only → pass by value)
- **Update** the book price (modify → pass by reference)

**Pseudocode:**





