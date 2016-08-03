#VFS (Virtual File System)

TODO : Implement a VFS for storing the files and related information.

##working

 The command you are executing is not valid, Execute one from the following list of commands. 
 
    	vfs create <file_system_name> [Optional] <size> 
    	vfs open <file_system_name/file_system_path> 
    	vfs save <file_name_to_be_saved>
    	vfs close <file_system_name>
    	vfs extract <file_system_name> [Optional] <file_info>
    	vfs status 
    	quit 

vfs@do>> :  


##HISTORY

###Ver1.0

1. Added the methods to create a vfs, save a file to vfs, unload a vfs, extract file contents from vfs.
2. sorted the file info using qsort.

###Ver1.2

1. Used bsearch instead of iterating though the files while extracting to improve performance.

##Compilation

make all
// to compile without debug logs
make debug
// to compile with debug logs

2. run using ./vfs command
