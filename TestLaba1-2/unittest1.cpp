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
			TestSubFirm = SubFirm(_name);
		}

		TEST_METHOD(TestFirmFactory)
		{
			//Пример строки: Имя_фирмы: Ромашка, Элетронная_почта: romashka@m.ru, Сайт: r.ru, Регион: Нижегородская область, Город: Нижний Новгород, Улица: "Горького, 1", Индекс: 603000, Страна: Россия, Дата_добавления: 01.12.2020, 
			//Дополнительные_поля: [
			//{Имя_поля: Направление, Значениие_поля: Консультационные услуги},
			//{Имя_поля: Годовой оборот, Значениие_поля: Консультационные услуги},
			//],
			//Суб_фирмы: [
			//	{Имя_суб-фирмы: Ромашка ритейл, Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Иван Иванович, Элетронная_почта: romashka_ret@m.ru, Телефон: +7(800)603-09-30, Тип_суб-фирмы: Продажа продукции, Главная_суб-фирма: да},
			//	{Имя_суб-фирмы: Ромашка продакт, Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Григорий Иванович,								   Телефон: +7(800)603-09-31, Тип_суб-фирмы: Производство продукции, Главная_суб-фирма: нет}
			//]
			TestFirm = FirmFactory().CreateFromStructuredString(string()
				+ "Имя_фирмы: Ромашка, "
				+ "Элетронная_почта: romashka@m.ru, Сайт: r.ru," 
				+ "Регион: Нижегородская область, Город: Нижний Новгород, Улица: \"Горького, 1\", Индекс: 603000, Страна: Россия, "
				+ "Дата_добавления: 01.12.2020, "
				+ "Дополнительные_поля: ["
				+ "{Имя_поля: Направление, Значениие_поля: Консультационные услуги},"
				+ "{Имя_поля: Годовой оборот, Значениие_поля: 5млн},"
				+ "],"
				+ "Суб_фирмы: ["
				+ "	{Имя_суб-фирмы: Ромашка ритейл, "
				+ "		Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Иван Иванович, "
				+ "		Элетронная_почта: romashka_ret@m.ru, Телефон: +7(800)603-09-30, "
				+ "		Тип_суб-фирмы: Продажа продукции, Главная_суб-фирма: да},"
				+ "	{Имя_суб-фирмы: Ромашка продакт, "
				+ "		Имя_начальника: Михаил Павлович, Имя_начальника_суб-фирмы: Григорий Иванович," 
				+ "		Телефон: +7(800)603-09-31, "
				+ "		Тип_суб-фирмы: Производство продукции, Главная_суб-фирма: нет}"
				+ "]");
			Firm DefFirm = Firm();
			//проверка основных полей
			Assert::AreEqual(string("Ромашка"), TestFirm.Name);
			Assert::AreEqual(string("romashka@m.ru"), TestFirm.Email);
			Assert::AreEqual(string("r.ru"), TestFirm.Web);
			Assert::AreEqual(string("Нижегородская область"), TestFirm.Region);
			Assert::AreEqual(string("Нижний Новгород"), TestFirm.Town);
			Assert::AreEqual(string("Горького, 1"), TestFirm.Street);
			Assert::AreEqual(string("603000"), TestFirm.PostInx);
			Assert::AreEqual(string("Россия"), TestFirm.Country);
			Assert::AreEqual(string("01.12.2020"), TestFirm.DateIn);
			//проверка дополнительных полей
			Assert::AreEqual(string("Консультационные услуги"), TestFirm.GetField("Направление"));
			Assert::AreEqual(string("5млн"), TestFirm.GetField("Годовой оборот"));
			//проверка суб-фирм
			SubFirm TestSbFrm = TestFirm.GetSbFirm("Ромашка ритейл");
			Assert::AreEqual(string("Ромашка ритейл"), TestSbFrm.Name);
			Assert::AreEqual(string("Михаил Павлович"), TestSbFrm.OfcBossName);
			Assert::AreEqual(string("Иван Иванович"), TestSbFrm.BossName);
			Assert::AreEqual(string("romashka_ret@m.ru"), TestSbFrm.Email);
			Assert::AreEqual(string("+7(800)603-09-30"), TestSbFrm.Tel);
			Assert::AreEqual(string("Продажа продукции"), TestSbFrm.FirmTpy.Name);
			Assert::AreEqual(true, TestSbFrm.FirmTpy.IsMain);

			TestSbFrm = TestFirm.GetSbFirm("Ромашка продакт");
			Assert::AreEqual(string("Ромашка продакт"), TestSbFrm.Name);
			Assert::AreEqual(string("Михаил Павлович"), TestSbFrm.OfcBossName);
			Assert::AreEqual(string("Григорий Иванович"), TestSbFrm.BossName);
			Assert::AreEqual(string(""), TestSbFrm.Email);
			Assert::AreEqual(string("+7(800)603-09-31"), TestSbFrm.Tel);
			Assert::AreEqual(string("Производство продукции"), TestSbFrm.FirmTpy.Name);
			Assert::AreEqual(false, TestSbFrm.FirmTpy.IsMain);
		}


	};
}