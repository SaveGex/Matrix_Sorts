#include "pch.h"
#include "CppUnitTest.h"
#include "Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
	TEST_CLASS(MatrixTest)
	{
	public:
		
		TEST_METHOD(InitTest)
		{
			
			Matrix obj1(1, 2, 0, 10);
			int** mat = obj1.get_matrix();

			Assert::IsTrue(mat != nullptr);
		}
	};
}
