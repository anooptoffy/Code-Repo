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
		//printf("\n[WARNING] The file system (%s) already exists",name_with_path);
		status = 1;
	}
	else{
		fp = fopen(name_with_path,"w");
		if(fp == NULL){
			printf("\nUnable to open the file");
		}
		struct vfs_info _vf;
		struct vfs_header_info _hf; 
		strcpy(_vf.vfs_name,"My VFS");
		_vf.num_files = 0;
		_vf.offset = 1000; // assumption that header is saved till first 1000B
		_hf.vfs_info = _vf;
		// _hf.vfs_files No file info added since its creation

		fwrite(&_vf,sizeof(_vf),1,fp);
		_vfs.vfs_status = VFS_OPEN; // commented since it is cause a bug that nake file pointer evaporate
		_vfs.vfs_fp = fp;
		_vfs.header = _hf;
		//fclose(fp); // don't close the file now.
	}
	

	return status;
}
