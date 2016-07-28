/*
 *
 * Version 1.0
 * Functionality : Virtual file system(vfs)
 * In version 1 the file system is dynamic, ie its size expands when new files are added into the system
 * In version 1 the header of the vfs store limited info
 *
 * Header file
 * 
 *  Design Patter : State based model.
 *  Structure vfs stores the state of vfs.
 *
 */

#ifndef VFS_H_
#define VFS_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 30 // Maximum length of the file names
#define MAX_FILES 10
#define VFS_OPEN 0
#define VFS_CLOSE 1

struct vfs_file_info{
        char fname[MAX_LEN];
	long offset;
	long file_size;
};

struct vfs_info{
        char vfs_name[MAX_LEN];
        int num_files;
	long offset;
        //int size; // size of the file system is fixed in v1.0
};

struct vfs_header_info{
        struct vfs_info vfs_info;
        struct vfs_file_info vfs_files[MAX_FILES];
};

struct vfs{
	struct vfs_header_info header;
	FILE *vfs_fp;
	int vfs_status;
};

// A total of 5 functions
int vfs_create(char *name_with_path);
int vfs_open(char *name_with_path); //load vfs
int vfs_save(char *name_with_path);
int vfs_close();
int vfs_extract(char *saved_name,char *name_with_path);
void info();
int vfs_unload(char *name_with_path);

#endif
