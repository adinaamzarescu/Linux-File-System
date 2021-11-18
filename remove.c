#include "tema1.h"

void rm (Dir* parent, char* name) {
    // The check variable is used to see if
    // there is a file having the given name
    int check = 1;
    File *file = parent->head_children_files;
    File *prev = NULL;
    // This finds the file in the list
    // and also checks if the file exists
    if (file) {
        while (strcmp(file->name, name) && check) {
            if (file->next) {
                if (!strcmp(file->next->name, name))
                    check = 0;
            }
            else
                break;
            prev = file;
            file = file->next;
        }
        if(check && strcmp(file->name, name))
            goto fail;
        // In order to link the previous file
        // from the list to the one that succeeds the
        // removed one
        if (prev)
            prev->next = file->next;
        else
            // If the removed file was the first one
            parent->head_children_files = file->next;
        // Now it's time to free the memory that
        // the removed file occupied
        free(file->name);
        free(file);
        return;
    }
    if (check)
        goto fail;
    return;
fail:
    printf("Could not find the file\n");
    return;
}

void rmdir (Dir* parent, char* name) {
    // The check variable is used to see if
    // there is a directory having the given name
    int check = 1;
    Dir *dir = parent->head_children_dirs;
    Dir *prev = NULL;

    // This finds the directory in the list
    // and also checks if the directory exists
    if (dir) {
        while (strcmp(dir->name, name) && check){
            if (dir->next) {
                if (!strcmp(dir->next->name, name))
                    check = 0;
            } else
                break;

            prev = dir;
            dir = dir->next;
        }
        if(check && strcmp(dir->name, name))
            goto fail;
        // In order to link the previous directory
        // from the list to the one that succeeds the
        // removed one
        if (prev)
            prev->next = dir->next;
        else
            // If the removed directory was the first one
            parent->head_children_dirs = dir->next;
        // Now it's time to free the memory that
        // the removed directory occupied
        free_directory(dir);
        dir = NULL;
        return;
    }
    if (check)
        goto fail;
    return;
fail:
    printf("Could not find the dir\n");
    return;
}