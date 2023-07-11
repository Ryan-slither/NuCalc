#include <wx/wx.h>
#include <wx/gbsizer.h>
#include <vector>
#include "MainFrame.h"
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
using boost::multiprecision::cpp_dec_float_50;

const int ROWS = 6;
const int COLS = 5;
const int WIDTH = 600;
const int HEIGHT = 400;
const int ID_ONE = '1';
const int ID_TWO = '2';
const int ID_THREE = '3';
const int ID_FOUR = '4';
const int ID_FIVE = '5';
const int ID_SIX = '6';
const int ID_SEVEN = '7';
const int ID_EIGHT = '8';
const int ID_NINE = '9';
const int ID_ZERO = '0';
const int ID_DEC = '.';
const int ID_NEG = '_';
const int ID_BACK = '<';
const int ID_C = 'C';
const int ID_CE = 'E';
const int ID_ADD = '+';
const int ID_SUB = '-';
const int ID_MULTI = 'x';
const int ID_DIV = '/';
const int ID_EQUAL = '=';
const wxSize BUTTON_SIZE = wxSize(WIDTH / 5, HEIGHT/4);

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	OnWindowOpen();
	CreateControls();
	BindEventHandlers();
}

void MainFrame::CreateControls()
{
	sizer = new wxGridBagSizer();
	wxFont Font(wxFontInfo(30).FaceName("Montserrat"));
	wxFont textFont(wxFontInfo(30).FaceName("Montserrat"));
	wxFont infoFont(wxFontInfo(10).FaceName("Montserrat"));
	this->SetFont(Font);
	//ROW 1
	text = new wxTextCtrl(this, wxID_ANY, wxString("0"), wxDefaultPosition, wxSize(WIDTH, HEIGHT/12), wxTE_READONLY | wxTE_RIGHT);
	text->SetFont(textFont);
	text->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(text, { 0, 0 }, { 1, 5 }, wxEXPAND);

	//ROW 1.5
	textInfo = new wxTextCtrl(this, wxID_ANY, wxString(""), wxDefaultPosition, wxSize(WIDTH, HEIGHT/360), wxTE_READONLY | wxTE_RIGHT);
	textInfo->SetFont(infoFont);
	textInfo->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(textInfo, { 1, 0 }, { 1, 5 }, wxEXPAND);
	//ROW 2
	buttonOne = new wxButton(this, ID_ONE, wxString("1"), wxDefaultPosition, BUTTON_SIZE);
	buttonOne->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonOne, { 2, 0 }, { 1, 1 }, wxEXPAND);

	buttonTwo = new wxButton(this, ID_TWO, wxString("2"), wxDefaultPosition, BUTTON_SIZE);
	buttonTwo->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonTwo, { 2, 1 }, { 1, 1 }, wxEXPAND);

	buttonThree = new wxButton(this, ID_THREE, wxString("3"), wxDefaultPosition, BUTTON_SIZE);
	buttonThree->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonThree, { 2, 2 }, { 1, 1 }, wxEXPAND);

	buttonCE = new wxButton(this, ID_CE, wxString("CE"), wxDefaultPosition, BUTTON_SIZE);
	buttonCE->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonCE, { 2, 3 }, { 1, 1 }, wxEXPAND);

	buttonC = new wxButton(this, ID_C, wxString("C"), wxDefaultPosition, BUTTON_SIZE);
	buttonC->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonC, { 2, 4 }, { 1, 1 }, wxEXPAND);
	//ROW 3
	buttonFour = new wxButton(this, ID_FOUR, wxString("4"), wxDefaultPosition, BUTTON_SIZE);
	buttonFour->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonFour, { 3, 0 }, { 1, 1 }, wxEXPAND);

	buttonFive = new wxButton(this, ID_FIVE, wxString("5"), wxDefaultPosition, BUTTON_SIZE);
	buttonFive->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonFive, { 3, 1 }, { 1, 1 }, wxEXPAND);

	buttonSix = new wxButton(this, ID_SIX, wxString("6"), wxDefaultPosition, BUTTON_SIZE);
	buttonSix->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonSix, { 3, 2 }, { 1, 1 }, wxEXPAND);

	buttonBack = new wxButton(this, ID_BACK, wxString("<~"), wxDefaultPosition, BUTTON_SIZE);
	buttonBack->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonBack, { 3, 3 }, { 1, 1 }, wxEXPAND);

	buttonEquals = new wxButton(this, ID_EQUAL, wxString("="), wxDefaultPosition, BUTTON_SIZE);
	buttonEquals->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonEquals, { 3, 4 }, { 1, 1 }, wxEXPAND);
	//ROW 4
	buttonSeven = new wxButton(this, ID_SEVEN, wxString("7"), wxDefaultPosition, BUTTON_SIZE);
	buttonSeven->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonSeven, { 4, 0 }, { 1, 1 }, wxEXPAND);

	buttonEight = new wxButton(this, ID_EIGHT, wxString("8"), wxDefaultPosition, BUTTON_SIZE);
	buttonEight->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonEight, { 4, 1 }, { 1, 1 }, wxEXPAND);

	buttonNine = new wxButton(this, ID_NINE, wxString("9"), wxDefaultPosition, BUTTON_SIZE);
	buttonNine->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonNine, { 4, 2 }, { 1, 1 }, wxEXPAND);

	buttonAddition = new wxButton(this, ID_ADD, wxString("+"), wxDefaultPosition, BUTTON_SIZE);
	buttonAddition->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonAddition, { 4, 3 }, { 1, 1 }, wxEXPAND);

	buttonSubtraction = new wxButton(this, ID_SUB, wxString("-"), wxDefaultPosition, BUTTON_SIZE);
	buttonSubtraction->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonSubtraction, { 4, 4 }, { 1, 1 }, wxEXPAND);
	//ROW 5
	buttonNegate = new wxButton(this, ID_NEG, wxString("+/-"), wxDefaultPosition, BUTTON_SIZE);
	buttonNegate->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonNegate, { 5, 0 }, { 1, 1 }, wxEXPAND);

	buttonZero = new wxButton(this, ID_ZERO, wxString("0"), wxDefaultPosition, BUTTON_SIZE);
	buttonZero->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonZero, { 5, 1 }, { 1, 1 }, wxEXPAND);

	buttonDecimal = new wxButton(this, ID_DEC, wxString("."), wxDefaultPosition, BUTTON_SIZE);
	buttonDecimal->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonDecimal, { 5, 2 }, { 1, 1 }, wxEXPAND);

	buttonMultiplication = new wxButton(this, ID_MULTI, wxString("x"), wxDefaultPosition, BUTTON_SIZE);
	buttonMultiplication->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonMultiplication, { 5, 3 }, { 1, 1 }, wxEXPAND);

	buttonDivision = new wxButton(this, ID_DIV, wxString("/"), wxDefaultPosition, BUTTON_SIZE);
	buttonDivision->SetBackgroundColour(wxColor(100, 100, 100));
	sizer->Add(buttonDivision, { 5, 4 }, { 1, 1 }, wxEXPAND);

	for (int i = 0; i < ROWS; ++i) sizer->AddGrowableRow(i, 1);
	for (int i = 0; i < COLS; ++i) sizer->AddGrowableCol(i, 1);

	sizer->SetMinSize(FromDIP(wxSize(400, 600)));
	this->SetSizerAndFit(sizer);
}

void MainFrame::BindEventHandlers()
{
	buttonOne->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonTwo->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonThree->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonFour->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonFive->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonSix->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonSeven->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonEight->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonNine->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonZero->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonBack->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonC->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonCE->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonNegate->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonDecimal->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonAddition->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonSubtraction->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonMultiplication->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonDivision->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	buttonEquals->Bind(wxEVT_BUTTON, &MainFrame::InputHandler, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnWindowClose, this);
}

void MainFrame::OnWindowOpen()
{
	numberOne = new std::string();
	operation = new std::string("0");
	numberTwo = new std::string();
}

void MainFrame::OnWindowClose(wxCloseEvent& evt)
{
	delete numberOne;
	delete operation;
	delete numberTwo;
	evt.Skip();
}

void MainFrame::ChangeNumber()
{
	cpp_dec_float_50 x(*numberOne);
	cpp_dec_float_50 y(*numberTwo);
	cpp_dec_float_50 ans {};

	if (*operation == "/")
	{
		if (*numberTwo == "0")
		{
			text->ChangeValue("Infinity");
		}
		else
		{
			ans = x / y;
		}
	}
	if (*operation == "x")
	{
		ans = x * y;
	}
	if (*operation == "+")
	{
		ans = x + y;
	}
	if (*operation == "-")
	{
		ans = x - y;
	}

	cpp_dec_float_50 wholeNum = round(ans);
	int floatSize{};
	int wholeSize{};
	for (floatSize = 0; floatSize < 100; ++floatSize)
	{
		if (fmod(ans * pow(10, floatSize), 1) == 0) break;
	}
	for (wholeSize = 0; wholeSize < 100; ++wholeSize)
	{
		if (fmod(wholeNum, pow(10, wholeSize)) == wholeNum) break;
	}
	if (floatSize > 20) floatSize = 16;
	if (wholeSize > 20) wholeSize = 16;
	int size = floatSize + wholeSize;

	delete numberOne;
	delete operation;
	delete numberTwo;
	numberOne = new std::string(ans.str(size));
	operation = new std::string("0");
	numberTwo = new std::string();

	text->ChangeValue(*numberOne);
}

void MainFrame::InputHandler(wxCommandEvent& evt)
{
	char input = evt.GetId();
	std::string* strInfo = new std::string();

	if (input >= ID_ZERO && input <= ID_NINE && text->GetValue().size() < 21)
	{
		if (input == ID_ZERO)
		{
			if (!numberOne->empty() && *operation == "0")
			{
				numberOne->append(1, input);
				text->ChangeValue(*numberOne);
			}
			if (!numberTwo->empty())
			{
				numberTwo->append(1, input);
				text->ChangeValue(*numberTwo);
			}
		}
		else if (*operation == "0")
		{
			numberOne->append(1, input);
			text->ChangeValue(*numberOne);
		}
		else
		{
			numberTwo->append(1, input);
			text->ChangeValue(*numberTwo);
		}
	}
	if (input == ID_ADD || input == ID_SUB || input == ID_MULTI || input == ID_DIV)
	{
		if (!numberOne->empty() && *operation == "0" && !numberTwo->empty())
		{
			ChangeNumber();
			operation[0] = input;
		}
		else if (!numberOne->empty() && numberTwo->empty())
		{
			operation[0] = input;
		}
	}
	if (input == ID_C)
	{
		delete numberOne;
		delete operation;
		delete numberTwo;
		numberOne = new std::string();
		operation = new std::string("0");
		numberTwo = new std::string();
		
		text->ChangeValue("0");
	}
	if (input == ID_EQUAL)
	{
		if (numberOne->empty() || *operation == "0" || numberTwo->empty());
		else ChangeNumber();
	}
	if (input == ID_CE)
	{
		if (!numberOne->empty() && *operation != "0")
		{
			delete numberTwo;
			numberTwo = new std::string();
			text->ChangeValue("0");
		}
	}
	if (input == ID_DEC)
	{
		if (text->GetValue().find(".") == -1)
		{
			if (*operation == "0" && !numberOne->empty())
			{
				numberOne->append(1, input);
				text->ChangeValue(*numberOne);
			}
			else if (!numberTwo->empty())
			{
				numberTwo->append(1, input);
				text->ChangeValue(*numberTwo);
			}
		}
	}
	if (input == ID_NEG)
	{
		if (text->GetValue().find("-") == -1)
		{
			if (*operation == "0" && !numberOne->empty())
			{
				numberOne->insert(0, 1, '-');
				text->ChangeValue(*numberOne);
			}
			else if (!numberTwo->empty())
			{
				numberTwo->insert(0, 1, '-');
				text->ChangeValue(*numberTwo);
			}
		}
		else
		{
			if (*operation == "0" && !numberOne->empty())
			{
				numberOne->erase(0, 1);
				text->ChangeValue(*numberOne);
			}
			else if (!numberTwo->empty())
			{
				numberTwo->erase(0, 1);
				text->ChangeValue(*numberTwo);
			}
		}
	}
	if (input == ID_BACK)
	{
		if (*operation == "0" && !numberOne->empty())
		{
			numberOne->pop_back();
			if (*numberOne == "-" || *numberOne == "")
			{
				delete numberOne;
				numberOne = new std::string();
				text->ChangeValue("0");
			}
			else
			{
				text->ChangeValue(*numberOne);
			}
		}
		else if (!numberTwo->empty())
		{
			numberTwo->pop_back();
			if (*numberTwo == "-" || *numberTwo == "")
			{
				delete numberTwo;
				numberTwo = new std::string();
				text->ChangeValue("0");
			}
			else
			{
				text->ChangeValue(*numberTwo);
			}
		}
	}

	strInfo->clear();
	if (!numberOne->empty())
	{
		strInfo->append(*numberOne);
		strInfo->append(" ");
		if (*operation != "0")
		{
			strInfo->append(*operation);
			strInfo->append(" ");
			if (!numberTwo->empty())
			{
				strInfo->append(*numberTwo);
			}
		}
	}
	textInfo->ChangeValue(*strInfo);
}