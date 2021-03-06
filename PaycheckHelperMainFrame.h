#ifndef __PaycheckHelperMainFrame__
#define __PaycheckHelperMainFrame__

/**
@file
Subclass of MainFrame, which is generated by wxFormBuilder.
*/

#include "pHelper.h"

/** Implementing MainFrame */
class PaycheckHelperMainFrame : public MainFrame
{
protected:
	// Handlers for MainFrame events.
	void OnGross( wxCommandEvent& event );
	void OnFiling( wxCommandEvent& event );
	void OnExemptions( wxCommandEvent& event );
	void OnPeriod( wxCommandEvent& event );
	void OnCalculate( wxCommandEvent& event );
	
public:
	/** Constructor */
	PaycheckHelperMainFrame( wxWindow* parent );
};

#endif // __PaycheckHelperMainFrame__
