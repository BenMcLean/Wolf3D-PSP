#ifndef	__ID_US_H__
#define	__ID_US_H__

#define	MaxX	480	//320
#define	MaxY	272	//200

#define	MaxHighName	57
#define	MaxScores	7
typedef	struct {
	char name[MaxHighName + 1];
	int score;
	int completed, episode;
} HighScore;

#define	MaxString	128	// Maximum input string size

extern	boolean NoWait;
extern	word		PrintX,PrintY;	// Current printing location in the window
extern	word		WindowX,WindowY,// Current location of window
			WindowW,WindowH;// Current size of window

#define USL_MeasureString       VW_MeasurePropString
#define USL_DrawString          VW_DrawPropString


extern	HighScore	Scores[];

void US_Startup(),
				US_Shutdown(),
				US_InitRndT(boolean randomize),
				US_DrawWindow(word x,word y,word w,word h),
				US_ClearWindow(void),
				US_PrintCentered(char *s),
				US_CPrint(char *s),
				US_CPrintLine(char *s),
				US_Print(char *s),
				US_PrintUnsigned(longword n);
boolean	US_LineInput(int x,int y,char *buf,char *def,boolean escok,
				int maxchars,int maxwidth);
int				US_RndT();

void	USL_PrintInCenter(char *s,Rect r);

#endif
