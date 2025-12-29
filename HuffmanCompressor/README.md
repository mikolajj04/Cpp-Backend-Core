# Huffman Compressor (C++)

A standalone data compression tool based on the **Huffman Coding algorithm**. This project was developed to master custom data structures, priority-based processing, and binary tree serialization in a backend-oriented context.

### 🚀 Key Features
- **Prefix-free Encoding:** Automatically generates optimal binary codes based on character frequency.
- **Symmetric Decoding:** Restores original files using an embedded Huffman code table.
- **CLI Interface:** Professional command-line handling for automated workflows.
- **Doxygen Documented:** Fully commented source code with a generated API reference guide.

### 🛠 Technical Architecture
| Component | Logic | Technical Detail |
| :--- | :--- | :--- |
| **Frequency Analysis** | `std::unordered_map` | Counts character occurrences in $O(n)$ time]. |
| **Tree Construction** | `std::priority_queue` | Builds the Huffman tree using a min-heap approach. |
| **Code Generation** | Recursive Traversal | Assigns '0' for left and '1' for right branches. |
| **File I/O** | `std::fstream` | Binary mode processing for data integrity. |

### 📖 Usage
The application accepts the following command-line arguments:
- `-i <input_file>`: Path to the source file.
- `-o <output_file>`: Path for the result.
- `-c`: Execute compression (encode).
- `-d`: Execute decompression (decode).

**Example:**
```bash
# Compress
./HuffmanV1 -i input.txt -o output.txt -c
# Decompress
./HuffmanV1 -i output.txt -o restored.txt -d
