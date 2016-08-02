#include "vfs.h"

// vfs utils
extern struct vfs _vfs;
int vfs_open(char *name_with_path){  // load vfs
	FILE *fp;
	int _status = 0;
	fp = fopen(name_with_path, "r");
	if(fp == NULL)
	{
		_status = 1;
		return _status;
		
	}
	else
	{
		fclose(fp);
		fp = fopen(name_with_path, "r");
		struct vfs_header_info _hf; 
		struct vfs_info _vf;
		struct vfs_file_info _file;
		rewind(fp);
		fread(&_vf,sizeof(_vf),1,fp);	
		_hf.vfs_info = _vf;
		
		
		if(_hf.vfs_info.num_files != 0)
		{
			for(int i = 0 ; i < _hf.vfs_info.num_files; i++)
			{
				fread(&_file,sizeof(_file),1,fp);
				_hf.vfs_files[i] = _file;
			}
		}
		_vfs.header = _hf;
		_vfs.vfs_status = VFS_OPEN;
		fclose(fp);
		fp = fopen(name_with_path, "a+"); // just reopening after gettting the data structures populated.
		_vfs.vfs_fp = fp;
		//fclose(fp); don't close this time close it only are the time of unloading.
	}
	return _status;
}


int vfs_unload(char *name_with_path){
	int status = 0;
	//rewind(_vfs.vfs_fp);
	fseek(_vfs.vfs_fp, 0L, SEEK_SET);
	fwrite(&_vfs.header.vfs_info,sizeof(_vfs.header.vfs_info),1,_vfs.vfs_fp);

	if(_vfs.header.vfs_info.num_files != 0)
		{
			for(int i = 0 ; i < _vfs.header.vfs_info.num_files; i++)
			{
				fwrite(&_vfs.header.vfs_files[i],sizeof(_vfs.header.vfs_files[i]),1,_vfs.vfs_fp);				
			}
		}

	fclose(_vfs.vfs_fp);
	return status;
}

void info(){

	printf("\n The command you are executing is not valid, Execute one from the following list of commands. \n");
		printf("	vfs create <file_system_name> [Optional] <size> \n \
	vfs open <file_system_name/file_system_path> \n \
	vfs save <file_name_to_be_saved>\n \
	vfs close <file_system_name>\n \
	vfs extract <file_system_name> [Optional] <file_info>\n \
	vfs status \n \
	quit \n");

}
