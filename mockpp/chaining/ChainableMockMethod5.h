/** @file
    @brief  Chainable Mock Method with 5 parameters.
            Generated with gen_chainablemethod_N.pl.

  $Id: ChainableMockMethod5.h,v 1.7 2005/10/19 20:53:09 ewald-arnold Exp $

 ***************************************************************************/

/**************************************************************************

   begin                : Thu Oct 2 2005
   copyright            : (C) 2002-2007 by Ewald Arnold
   email                : mockpp at ewald-arnold dot de

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 **/

#ifndef MOCKPP_ChainableMockMethod5_H
#define MOCKPP_ChainableMockMethod5_H

#include <mockpp/mockpp.h>

#include <mockpp/chaining/ChainableMockObject.h>
#include <mockpp/chaining/ChainableMockMethod.h>

#include <mockpp/chaining/TypeTraits.h>
#include <mockpp/chaining/IsAnyType.h>
#include <mockpp/chaining/IsRef.h>
#include <mockpp/chaining/OutBoundAnyValue.h>


MOCKPP_NS_START


/** Common stuff to set up chainable mock method expectations with 5 parameters.
  * @ingroup grp_chainer
  * @internal
  */
template <typename RT, typename P1, typename P2, typename P3, typename P4, typename P5>
class ChainableMockMethod5Common
  : public ChainableMockMethodCommon
  , public ChainingMockBuilder <ArgumentsMatchBuilder5<RT, Invocation5<P1, P2, P3, P4, P5> > >
{
  public:

    typedef Invocation5<P1, P2, P3, P4, P5>                InvocationType;  //!< internal shorthand

    typedef CoreMock<RT, InvocationType>                      CoreMockType;   //!< internal shorthand
    typedef RT                                                ReturnType;     //!< internal shorthand

	 typedef typename TypeTraits<RT>::RefType          RRT;     //!< internal shorthand

	 typedef typename TypeTraits<P1>::Type  OT1;     //!< internal shorthand
	 typedef typename TypeTraits<P2>::Type  OT2;     //!< internal shorthand
	 typedef typename TypeTraits<P3>::Type  OT3;     //!< internal shorthand
	 typedef typename TypeTraits<P4>::Type  OT4;     //!< internal shorthand
	 typedef typename TypeTraits<P5>::Type  OT5;     //!< internal shorthand

    typedef ChainingMockBuilder <ArgumentsMatchBuilder5<ReturnType, InvocationType> > Builder; //!< internal shorthand

  /** Constructs the mock object.
    * @param name    human readable description about the expectation
    * @param parent  parent chainable mock object
    */
    ChainableMockMethod5Common(const String &name, ChainableMockObject *parent )
      : ChainableMockMethodCommon(name, parent)
      , Builder(&coremock, this->getChainableMockObject(), this->getMethodName())
      , coremock(name + MOCKPP_PCHAR("/coreMock"), this)
    {
    }

  protected:

  /** Returns the underlying coremock.
    * @return reference to the mock object
    */
    CoreMockType & getCoreMock() const
    {
      return coremock;
    }

  private:

    mutable CoreMockType    coremock;
};


/** Set up a chainable mock method expectations with 5 parameters.
  * @ingroup grp_chainer
  */
template <typename RT, typename P1, typename P2, typename P3, typename P4, typename P5>
class ChainableMockMethod5
  : public ChainableMockMethod5Common<RT, P1, P2, P3, P4, P5>
{

    static const bool rtIsAny  =  IsAnyType<RT>::isTrue;     //!< internal shorthand 
	 static const bool p1IsAny  =  IsAnyType<P1>::isTrue;     //!< internal shorthand
	 static const bool p2IsAny  =  IsAnyType<P2>::isTrue;     //!< internal shorthand
	 static const bool p3IsAny  =  IsAnyType<P3>::isTrue;     //!< internal shorthand
	 static const bool p4IsAny  =  IsAnyType<P4>::isTrue;     //!< internal shorthand
	 static const bool p5IsAny  =  IsAnyType<P5>::isTrue;     //!< internal shorthand

  public:

    typedef typename ChainableMockMethod5Common<RT, P1, P2, P3, P4, P5>::InvocationType   InvocationType;  //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<RT, P1, P2, P3, P4, P5>::RRT   RRT;     //!< internal shorthand

	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT1   OT1;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT2   OT2;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT3   OT3;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT4   OT4;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT5   OT5;     //!< internal shorthand

  /** Constructs the mock object.
    * @param name    human readable description about the expectation
    * @param parent  parent chainable mock object
    */
    ChainableMockMethod5(const String &name, ChainableMockObject *parent )
      : ChainableMockMethod5Common<RT, P1, P2, P3, P4, P5>(name, parent)
    {
    }

  /** Actually verifies the mocked method.
    * Must be called by the client code.
    * @param p1 mock method parameter 1
    * @param p2 mock method parameter 2
    * @param p3 mock method parameter 3
    * @param p4 mock method parameter 4
    * @param p5 mock method parameter 5
    * @return the calculated value
    */
    RRT forward(const OT1 &p1, const OT2 &p2, const OT3 &p3, const OT4 &p4, const OT5 &p5) const
    {
      InvocationType inv(this->getMethodName(), p1, p2, p3, p4, p5);
      return this->getCoreMock().invoke(inv);
    }

    RT operator () (P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) const
    {
      return forward(p1, p2, p3, p4, p5);
    }

    template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
    typename TypeTraits<R>::RefType anycall(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5) const
    {
      const bool outBoundP1 = p1IsAny && IsRef<T1>::outBoundable;
      const bool outBoundP2 = p2IsAny && IsRef<T2>::outBoundable;
      const bool outBoundP3 = p3IsAny && IsRef<T3>::outBoundable;
      const bool outBoundP4 = p4IsAny && IsRef<T4>::outBoundable;
      const bool outBoundP5 = p5IsAny && IsRef<T5>::outBoundable;
  
      P1 pp1 = p1;
      P2 pp2 = p2;
      P3 pp3 = p3;
      P4 pp4 = p4;
      P5 pp5 = p5;
  
      RRT r = forward(pp1, pp2, pp3, pp4, pp5);

      OutBoundAnyValue<outBoundP1, T1>::outBound(p1, pp1);
      OutBoundAnyValue<outBoundP2, T2>::outBound(p2, pp2);
      OutBoundAnyValue<outBoundP3, T3>::outBound(p3, pp3);
      OutBoundAnyValue<outBoundP4, T4>::outBound(p4, pp4);
      OutBoundAnyValue<outBoundP5, T5>::outBound(p5, pp5);
  
      return rtIsAny ? any_cast<typename TypeTraits<R>::RefType>(r) : r;    
    }

};


/** Set up a chainable mock method expectations with 5 parameters.
  * Partial specialisation for a void return value.
  * @ingroup grp_chainer
  */
template <typename P1, typename P2, typename P3, typename P4, typename P5>
class ChainableMockMethod5<void, P1, P2, P3, P4, P5>
  : public ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>
{

	 static const bool p1IsAny  =  IsAnyType<P1>::isTrue;     //!< internal shorthand
	 static const bool p2IsAny  =  IsAnyType<P2>::isTrue;     //!< internal shorthand
	 static const bool p3IsAny  =  IsAnyType<P3>::isTrue;     //!< internal shorthand
	 static const bool p4IsAny  =  IsAnyType<P4>::isTrue;     //!< internal shorthand
	 static const bool p5IsAny  =  IsAnyType<P5>::isTrue;     //!< internal shorthand

  public:
 
    typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::InvocationType   InvocationType;  //!< internal shorthand

	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT1   OT1;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT2   OT2;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT3   OT3;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT4   OT4;     //!< internal shorthand
	 typedef typename ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>::OT5   OT5;     //!< internal shorthand

  /** Constructs the mock object.
    * @param name    human readable description about the expectation
    * @param parent  parent chainable mock object
    */
    ChainableMockMethod5(const String &name, ChainableMockObject *parent )
      : ChainableMockMethod5Common<void, P1, P2, P3, P4, P5>(name, parent)
    {
    }

  /** Actually verifies the mocked method.
    * Must be called by the client code.
    * @param p1 mock method parameter 1
    * @param p2 mock method parameter 2
    * @param p3 mock method parameter 3
    * @param p4 mock method parameter 4
    * @param p5 mock method parameter 5
    */
    void forward(const OT1 &p1, const OT2 &p2, const OT3 &p3, const OT4 &p4, const OT5 &p5) const
    {
      InvocationType inv(this->getMethodName(), p1, p2, p3, p4, p5);
      this->getCoreMock().invoke(inv);
    }

    void operator () (P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) const
    {
      forward(p1, p2, p3, p4, p5);
    }

    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    void anycall(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5) const
    {
      const bool outBoundP1 = p1IsAny && IsRef<T1>::outBoundable;
      const bool outBoundP2 = p2IsAny && IsRef<T2>::outBoundable;
      const bool outBoundP3 = p3IsAny && IsRef<T3>::outBoundable;
      const bool outBoundP4 = p4IsAny && IsRef<T4>::outBoundable;
      const bool outBoundP5 = p5IsAny && IsRef<T5>::outBoundable;

      P1 pp1 = p1;
      P2 pp2 = p2;
      P3 pp3 = p3;
      P4 pp4 = p4;
      P5 pp5 = p5;

      forward(pp1, pp2, pp3, pp4, pp5);

      OutBoundAnyValue<outBoundP1, T1>::outBound(p1, pp1);
      OutBoundAnyValue<outBoundP2, T2>::outBound(p2, pp2);
      OutBoundAnyValue<outBoundP3, T3>::outBound(p3, pp3);
      OutBoundAnyValue<outBoundP4, T4>::outBound(p4, pp4);
      OutBoundAnyValue<outBoundP5, T5>::outBound(p5, pp5);
    }

};


MOCKPP_NS_END


#endif // MOCKPP_ChainableMockMethod5_H

