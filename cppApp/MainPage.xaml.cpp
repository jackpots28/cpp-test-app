
#include "pch.h"
#include "testerFile.h"
#include "childClassTest.h"
#include "MainPage.xaml.h"


// Lasted edited AUG 18TH
//------------------------
// check line 246 for comments
// also changed preprocessor definitions under----v
//                                       "cppApp Properties"
//----------------------------------------------------------

using std::unique_ptr;
using std::shared_ptr;

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

std::string fileNameCPP = "cppText";

shared_ptr<testerFile> testClassObj(new testerFile());
shared_ptr<childClassTest> childTestObj(new childClassTest());


std::string msg = "THIS IS A TEST.";
unique_ptr<testerFile> streamTest(new testerFile(fileNameCPP));

int counter = 0; // counter for word storage in AddContact_Click vector
std::vector<std::wstring>outsideVec; // vector to hold names to edit

MainPage::MainPage()
{
	InitializeComponent();
	indexToEdit->IsEnabled = false;
	editName->IsEnabled = false;
}

// Think about coming back in and adding documentation 
// to what exactly this button click event does
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


// Also document this AddContact_Click event
// look through and references to childClassTest for methods meanings
void cppApp::MainPage::AddContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// test -- srchResultNumber->Text = number.ToString();
	// test -- findPerson->Text = ref new String(name.c_str());


	std::wstring name= ((personName->Text)->Data()); // platform_String converted to wide_string
	std::transform(name.begin(), name.end(), name.begin(), tolower);

	double number = _wtof((personNumber->Text)->Data()); // platform_String converted to double
	childTestObj->insertIntoHT(name, counter);
	outsideVec.push_back(name.append(L"\r\n"));

	formsContainerName->Text += ref new String((outsideVec.at(counter)).c_str()); // wide_string converted to platform_String

	formsContainerNumber->Text += "#" + personNumber->Text + "\r\n";
	indexCounter->Text += (counter.ToString() + "\r\n");

	personName->Text = "";
	personNumber->Text = ""; 
	counter += 1;
	editForm->IsEnabled = true;
	indexToEdit->IsEnabled = true;
	editName->IsEnabled = true;
}


// search hashtable via double "key"
void cppApp::MainPage::SrchContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int srchName = _wtoi((findPerson->Text)->Data());
	// std::transform(srchName.begin(), srchName.end(), srchName.begin(), tolower);

	auto returnString = childTestObj->findValInTable(srchName);

	// escape word for if unordered map returns a wide string of "Nil"
	if (returnString == L"Nil") {
		numberResult->Text = "Not found.";
	}
	else {
		numberResult->Text = ref new String(returnString.c_str());
		// editForm->Background = ref new SolidColorBrush(Windows::UI::ColorHelper::FromArgb(255, 20, 158, 60));
	}
	
}

// works for changing foreground color:
// formsContainerName->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Green);


// clears hash table in childClassTest
void cppApp::MainPage::ClearTable_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	childTestObj->clrTable();

	findPerson->Text = "";
	numberResult->Text = "";

	editForm->IsEnabled = false;
	indexToEdit->IsEnabled = false;
	editName->IsEnabled = false;
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
// also sets "edit" button back to disabled
void cppApp::MainPage::ClrForms_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	childTestObj->clrFormsVect();
	childTestObj->clrTable();
	counter = 0;
	outsideVec.clear();

	formsContainerName->Text = "";
	formsContainerNumber->Text = "";
	indexCounter->Text = "";

	findPerson->Text = "";
	numberResult->Text = "";

	editForm->IsEnabled = false;
	indexToEdit->IsEnabled = false;
	editName->IsEnabled = false;
}


void cppApp::MainPage::EditForm_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (!outsideVec.empty()) {

		//**************************************************************//
		//		This is how I can update the "Forms" Name section		//
		//		saving a copy of the platform string in a wstring		//
		//		then editing what I want in the wstring and writing		//
		//		back to the "formsContainerName" platform string		//
		//**************************************************************//

		// tmp wide string to hold contents of the formsContainerName platform string
		// childTestObj->setOutsideToChildVec(outsideVec);
		std::wstring fndStr; //= ((formsContainerName->Text)->Data());

		/*for (int i = 0; i < childTestObj->getVecSize(); i++) {
			fndStr += childTestObj->getVecString(i);
		}*/


		// outsideVec.at(2) = L"hello";
		std::wstring newText = (editName->Text)->Data();
		int index = _wtoi((indexToEdit->Text)->Data());
		int sizeOfVec = outsideVec.size();

		// test for index within range for outSideVec
		if (index < sizeOfVec && index > -1) {
			outsideVec.at(index) = (newText.append(L"\r\n"));

			for (int i = 0; i < outsideVec.size(); i++) {
				fndStr += (outsideVec.at(i));
				childTestObj->editHashTable(i, outsideVec);
			}

			editName->Text = "";
			indexToEdit->Text = "";

			// rewrite the formsContainerName->Text with the updated tmp wide string
			formsContainerName->Text = ref new String(fndStr.c_str());
			
			/// Debugging test
			std::wstring indexOP = L"--Name value changed--\nSize of vec: " + std::to_wstring(sizeOfVec);
			OutputDebugString(indexOP.c_str());
		}
		else if(index > sizeOfVec - 1 || index < 0) {
			editName->Text = "";
			indexToEdit->Text = "";

			/// Debugging test
			OutputDebugString(L"--Index is out of range--\n");
		}
	}

	else {
		return;
	}
}


void cppApp::MainPage::AppBar_Opened(Platform::Object^ sender, Platform::Object^ e)
{

}


// Used to save variable states and/or off load hash tables and vectors to files
void cppApp::MainPage::SaveData_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////															    ////
	////  This is where I left off, AUG 18TH. Unsure of what to do to   ////
	////  fix any of the issues with opening files via button click or  ////
	////  using outside class construction to open files                ////
	////															    ////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	//----v
	//   edited "testerFile.cpp" and---v
	//                               "testerFile.h"


	streamTest->writeToFile(msg);

	char buff[100];
	std::fstream of;

	of.open("isThisCreated.txt");
	if (of.is_open()) {
		while (!of.eof()) {
			of >> buff;

			std::string s(buff);
			std::wstring out(s.begin(), s.end());
			quantTitleBox->Text = ref new String(out.c_str());
			OutputDebugString(out.c_str());
		}
	}
	else if (!of.is_open()) {
		quantTitleBox->Text = "File not opened";
	}
	//of.close();

	static int i = 1;
	// saveData->Background = ref new SolidColorBrush(Windows::UI::Colors::Blue);
	if (i % 2 == 0) {
		saveData->Background = ref new SolidColorBrush(Windows::UI::Colors::White);
		// i++;
	}
	else if (i % 2 != 0) {
		saveData->Background = ref new SolidColorBrush(Windows::UI::Colors::LightSlateGray);
		// i++;
	}
	i++;
}


void cppApp::MainPage::IndexToEdit_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}
