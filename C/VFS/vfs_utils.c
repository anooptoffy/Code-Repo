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
		fp = fopen(name_with_path, "r"); // just reopening after gettting the data structures populated.
		_vfs.vfs_fp = fp;
		//fclose(fp); don't close this time close it only are the time of unloading.
	}
	return _status;
}


int vfs_unload(char *name_with_path){
	int status = 0;
	char str[100000],ch;
	int j = 0;
	//rewind(_vfs.vfs_fp);
	FILE *fp,*fpf;
	long offset, size;
	size_t bytes_read;

	fclose(_vfs.vfs_fp); //closing this pointer.
	fp =  fopen(name_with_path,"w");
	fseek(fp, 0L, SEEK_SET); // seeking to begining of the file. NOT WORKING due to
	// http://stackoverflow.com/questions/15826010/reading-from-a-file-opened-using-append-mode
	fwrite(&_vfs.header.vfs_info,sizeof(_vfs.header.vfs_info),1,fp);

	if(_vfs.header.vfs_info.num_files != 0)
		{
			for(int i = 0 ; i < _vfs.header.vfs_info.num_files; i++)
			{
				fwrite(&_vfs.header.vfs_files[i],sizeof(_vfs.header.vfs_files[i]),1,fp);
				
			}

#ifdef DEBUG
			printf("\n[INFO] Finished with writing the header info and file header info");
#endif			

				for(int i = 0 ; i < _vfs.header.vfs_info.num_files; i++)
				{

#ifdef DEBUG
					printf("\n[INFO]  The file name is : %s", _vfs.header.vfs_files[i].fname);
#endif					

					
					fpf = fopen(_vfs.header.vfs_files[i].fname,"r");
					if(fpf == NULL){
						printf("\n[ERROR] Error reading the file %s", _vfs.header.vfs_files[i].fname);
						continue;
					}				

					offset = _vfs.header.vfs_files[i].offset;
#ifdef DEBUG
				printf("\n[DEBUG] The offset value of file is %ld \n", offset );
				printf("\n[DEBUG] Size of give file is %ld",_vfs.header.vfs_files[i].file_size);
#endif	
					j = 0;
					ch = fgetc(fpf);
					while(ch != EOF){
						//printf("%c",ch);
						str[j] = ch;
						j++;
						ch = fgetc(fpf);
					}
					str[j] = '\0';

#ifdef DEBUG
					printf("\n[INFO] Contents of the file : %s", str);
#endif					
					fseek(fp, offset, SEEK_SET);	// setting the fp to the end of the file.
					fwrite(&str,strlen(str),1,fp);
					fclose(fpf);
				}
			}

	fclose(fp);
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
