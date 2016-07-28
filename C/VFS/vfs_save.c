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
			char str[100000],ch;
			int i = 0;
			ch = fgetc(fp);
			while(ch != EOF){
				
				str[i] = ch;
				i++;
				ch = fgetc(fp);
			}
			str[i] = '\0';


#ifdef DEBUG
			printf("\n[DEBUG] Size of give file is %ld",sz);
#endif
			if(_vfs.header.vfs_info.num_files == 0){
				long offset = _vfs.header.vfs_info.offset;
#ifdef DEBUG
				printf("\n[DEBUG] Offest value : %ld", offset);
#endif
				fseek(_vfs.vfs_fp, offset, SEEK_SET);	// setting the fp to the end of the file.
				fwrite(&str,strlen(str),1,_vfs.vfs_fp);
				_vf_file.offset = offset + sz;	// setting the offset of the file
				_vfs.header.vfs_files[0] = _vf_file;
				//rewind(_vfs.vfs_fp);
				fseek(_vfs.vfs_fp, 0L, SEEK_SET);
				_vfs.header.vfs_info.num_files++;
				//fwrite(&_vfs.header,sizeof(_vfs.header),1,_vfs.vfs_fp);
				fwrite(&_vfs.header.vfs_info, sizeof(_vfs.header.vfs_info),1,_vfs.vfs_fp);
				fwrite(&_vfs.header.vfs_files[0], sizeof(_vfs.header.vfs_files[0]),1, _vfs.vfs_fp);

#ifdef DEBUG
				printf("\n[DEBUG]The no of files in header is : %d", _vfs.header.vfs_info.num_files);
#endif

			}
			else{
				long offset = _vfs.header.vfs_files[_vfs.header.vfs_info.num_files - 1].offset;
				int n = _vfs.header.vfs_info.num_files++;
#ifdef DEBUG
				printf("\n[DEBUG] Offest value : %ld", offset);
#endif
				fseek(_vfs.vfs_fp, offset, SEEK_SET);	// setting the fp to the end of the file.
				fwrite(&str,i,1,_vfs.vfs_fp);
				_vf_file.offset = offset + sz;	// setting the offset of the file
				_vfs.header.vfs_files[n - 1] = _vf_file;
				//rewind(_vfs.vfs_fp);
				fseek(_vfs.vfs_fp, 0L, SEEK_SET);
				fwrite(&_vfs.header.vfs_info, sizeof(_vfs.header.vfs_info),1,_vfs.vfs_fp);
				_vfs.header.vfs_files[n] = _vf_file;
				for(int i = 0 ; i < n; i++)
				{
					fwrite(&_vfs.header.vfs_files[i], sizeof(_vfs.header.vfs_files[i]),1, _vfs.vfs_fp);
				}

				//fwrite(&_vfs.header,sizeof(_vfs.header),1,_vfs.vfs_fp);
			}
		}
		fclose(fp);
		
	}

	return status;
}
