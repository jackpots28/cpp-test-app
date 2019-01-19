//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"
#include "MainPage.xaml.h"
#include <stdlib.h>

#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <sstream>



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


unique_ptr<testerFile> testClassObj(new testerFile());
unique_ptr<childClassTest> childTestObj(new childClassTest());

void cppApp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ srchValText = firstTextBox->Text;
	String^ paraString;

	//String^ s1 = secTextBox->Text;

	double dSrchVal = _wtof(srchValText->Data());
	testClassObj->setSrch(dSrchVal);
		

	//double b = _wtof(s1->Data());
	//firstTextBox->Text = (childTestObj->getSrch()).ToString();

	double posOfSrch = 0.0;
	double quantOfSrch = 0.0;

	testClassObj->refVecSrchAndCount(posOfSrch, quantOfSrch);
	secValBox->Text = (quantOfSrch.ToString());

	paraString = posOfSrch.ToString();

	if (posOfSrch == -1) {
		outputBox->Text = "Not found.";
	}
	else {
		outputBox->Text = (posOfSrch.ToString());
	}

	auto formattedText = wstring(paraString->Data()).append(L"\n");
	OutputDebugString(formattedText.c_str()); 

	// "outputBox" = srch index
	// "secValBox" = quantity of
}

void cppApp::MainPage::CheckBox_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}
