#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include "CategoryManager.h"
#include "FileOrganizer.h"
using namespace std;
namespace fs = filesystem;


//creates a test folder for some edge cases
void createTest()
{
    string folderPath;
    cout << "Enter folder path: ";
    cin >> folderPath;

    if (!fs::exists(folderPath) || !fs::is_directory(folderPath))
    {
        cout << "Invalid folder path" << endl;
        return;
    }

    fs::path testDir = fs::path(folderPath) / "TestFolder";

    if (fs::exists(testDir)) {
        cout << "Test folder already exists, deleting it first...\n";
        fs::remove_all(testDir);
    }

    fs::create_directory(testDir);

    // Files: name → description
    vector<string> files = {
        "photo1.JPG",          // Uppercase extension
        "photo2.png",          // Lowercase extension
        "video1.mp4",
        "clip.AVI",            // Uppercase extension
        "doc1.pdf",
        "notes.txt",
        "report.docx",
        "random.bin",          // Unknown extension
        "README",              // No extension
        ".hiddenfile",         // Hidden file (no extension)
        "archive.tar.gz",      // Multiple dots
        "multi.part.name.txt", // Multiple dots
        "file with spaces.txt",// Spaces in name
        "file@special#chars!.mp3", // Special characters
        "longfilename_" + string(50, 'x') + ".txt", // Very long name
        ".gitignore",          // Dotfile with extension
        "duplicate.ext",
        "duplicate.EXT"        // Same name diff case
    };

    for (const auto& file : files) {
        fs::path filePath = testDir / file;
        ofstream(filePath) << "Dummy content for " << file;
    }

    // Empty subfolder
    fs::create_directory(testDir / "EmptyFolder");

    // Subfolder with files
    fs::path subDir = testDir / "SubFolder";
    fs::create_directory(subDir);
    ofstream(subDir / "subfile.txt") << "Inside subfolder";

    cout << "Test folder created at: " << fs::absolute(testDir) << "\n";
}




int main() {
    CategoryManager categoryManager;
    FileOrganizer organizer(categoryManager);
    int choice;
    string folderPath;
    bool simulate = 0;
    do
    {

        cout << "\n=== File Organizer Menu ===\n"
         << "1) Organize files\n"
         << "2) Toggle simulation mode (currently " << (simulate ? "ON" : "OFF") << ")\n"
         << "3) Options menu\n"
         << "4) Create Test Folder\n"
         << "0) Exit\n"
         << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 0:
                "Exiting";
                break;
            case 1:

                cout << "Enter folder path: ";
                getline(cin >> ws, folderPath);
                organizer.organize(folderPath, simulate);
                break;
            case 2:
                simulate = !simulate;
                cout << "Simulation mode is now: " << (simulate ? "ON" : "OFF") << endl;
                break;
            case 3:
                cout << "\nOptions Menu:\n"
                  << "1) Change Category Of Extension\n"
                  << "2) Remove Extension\n"
                  << "3) Show categories\n"
                  << "0) Back to main menu\n";
                int optChoice;
                do
                {
                    cin >> optChoice;
                    string ext,cat;
                    switch(optChoice)
                    {
                        case 1:
                            cout << "Enter Extension (without .): ";
                            getline(cin >> ws, ext);
                            cout << "Enter Category: ";
                            getline(cin >> ws, cat);
                            categoryManager.changeCategory(cat,ext);
                            break;
                        case 2:
                            cout << "Enter Extension (without .): ";
                            cin >> ext;
                            categoryManager.removeExtension(ext);
                            break;
                        case 3:
                            categoryManager.showCategories();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid Choice. Try Again" << endl;
                    }
                }while (optChoice!=0);
                break;
            case 4:
                createTest();
                break;
            default:
                cout << "Invalid choice. Try again" << endl;
        }
    }while (choice != 0);

    return 0;
}