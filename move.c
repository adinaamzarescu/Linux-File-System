#include "tema1.h"

void mv(Dir* parent, char *oldname, char *newname) {
    Dir *dir = parent->head_children_dirs, *changed_dir, *prev_dir = NULL;
    File *file = parent->head_children_files, *changed_file, *prev_file = NULL;
    int checker_old = check_existance(parent, oldname);
    int checker_new = check_existance(parent, newname);
    // If checker_new = 0 there is no file/directory
    // with the same name
    if (!checker_new) {
        // If checker_old = 2 the mv function
        // will be applied to a directory
        if (checker_old == 2) {
            while (dir) {
                if (!strcmp(dir->name, oldname)) {
                    changed_dir = dir;
                    // If this is the first dir in the directory
                    // but not the only one
                    if(parent->head_children_dirs == dir) {
                        if (dir->next)
                            parent->head_children_dirs = dir->next;
                    }
                    else
                        // If the directory is any other than the first one
                        prev_dir->next = dir->next;
                    while (dir->next) {
                        // This will find the last dir in the list
                        dir = dir->next;
                    }
                    // Adds the changed directory to the end of the list
                    dir->next = changed_dir;
                    // In order to change its name the memory must be changed as well
                    changed_dir->name = realloc(changed_dir->name, strlen(newname) + 1);
                    strcpy(changed_dir->name, newname);
                    // His next must be empty because now it is the last one
                    changed_dir->next = NULL;
                    break;
                    prev_dir = dir;
                    dir = dir->next;
                }
            }
        } else if (checker_old == 1) {
            while (file) {
                if (!strcmp(file->name, oldname)) {
                    changed_file = file;
                    // If this is the first file in the directory
                    // but not the only one
                    if(parent->head_children_files == file) {
                        if (file->next)
                            parent->head_children_files = file->next;
                    }
                    else
                        // If the file is any other than the first one
                        prev_file->next = file->next;
                    while (file->next) {
                        // This will find the last file in the list
                        file = file->next;
                    }
                    // Adds the changed file to the end of the list
                    file->next = changed_file;
                    // In order to change its name the memory must be changed as well
                    changed_file->name = realloc(changed_file->name, strlen(newname) + 1);
                    strcpy(changed_file->name, newname);
                    // His next must be empty because now it is the last one
                    changed_file->next = NULL;
                    break;
                    prev_file = file;
                    file = file->next;
                }
            }
        } else
            goto fail;
    } else
        goto exists;

    return;
fail:
    printf("File/Director not found\n");
    return;
exists:
    printf("File/Director already exists\n");
}