#include <stdio.h>
#include <X11/Intrinsic.h>
#include "ListTree.h"
/* #define USE_XPM */

Widget	toplevel,paned,form,tree,list;
XtAppContext app_con;
char *files[256];


void
HighlightCallback(w,client,call)
Widget w;
XtPointer client;
XtPointer call;
{
ListTreeMultiReturnStruct *ret;
ListTreeItem *item;
int count,i;

	ret=(ListTreeMultiReturnStruct *)call;
	printf("HIGHLIGHT: count=%d\n",ret->count);
	for (i=0; i<ret->count; i++) {
	  item=ret->items[i];
	  printf("%s",item->text);
	  while (item->parent) {
	    item=item->parent;
	    printf("<--%s",item->text);
	  }
	  printf("\n");
	}
}

void
MenuCallback(w,client,call)
Widget w;
XtPointer client;
XtPointer call;
{
ListTreeItemReturnStruct *ret = (ListTreeItemReturnStruct *)call;

        printf ("MENU: item=%s\n", ret->item->text);
}

void
ActivateCallback(w,client,call)
Widget w;
XtPointer client;
XtPointer call;
{
ListTreeActivateStruct *ret;
ListTreeMultiReturnStruct ret2;
ListTreeItem *item;
int count;

	ret=(ListTreeActivateStruct *)call;
	printf("ACTIVATE: item=%s count=%d\n",ret->item->text,ret->count);
	count=0;
	while (count<ret->count) {
		printf(" path: %s\n",ret->path[count]->text);
		count++;
	}
}

Pixmap testPix;

Init(Widget tree)
{
int i,j,k,l;
char test[64];
ListTreeItem *level1,*level2,*level3,*level4;
#if 1
	for (i=0; i<10; i++) {
		sprintf(test,"%c Level #1, entry #%d",
			(char)('Z'-i),i);
		level1=ListTreeAdd(tree,NULL,test);
		for (j=0; j<i; j++) {
			sprintf(test,"%c Level #2, entry #%d",
				(char)('Z'-j),j);
			level2=ListTreeAdd(tree,level1,test);
			for (k=0; k<i; k++) {
				sprintf(test,"%c Level #3, entry #%d",
					(char)('Z'-k),k);
				level3=ListTreeAdd(tree,level2,test);
				for (l=0; l<i; l++) {
					sprintf(test,"%c Level #4, entry #%d",
						(char)('Z'-l),l);
					level4=ListTreeAdd(tree,level3,test);
				}
			}
		}
	}
#else
sprintf (test, "Document: /u/alan/images/mass.ntf");
level1 = ListTreeAdd (tree, NULL, test);
ListTreeSetItemPixmaps (tree, level1, testPix, testPix);

 sprintf (test, "Image: Massachusetts");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Controlled Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "Tag: SPIA");
  level4 = ListTreeAdd (tree, level3, test);
  sprintf (test, "Tag: Ruler");
  level4 = ListTreeAdd (tree, level3, test);
  sprintf (test, "User Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "Abstract Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Docuemnt: Word Perfect");
   level4 = ListTreeAdd (tree, level3, test);

 sprintf (test, "Image: Wilmington ROI");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Controlled Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "User Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "Abstract Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Spread Sheet: FBI Locality Statistic");
   level4 = ListTreeAdd (tree, level3, test);
   sprintf (test, "Database: Areas of Interest");
   level4 = ListTreeAdd (tree, level3, test);

 sprintf (test, "Associated Data");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Document: State Profile");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "URL: http://www.massachusetts.gov");
  level3 = ListTreeAdd (tree, level2, test);


sprintf (test, "Document: /u/alan/images/cali.ntf");
level1 = ListTreeAdd (tree, NULL, test);
ListTreeSetItemPixmaps (tree, level1, testPix, testPix);

 sprintf (test, "Image: California");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Controlled Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Tag: SPIA");
   level4 = ListTreeAdd (tree, level3, test);
   sprintf (test, "Tag: Ruler");
   level4 = ListTreeAdd (tree, level3, test);
  sprintf (test, "User Data");
  level3 = ListTreeAddBranch (tree, level2, test);
  sprintf (test, "Abstract Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Document: Word Perfect");
   level4 = ListTreeAdd (tree, level3, test);

 sprintf (test, "Image: California");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Controlled Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Tag: SPIA");
   level4 = ListTreeAdd (tree, level3, test);
   sprintf (test, "Tag: Ruler");
   level4 = ListTreeAdd (tree, level3, test);
  sprintf (test, "User Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "Abstract Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Document: Word Perfect");
   level4 = ListTreeAdd (tree, level3, test);

 sprintf (test, "Image: San Jose ROI");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Controlled Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "User Data");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "Abstract Data");
  level3 = ListTreeAdd (tree, level2, test);
   sprintf (test, "Spread Sheet: FBI Locality Statistics");
   level4 = ListTreeAdd (tree, level3, test);
   sprintf (test, "Database: Areas of Interest");
   level4 = ListTreeAdd (tree, level3, test);

 sprintf (test, "Associated Data");
 level2 = ListTreeAdd (tree, level1, test);
  sprintf (test, "Document: State Profile");
  level3 = ListTreeAdd (tree, level2, test);
  sprintf (test, "URL: http://www.cal.gov");
  level3 = ListTreeAdd (tree, level2, test);

#endif
}

#ifdef USE_XPM
#include <X11/xpm.h>
static char * folder_xpm[] = {
"17 13 4 1",
"       c #FFFFFFFFFFFF",
".      c #FFFF00000000",
"X      c #000000000000",
"o      c #FFFFFFFF0000",
"        .....    ",
"       .......X  ",
"  oooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
" ooooooooooooooX ",
"  ooooooooooooX  ",
"   XXXXXXXXXXX   "};
static char * folderopen_xpm[] = {
"17 13 5 1",
"       c #FFFFFFFFFFFF",
".      c #FFFF00000000",
"X      c #000000000000",
"o      c #FFFFCCCC4242",
"O      c #FFFFFFFF0000",
"         .....   ",
"        .......X ",
"   oooooooooooooX",
"  ooooooooooooooX",
"  ooooooooooooooX",
" OOOOOOOOOOOooooX",
"OOOOOOOOOOOOOoooX",
" OOOOOOOOOOOOOooX",
" OOOOOOOOOOOOOOoX",
"  OOOOOOOOOOOOOoX",
"  OOOOOOOOOOOOOoX",
"   OOOOOOOOOOOOX ",
"    XXXXXXXXXXX  "};
static char * fileopen_xpm[] = {
"17 13 5 1",
"       c #FFFFFFFFFFFF",
".      c #FFFF00000000",
"X      c #000000000000",
"o      c #FFFFFFFF0000",
"O      c #FFFFFFFF0000",
"     XXXXXXXXXXX ",
"    XXoooooooooX ",
"   XOXoooooooooX ",
"  XOOXoooooooooX ",
" XXXXXoooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XXXXXXXXXXXXXXX "};
static char * fileclosed_xpm[] = {
"17 13 5 1",
"       c #FFFFFFFFFFFF",
".      c #FFFF00000000",
"X      c #000000000000",
"o      c #FFFFFFFF0000",
"O      c #FFFFFFFF0000",
"     XXXXXXXXXXX ",
"    XXoooooooooX ",
"   XOXoooooooooX ",
"  XOOXoooooooooX ",
" XXXXXoooooooooX ",
" Xoooooo.ooooooX ",
" Xoooooo.ooooooX ",
" Xoooo.....ooooX ",
" Xoooooo.ooooooX ",
" Xoooooo.ooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XXXXXXXXXXXXXXX "};
static char * test_xpm[] = {
"17 13 5 1",
"       c #FFFFFFFFFFFF",
".      c #FFFF00000000",
"X      c #000000000000",
"o      c #FFFF00000000",
"O      c #FFFF55550000",
"     XXXXXXXXXXX ",
"    XXoooooooooX ",
"   XOXoooooooooX ",
"  XOOXoooooooooX ",
" XXXXXoooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XoooooooooooooX ",
" XXXXXXXXXXXXXXX "};
#endif
main (argc, argv)
int argc;
char **argv;
{
#ifdef USE_XPM
Pixmap open,closed, file_open, file_closed; 
Pixel bg;
XpmColorSymbol transparent;
XpmAttributes attrib;
#endif

	toplevel = XtAppInitialize(&app_con,"ListTreeDemo",NULL,0,
				&argc,argv,NULL,NULL,0);

#ifdef USE_XPM
        XtVaGetValues(toplevel,
                XtNbackground,  &bg,
                NULL);
        transparent.name=NULL;
        transparent.value="#FFFFFFFFFFFF";
        transparent.pixel=bg;
        attrib.colorsymbols=&transparent;
        attrib.valuemask=XpmColorSymbols;
        attrib.numsymbols=1;
	XpmCreatePixmapFromData(XtDisplay(toplevel),
		RootWindowOfScreen(XtScreen(toplevel)),
		folderopen_xpm,&open,NULL,&attrib);
	XpmCreatePixmapFromData(XtDisplay(toplevel),
		RootWindowOfScreen(XtScreen(toplevel)),
		folder_xpm,&closed,NULL,&attrib);
	XpmCreatePixmapFromData(XtDisplay(toplevel),
		RootWindowOfScreen(XtScreen(toplevel)),
		fileopen_xpm,&file_open,NULL,&attrib);
	XpmCreatePixmapFromData(XtDisplay(toplevel),
		RootWindowOfScreen(XtScreen(toplevel)),
		fileclosed_xpm,&file_closed,NULL,&attrib);
	XpmCreatePixmapFromData(XtDisplay(toplevel),
		RootWindowOfScreen(XtScreen(toplevel)),
		test_xpm,&testPix,NULL,&attrib);
#endif
#if OLD_WAY
	tree = XtVaCreateManagedWidget("tree",listtreeWidgetClass,toplevel,
		XtNfont,	XLoadQueryFont(XtDisplay(toplevel),"-adobe-helvetica-medium-r-normal--*-100-*"),
		XtNheight,      	(Dimension)200,
		XtNwidth,		(Dimension)150,
	        XtNhorizontalSpacing,   5,
	        XtNverticalSpacing,     5,
		XtNhighlightPath,       True,
#ifdef USE_XPM
		XtNbranchPixmap,	closed,
		XtNbranchOpenPixmap,	open,
		XtNleafPixmap,		file_closed,
		XtNleafOpenPixmap,	file_open,
#else
/*		XtNbranchPixmap,	NULL,*/
/*		XtNbranchOpenPixmap,	NULL,*/
/*		XtNleafPixmap,		NULL,*/
/*		XtNleafOpenPixmap,	NULL,*/
/*		XtNindent,		(int)5,*/
#endif
		NULL,0);
#else
        tree=XmCreateScrolledListTree(toplevel,"tree",NULL,0);
        XtVaSetValues(tree,
          XtNheight,      	(Dimension)200,
          XtNwidth,		(Dimension)150,
          XtNhorizontalSpacing,   5,
          XtNverticalSpacing,     5,
          XtNhighlightPath,       True,
#ifdef USE_XPM
          XtNbranchPixmap,	closed,
          XtNbranchOpenPixmap,	open,
          XtNleafPixmap,		file_closed,
          XtNleafOpenPixmap,	file_open,
#else
/*		XtNbranchPixmap,	NULL,*/
/*		XtNbranchOpenPixmap,	NULL,*/
/*		XtNleafPixmap,		NULL,*/
/*		XtNleafOpenPixmap,	NULL,*/
/*		XtNindent,		(int)5,*/
#endif
          NULL);
        XtManageChild(tree);
        
#endif
	Init(tree);
	XtAddCallback(tree,XtNhighlightCallback, HighlightCallback, (XtPointer) NULL);
	XtAddCallback(tree,XtNactivateCallback, ActivateCallback, (XtPointer) NULL);
	XtAddCallback(tree,XtNmenuCallback, MenuCallback, (XtPointer) NULL);

	XtRealizeWidget(toplevel);

	XtAppMainLoop(app_con);
}
