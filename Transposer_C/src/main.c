/**
 * @file main.c
 * 	* I am trying to build a transposer for music chords and get to know C/C++ a little better
 * @author Cedric Destin
 * @date 8/13/2013
 **/
/**
 * @brief
 * 	* First asked for the key change DONE
 * 	* Import the a text file into the workspace DONE
 * 	* Find the Key. TODO
 * 	*	* Maybe find the string "Key"
 * 	*	* Then get the next character that is not null
 * 	* Get the chords into strings DONE
 * 	* Get the text into strings DONE
 * 	* Transpose the chords according to what was asked DONE
 * 	* Bold the text using .RTF DONE
 * TODO:
 * 	* Get the # when needed... This is kind of tricky sinc I am looking at the
 * 		* characters of the string
 * 	* Build a GUI using GTK
 **/
/**
 * @include
 **/
#include <stdio.h>
#include <string.h>
#include "../inc/chord.h"
/**
 * @var
 **/
char Chrd[] = {'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char Key;
char fileName[30];
char fileName2[30];
char newKey;
FILE *ptr_file;
FILE *ptr_file2;
char str[10000];
int Index;
int newIndex;
/**
 * @def
 **/
void getName(void);
void getSwitch(void);
void doSwitch(void);
void doPrint(void);
int main(void){
  getName();
  ptr_file =fopen(fileName,"r+");
  ptr_file2 =fopen(fileName2,"w");
  doPrint();
  getSwitch();
  doSwitch();
  return 0;
}
void getName(void){
  printf("\rEnter the original key and new key separated by a space\n");
  scanf("%c %c", &Key, &newKey);
  printf("\rEnter the name of the file no space and max 30 characters\n");
  scanf("%s", fileName);
  strcpy(fileName2, fileName);
  printf("\rThe file is :%s\n", fileName);
  strncat(fileName, ".txt", 4);
  strncat(fileName2, "T.rtf", 5);
  puts(fileName);
}
void getSwitch(void){
  switch(Key){
    case 'G':
      Index = 0;
      break;
    case 'A':
      Index = 1;
      break;
    case 'B':
      Index = 2;
      break;
    case 'C':
      Index = 3;
      break;
    case 'D':
      Index = 4;
      break;
    case 'E':
      Index = 5;
      break;
    case 'F':
      Index = 6;
      break;
  }
  printf("\rKeys = %c, %c\n", Key, newKey);
  switch(newKey){
    case 'G':
      newIndex = 0;
      break;
    case 'A':
      newIndex = 1;
      break;
    case 'B':
      newIndex = 2;
      break;
    case 'C':
      newIndex = 3;
      break;
    case 'D':
      newIndex = 4;
      break;
    case 'E':
      newIndex = 5;
      break;
    case 'F':
      newIndex = 6;
      break;
  }
}
void doSwitch(void){
  int n = 0;
  int i = 0;
  while(fgets(str, 10000, ptr_file)!= NULL){
    if(i % 2 == 0){
      for(n = 0; n <= strlen(str); n++){
	if(str[n] != ' '){
	  if(str[n] == Chrd[Index]){
	    str[n] = Chrd[newIndex];
	  }else if(str[n] == Chrd[Index + 1]){
	    str[n] = Chrd[newIndex + 1];
	  }else if(str[n] == Chrd[Index + 2]){
	    str[n] = Chrd[newIndex + 2];
	  }else if(str[n] == Chrd[Index + 3]){
	    str[n] = Chrd[newIndex + 3];
	  }else if(str[n] == Chrd[Index + 4]){
	    str[n] = Chrd[newIndex + 4];
	  }else if(str[n] == Chrd[Index + 5]){
	    str[n] = Chrd[newIndex + 5];
	  }else if(str[n] == Chrd[Index + 6]){
	    str[n] = Chrd[newIndex + 6];
	  }
	}	
      }
      fputs("{\\b \n", ptr_file2);
      fputs(str, ptr_file2);
      strcpy(str, "}  \\par \n");
      fputs(str, ptr_file2);
    }else{
      fputs(str, ptr_file2);
      strcpy(str, "  \\par \n");
      fputs(str, ptr_file2);
    }
    i = i + 1;
  }
  fputs(" \n }", ptr_file2);
}
void doPrint(void){
  char strRTF[60];
  strcpy(strRTF, "{\\rtf1\\ansi{\\fonttbl\\f0\\fswiss Helvetica;}\\f0\\pard");
  fputs(strRTF, ptr_file2);
}