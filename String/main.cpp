#include"String.h"

//#define CONSTRUCTORS_CHECK
//#define COPY_SEMANTIC_CHECK


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK

	String str1;
	str1.print();
	String str2(5);      // Conversion from 'int' to 'String'
	str2.print();
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;
	String str4 = "World";
	cout << str4 << endl;
	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;

#endif // CONSTRUCTORS_CHECK

#ifdef COPY_SEMANTIC_CHECK

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = str1;
	str2 = str1;
	cout << str2 << endl;

#endif // DEBUG

	String str1;    // DefaultConstructor                 - по умолчанию
	str1.print();

	String str2(5); //
	str2.print();

	String str3 = "Hello";   //Single-argument Constructor (const char str[])        - это преобразование типов
	str3.print();

	String str4();  // В этой строке Не вызывается DefaultConstructor, и НЕ создается объект, здесь оьъявляется функция 'str4', которая ничего не принимает, и возращает значение типа 'String'
	//str4 не является объектом // то есть, круглые скобки не делают явный вызов конструктора по умолчанию, если есть необходимость явно вызвать констуртор по умолчанию, 
	// то это можно сделать при помощи фигурных скобок:

	String str5{};  // А это строка уже явно вызывает DefaultConstructor()
	str5.print();

	String str6{ 6 };  // Single-argument Constructor (int)
	str6.print();

	String str7{ "World" };     // CopyConstructor
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	// !!!!!!!!!!!!! Фигурные скобки для вызова конструкторов следует использовать с большой осторожность !!!!!!!!!!!!!!!

	String str11 = str3 + str8;
	str11.print();
	cout << str11 << endl;

}