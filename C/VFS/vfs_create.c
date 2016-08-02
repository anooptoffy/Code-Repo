#include "vfs.h"

extern struct vfs _vfs;
int vfs_create(char *name_with_path){
	int status = 0;	// 0 for success and 1 for failure

	printf("\n[INFO] Creating new VFS ... ");
	printf("\n[DEBUG] File Name : %s", name_with_path);
	
	FILE *fp;
	fp = fopen(name_with_path,"r");
	if(fp != NULL)
	{
		fclose(fp);
		status = 1;
	}
	else{
		fp = fopen(name_with_path,"w+");
		if(fp == NULL){
			printf("\nUnable to open the file");
		}
		struct vfs_info _vf;
		struct vfs_header_info _hf; 
		strcpy(_vf.vfs_name,"My VFS");
		_vf.num_files = 0;
		_vf.offset = 2048; // assumption that header is saved till first 1000B
		_hf.vfs_info = _vf;
		// _hf.vfs_files No file info added since its creation
		_vfs.vfs_status = VFS_OPEN; 
		_vfs.vfs_fp = fp;
		_vfs.header = _hf;
	}

	return status;
}
