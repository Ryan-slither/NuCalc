#pragma once
#include <wx/wx.h>
#include <wx/gbsizer.h>
#include <string>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	void CreateControls();
	void BindEventHandlers();
	void OnWindowOpen();
	void OnWindowClose(wxCloseEvent& evt);
	void ChangeNumber();
	void InputHandler(wxCommandEvent& evt);

	std::string* numberOne;
	std::string* operation;
	std::string* numberTwo;

	wxGridBagSizer* sizer;

	wxTextCtrl* text;
	wxTextCtrl* textInfo;

	wxButton* buttonOne;
	wxButton* buttonTwo;
	wxButton* buttonThree;
	wxButton* buttonFour;
	wxButton* buttonFive;
	wxButton* buttonSix;
	wxButton* buttonSeven;
	wxButton* buttonEight;
	wxButton* buttonNine;
	wxButton* buttonZero;
	wxButton* buttonNegate;
	wxButton* buttonDecimal;
	wxButton* buttonEquals;
	wxButton* buttonBack;
	wxButton* buttonAddition;
	wxButton* buttonSubtraction;
	wxButton* buttonDivision;
	wxButton* buttonMultiplication;
	wxButton* buttonC;
	wxButton* buttonCE;
};

