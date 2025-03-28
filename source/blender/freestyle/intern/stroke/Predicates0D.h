/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/** \file
 * \ingroup freestyle
 * \brief Class gathering stroke creation algorithms
 */

#include "../view_map/Functions0D.h"

#include "MEM_guardedalloc.h"

namespace Freestyle {

//
// UnaryPredicate0D (base class for predicates in 0D)
//
///////////////////////////////////////////////////////////

/** Base class for Unary Predicates that work on Interface0DIterator.
 *  A UnaryPredicate0D is a functor that evaluates a condition on a Interface0DIterator and returns
 *  true or false depending on whether this condition is satisfied or not.
 *  The UnaryPredicate0D is used by calling its () operator.
 *  Any inherited class must overload the () operator.
 */
class UnaryPredicate0D {
 public:
  bool result;
  void *py_up0D;

  /** Default constructor. */
  UnaryPredicate0D()
  {
    py_up0D = 0;
  }

  /** Destructor. */
  virtual ~UnaryPredicate0D() {}

  /** Returns the string of the name of the UnaryPredicate0D. */
  virtual string getName() const
  {
    return "UnaryPredicate0D";
  }

  /** The () operator. Must be overload by inherited classes.
   *  \param it:
   *    The Interface0DIterator pointing onto the Interface0D at which we wish to evaluate the
   * predicate. \return true if the condition is satisfied, false otherwise.
   */
  virtual int operator()(Interface0DIterator &it);

  MEM_CXX_CLASS_ALLOC_FUNCS("Freestyle:UnaryPredicate0D")
};

//
// BinaryPredicate0D (base class for predicates in 0D)
//
///////////////////////////////////////////////////////////

/** Base class for Binary Predicates working on Interface0D.
 *  A BinaryPredicate0D is typically an ordering relation between two Interface0D.
 *  It evaluates a relation between 2 Interface0D and returns true or false.
 *  It is used by calling the () operator.
 */
class BinaryPredicate0D {
 public:
  bool result;
  void *py_bp0D;

  /** Default constructor. */
  BinaryPredicate0D()
  {
    py_bp0D = 0;
  }

  /** Destructor. */
  virtual ~BinaryPredicate0D() {}

  /** Returns the string of the name of the binary predicate. */
  virtual string getName() const
  {
    return "BinaryPredicate0D";
  }

  /** The () operator. Must be overload by inherited classes.
   *  It evaluates a relation between 2 Interface0D.
   *  \param inter1:
   *    The first Interface0D.
   *  \param inter2:
   *    The second Interface0D.
   *  \return true or false.
   */
  virtual int operator()(Interface0D &inter1, Interface0D &inter2);

  MEM_CXX_CLASS_ALLOC_FUNCS("Freestyle:BinaryPredicate0D")
};

//
// Predicates definitions
//
///////////////////////////////////////////////////////////

namespace Predicates0D {

// TrueUP0D
/** Returns true any time */
class TrueUP0D : public UnaryPredicate0D {
 public:
  /** Default constructor. */
  TrueUP0D() {}

  /** Returns the string "TrueUP0D". */
  string getName() const
  {
    return "TrueUP0D";
  }

  /** The () operator. */
  int operator()(Interface0DIterator &)
  {
    result = true;
    return 0;
  }
};

// FalseUP0D
/** Returns false any time */
class FalseUP0D : public UnaryPredicate0D {
 public:
  /** Default constructor. */
  FalseUP0D() {}

  /** Returns the string "FalseUP0D". */
  string getName() const
  {
    return "FalseUP0D";
  }

  /** The () operator. */
  int operator()(Interface0DIterator &)
  {
    result = false;
    return 0;
  }
};

}  // end of namespace Predicates0D

} /* namespace Freestyle */
