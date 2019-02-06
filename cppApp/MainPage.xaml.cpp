
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
int counter = 0;
void cppApp::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	String^ srchValText = firstTextBox->Text;
	String^ paraString;

	double dSrchVal = _wtof(srchValText->Data());
	testClassObj->setSrch(dSrchVal);

	double posOfSrch = 0.0;
	double quantOfSrch = 0.0;
	int vecSize = testClassObj->getVecSize();

	testClassObj->refVecSrchAndCount(posOfSrch, quantOfSrch);
	secValBox->Text = (quantOfSrch.ToString());

	outputVecSize->Text = vecSize.ToString();

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


	std::wstring name= ((personName->Text)->Data()); // platform_String converted to wide_string
	std::transform(name.begin(), name.end(), name.begin(), tolower);

	double number = _wtof((personNumber->Text)->Data()); // platform_String converted to double
	childTestObj->insertIntoHT(name, number);

	formsContainerName->Text += ref new String((childTestObj->getVecString(counter).append(L"\r\n")).c_str()); // wide_string converted to platform_String
	formsContainerNumber->Text += "#" + personNumber->Text + "\r\n";
	indexCounter->Text += (counter.ToString() + "\r\n");

	personName->Text = "";
	personNumber->Text = ""; 
	counter += 1;
}

void cppApp::MainPage::SrchContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	std::wstring srchName = (findPerson->Text)->Data();
	std::transform(srchName.begin(), srchName.end(), srchName.begin(), tolower);


	double returnNum = childTestObj->findValInTable(srchName);
	if (returnNum == -1) {
		numberResult->Text = "Not found.";
	}
	else {
		numberResult->Text = returnNum.ToString();
	}
	
}

// works for changing foreground color:
// formsContainerName->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Green);


// clears hash table in childClassTest
void cppApp::MainPage::ClearTable_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	childTestObj->clrTable();
}

// clears top vector searh for numbers
void cppApp::MainPage::ClearVec_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	testClassObj->clearVec();
	outputVecSize->Text = "";
}


void cppApp::MainPage::FillVec_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	testClassObj->fillVec();
}

// clears both the forms and person lookup vectors
void cppApp::MainPage::ClrForms_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	childTestObj->clrFormsVect();
	childTestObj->clrTable();
	counter = 0;

	formsContainerName->Text = "";
	formsContainerNumber->Text = "";
	indexCounter->Text = "";
}
