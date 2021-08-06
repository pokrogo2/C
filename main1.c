#include <stdio.h>

void fileCopy(char * src, char * des)
{
	FILE * source = fopen(src, "rb");
	FILE * destination = fopen(des, "wb");
	FILE * error = NULL;
	char buffer[1024];
	int readCount;
	
	if(source == NULL || destination == NULL) {
		error = fopen("error.txt", "wt");
		fputs("파일을 읽거나 생성할 수 없습니다. \n", error);
		if (error != NULL) fclose(error);
		return;
	}
	
	while(1) {
		readCount = fread(buffer, sizeof(char), sizeof(buffer), source);
		if(readCount < sizeof(buffer)) {
			  fwrite(buffer, sizeof(char), readCount, destination);
			  break;

		} else {

			fwrite(buffer, sizeof(char), sizeof(buffer), destination);
		}

	}
	if (source != NULL) fclose(source);
	if (destination != NULL) fclose(destination);

}

int main(void)
{

	fileCopy("dog.mp4", "dogCopy.mp4");
	return 0;
}

