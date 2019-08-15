﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Button;
                ref class TextBlock;
                ref class TextBox;
            }
        }
    }
}

namespace cppApp
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class MainPage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        void UnloadObject(::Windows::UI::Xaml::DependencyObject^ dependencyObject);
        void DisconnectUnloadedObject(int connectionId);
    
    private:
        bool _contentLoaded;
    
        class MainPage_obj1_Bindings;
    
        private: ::Windows::UI::Xaml::Controls::Button^ clearPersonTable;
        private: ::Windows::UI::Xaml::Controls::Button^ clearVec;
        private: ::Windows::UI::Xaml::Controls::Button^ fillVec;
        private: ::Windows::UI::Xaml::Controls::Button^ clrForms;
        private: ::Windows::UI::Xaml::Controls::Button^ saveData;
        private: ::Windows::UI::Xaml::Controls::Button^ calculate;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ outputBox;
        private: ::Windows::UI::Xaml::Controls::TextBox^ firstTextBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ secValBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ outputVecSize;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ quantTitleBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ compartTitleNumber;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ vecSize;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ frstIndexTitleBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ inputTxtBlock;
        private: ::Windows::UI::Xaml::Controls::Button^ addContact;
        private: ::Windows::UI::Xaml::Controls::Button^ srchContact;
        private: ::Windows::UI::Xaml::Controls::TextBox^ personName;
        private: ::Windows::UI::Xaml::Controls::TextBox^ personNumber;
        private: ::Windows::UI::Xaml::Controls::TextBox^ findPerson;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ numberResult;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ titlePersonName;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ titlePersonNumber;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ compartTitle;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ titleForPersonSrch;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ indexFormsBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ nameFormsBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ numberFormsBox;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ formsTextBlk;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ formsEditNameDis;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ formsEditIndexDis;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ formsContainerName;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ formsContainerNumber;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ indexCounter;
        private: ::Windows::UI::Xaml::Controls::Button^ editForm;
        private: ::Windows::UI::Xaml::Controls::TextBox^ indexToEdit;
        private: ::Windows::UI::Xaml::Controls::TextBox^ editName;
    };
}

