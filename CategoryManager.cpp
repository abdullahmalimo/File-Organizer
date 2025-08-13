#include "CategoryManager.h"
#include <iostream>
#include <algorithm>
using namespace std;
CategoryManager::CategoryManager() {
    extensionMap = {
        {"jpg", "Images"}, {"jpeg", "Images"}, {"png", "Images"}, {"gif", "Images"},
        {"mp4", "Videos"}, {"mov", "Videos"}, {"avi", "Videos"},
        {"pdf", "Documents"}, {"docx", "Documents"}, {"txt", "Documents"}
    };
}

//remove spaces
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

//check file name is valid, spaces not allowed for extensions but are ok for category folder names.
bool isValidName(string name, bool allowSpaces) {
    name = trim(name);
    if (name.empty()) return false;

    for (char c : name) {
        if (!isalnum(static_cast<unsigned char>(c))) {
            if (allowSpaces && c == ' ') continue;
            return false;
        }
    }
    return true;
}

string CategoryManager::getCategoryFromExtension(string ext)  {

    auto it = extensionMap.find(ext);
    if (it != extensionMap.end()) {
        return it->second;
    }
    return "Others";
}

//adds existing or completely new extension to category
void CategoryManager::changeCategory(string category, string extension) {
    if (!isValidName(extension,false)) {
        cout << "Please enter valid extension name." << endl;;
        return;
    }
    if (!isValidName(category,true)) {
        cout << "Please enter valid category name." << endl;
        return;
    }
    extensionMap[extension] = category;
    cout << "Added: ." << extension << " -> " << category << "\n";
}

// completely removes extension
void CategoryManager::removeExtension(string extension) {
    if (extensionMap.erase(extension)) {
        cout << "Removed extension: ." << extension << "\n";
    } else {
        cout << "Extension not found.\n";
    }
}


void CategoryManager::showCategories()  {
    for (auto it : extensionMap) {
        cout << "." << it.first << " -> " << it.second << "\n";
    }
}


