
#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"
#include "MainPage.xaml.h"
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <sstream>
#include <cwctype>
#include <optional>

using std::optional;
using std::nullopt;
using std::unique_ptr;

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

	double dSrchVal = _wtof(srchValText->Data());
	testClassObj->setSrch(dSrchVal);

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

	auto formattedText = std::wstring(paraString->Data()).append(L"\n");
	OutputDebugString(formattedText.c_str()); 

	// "outputBox" = srch index
	// "secValBox" = quantity of
}

void cppApp::MainPage::AddContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// test -- srchResultNumber->Text = number.ToString();
	// test -- findPerson->Text = ref new String(name.c_str());


	std::wstring name= ((personName->Text)->Data());
	std::transform(name.begin(), name.end(), name.begin(), tolower);

	double number = _wtof((personNumber->Text)->Data());
	childTestObj->insertIntoHT(name, number);

	personName->Text = "";
	personNumber->Text = "";
}

void cppApp::MainPage::SrchContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	std::wstring srchName = ((findPerson->Text)->Data());
	std::transform(srchName.begin(), srchName.end(), srchName.begin(), tolower);

	double returnNum = childTestObj->findValInTable(srchName);
	if (returnNum == -1) {
		numberResult->Text = "Not found.";
	}
	else {
		numberResult->Text = returnNum.ToString();
	}
}


// clears hash table in childClassTest
void cppApp::MainPage::ClearTable_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	childTestObj->clrTable();
}
