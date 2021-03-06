/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <utility>

// template <class T1, class T2> struct pair

// template <class T1, class T2> bool operator==(const pair<T1,T2>&, const pair<T1,T2>&);
// template <class T1, class T2> bool operator!=(const pair<T1,T2>&, const pair<T1,T2>&);
// template <class T1, class T2> bool operator< (const pair<T1,T2>&, const pair<T1,T2>&);
// template <class T1, class T2> bool operator> (const pair<T1,T2>&, const pair<T1,T2>&);
// template <class T1, class T2> bool operator>=(const pair<T1,T2>&, const pair<T1,T2>&);
// template <class T1, class T2> bool operator<=(const pair<T1,T2>&, const pair<T1,T2>&);

#include <utility>
#include <cassert>
#include "libcxx_tc_common.h"

#include "test_macros.h"

int tc_libcxx_utilities_pairs_spec_comparison(void)
{
    {
        typedef std::pair<int, short> P;
        P p1(3, static_cast<short>(4));
        P p2(3, static_cast<short>(4));
        TC_ASSERT_EXPR( (p1 == p2));
        TC_ASSERT_EXPR(!(p1 != p2));
        TC_ASSERT_EXPR(!(p1 <  p2));
        TC_ASSERT_EXPR( (p1 <= p2));
        TC_ASSERT_EXPR(!(p1 >  p2));
        TC_ASSERT_EXPR( (p1 >= p2));
    }
    {
        typedef std::pair<int, short> P;
        P p1(2, static_cast<short>(4));
        P p2(3, static_cast<short>(4));
        TC_ASSERT_EXPR(!(p1 == p2));
        TC_ASSERT_EXPR( (p1 != p2));
        TC_ASSERT_EXPR( (p1 <  p2));
        TC_ASSERT_EXPR( (p1 <= p2));
        TC_ASSERT_EXPR(!(p1 >  p2));
        TC_ASSERT_EXPR(!(p1 >= p2));
    }
    {
        typedef std::pair<int, short> P;
        P p1(3, static_cast<short>(2));
        P p2(3, static_cast<short>(4));
        TC_ASSERT_EXPR(!(p1 == p2));
        TC_ASSERT_EXPR( (p1 != p2));
        TC_ASSERT_EXPR( (p1 <  p2));
        TC_ASSERT_EXPR( (p1 <= p2));
        TC_ASSERT_EXPR(!(p1 >  p2));
        TC_ASSERT_EXPR(!(p1 >= p2));
    }
    {
        typedef std::pair<int, short> P;
        P p1(3, static_cast<short>(4));
        P p2(2, static_cast<short>(4));
        TC_ASSERT_EXPR(!(p1 == p2));
        TC_ASSERT_EXPR( (p1 != p2));
        TC_ASSERT_EXPR(!(p1 <  p2));
        TC_ASSERT_EXPR(!(p1 <= p2));
        TC_ASSERT_EXPR( (p1 >  p2));
        TC_ASSERT_EXPR( (p1 >= p2));
    }
    {
        typedef std::pair<int, short> P;
        P p1(3, static_cast<short>(4));
        P p2(3, static_cast<short>(2));
        TC_ASSERT_EXPR(!(p1 == p2));
        TC_ASSERT_EXPR( (p1 != p2));
        TC_ASSERT_EXPR(!(p1 <  p2));
        TC_ASSERT_EXPR(!(p1 <= p2));
        TC_ASSERT_EXPR( (p1 >  p2));
        TC_ASSERT_EXPR( (p1 >= p2));
    }

#if TEST_STD_VER > 11
    {
        typedef std::pair<int, short> P;
        constexpr P p1(3, static_cast<short>(4));
        constexpr P p2(3, static_cast<short>(2));
        static_assert(!(p1 == p2), "");
        static_assert( (p1 != p2), "");
        static_assert(!(p1 <  p2), "");
        static_assert(!(p1 <= p2), "");
        static_assert( (p1 >  p2), "");
        static_assert( (p1 >= p2), "");
    }
#endif
    TC_SUCCESS_RESULT();
    return 0;
}
