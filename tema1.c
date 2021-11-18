// Copyright 2021 Adina-Maria Amzarescu 321CA
#include "tema1.h"

int main(void) {
    char *command = malloc(MAX_INPUT_LINE_SIZE);
    if (!command)
        goto fail;
    char *name = malloc(MAX_INPUT_LINE_SIZE);
    if (!name)
        goto fail;

    // Everything will be done in the "home" directory
    // so before everything, the program will create it
    Dir *target = make_dir(NULL, "home");
    // The program will run for as long as the user wants
    // This is why it is used an infinite loop
    do {
        scanf("%s", command);
        if (!strcmp(command, "touch"))
        {
            scanf("%s", name);
            touch (target, name);
        }
        else if (!strcmp(command, "mkdir"))
        {
                scanf("%s", name);
                mkdir(target, name);
        }
        else if (!strcmp(command, "ls"))
            ls(target);
        else if (!strcmp(command, "rm")) {
            scanf("%s", name);
            rm(target, name);
        }
        else if (!strcmp(command, "rmdir")){
            scanf("%s", name);
            rmdir(target, name);
        }
        else if (!strcmp(command, "cd"))
        {
            scanf("%s", name);
            cd(&target, name);
        }
        else if (!strcmp(command, "tree")) {
            tree(target,0);
        }
        else if (!strcmp(command, "pwd")) {
            char *path = pwd(target);
            printf("%s", path);
            free(path);
        }
        else if (!strcmp(command, "mv")) {
            char *oldname = malloc(MAX_INPUT_LINE_SIZE);
            char *newname = malloc(MAX_INPUT_LINE_SIZE);
            scanf("%s", oldname);
            scanf("%s", newname);
            mv(target, oldname, newname);
            free(newname);
            free(oldname);
        }
        else if (!strcmp(command, "stop"))
        {
            while(target->parent)
                target = target->parent;
		    stop(target);
            target = NULL;
            break;
        }
    } while (1);

    free(command);
    command = NULL;
    free(name);
    name = NULL;
    return 0;
fail: 
    printf("Malloc failed");
}
