#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	struct stat buf;

	stat(argv[1], &buf);

	printf("Mode = %o (16 : %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	
	if((buf.st_mode & S_IREAD) != 0)
		printf("%s : user has a read permission\n", argv[1]);
	
	if((buf.st_mode & S_IWUSR) != 0)
		printf("%s : user has a write permission\n", argv[1]);

	if((buf.st_mode & S_IEXEC) != 0)
		printf("%s : user has a exec permission\n", argv[1]);

	
	if((buf.st_mode & (S_IREAD >> 3)) != 0)
		printf("%s : group has a read permission\n", argv[1]);

	if((buf.st_mode & (S_IEXEC >> 3)) != 0)
		printf("%s : group has a exec permission\n", argv[1]);
	
	if((buf.st_mode & S_IROTH) != 0)
		printf("%s : other have a read permission\n", argv[1]);

	if((buf.st_mode & S_IXOTH) != 0)
		printf("%s : other have a exec permission\n", argv[1]);


	return 0;


}
