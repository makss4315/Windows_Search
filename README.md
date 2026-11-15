# Windows Search

A console application for Windows that searches a drive for files and directories by their exact name. Built with C++23 and `std::filesystem`.

## Features

- Recursively scan a selected drive.
- Find files and directories by exact, case-sensitive name.
- Display file paths and sizes in bytes while scanning.
- Search previously saved file paths before starting a new scan.
- Save scanned file paths to `indexPool.txt` after a completed scan.
- Skip recursion into entries named `Recovery` or starting with `$`.
- Use `skip_permission_denied` when traversing directories.
- Display elapsed scan time in milliseconds.

## Requirements

- Windows.
- CMake 4.2 or newer, as required by `CMakeLists.txt`.
- A C++ compiler with C++23 support, such as a compatible MSVC toolchain.
- Git, if cloning the repository from the command line.

## Build

Clone the repository and configure the project:

```powershell
git clone https://github.com/makss4315/Windows_Search.git
cd Windows_Search
cmake -S . -B build
cmake --build build --config Release
```

With a Visual Studio multi-configuration generator, run:

```powershell
.\build\Release\findSystem.exe
```

With a single-configuration generator, the executable is typically located at `build\findSystem.exe`.

## Usage

1. Enter a drive letter without a colon or slash, such as `C` or `D`.
2. Enter the exact file or directory name. Include the extension when searching for a file, for example `report.pdf`.
3. Review matches from the saved index, followed by results from the live drive scan.
4. Press a key when the application pauses after a live match to continue scanning.

Example input:

```text
pls enter ur disk Name
D
Pls enter the target: report.pdf
```

A live match is displayed with the following prefix:

```text
[target find]D:/Documents/report.pdf
```

The application also pauses before closing.

## How the Index Works

`indexPool.txt` is stored in the current working directory—the directory from which the application is launched.

At startup, the application reads this file and compares the filename in each saved path with the requested name. It then scans the selected drive even if the index already contains a match.

After a completed scan, the index is overwritten with the regular-file paths collected during that scan. Directory paths are not saved. If the selected root cannot be opened, the scan returns without overwriting the existing index.

On the first run, a message indicating that the index cannot be opened is expected if `indexPool.txt` does not exist yet. The drive scan still proceeds.



## Project Structure

```text
Windows_Search/
├── CMakeLists.txt               # Build configuration and CTest registration
├── main.cpp                     # Console input and search workflow
├── FileSearch.h                 # Search function declarations
├── FileSearch.cpp               # Drive traversal and index handling
```
