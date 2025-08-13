#ifndef FILE_ORGANIZER_H
#define FILE_ORGANIZER_H

#include <string>
#include "CategoryManager.h"

class FileOrganizer {
private:
    CategoryManager& categoryManager;

public:
    FileOrganizer(CategoryManager &manager);
    void organize(string folderPath, bool simulate);
};

#endif
