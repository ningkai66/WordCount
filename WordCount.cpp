#include <stdio.h>
#include <string.h>
int *getCharNum(char *filename, int *totalNum);
int main(){
    char filename[30];
    int totalNum[3] = {0, 0, 0};
    printf("Input file name: ");
    scanf("%s", filename);
    if(getCharNum(filename, totalNum)){
        printf("%d¸ö×Ö·û, %d¸öµ¥´Ê", totalNum[2], totalNum[1]);
    }else{
        printf("Error!\n");
    } 
    return 0;
}
int *getCharNum(char *filename, int *totalNum){
    FILE *fp;  
    char buffer[1003];  
    int bufferLen; 
    int i; 
    char c; 
    int isLastBlank = 0; 
    int charNum = 0; 
    int wordNum = 0; 
    if( (fp=fopen(filename, "rb")) == NULL ){
        perror(filename);
        return NULL;
    }
    while(fgets(buffer, 1003, fp) != NULL){
        bufferLen = strlen(buffer);
        for(i=0; i<bufferLen; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){ 
                !isLastBlank && wordNum++;
                isLastBlank = 1;
            }else if(c!='\n'&&c!='\r'){  
                charNum++; 
                isLastBlank = 0;
            }
        }
        !isLastBlank && wordNum++; 
        isLastBlank = 1;  
        totalNum[0]++;  
        totalNum[1] += charNum;  
        totalNum[2] += wordNum; 
        charNum = 0;
        wordNum = 0;
    }
    return totalNum;
}
