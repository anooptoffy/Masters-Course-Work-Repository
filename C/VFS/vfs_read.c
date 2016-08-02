#include "vfs.h"

// v1.2 : use bsearch for search the file

extern struct vfs _vfs;
int vfs_extract(char *saved_name,char *name_with_path){
	int status = 0;
	FILE *fp;
	char *buffer;

#ifdef DEBUG
		printf("\n[DEBUG] The file name to be searched %s",saved_name);
#endif	

	for(int i = 0; i < _vfs.header.vfs_info.num_files; i++)
	{

#ifdef DEBUG
		printf("\n[DEBUG] The file name is %s",_vfs.header.vfs_files[i].fname );
#endif		
		if(strcmp(_vfs.header.vfs_files[i].fname,saved_name) == 0)
		{

#ifdef DEBUG
		printf("\n[DEBUG] Matched %s",_vfs.header.vfs_files[i].fname );
#endif

			fp = fopen("out.txt","w");
			long offset = _vfs.header.vfs_files[i].offset;

#ifdef DEBUG
		printf("\n[DEBUG] Offset start %ld",offset );
		printf("\n[DEBUG] Size of file %ld",_vfs.header.vfs_files[i].file_size );
#endif

			long size = _vfs.header.vfs_files[i].file_size;
			size_t bytes_read;
			fseek(_vfs.vfs_fp, offset, SEEK_SET);

#ifdef DEBUG
			printf("\n[INFO] Here1!");
#endif			

			printf("\n");
			char c;
			while(size > 0)
			{
				
				
				c = fgetc(_vfs.vfs_fp);
				//printf("%c",c);
				fputc(c,fp);
				size--;
			}

			fclose(fp);
		}
	}
	
	return status;
}
