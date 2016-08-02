#vfs Makefile.mk
#pre requistics export PATH=$PATH:/home/anoop/Desktop/IIITB/PrepC/VFS
GCC = gcc

all : vfs_driver.o vfs_driver 
debug : GCC+= -DDEBUG -g
debug : all

vfs_driver.o : vfs_driver.c vfs_create.c vfs.h vfs_utils.c vfs_save.c vfs_read.c
	$(GCC) -c vfs_driver.c vfs_create.c vfs.h vfs_utils.c vfs_save.c vfs_read.c

vfs_driver : vfs_driver.o vfs_create.o vfs_utils.o vfs_save.o vfs_read.o
	gcc -o vfs vfs_driver.o vfs_create.o vfs_utils.o vfs_save.o vfs_read.o

clean :
	rm vfs_driver.o vfs_create.o vfs_utils.o vfs vfs.h.gch core vfs_save.o *.v *.vfs vfs_read.o demo* out.*
