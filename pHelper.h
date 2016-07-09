///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 29 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __pHelper__
#define __pHelper__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_gross;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxChoice* m_filing;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_exemptions;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText10;
		wxChoice* m_period;
		wxStaticText* m_staticText7;
		
		
		wxStaticText* m_staticText8;
		
		wxButton* m_calculate;
		wxStaticText* m_staticText9;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnGross( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFiling( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExemptions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPeriod( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCalculate( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* m_taxable;
		wxTextCtrl* m_basetax;
		wxTextCtrl* m_taxrate;
		wxTextCtrl* m_medicare;
		wxTextCtrl* m_socsec;
		wxTextCtrl* m_netpay;
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Paycheck Helper"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrame();
	
};

#endif //__pHelper__
