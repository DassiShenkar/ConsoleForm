#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../CompleteForm/Control.h"
//#include "../CompleteForm/Panel.h"
#include "../CompleteForm/OptionsContainer.h"
#include "..\CompleteForm\RadioList.h"
//#include "..\CompleteForm\Button.h"
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestRadio
{
	TEST_CLASS(TestRadio)
	{
	public:

		TEST_METHOD(TestDraw)
		{

			string a = "Male";
			RadioList rSex(2, 15, { "Male", "Female" });
			rSex.setSelectedIndex(0);
			Assert::AreEqual(size_t(0), rSex.getSelectedIndex());

		}


	};
}