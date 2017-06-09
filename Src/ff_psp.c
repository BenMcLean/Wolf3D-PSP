#include "include/ff.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#ifdef _PSP
#include <sys/dirent.h>
#else
#include <dirent.h>
#endif
#ifdef USE_DMALLOC
#include<dmalloc.h>
#endif

static char **dirfname;
static int dirpos;
static int dirsize;

static int wildcard(const char *name, const char *match)
{
	int i;
	int max;
	max=strlen(name);
	if(strlen(match)!=max) {
		return 0;
	}
	for(i=0;i<max;i++) {
		char a,b;
		a=name[i];
		b=match[i];
		if(a>='a' && a<='z') a^=32;
		if(b>='a' && b<='z') b^=32;
		if(b=='?' || a==b) {
			// continue
		} else {
			return 0;
		}
	}
	return 1;
}

int findfirst(const char *pathname, struct ffblk *ffblk, int attrib) {
  char *match=strdup(pathname);
  unsigned int i;
  DIR *dirhandle=opendir(".");
  if(match[0]=='*') match++;
  for(i=0;i<strlen(match);i++) { 
	if(match[i]>='a' && match[i]<='z') match[i]^=32; 
  }
pspDebugScreenPrintf("Looking for '%s' (%s)\n",match,pathname);
if(!dirhandle) pspDebugScreenPrintf("Couldn't open dir.\n");

  dirsize=0;
  if(!dirhandle) {
    strcpy(ffblk->ff_name,""); 
    //if(match) free(match);
    return 1;
  }
  struct dirent *ent;
  while( (ent=readdir(dirhandle))!=0 ) {
    if(strstr(ent->d_name,match)==0 && wildcard(ent->d_name,match)==0) continue;
    if(dirsize==0) {
	dirfname=(char **)calloc(sizeof(char *),64);
    } else if((dirsize%64)==0) {
	dirfname=(char **)realloc(dirfname,sizeof(char *)*(dirsize+64));
    }
    dirfname[dirsize++]=strdup(ent->d_name);
  } 
  closedir(dirhandle);
pspDebugScreenPrintf("Got %d matches\n",dirsize);
  //if(match) free(match);
  if (dirsize>0) {
    dirpos=1;
    strcpy(ffblk->ff_name,dirfname[dirsize-1]);
    return 0;
  }

  return 1;

}

int findnext(struct ffblk *ffblk) {

  if (dirpos<dirsize) {
    strcpy(ffblk->ff_name,dirfname[dirpos++]);
    return 0;
  }
  return 1;

}

void resetinactivity(void) {
	//User::ResetInactivityTime();
}
