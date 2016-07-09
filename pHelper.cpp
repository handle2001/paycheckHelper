///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 29 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "pHelper.h"

///////////////////////////////////////////////////////////////////////////

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
