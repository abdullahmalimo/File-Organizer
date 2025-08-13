#include "FileOrganizer.h"
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

FileOrganizer::FileOrganizer(CategoryManager& manager) : categoryManager(manager) {}

void FileOrganizer::organize(string folderPath, bool simulate) {
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
        cout << "Invalid folder path." << endl;
        return;
    }
    if (fs::is_empty(folderPath)) {
        cout << "The folder is empty, nothing to organize." << endl;
        return;
    }
    unordered_map<string,int> category_cnt;

    //iterate over each entry in the folder, check if file and then categorize
    for (auto& entry : fs::directory_iterator(folderPath)) {
        if (fs::is_regular_file(entry)) {
            string ext = entry.path().extension().string();
            ext.erase(0,1); // remove the initial dot
            for (auto &c : ext) c = tolower(c);
            string category = categoryManager.getCategoryFromExtension(ext);
            fs::path categoryPath = fs::path(folderPath) / category;

            if(!simulate)
                fs::create_directory(categoryPath);

            fs::path newPath = fs::path(categoryPath) / entry.path().filename();

            if (simulate) {
                cout << "[SIMULATE] Would move: " << entry.path().filename()
                     << " -> " << category << endl;
            }
            else {
                fs::rename(entry.path(), newPath);

                cout << "Moved: " << entry.path().filename()
                     << " to " << category << endl;
            }

            category_cnt[category]++;
        }
    }
    //summary of the number of files moved per category.
    for (auto it : category_cnt) {
        cout << it.first << " : " << it.second << (simulate ? " file(s) would be moved\n" : " file(s) moved\n");
    }

    cout << "Organization complete.\n";
}
