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
	};
}
