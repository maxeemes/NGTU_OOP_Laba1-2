#include "stdafx.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLaba12
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		string _name = "�����", _Country = "������", _Web = "����", _email = "���������� �����", _tel = "+7 (999) 999 99 99";
		TEST_METHOD(TestFirmFactoryClass)
		{
			string _name = "�����";
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
		}

		TEST_METHOD(TestFirmClass)
		{
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
			
			Firm TestFirm = Firm(_name, _Country, "�������� ����", _email, _Web);
			Assert::AreEqual(_name + _Country + _Web + _email, TestFirm.Name + TestFirm.Country + TestFirm.Web + TestFirm.Email);
		}
		TEST_METHOD(TestSbFirmClass)
		{

		}


	};
}