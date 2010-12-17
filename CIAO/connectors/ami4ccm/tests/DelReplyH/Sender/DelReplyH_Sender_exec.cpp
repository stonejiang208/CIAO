// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.8.3
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

#include "DelReplyH_Sender_exec.h"
#include "ace/OS_NS_unistd.h"

namespace CIAO_DelReplyH_Sender_Impl
{

  //============================================================
  // Worker thread for asynchronous invocations for MyFoo
  //============================================================
  asynch_foo_generator::asynch_foo_generator (
    ::DelReplyH::CCM_Sender_Context_ptr context,
     Atomic_UShort  &nr_callbacks,
     Atomic_UShort  &nr_exceptions)
   : context_(::DelReplyH::CCM_Sender_Context::_duplicate (context)),
     nr_callbacks_(nr_callbacks),
     nr_exceptions_(nr_exceptions)
  {
  }

  int asynch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::DelReplyH::AMI4CCM_MyFoo_var my_foo_ami_  =
        this->context_->get_connection_sendc_run_my_foo();

    if (CORBA::is_nil (my_foo_ami_))
      {
        ACE_ERROR ((LM_ERROR,
                    "ERROR Sender (ASYNCH) :\tfoo_ami is NIL !\n"));
        return 1;
      }
    else
      {
        //Invoke Asynchronous calls
        //test with  replyhandler.
        ::DelReplyH::AMI4CCM_MyFooReplyHandler_var cb =
            new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
                                                      this->nr_callbacks_,
                                                      this->nr_exceptions_);

        my_foo_ami_->sendc_foo(cb.in(),
                               "Do something asynchronous");

      }
     //Invoke Asynchronous calls to test exception handling
     ::DelReplyH::AMI4CCM_MyFooReplyHandler_var cb2 =
         new AMI4CCM_MyFooReplyHandler_run_my_foo_i (
                                                   this->nr_callbacks_,
                                                   this->nr_exceptions_);

     my_foo_ami_->sendc_foo (cb2.in (), "");

     return 0;
  }
  //============================================================
  // Worker thread for synchronous invocations for MyFoo
  //============================================================
  synch_foo_generator::synch_foo_generator (
     ::DelReplyH::CCM_Sender_Context_ptr context)
  : context_(::DelReplyH::CCM_Sender_Context::_duplicate (context))
  {
  }

  int synch_foo_generator::svc ()
  {
    ACE_OS::sleep (3);
    ::DelReplyH::MyFoo_var my_foo_ami_ =
      this->context_->get_connection_run_my_foo ();

    //run some synch calls
    try
      {
        CORBA::String_var answer;
        my_foo_ami_->foo("synchronous call", answer.out ());
        ACE_DEBUG ((LM_DEBUG, "OK: SYNCH foo returns <%C>.\n",
                               answer.in ()));
      }
    catch (const DelReplyH::InternalError& )
      {
        ACE_ERROR ((LM_ERROR, "ERROR: SYNCH foo(): "
                              "Unexpected return.\n"));
      }
    return 0;
  }
  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  Sender_exec_i::Sender_exec_i (void)
    : nr_callbacks_ (0),
      nr_exceptions_ (0)
  {
  }

  Sender_exec_i::~Sender_exec_i (void)
  {
  }

  // Supported operations and attributes.

  // Component attributes and port operations.

  // Operations from Components::SessionComponent.

  void
  Sender_exec_i::set_session_context (
     ::Components::SessionContext_ptr ctx)
  {
    this->ciao_context_ =
      ::DelReplyH::CCM_Sender_Context::_narrow (ctx);

    if ( ::CORBA::is_nil (this->ciao_context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }

  void
  Sender_exec_i::configuration_complete (void)
  {
     /* Your code here. */
  }

  void
  Sender_exec_i::ccm_activate (void)
  {
    this->asynch_foo_gen =
       new asynch_foo_generator (this->ciao_context_.in (),
                                 this->nr_callbacks_,
                                 this->nr_exceptions_);
    this->asynch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);

    this->synch_foo_gen =
       new synch_foo_generator (this->ciao_context_.in());
    this->synch_foo_gen->activate (THR_NEW_LWP | THR_JOINABLE, 1);
  }

  void
  Sender_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }

  void
  Sender_exec_i::ccm_remove (void)
  {
    if (this->nr_callbacks_.value() != 0)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Not all ReplyHandlers were "
                               "deleted, %d left.\n",
                               this->nr_callbacks_.value ()));
      }
    if (this->nr_exceptions_.value() != 1)
      {
        ACE_ERROR ((LM_ERROR, "ERROR: Wrong number of exceptions received. "
          "Expected : 1, Received = %u.\n",
          this->nr_exceptions_.value()));
      }
    if ((this->nr_callbacks_.value() == 0) &&
        (this->nr_exceptions_.value() == 1))
      {
        ACE_DEBUG ((LM_DEBUG,
                "OK: All constructed ReplyHandlers were deleted.\n"));
      }
    delete this->asynch_foo_gen;
    this->asynch_foo_gen = 0;
    delete this->synch_foo_gen;
    this->synch_foo_gen = 0;
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::AMI4CCM_MyFooReplyHandler_run_my_foo_i (
      Atomic_UShort &nr_callbacks,
      Atomic_UShort &nr_exceptions)
   : nr_callbacks_ (nr_callbacks),
     nr_exceptions_ (nr_exceptions)
  {
    ACE_DEBUG ((LM_DEBUG,"CONSTRUCTOR replyhandle\n"));
     ++this->nr_callbacks_;
  }

  AMI4CCM_MyFooReplyHandler_run_my_foo_i::~AMI4CCM_MyFooReplyHandler_run_my_foo_i (void)
  {
    ACE_DEBUG ((LM_DEBUG,"DESTRUCTOR replyhandle\n"));
    --this->nr_callbacks_;
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo (
    ::CORBA::Long /* ami_return_val */,
     const char * answer)
  {
    ACE_DEBUG ((LM_DEBUG, "OK: ASYNCH foo() returns answer: %C.\n", answer));
  }

  void
  AMI4CCM_MyFooReplyHandler_run_my_foo_i::foo_excep (
    ::CCM_AMI::ExceptionHolder_ptr /* excep_holder */)
  {
    ++this->nr_exceptions_;
  }

  extern "C" DELREPLYH_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DelReplyH_Sender_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();

    ACE_NEW_NORETURN (
      retval,
      Sender_exec_i);

    return retval;
  }
}
