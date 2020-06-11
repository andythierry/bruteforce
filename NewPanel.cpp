#include "NewPanel.h"

//(*InternalHeaders(NewPanel)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(NewPanel)
//*)

BEGIN_EVENT_TABLE(NewPanel,wxPanel)
	//(*EventTable(NewPanel)
	//*)
END_EVENT_TABLE()

NewPanel::NewPanel(wxWindow* parent)
{
	//(*Initialize(NewPanel)
	wxXmlResource::Get()->LoadObject(this,parent,_T("NewPanel"),_T("wxPanel"));
	//*)
}

NewPanel::~NewPanel()
{
	//(*Destroy(NewPanel)
	//*)
}

