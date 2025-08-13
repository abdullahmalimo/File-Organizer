#ifndef CATEGORY_MANAGER_H
#define CATEGORY_MANAGER_H

#include <string>
#include <unordered_map>
using namespace std;

class CategoryManager {
private:
    unordered_map<string, string> extensionMap;

public:
    CategoryManager();

    string getCategoryFromExtension(string ext);
    void changeCategory(string category, string extension);
    void removeExtension(string extension);
    void showCategories();
};

#endif
