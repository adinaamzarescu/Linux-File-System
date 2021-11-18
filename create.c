#include "tema1.h"

int check_existance(Dir *parent, char *name) {
    // This function will return 1 if there
    // is a file with the same name
    // and 2 if there is a directory with the same name
    Dir *dir = parent->head_children_dirs;
    File *file = parent->head_children_files;

    // For files
    if (file) {
        if (!strcmp(file->name, name))
            return 1;
        while (file->next) {
            if (!strcmp(file->name, name))
                return 1;
            file = file->next;
        }
        if (!strcmp(file->name, name))
            return 1;
    }
    // For directories
    if (dir)
    {
        if (!strcmp(dir->name, name))
            return 2;
        while (dir->next) {
            if (!strcmp(dir->name, name))
                return 2;
            dir = dir->next;
        }
        if (!strcmp(dir->name, name))
            return 2;
    }
    return 0;
}

void touch (Dir *parent, char *name) {
    File *new_file = make_file(parent, name);
    File *current_file = parent->head_children_files;
    if(!parent->head_children_files) {
        //This checks if this is the first file in the current directory
        if (check_existance(parent, name))
            goto fail;
        parent->head_children_files = new_file;
    } else {
        // This checks if a file/directory with this name already exists
        if (check_existance(parent, name))
            goto fail;
        while(current_file->next) {
            current_file = current_file->next;
        }
        // The loop will stop at the previous file
        // So in order to add the new file in the list of 
        // files, the last file's next has to be changed
        current_file->next = new_file;
    }
    return;

fail:
    printf("File already exists\n");
    // If there is already a file with the same name
    // since the memory was allocated before
    // the file will be freed here,
    free_file(new_file);
    return;  
}

void mkdir (Dir* parent, char* name) {
    // First of all, memory allocation
    Dir *new_dir = make_dir(parent, name);
    Dir *current_dir = parent->head_children_dirs;
    if (!parent->head_children_dirs) {
        // If this is the first directory in the current folder
        if (check_existance(parent, name))
            goto fail;
        parent->head_children_dirs = new_dir;
    } else {
        // This checks if a file/directory with this name already exists
        if (check_existance(parent, name))
            goto fail;
        while(current_dir->next) {
            current_dir = current_dir->next;
        }
        // The loop will stop at the previous directory
        // So in order to add the new directory in the list of 
        // directories, the last directory's next has to be changed
        current_dir->next = new_dir;
    }
    return;
fail:
    printf("Directory already exists\n");
    // If there is already a directory with the same name
    // since the memory was allocated before,
    // the directory will be freed here
    free_directory(new_dir);
    return;
}