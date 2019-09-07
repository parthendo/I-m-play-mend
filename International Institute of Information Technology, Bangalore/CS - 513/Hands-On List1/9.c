/*
 * Solution to display various attributes of a file
 * Author: MT2019074
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){

	if(argc!=2){
		write(1,"Not enough arguments found!\n",sizeof("Not enough arguments found!")+1);
	}
	else{
		struct stat sb;
		const char* inp = (const char*)argv[1];
		int fp = open(inp,O_RDONLY);
		fstat(fp,&sb);
		printf("The following details of the file are:\n1. Inode: %ld\n2. Number of hard links: %ld\n3. UID: %ld\n4. GID: %ld\n5. Size: %lld \n6. Block Size: %ld \n7. Number of blocks: %lld\n8. Time of last access: %s9. Time of last modification: %s10. Time of last change: %s",(long)sb.st_ino,(long)sb.st_nlink,(long)sb.st_uid,(long)sb.st_gid,(long long)sb.st_size,(long)sb.st_blksize,(long long)sb.st_blocks,ctime(&sb.st_atime),ctime(&sb.st_mtime),ctime(&sb.st_ctime));
	}
	return 0;
}
