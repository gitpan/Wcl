#ifndef _XmpMotif_h_
#define _XmpMotif_h_
#include <X11/Xmp/COPY.h>

/*
* SCCS_data: @(#) XmpMotif.h	1.3 92/10/28 07:50:38
*
*	This module includes all of the public headers for all Motif
*	widgets and Xmp widgets (public widgets based on Motif).
*
*******************************************************************************
*/

#include <Xm/ArrowB.h>
#include <Xm/ArrowBG.h>
#include <Xm/BulletinB.h>
#include <Xm/CascadeB.h>
#include <Xm/CascadeBG.h>
#include <Xm/Command.h>
#include <Xm/DialogS.h>
#include <Xm/DrawingA.h>
#include <Xm/DrawnB.h>
#include <Xm/FileSB.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#if (defined(XmVERSION) && XmVERSION > 1)
/* Motif 2.0 */
#include <Xm/IconG.h>
#include <Xm/IconH.h>
#endif
#include <Xm/Label.h>
#include <Xm/LabelG.h>
#include <Xm/List.h>
#include <Xm/MainW.h>
#include <Xm/MenuShell.h>
#include <Xm/MessageB.h>
#include <Xm/PanedW.h>
#include <Xm/PushB.h>
#include <Xm/PushBG.h>
#include <Xm/RowColumn.h>
#include <Xm/RowColumnP.h>	/* for CvtStringToMenuWidget */
#include <Xm/Scale.h>
#include <Xm/ScrollBar.h>
#include <Xm/ScrolledW.h>
#include <Xm/SelectioB.h>
#include <Xm/SeparatoG.h>
#include <Xm/Separator.h>
#include <Xm/Text.h>
#if (defined(XmVERSION) && XmVERSION > 1)
/* Motif 2.0 */
#include <Xm/CSText.h>
#endif
#ifndef _OLD_MOTIF
#include <Xm/TextF.h>
#endif
#include <Xm/ToggleB.h>
#include <Xm/ToggleBG.h>
#if (defined(XmVERSION) && XmVERSION > 1)
/* Motif 2.0 */
#include <Xm/TearOffBP.h>
#endif
#if (defined(XmVERSION) && XmVERSION > 1)
/* Motif 2.0 */
#include <Xm/ComboBox.h>
#include <Xm/Container.h>
#include <Xm/Notebook.h>
#include <Xm/SpinB.h>
#include <Xm/GrabShell.h>
#endif

#include <X11/Xmp/Table.h>

#endif /* _XmpMotif_h_ */
