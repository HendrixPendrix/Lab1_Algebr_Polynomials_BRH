//#include "polinom.h"
//#include <gtest.h>
//
//TEST(TPolinom, can_create_polinom)
//{
//	ASSERT_NO_THROW(TPolinom p);
//}
//TEST(TPolinom, can_set_polinom)
//{
//	ASSERT_NO_THROW(TPolinom p("x^2*y^1*z^4+x^1*y^3*z^1"));
//}
//TEST(TPolinom, can_create_copy)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k(p);
//	EXPECT_EQ(p.GetPolinom(), k.GetPolinom());
//}
//TEST(TPolinom, can_equate)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k("x1*y1*z2+x4*y2*z1");
//	ASSERT_NO_THROW(k = p);
//}
//TEST(TPolinom, can_addition)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k(p);
//	ASSERT_NO_THROW(p + k);
//}
//TEST(TPolinom, can_subtract)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k("x2*y1*z4");
//	ASSERT_NO_THROW(p - k);
//}
//TEST(TPolinom, can_multiply)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	TPolinom k("x2*y1*z4");
//	ASSERT_NO_THROW(p*k);
//}
//TEST(TPolinom, can_integration)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Integration(p, 'x'));
//}
//TEST(TPolinom, can_differtiation)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Differentiation(p, 'x'));
//}
//TEST(TPolinom, can_calculate)
//{
//	TPolinom p("x2*y1*z4+x1*y3*z1");
//	ASSERT_NO_THROW(p.Calculate(1, 2, 3));
//}