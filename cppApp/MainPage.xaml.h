#pragma once

#include "MainPage.g.h"


namespace cppApp
{
	/// <summary>
	
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CheckBox_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void AddContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void SrchContact_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ClearTable_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ClearVec_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void FillVec_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ClrForms_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void EditForm_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void AppBar_Opened(Platform::Object^ sender, Platform::Object^ e);
		void SaveData_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void IndexToEdit_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);

		void DbTest_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
	
}
