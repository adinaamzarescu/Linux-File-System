#ifndef TEMA_H
#define TEMA_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LINE_SIZE 300

struct Dir;
struct File;

typedef struct Dir{
	char *name;
	struct Dir* parent;
	struct File* head_children_files;
	struct Dir* head_children_dirs;
	struct Dir* next;
} Dir;

typedef struct File {
	char *name;
	struct Dir* parent;
	struct File* next;
} File;

// You can find these in:
// init.c
Dir* make_dir(Dir *parent, char *name);
File* make_file(Dir *parent, char *name);
// free_mem.c
void free_file(File *file);
void free_directory(Dir *dir);
void stop (Dir* target);
// create.c
int check_existance(Dir *parent, char *name);
void touch (Dir *parent, char *name);
void mkdir (Dir* parent, char* name);
// list.c
void ls_file(File *file);
void ls_dir(Dir *dir);
void ls (Dir* parent);
void tree (Dir* target, int level);
// remove.c
void rm (Dir* parent, char* name);
void rmdir (Dir* parent, char* name);
// paths.c
void cd(Dir **target, char *name);
void find_path(Dir* target, char *path);
char *pwd (Dir* target);
// move.c
void mv(Dir* parent, char *oldname, char *newname);
