#include "tema1.h"

void cd(Dir **target, char *name) {
    // First of all it checks if the directory the
    // user wants to go to is the previous one
    if (!strcmp(name, "..")) {
        if ((*target)->parent)
            (*target) = (*target)->parent;
        return;
    }
    // This checks in the list of directories
    Dir *dir = (*target)->head_children_dirs;
    while(dir) {
        if (!strcmp(dir->name, name)) {
            *target = dir;
            return;
        }
        dir = dir->next;
    }
    // In case it found nothing, it will print the message
    printf("No directories found!\n");
}

void find_path(Dir* target, char *path){
    Dir *dir = target->parent;
    if (dir->parent)
        find_path(dir, path);
    // Every parent found will be attached to
    // the current path
    strcat(path, "/");
    strcat(path, target->name);
}

char *pwd (Dir* target) {
    char *path = malloc(MAX_INPUT_LINE_SIZE);
    // Since every path will begin with home
    strcpy(path, "/home");
    // This checks if the current directory is
    // the home directory
    if (target->parent)
        // In order to find the path, the program
        // is using a recursive function
        find_path(target, path);
    return path;
}