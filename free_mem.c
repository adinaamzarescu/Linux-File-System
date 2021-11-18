#include "tema1.h"

void free_file(File *file) {
    if (!file)
        return;
    if (file->next) {
        free_file(file->next);
    }
    free(file->name);
    free(file);
}

void free_directory(Dir *dir) {
    if (!dir)
        return;
    // To free the memory for all the directories
    Dir *new_dir = dir->head_children_dirs;
    Dir *prev_dir = NULL;
    while (new_dir) {
        prev_dir = new_dir;
        new_dir = new_dir->next;
        free_directory(prev_dir);
    }
    free_file(dir->head_children_files);
    free(dir->name);
    free(dir);
}

void stop (Dir* target) {
    free_directory(target);
}