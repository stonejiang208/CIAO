/* -*- C++ -*- */
/**
 *  @file   EC_TPC_ProxySupplier.h
 *
 *  $Id$
 *
 *  @author Chris Cleeland <cleeland at ociweb.com>
 *
 */

#ifndef TAO_EC_TPC_PROXYSUPPLIER_H
#define TAO_EC_TPC_PROXYSUPPLIER_H
#include "ace/pre.h"

#include "EC_Default_ProxySupplier.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_EC_Dispatching;
class TAO_EC_TPC_Dispatching;

class TAO_RTEvent_Serv_Export TAO_EC_TPC_ProxyPushSupplier :
  public TAO_EC_Default_ProxyPushSupplier
{
public:
  /// Constructor
  TAO_EC_TPC_ProxyPushSupplier (TAO_EC_Event_Channel_Base* event_channel, int validate_connection);
  
  /// Dtor
  virtual ~TAO_EC_TPC_ProxyPushSupplier (void);

  /*! These are overriden from the base class in order to maintain the
       map in the dispatcher class. */
  
  // = The RtecEventChannelAdmin::ProxyPushSupplier methods...
  virtual void connect_push_consumer (
                RtecEventComm::PushConsumer_ptr push_consumer,
                const RtecEventChannelAdmin::ConsumerQOS &qos
                ACE_ENV_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException,
                       RtecEventChannelAdmin::AlreadyConnected,
                       RtecEventChannelAdmin::TypeError));

  virtual void disconnect_push_supplier (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
      ACE_THROW_SPEC ((CORBA::SystemException));
  
private:  
  typedef TAO_EC_Default_ProxyPushSupplier BASECLASS;
  TAO_EC_TPC_Dispatching* tpc_dispatching ();
};

#if defined (__ACE_INLINE__)
#include "EC_TPC_ProxySupplier.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"

#endif
