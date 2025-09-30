# HuffmanHeap

HuffmanHeap is a C project that builds and manipulates a **min-heap-based binary tree**, primarily designed for operations related to **Huffman encoding** and symbol decoding.  
It provides several case functions (`-c1`, `-c2`, `-c3`, `-c4`) that allow traversal, encoding, and searching operations on the tree.

---

## 📂 Project Structure
- **`main.c`** – Handles input/output, builds the min-heap, and dispatches to the correct case function.  
- **`case_function.c`** – Implements the main operations:
  - Level-order printing of the tree.
  - Decoding of encoded sequences.
  - Searching for codes corresponding to symbols.
  - Multi-string searching in the tree.  
- **`functions_heap.c`** – Provides the min-heap implementation and utility functions:
  - Insert and extract operations.
  - Heap construction.
  - Recursive searches.
  - Memory cleanup.

---

## ⚙️ Features
- **Min-Heap Construction** – Creates a binary tree from weighted nodes.  
- **Tree Traversals** – Supports level-order traversal (BFS).  
- **Encoding/Decoding** – Works with binary codes (`0` for left, `1` for right) to encode or decode symbols.  
- **Search Functions** –  
  - Find the binary code for a given symbol.  
  - Find the smallest tree node containing all queried substrings.  

---

## 🚀 Usage

### 🔨 Compilation
```bash
gcc main.c case_function.c functions_heap.c -o huffmanheap
