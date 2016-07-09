#include <wx/wx.h>
#include "PaycheckHelperMainFrame.h"
#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <sstream>

static float socsec = 0.062;
static float medicare = 0.0145;
static float exempt = 155.8;

float bottom;
float base;
float pct;

wxString float_to_string(float f)
{
    std::ostringstream s;
    s << std::fixed << std::setprecision(2) << f;
    return s.str();
} 

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   bottom = atof(argv[1]);
   std::cout << "Bottom: " << bottom << std::endl;
   base = atof(argv[3]);
   std::cout << "Base: " << base << std::endl;
   pct = (atof(argv[4])*100);
   std::cout << "Percent: " << pct << std::endl;
   return 0;
}

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,300 ), wxSize( 500,300 ) );
	
	wxGridSizer* MainSizer;
	MainSizer = new wxGridSizer( 6, 4, 1, 1 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Gross:"), wxPoint( 20,20 ), wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	m_staticText1->SetMinSize( wxSize( 40,15 ) );
	
	MainSizer->Add( m_staticText1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_gross = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	MainSizer->Add( m_gross, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Taxable Income:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	MainSizer->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_taxable = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_taxable->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	
	MainSizer->Add( m_taxable, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Filing Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	MainSizer->Add( m_staticText3, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_filingChoices[] = { wxT("Single"), wxT("Married") };
	int m_filingNChoices = sizeof( m_filingChoices ) / sizeof( wxString );
	m_filing = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_filingNChoices, m_filingChoices, 0 );
	m_filing->SetSelection( 0 );
	MainSizer->Add( m_filing, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Base Tax:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	MainSizer->Add( m_staticText4, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_basetax = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_basetax->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	MainSizer->Add( m_basetax, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Exemptions:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	MainSizer->Add( m_staticText5, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_exemptions = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	MainSizer->Add( m_exemptions, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Tax Rate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	MainSizer->Add( m_staticText6, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_taxrate = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_taxrate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	MainSizer->Add( m_taxrate, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Pay Period:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	MainSizer->Add( m_staticText10, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString m_periodChoices[] = { wxT("Weekly"), wxT("Bi-Weekly"), wxT("Semi-Monthly"), wxT("Monthly"), wxT("Quarterly"), wxT("Semi-Annually"), wxT("Annually"), wxT("Daily") };
	int m_periodNChoices = sizeof( m_periodChoices ) / sizeof( wxString );
	m_period = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_periodNChoices, m_periodChoices, 0 );
	m_period->SetSelection( 0 );
	MainSizer->Add( m_period, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Medicare:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	MainSizer->Add( m_staticText7, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_medicare = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_medicare->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	MainSizer->Add( m_medicare, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	MainSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	MainSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Social Security:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	MainSizer->Add( m_staticText8, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_socsec = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_socsec->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	MainSizer->Add( m_socsec, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	MainSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_calculate = new wxButton( this, wxID_ANY, wxT("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_calculate->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	MainSizer->Add( m_calculate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Net Pay:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	MainSizer->Add( m_staticText9, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_netpay = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_netpay->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	m_netpay->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	MainSizer->Add( m_netpay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	// Connect Events
	m_gross->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnGross ), NULL, this );
	m_filing->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::OnFiling ), NULL, this );
	m_exemptions->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnExemptions ), NULL, this );
	m_period->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::OnPeriod ), NULL, this );
	m_calculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnCalculate ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_gross->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnGross ), NULL, this );
	m_filing->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::OnFiling ), NULL, this );
	m_exemptions->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnExemptions ), NULL, this );
	m_period->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainFrame::OnPeriod ), NULL, this );
	m_calculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnCalculate ), NULL, this );
}

PaycheckHelperMainFrame::PaycheckHelperMainFrame( wxWindow* parent )
:
MainFrame( parent )
{

}

void PaycheckHelperMainFrame::OnGross( wxCommandEvent& event )
{
	std::cout << "Gross value entered" << std::endl;
}

void PaycheckHelperMainFrame::OnFiling( wxCommandEvent& event )
{
	std::cout << "Filing status selected" << std::endl;
}

void PaycheckHelperMainFrame::OnExemptions( wxCommandEvent& event )
{
	std::cout << "Exemptions value entered" << std::endl;
}

void PaycheckHelperMainFrame::OnPeriod( wxCommandEvent& event )
{
	std::cout << "Pay period selected" << std::endl;
}

void PaycheckHelperMainFrame::OnCalculate( wxCommandEvent& event )
{
	wxString gross = m_gross->GetValue();
	wxString filing = m_filing->GetString(m_filing->GetSelection());
	wxString exemptions = m_exemptions->GetValue();
	wxString period = m_period->GetString(m_period->GetSelection());
	std::cout << "Calculate button clicked" << std::endl;
	std::cout << "Gross Pay Value: " << gross << std::endl;
	std::cout << "Filing Status Value: " << filing << std::endl;
	std::cout << "Exemptions Value: " << exemptions << std::endl;
	std::cout << "Pay Period Value: " << period << std::endl;
	
	sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  wxString sql;
  float net;
  float i_tax;
  std::ostringstream conv;
  
  rc = sqlite3_open("tax.db",  &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
  }else{
    std::cout << "Opened database successfully" << std::endl;
  }
  
  float taxable = atof(gross) - (atof(exemptions)*exempt);
  float mcare = (atof(gross) * medicare);
  float ssec = (atof(gross) * socsec);
  wxString qtaxable = float_to_string(taxable);
  
  sql = "SELECT * FROM `fed_biweekly` WHERE `status` = '"+filing+"' AND '"+qtaxable+"' BETWEEN `bottom` AND `top`;";
  
  rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
  if (rc != SQLITE_OK ) {
    fprintf(stderr, "SQL error: %s\n",  zErrMsg);
  }else{
  	i_tax = taxable - bottom;
  	m_taxable->ChangeValue("$"+float_to_string(i_tax));
  	m_basetax->ChangeValue("$"+float_to_string(base));
  	m_taxrate->ChangeValue(float_to_string(pct)+"%");
  	m_medicare->ChangeValue("$"+float_to_string(mcare));
  	m_socsec->ChangeValue("$"+float_to_string(ssec));
 	net = atof(gross) - base - (i_tax*(pct/100)) - mcare - ssec;
 	std::cout << pct << std::endl;
 	m_netpay->ChangeValue("$"+float_to_string(net));
  }
}

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    PaycheckHelperMainFrame* frame = new PaycheckHelperMainFrame(NULL);
    frame->Show( true );
    return true;
}

