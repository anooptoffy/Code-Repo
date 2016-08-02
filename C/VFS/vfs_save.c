#include "vfs.h"

extern struct vfs _vfs;
int vfs_save(char *name_with_path){
	int status = 1;
	
	FILE *fp = fopen(name_with_path, "r");
	if(fp == NULL)
	{
		printf("\n[WARNING] Requested file does not exit");
		return status;
	}
	else
	{
		if(_vfs.vfs_status == VFS_OPEN)
		{
			struct vfs_file_info _vf_file;
			strcpy(_vf_file.fname, name_with_path); // name of file
			fseek(fp, 0L, SEEK_END);
			long sz = ftell(fp);
			_vf_file.file_size = sz; // file size
			rewind(fp);


#ifdef DEBUG
			printf("\n[DEBUG] Size of give file is %ld",sz);
#endif
			if(_vfs.header.vfs_info.num_files == 0){
				long offset = _vfs.header.vfs_info.offset;
				offset++;
#ifdef DEBUG
				printf("\n[DEBUG] Offest value : %ld", offset);
#endif

				_vf_file.offset = offset;	// setting the offset of the file, from where file info starts.
				_vfs.header.vfs_files[0] = _vf_file;
				_vfs.header.vfs_info.num_files++;

#ifdef DEBUG
				printf("\n[DEBUG]The no of files in header is : %d", _vfs.header.vfs_info.num_files);
#endif

			}
			else{
				long offset = _vfs.header.vfs_files[_vfs.header.vfs_info.num_files - 1].offset;
#ifdef DEBUG
				printf("\n[DEBUG] The offset value of previous file is %ld \n", offset );
#endif				
				offset = offset + _vfs.header.vfs_files[_vfs.header.vfs_info.num_files - 1].file_size;
#ifdef DEBUG
				printf("\n[DEBUG] The new offset value of previous file is %ld \n", offset );
#endif	

				offset++;
				//int n = _vfs.header.vfs_info.num_files++;
				
#ifdef DEBUG
				printf("\n[DEBUG] Offest value : %ld", offset);
#endif
				_vf_file.offset = offset;	// setting the offset of the file
				_vfs.header.vfs_files[_vfs.header.vfs_info.num_files] = _vf_file;
				_vfs.header.vfs_info.num_files++;
			}
		}
		fclose(fp);
		
	}

	return status;
}
