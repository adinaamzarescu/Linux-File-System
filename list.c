#include "tema1.h"

void ls_file(File *file) {
    if(file) {
        printf("%s\n", file->name);
        if (file->next)
            ls_file(file->next);
    }
}

void ls_dir(Dir *dir) {
    if(dir) {
        printf("%s\n", dir->name);
        if (dir->next)
            ls_dir(dir->next);
    }
}

void ls (Dir* parent) {
    ls_dir(parent->head_children_dirs);
    ls_file(parent->head_children_files);
}

void tree (Dir* target, int level) {
    // First the program will show the directories
    Dir *dir = target->head_children_dirs;
    while (dir) {
        // In order to add the spaces
        int level_now = level;
        while (level_now) {
            printf("    ");
            --level_now;
        }
        printf("%s\n", dir->name);
        // For each directory, it will do the same for
        // the sub-directories
        tree(dir, level + 1);
        dir = dir->next;
    }
    // For the files it will only need to
    // print them with the correct spacing
    File *file = target->head_children_files;
    while (file) {
        int level_now = level;
        while (level_now) {
            printf("    ");
            --level_now;
        }
        printf("%s\n", file->name);
        file = file->next;
    }
}