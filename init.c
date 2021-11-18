#include "tema1.h"

Dir* make_dir(Dir *parent, char *name) {
    // First of all, memory allocation
    Dir *new_dir = malloc(sizeof(*new_dir));
    if (!new_dir)
        goto fail;

    new_dir->name = malloc(MAX_INPUT_LINE_SIZE);
    if (!new_dir->name)
        goto fail;
    
    // Now the initializations
    memcpy(new_dir->name, name, strlen(name) + 1);
    new_dir->parent = parent;
    new_dir->next = NULL;
    new_dir->head_children_dirs = NULL;
    new_dir->head_children_files = NULL;

    return new_dir;
fail:
    printf("Malloc for home failed\n");
    return NULL;
}

File* make_file(Dir *parent, char *name) {
    // First of all, memory allocation
    File *new_file = malloc(sizeof(*new_file));
    if (!new_file)
        goto fail;
    
    new_file->name = malloc(MAX_INPUT_LINE_SIZE);
    if (!new_file->name)
        goto fail;

    // Now the initializations
    memcpy(new_file->name, name, strlen(name) + 1);
    new_file->parent = parent;
    new_file->next = NULL;

    return new_file;

fail:
    printf("Malloc for file failed\n");
    return NULL;
}
