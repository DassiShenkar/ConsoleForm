#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Label/Label.h"
#include "../Control/Control.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabelTest
{		
	TEST_CLASS(LabelTest)
	{
	public:
		
		TEST_METHOD(TestGetSetText)
		{
			Label l1(10);
			l1.setText("Test");
			string s = "Test";
			Assert::AreEqual(l1.getText(), s);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetText)
		{
			Label l1(10);
			l1.setText("Test");
			string s = "Test";
			Assert::AreEqual(l1.getText(), s);
			// TODO: Your test code here
		}

		

	};
}