//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "testerFile.h"
#include "MainPage.xaml.h"
#include <iostream>
#include <memory>

using std::unique_ptr;
using namespace std;

using namespace cppApp;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

MainPage::MainPage()
{
	InitializeComponent();
}

unique_ptr<testerFile> obj1(new testerFile);

void cppApp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	String^ srchValText = firstTextBox->Text;
	//String^ s1 = secTextBox->Text;

	double dSrchVal = _wtof(srchValText->Data());
	obj1->setSrch(dSrchVal);

	//double b = _wtof(s1->Data());

	double posOfSrch = 0.0;
	double quantOfSrch = 0.0;

	obj1->refVecSrchAndCount(posOfSrch, quantOfSrch);
	secValBox->Text = (quantOfSrch.ToString());

	if (posOfSrch == -1) {
		outputBox->Text = "Val not found.";
	}
	else {
		outputBox->Text = (posOfSrch.ToString());
	}

	// "firstValBox" = srch index
	// "secValBox" = quantity of
	
}


void cppApp::MainPage::CheckBox_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}
