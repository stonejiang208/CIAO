// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1283

#ifndef CIAO_CIF_COMPONENT_EXEC_04QPBG_H_
#define CIAO_CIF_COMPONENT_EXEC_04QPBG_H_

#include /**/ "ace/pre.h"

#include "CIF_ComponentEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "CIF_Component_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_CIF_CIF_Provider_Impl
{

  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53
  class CIF_COMPONENT_EXEC_Export provide_cif_foo_exec_i
    : public virtual ::CIF::CCM_foo,
      public virtual ::CORBA::LocalObject
  {
  public:
    provide_cif_foo_exec_i (
      ::CIF::CCM_CIF_Provider_Context_ptr ctx);
    virtual ~provide_cif_foo_exec_i (void);

    // Operations and attributes from ::CIF::foo

    virtual
    void do_foo (void);

  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_component/facet_exh.cpp:53
  class CIF_COMPONENT_EXEC_Export provide_cif_derived_foo_exec_i
    : public virtual ::CIF::CCM_derived_foo,
      public virtual ::CORBA::LocalObject
  {
  public:
    provide_cif_derived_foo_exec_i (
      ::CIF::CCM_CIF_Provider_Context_ptr ctx);
    virtual ~provide_cif_derived_foo_exec_i (void);

    // Operations and attributes from ::CIF::derived_foo

    virtual
    void do_derived_foo (void);

    virtual
    void do_foo (void);

  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
  };

  class CIF_COMPONENT_EXEC_Export CIF_Provider_exec_i
    : public virtual CIF_Provider_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CIF_Provider_exec_i (void);
    virtual ~CIF_Provider_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */


    virtual ::CIF::CCM_foo_ptr
    get_provide_cif_foo (void);

    virtual ::CIF::CCM_derived_foo_ptr
    get_provide_cif_derived_foo (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36

    virtual ::CORBA::Short
    provider_id (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36

    virtual void
    provider_id (
      ::CORBA::Short provider_id);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

  private:
    ::CIF::CCM_CIF_Provider_Context_var ciao_context_;
    ::CIF::CCM_foo_var ciao_provide_cif_foo_;
    ::CIF::CCM_derived_foo_var ciao_provide_cif_derived_foo_;

    ::CORBA::Short provider_id_;
  };

  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_Provider_Impl (void);
}

namespace CIAO_CIF_CIF_User_Impl
{

  class CIF_COMPONENT_EXEC_Export CIF_User_exec_i
    : public virtual CIF_User_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CIF_User_exec_i (void);
    virtual ~CIF_User_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */


    virtual void
    push_consume_do_something (
      ::CIF::DoSomething * ev);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36

    virtual ::CORBA::Short
    user_id (void);

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:36

    virtual void
    user_id (
      ::CORBA::Short user_id);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */

    virtual void set_session_context (::Components::SessionContext_ptr ctx);

    virtual void configuration_complete (void);

    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

  private:
    ::CIF::CCM_CIF_User_Context_var ciao_context_;

    ::CORBA::Short user_id_;
  };

  extern "C" CIF_COMPONENT_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_CIF_CIF_User_Impl (void);
}

namespace CIAO_CIF_CIF_User_Impl
{
  class CIF_COMPONENT_EXEC_Export CIF_UserHome_exec_i
    : public virtual CIF_UserHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    CIF_UserHome_exec_i (void);

    virtual ~CIF_UserHome_exec_i (void);

    // Implicit operations.

    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };

  extern "C" CIF_COMPONENT_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_CIF_CIF_UserHome_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
