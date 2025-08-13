## Option Chosen

### Option 1 – File Organizer
## How to Run

### 1. Compile with C++17 (optional, if you want to build from source)
Open PowerShell in the project folder and run:

```powershell
g++ -std=c++17 main.cpp FileOrganizer.cpp CategoryManager.cpp -o File_Organizer.exe
```
### 2.Run the program

```powershell
.\File_Organizer.exe
``` 

## Language and Tools
- Language: C++
- Compiler: g++ / MSVC (C++17 compatible)
- IDE: CLion (optional)
- Libraries: <filesystem>, <unordered_map>, <iostream>, <fstream>

## Program Explanation
- Organize files – Moves files in a folder into category subfolders based on extensions.
- Toggle simulation mode – Preview file moves without actually moving files.
- Options menu – Change or Remove categories and extensions.
- Create test folder – Generates dummy files for testing.



## Extra Features
- Simulation mode previews moves without modifying files.

- Options menu to Change Category of extension / Remove Extension.
  ( only persisting through runtime. )

- createTest() generates dummy files for testing different cases.

- Validates user input for extensions and categories 
( categories can include spaces, both can only include alphanumeric characters only. )

## Notes
- Only scans the specified folder (subfolders are ignored).
- Existing folders themselves are ignored.
- Files without a recognized extension go into "Others".
