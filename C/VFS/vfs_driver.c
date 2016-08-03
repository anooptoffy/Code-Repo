#include "vfs.h"

struct vfs _vfs;

int main(int argc,char *argv[]){

	char command[20],ch,run[20],*cptr,name_vfs[100];
	char arr[100][100];
	int i,status = 1;
#ifdef DEBUG	
	printf("\n[DEBUG] Welcome to new Virtual"
			" File System\n");
#endif	
		
		
		_vfs.vfs_status = VFS_CLOSE;
		info_start();
		while(1)
		{	

			printf("\nvfs@do>> :  ");
			i = 0;
			while((ch = getchar())!= '\n')
			{
				command[i] = ch;
				i++;
			}
			command[i] = '\0';

			cptr = strtok(command," ");
			i = 0;
			while(cptr != NULL)
			{
				strcpy(arr[i],cptr);
				cptr= strtok(NULL," ");
				i++;
			}

			
			if((strcmp(arr[1], "quit") == 0 ) ||
					(strcmp(command, "quit") == 0 )){
				if(_vfs.vfs_fp != NULL)
					printf("\n[WARNING] Please unload "
						"the vfs before quitting");
				else{
					printf("\nQuitting the utility, "
							"Bye for now...");
					break;
				}
			}
			
			else if(strcmp(arr[1], "create") == 0){
				if(i <= 2){
					printf("\n[WARNINGS] Please provide "
								"with the name of" 
								"file system");
					info();
					//break;
				}


				if(_vfs.vfs_status == VFS_CLOSE){
					printf("\n[INFO] Creating the Virtual "
							"File System ");
					strcpy(name_vfs,arr[2]);
					status  = vfs_create(arr[2]);
					if(status == 0){
						printf("\n[INFO] VFS creation Successfull ");	
						//_vfs->vfs_status = VFS_OPEN;
					}
					else if(status == 1){
						printf("\n[WARNING] The file system "
									"(%s) already" 
										" exists",arr[2]);
					}
				}
				else{				
					printf("\n[WARNING] Already using a vfs\n");
				}
				//break;
			}
			else if(strcmp(arr[1], "open") == 0) // load the existing file system to memory
			{
				if(i <= 2)
					printf("\nPlease provide with the name of file system");
				if(_vfs.vfs_status == VFS_OPEN)
				{	
					printf("\n[WARNING] Already using a vfs\n");
				}
				else{

					status = vfs_open(arr[2]);
					strcpy(name_vfs,arr[2]);
					if(status == 0 && _vfs.vfs_status == VFS_OPEN){
						printf("\n[INFO] Successfully loaded the filesystem");
						printf("\n[INFO] Name of VFS is %s",_vfs.header.vfs_info.vfs_name);
						printf("\n[INFO] Number of files is %d",_vfs.header.vfs_info.num_files);
						printf("\n[INFO] Offset %ld", _vfs.header.vfs_info.offset);

						printf("\n[INFO]  The file info");
						for(int i = 0; i <_vfs.header.vfs_info.num_files; i++){
							printf("\n[INFO] The name of file %d is : %s" , i+1,_vfs.header.vfs_files[i].fname);
							printf("\n[INFO] The offset is : %ld",_vfs.header.vfs_files[i].offset);
						}
					}
					else if(status == 1)
					{

						printf("\n[ERROR] Error in loading the file system");
					}

				}
				//break;
			}
			else if(strcmp(arr[1], "save") == 0) // save the filesystem from within
			{
				if(i <= 2)
					printf("\nPlease provide with the name of file system");

				if(_vfs.vfs_status == VFS_OPEN){ // pre condition that make sure that a vfs is loaded
					
					// vfs save file_name.txt
					status = vfs_save(arr[2]);
					if(status == 1)
					{
							printf("\n[ERROR] Error in saving to vfs ");
					}else
					{
						// on success
						printf("\n[INFO] Successfully saved.");
					}
				}
				else{
					printf("\n[WARNING] File system not loaded");
				}
				//break;
			}
			else if(strcmp(arr[1], "extract") == 0) // extract the file from a file system and print it or save it locally
			{
				if(i <= 2)
					printf("\nPlease provide with the name of file system");

				if(_vfs.vfs_status == VFS_OPEN){
					
					status = vfs_extract(arr[2],arr[1]);
					if(status == 1)
					{
						printf("\n[INFO] File you are search is not available in VFS");
					}

				}
				else
				{
					printf("\n[WARNING] File system not loaded");
				}
				//break;
			}	
			else if(strcmp(arr[1], "close") == 0)
			{

				if(_vfs.vfs_status == VFS_OPEN){
					status = vfs_unload(name_vfs);
					if(status == 0){
						printf("\n[INFO] Successfully unloaded.");
						break;
					}
					else
					{
						printf("\n[ERROR] Error in unloading.");
					}
				}
				else
				{
					printf("\n[WARNING] No filesystem loaded to unload.");
				}
				
				
			}
			else if(strcmp(arr[1], "status") == 0)
			{
				if(i <= 2)
					printf("\nPlease provide with the name of file system");
				if(_vfs.vfs_status == VFS_OPEN){
						printf("\n[INFO] Successfully loaded the filesystem");
						printf("\n[INFO] Name of VFS is %s",_vfs.header.vfs_info.vfs_name);
						printf("\n[INFO] Number of files is %d",_vfs.header.vfs_info.num_files);
						printf("\n[INFO] Offset %ld", _vfs.header.vfs_info.offset);

						printf("\n[INFO]  The file info");
						for(int i = 0; i <_vfs.header.vfs_info.num_files; i++){
							printf("\n[INFO] The name of file %d is : %s" , i+1,_vfs.header.vfs_files[i].fname);
							printf("\n[INFO] The offset is : %ld",_vfs.header.vfs_files[i].offset);
						}
					}
					else{
						printf("\n[WARNING] One need to load the filesystem, to get status.");
					}
				//break;
			}	
			else{
				info();
				//break;
			}

			

			
		} 
	printf("\n");
	return 0;
}

