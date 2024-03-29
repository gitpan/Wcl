#include <X11/Wc/COPY.h>
/*
* SCCS_data: %Z% %M%	%I% %E% %U%
*
*	This module contains registration routine for all Motif
*	widget/gadget constructors and classes.  
*
* Module_interface_summary: 
*
* All are exactly equivalent.  Register all Motif widgets and Xmp widgets.
*
*    void XmpRegisterMotif ( XtAppContext app )
*    void XmpRegisterAll   ( XtAppContext app )
*    void MriRegisterMotif ( XtAppContext app )
*
*******************************************************************************
*/

#include <X11/IntrinsicP.h>

#ifdef sun
#include <X11/ObjectP.h>        /* why don't they just use X from mit!?! */
#include <X11/RectObjP.h>
#endif

#include <X11/StringDefs.h>
#include <Xm/Xm.h>

#include <X11/Wc/WcCreate.h>
#include <X11/Xmp/XmpP.h>

#ifdef DEBUG
#include <X11/Xmp/XmpMotifP.h>
#else
#include <X11/Xmp/XmpMotif.h>
#endif


/* -- Register all Motif widgets, converters, callbacks, actions.
*******************************************************************************
*/

void MriRegisterMotif ( app )
    XtAppContext app;
{
    XmpRegisterMotif(app);
}

void XmpRegisterAll ( app )
    XtAppContext app;
{
    XmpRegisterMotif(app);
}

void XmpRegisterMotif ( app )
    XtAppContext app;
{
    ONCE_PER_XtAppContext( app );

/* -- Register Motif specific action and callback procedures */
    XmpAddActionsAndCallbacks( app );

/* -- Force Motif to load all of its converters */
    XmpAddMotifConverters( app );

/* -- Register Motif specific converters */
    XmpAddConverters( app );

/* -- Make sure the Wcl converters win over all the Motif converters */
    WcAddConverters( app );

#define RCO( name, func  )  WcRegisterConstructor ( app, name, func  )
#define RCP( name, class )  WcRegisterClassPtr    ( app, name, class )

/* -- register all Xmp widget constructors */
 RCO( "XmpCreateTable",			XmpCreateTable			);
 RCO( "XmpCreateTableDialog",		XmpCreateTableDialog		);
 RCO( "XmpCreateTableTransient",	XmpCreateTableTransient		);

/* -- register all Xmp widget classes */
 RCP( "XmpTable",			xmpTableWidgetClass		);
 RCP( "xmpTableWidgetClass",		xmpTableWidgetClass		);

/* -- register all Motif constructors */
 RCO( "XmCreateArrowButton",		XmCreateArrowButton		);
 RCO( "XmCreateArrowButtonGadget",	XmCreateArrowButtonGadget	);
 RCO( "XmCreateBulletinBoard",		XmCreateBulletinBoard		);
 RCO( "XmCreateBulletinBoardDialog",	XmCreateBulletinBoardDialog	);
 RCO( "XmCreateCascadeButton",		XmCreateCascadeButton		);
 RCO( "XmCreateCascadeButtonGadget",	XmCreateCascadeButtonGadget	);
#ifndef _OLD_MOTIF
 RCO( "XmCreateCheckBox",		XmCreateSimpleCheckBox		);
#endif
 RCO( "XmCreateCommand",		XmCreateCommand			);
 RCO( "XmCreateDialogShell",		XmCreateDialogShell		);
 RCO( "XmCreateDrawingArea",		XmCreateDrawingArea		);
 RCO( "XmCreateDrawnButton",		XmCreateDrawnButton		);
 RCO( "XmCreateErrorDialog",		XmCreateErrorDialog		);
 RCO( "XmCreateFileSelectionBox",	XmCreateFileSelectionBox	);
 RCO( "XmCreateFileSelectionDialog",	XmCreateFileSelectionDialog	);
 RCO( "XmCreateForm",			XmCreateForm			);
 RCO( "XmCreateFormDialog",		XmCreateFormDialog		);
 RCO( "XmCreateFrame",			XmCreateFrame			);
 RCO( "XmCreateInformationDialog",	XmCreateInformationDialog	);
#if (XmVERSION >= 2) || (XmREVISION >= 2)
 /* Motif 1.2 or later */
 RCO( "XmCreateTemplateDialog",		XmCreateTemplateDialog		);
#endif
 RCO( "XmCreateLabel",			XmCreateLabel			);
 RCO( "XmCreateLabelGadget",		XmCreateLabelGadget		);
 RCO( "XmCreateList",			XmCreateList			);
 RCO( "XmCreateMainWindow",		XmCreateMainWindow		);
 RCO( "XmCreateMenuBar",		XmCreateMenuBar			);
 RCO( "XmCreateMenuShell",		XmCreateMenuShell		);
 RCO( "XmCreateMessageBox",		XmCreateMessageBox		);
 RCO( "XmCreateMessageDialog",		XmCreateMessageDialog		);
 RCO( "XmCreateOptionMenu",		XmCreateOptionMenu		);
 RCO( "XmCreatePanedWindow",		XmCreatePanedWindow		);
 RCO( "XmCreatePopupMenu",		XmCreatePopupMenu		);
 RCO( "XmCreatePromptDialog",		XmCreatePromptDialog		);
 RCO( "XmCreatePulldownMenu",		XmCreatePulldownMenu		);
 RCO( "XmCreatePushButton",		XmCreatePushButton		);
 RCO( "XmCreatePushButtonGadget",	XmCreatePushButtonGadget	);
 RCO( "XmCreateQuestionDialog",		XmCreateQuestionDialog		);
 RCO( "XmCreateRadioBox",		XmCreateRadioBox		);
 RCO( "XmCreateRowColumn",		XmCreateRowColumn		);
 RCO( "XmCreateScale",			XmCreateScale			);
 RCO( "XmCreateScrollBar",		XmCreateScrollBar		);
 RCO( "XmCreateScrolledList",		XmCreateScrolledList		);
 RCO( "XmCreateScrolledText",		XmCreateScrolledText		);
 RCO( "XmCreateScrolledWindow",		XmCreateScrolledWindow		);
 RCO( "XmCreateSelectionBox",		XmCreateSelectionBox		);
 RCO( "XmCreateSelectionDialog",	XmCreateSelectionDialog		);
 RCO( "XmCreateSeparator",		XmCreateSeparator		);
 RCO( "XmCreateSeparatorGadget",	XmCreateSeparatorGadget		);
#ifndef _OLD_MOTIF
 RCO( "XmCreateSimpleCheckBox",		XmCreateSimpleCheckBox		);
#endif
 RCO( "XmCreateText",			XmCreateText			);
#ifndef _OLD_MOTIF
 RCO( "XmCreateTextField",		XmCreateTextField		);
 RCO( "XmCreateToggleButton",		XmCreateToggleButton		);
#endif
 RCO( "XmCreateToggleButtonGadget",	XmCreateToggleButtonGadget	);
 RCO( "XmCreateWarningDialog",		XmCreateWarningDialog		);
 RCO( "XmCreateWorkingDialog",		XmCreateWorkingDialog		);
#if (XmVERSION >= 2)
 /* Motif 2.0 or later */
 RCO( "XmCreateComboBox",			XmCreateComboBox			);
 RCO( "XmCreateCommandDialog",		XmCreateCommandDialog		);
 RCO( "XmCreateContainer",			XmCreateContainer			);
#if (XmVERSION == 2) && (XmREVISION < 1)
 /* Motif 2.0 only */
 RCO( "XmCreateCSText",				XmCreateCSText				);
#endif
 RCO( "XmCreateDragIcon",			XmCreateDragIcon			);
 RCO( "XmCreateDropDownComboBox",	XmCreateDropDownComboBox	);
 RCO( "XmCreateDropDownList",		XmCreateDropDownList		);
 RCO( "XmCreateGrabShell",			XmCreateGrabShell			);
 RCO( "XmCreateIconGadget",			XmCreateIconGadget			);
 RCO( "XmCreateIconHeader",			XmCreateIconHeader			);
 RCO( "XmCreateNotebook",			XmCreateNotebook			);
#if (XmVERSION == 2) && (XmREVISION < 1)
 /* Motif 2.0 only */
 RCO( "XmCreateScrolledCSText",		XmCreateScrolledCSText		);
#endif
 RCO( "XmCreateSimpleCheckBox",		XmCreateSimpleCheckBox		);
 RCO( "XmCreateSimpleMenuBar",		XmCreateSimpleMenuBar		);
 RCO( "XmCreateSimpleOptionMenu",	XmCreateSimpleOptionMenu	);
 RCO( "XmCreateSimplePopupMenu",	XmCreateSimplePopupMenu		);
 RCO( "XmCreateSimplePulldownMenu",	XmCreateSimplePulldownMenu	);
 RCO( "XmCreateSimpleRadioBox",		XmCreateSimpleRadioBox		);
 RCO( "XmCreateSpinBox",			XmCreateSpinBox				);
 RCO( "XmCreateTemplateDialog",		XmCreateTemplateDialog		);
#endif

/* -- register Motif widget classes */
 RCP("xmArrowButtonWidgetClass",	xmArrowButtonWidgetClass	);
 RCP("XmArrowButton",			xmArrowButtonWidgetClass	);
 RCP("xmArrowButtonGadgetClass",	xmArrowButtonGadgetClass	);
 RCP("XmArrowButtonGadget",		xmArrowButtonGadgetClass	);
 RCP("xmBulletinBoardWidgetClass",	xmBulletinBoardWidgetClass	);
 RCP("XmBulletinBoard",			xmBulletinBoardWidgetClass	);
 RCP("xmCascadeButtonWidgetClass",	xmCascadeButtonWidgetClass	);
 RCP("XmCascadeButton",			xmCascadeButtonWidgetClass	);
 RCP("xmCascadeButtonGadgetClass",	xmCascadeButtonGadgetClass	);
 RCP("XmCascadeButtonGadget",		xmCascadeButtonGadgetClass	);
 RCP("xmCommandWidgetClass",		xmCommandWidgetClass		);
 RCP("XmCommand",			xmCommandWidgetClass		);
 RCP("xmDialogShellWidgetClass",	xmDialogShellWidgetClass	);
 RCP("XmDialogShell",			xmDialogShellWidgetClass	);
 RCP("xmDrawingAreaWidgetClass",	xmDrawingAreaWidgetClass	);
 RCP("XmDrawingArea",			xmDrawingAreaWidgetClass	);
 RCP("xmDrawnButtonWidgetClass",	xmDrawnButtonWidgetClass	);
 RCP("XmDrawnButton",			xmDrawnButtonWidgetClass	);
 RCP("xmFileSelectionBoxWidgetClass",	xmFileSelectionBoxWidgetClass	);
 RCP("XmFileSelectionBox",		xmFileSelectionBoxWidgetClass	);
 RCP("xmFormWidgetClass",		xmFormWidgetClass		);
 RCP("XmForm",				xmFormWidgetClass		);
 RCP("xmFrameWidgetClass",		xmFrameWidgetClass		);
 RCP("XmFrame",				xmFrameWidgetClass		);
 RCP("xmGadgetClass",			xmGadgetClass			);
 RCP("XmGadget",			xmGadgetClass			);
 RCP("xmLabelWidgetClass",		xmLabelWidgetClass		);
 RCP("XmLabel",				xmLabelWidgetClass		);
 RCP("xmLabelGadgetClass",		xmLabelGadgetClass		);
 RCP("XmLabelGadget",			xmLabelGadgetClass		);
 RCP("xmListWidgetClass",		xmListWidgetClass		);
 RCP("XmList",				xmListWidgetClass		);
 RCP("xmMainWindowWidgetClass",		xmMainWindowWidgetClass		);
 RCP("XmMainWindow",			xmMainWindowWidgetClass		);
 RCP("xmManagerWidgetClass",		xmManagerWidgetClass		);
 RCP("XmManager",			xmManagerWidgetClass		);
 RCP("xmMenuShellWidgetClass",		xmMenuShellWidgetClass		);
 RCP("XmMenuShell",			xmMenuShellWidgetClass		);
 RCP("xmMessageBoxWidgetClass",		xmMessageBoxWidgetClass		);
 RCP("XmMessageBox",			xmMessageBoxWidgetClass		);
 RCP("xmPanedWindowWidgetClass",	xmPanedWindowWidgetClass	);
 RCP("XmPanedWindow",			xmPanedWindowWidgetClass	);
 RCP("xmPrimitiveWidgetClass",		xmPrimitiveWidgetClass		);
 RCP("XmPrimitive",			xmPrimitiveWidgetClass		);
 RCP("xmPushButtonWidgetClass",		xmPushButtonWidgetClass		);
 RCP("XmPushButton",			xmPushButtonWidgetClass		);
 RCP("xmPushButtonGadgetClass",		xmPushButtonGadgetClass		);
 RCP("XmPushButtonGadget",		xmPushButtonGadgetClass		);
 RCP("xmRowColumnWidgetClass",		xmRowColumnWidgetClass		);
 RCP("XmRowColumn",			xmRowColumnWidgetClass		);
 RCP("xmScaleWidgetClass",		xmScaleWidgetClass		);
 RCP("XmScale",				xmScaleWidgetClass		);
 RCP("xmScrollBarWidgetClass",		xmScrollBarWidgetClass		);
 RCP("XmScrollBar",			xmScrollBarWidgetClass		);
 RCP("xmScrolledWindowWidgetClass",	xmScrolledWindowWidgetClass	);
 RCP("XmScrolledWindow",		xmScrolledWindowWidgetClass	);
 RCP("xmSelectionBoxWidgetClass",	xmSelectionBoxWidgetClass	);
 RCP("XmSelectionBox",			xmSelectionBoxWidgetClass	);
 RCP("xmSeparatorWidgetClass",		xmSeparatorWidgetClass		);
 RCP("XmSeparator",			xmSeparatorWidgetClass		);
 RCP("xmSeparatorGadgetClass",		xmSeparatorGadgetClass		);
 RCP("XmSeparatorGadget",		xmSeparatorGadgetClass		);
 RCP("xmTextWidgetClass",		xmTextWidgetClass		);
 RCP("XmText",				xmTextWidgetClass		);
#ifndef _OLD_MOTIF
 RCP("xmTextFieldWidgetClass",		xmTextFieldWidgetClass		);
 RCP("XmTextField",			xmTextFieldWidgetClass		);
#endif
 RCP("xmToggleButtonWidgetClass",	xmToggleButtonWidgetClass	);
 RCP("XmToggleButton",			xmToggleButtonWidgetClass	);
 RCP("xmToggleButtonGadgetClass",	xmToggleButtonGadgetClass	);
 RCP("XmToggleButtonGadget",		xmToggleButtonGadgetClass	);
#if (XmVERSION >= 2)
 /* Motif 2.0 or later */
#if 0
 RCP("xmClipWindowWidgetClass",		xmClipWindowWidgetClass		);
 RCP("XmClipWindow",				xmClipWindowWidgetClass		);
#endif
 RCP("xmComboBoxWidgetClass",		xmComboBoxWidgetClass		);
 RCP("XmComboBox",					xmComboBoxWidgetClass		);
 RCP("xmContainerWidgetClass",		xmContainerWidgetClass		);
 RCP("XmContainer",					xmContainerWidgetClass		);
#if (XmVERSION == 2) && (XmREVISION < 1)
 /* Motif 2.0 only */
 RCP("xmCSTextWidgetClass",			xmCSTextWidgetClass			);
 RCP("XmCSText",					xmCSTextWidgetClass			);
#endif
 RCP("xmDragOverShellWidgetClass",	xmDragOverShellWidgetClass	);
 RCP("XmDragOverShell",				xmDragOverShellWidgetClass	);
 RCP("xmGrabShellWidgetClass",		xmGrabShellWidgetClass		);
 RCP("XmGrabShell",					xmGrabShellWidgetClass		);
 RCP("xmIconGadgetClass",			xmIconGadgetClass			);
 RCP("XmIconGadget",				xmIconGadgetClass			);
 RCP("xmNotebookWidgetClass",		xmNotebookWidgetClass		);
 RCP("XmNotebook",					xmNotebookWidgetClass		);
 RCP("xmSpinBoxWidgetClass",		xmSpinBoxWidgetClass		);
 RCP("XmSpinBox",					xmSpinBoxWidgetClass		);
 RCP("xmTearOffButtonWidgetClass",	xmTearOffButtonWidgetClass	);
 RCP("XmTearOffButton",				xmTearOffButtonWidgetClass	);
#if 0
 RCP("XmVendorShellWidgetClass",	XmVendorShellWidgetClass	);
#endif
#endif
#if (XmVERSION > 2) || ((XmVERSION == 2) && (XmREVISION >= 1))
 /* Motif 2.1 or later */
 RCP("xmPrintShellWidgetClass",     xmPrintShellWidgetClass     );
 RCP("XmPrintShell",                xmPrintShellWidgetClass     );
#if 0
 RCP("xmSashWidgetClass",           xmSashWidgetClass           );
 RCP("XmSashWidget",                xmSashWidgetClass           );
#endif
 RCP("xmSimpleSpinBoxWidgetClass",  xmSimpleSpinBoxWidgetClass  );
 RCP("XmSimpleSpinBox",             xmSimpleSpinBoxWidgetClass  );
#endif
}
