#include "stdafx.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLaba12
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		string 
			_dateIn = "20.12.2020",
			_dateEnd = "21.12.2020",
			_dataContactInfo = "письмо Ивану Ивановичу",
			_contactDescr = "отправлено письмо Ивану Ивановичу по поставкам",
			_name = "Фирма", 
			_Country = "страна", 
			_Web = "сайт", 
			_email = "элетронная почта", 
			_tel = "+7 (999) 999 99 99", 
			_bossName = "Иван Иванович",
			_contTypeName = "Электронное письмо",
			_contTypeNote = "отправлено письмо"
			;
		ContType TestContType;
		TEST_METHOD(TestContTypeClass)	
		{
			TestContType = ContType(_contTypeName, _contTypeNote);
			Assert::AreEqual(_contTypeName + _contTypeNote, TestContType.Name + TestContType.Note);
		}

		Contact TestContact;

		TEST_METHOD(TestContactClass)
		{
			TestContact = Contact(_dataContactInfo, _contactDescr, TestContType, _dateIn, _dateEnd);
			Assert::AreEqual(_dataContactInfo + _contactDescr + TestContType.Name + TestContType.Note + _dateIn + _dateEnd, 
				TestContact.DataInfo + TestContact.Descr + TestContact.CntType.Name + TestContact.CntType.Note + TestContact.BeginDt + TestContact.EndDt);
			Assert::IsTrue(TestContact == Contact(_dataContactInfo, _contactDescr, TestContType, _dateIn, _dateEnd));
			Assert::IsFalse(TestContact != Contact(_dataContactInfo, _contactDescr, TestContType, _dateIn, _dateEnd));
		}

		SbFirmType TestSbFirmType;


		SubFirm TestSubFirm;

		Firm TestFirm;



		TEST_METHOD(TestFirmFactoryClass)//TODO	
		{
			string _name = "Фирма";
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
		}

		TEST_METHOD(TestFirmClass)
		{
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
			
			TestFirm = Firm(_name, _Country, "текущатя дата", _email, _Web);
			Assert::AreEqual(_name + _Country + _Web + _email, TestFirm.Name + TestFirm.Country + TestFirm.Web + TestFirm.Email);
		}
		TEST_METHOD(TestSbFirmClass)
		{
			TestSubFirm = SubFirm(_name );
		}


	};
}