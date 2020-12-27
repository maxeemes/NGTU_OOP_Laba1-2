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
			_dataContactInfo = "������ ����� ���������",
			_contactDescr = "���������� ������ ����� ��������� �� ���������",
			_name = "�����", 
			_Country = "������", 
			_Web = "����", 
			_email = "���������� �����", 
			_tel = "+7 (999) 999 99 99", 
			_bossName = "���� ��������",
			_contTypeName = "����������� ������",
			_contTypeNote = "���������� ������"
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
			string _name = "�����";
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
		}

		TEST_METHOD(TestFirmClass)
		{
			Assert::AreEqual(_name, Firm().Name);
			Assert::AreEqual(_name + "1", Firm(_name + "1").Name);
			
			TestFirm = Firm(_name, _Country, "�������� ����", _email, _Web);
			Assert::AreEqual(_name + _Country + _Web + _email, TestFirm.Name + TestFirm.Country + TestFirm.Web + TestFirm.Email);
		}
		TEST_METHOD(TestSbFirmClass)
		{
			TestSubFirm = SubFirm(_name);
		}

		TEST_METHOD(TestFirmFactory)
		{
			//������ ������: ���_�����: �������, ����������_�����: romashka@m.ru, ����: r.ru, ������: ������������� �������, �����: ������ ��������, �����: "��������, 1", ������: 603000, ������: ������, ����_����������: 01.12.2020, 
			//��������������_����: [
			//{���_����: �����������, ���������_����: ���������������� ������},
			//{���_����: ������� ������, ���������_����: ���������������� ������},
			//],
			//���_�����: [
			//	{���_���-�����: ������� ������, ���_����������: ������ ��������, ���_����������_���-�����: ���� ��������, ����������_�����: romashka_ret@m.ru, �������: +7(800)603-09-30, ���_���-�����: ������� ���������, �������_���-�����: ��},
			//	{���_���-�����: ������� �������, ���_����������: ������ ��������, ���_����������_���-�����: �������� ��������,								   �������: +7(800)603-09-31, ���_���-�����: ������������ ���������, �������_���-�����: ���}
			//]
			TestFirm = FirmFactory().CreateFromStructuredString(string()
				+ "���_�����: �������, "
				+ "����������_�����: romashka@m.ru, ����: r.ru," 
				+ "������: ������������� �������, �����: ������ ��������, �����: \"��������, 1\", ������: 603000, ������: ������, "
				+ "����_����������: 01.12.2020, "
				+ "��������������_����: ["
				+ "{���_����: �����������, ���������_����: ���������������� ������},"
				+ "{���_����: ������� ������, ���������_����: 5���},"
				+ "],"
				+ "���_�����: ["
				+ "	{���_���-�����: ������� ������, "
				+ "		���_����������: ������ ��������, ���_����������_���-�����: ���� ��������, "
				+ "		����������_�����: romashka_ret@m.ru, �������: +7(800)603-09-30, "
				+ "		���_���-�����: ������� ���������, �������_���-�����: ��},"
				+ "	{���_���-�����: ������� �������, "
				+ "		���_����������: ������ ��������, ���_����������_���-�����: �������� ��������," 
				+ "		�������: +7(800)603-09-31, "
				+ "		���_���-�����: ������������ ���������, �������_���-�����: ���}"
				+ "]");
			Firm DefFirm = Firm();
			//�������� �������� �����
			Assert::AreEqual(string("�������"), TestFirm.Name);
			Assert::AreEqual(string("romashka@m.ru"), TestFirm.Email);
			Assert::AreEqual(string("r.ru"), TestFirm.Web);
			Assert::AreEqual(string("������������� �������"), TestFirm.Region);
			Assert::AreEqual(string("������ ��������"), TestFirm.Town);
			Assert::AreEqual(string("��������, 1"), TestFirm.Street);
			Assert::AreEqual(string("603000"), TestFirm.PostInx);
			Assert::AreEqual(string("������"), TestFirm.Country);
			Assert::AreEqual(string("01.12.2020"), TestFirm.DateIn);
			//�������� �������������� �����
			Assert::AreEqual(string("���������������� ������"), TestFirm.GetField("�����������"));
			Assert::AreEqual(string("5���"), TestFirm.GetField("������� ������"));
			//�������� ���-����
			SubFirm TestSbFrm = TestFirm.GetSbFirm("������� ������");
			Assert::AreEqual(string("������� ������"), TestSbFrm.Name);
			Assert::AreEqual(string("������ ��������"), TestSbFrm.OfcBossName);
			Assert::AreEqual(string("���� ��������"), TestSbFrm.BossName);
			Assert::AreEqual(string("romashka_ret@m.ru"), TestSbFrm.Email);
			Assert::AreEqual(string("+7(800)603-09-30"), TestSbFrm.Tel);
			Assert::AreEqual(string("������� ���������"), TestSbFrm.FirmTpy.Name);
			Assert::AreEqual(true, TestSbFrm.FirmTpy.IsMain);

			TestSbFrm = TestFirm.GetSbFirm("������� �������");
			Assert::AreEqual(string("������� �������"), TestSbFrm.Name);
			Assert::AreEqual(string("������ ��������"), TestSbFrm.OfcBossName);
			Assert::AreEqual(string("�������� ��������"), TestSbFrm.BossName);
			Assert::AreEqual(string(""), TestSbFrm.Email);
			Assert::AreEqual(string("+7(800)603-09-31"), TestSbFrm.Tel);
			Assert::AreEqual(string("������������ ���������"), TestSbFrm.FirmTpy.Name);
			Assert::AreEqual(false, TestSbFrm.FirmTpy.IsMain);
		}


	};
}