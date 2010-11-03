/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DOMAINPARTICIPANT_T_H_
#define DOMAINPARTICIPANT_T_H_

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"
#include "convertors/InstanceHandle_t.h"

#include "tao/LocalObject.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    // Forward declarations
    template <typename DDS_TYPE>
    class DDS_Topic_T;

    template <typename DDS_TYPE>
    class DDS_SubscriberListener_T;

    template <typename DDS_TYPE>
    class DDS_Publisher_T;

    template <typename DDS_TYPE>
    class DDS_Subscriber_T;

    template <typename DDS_TYPE>
    class DDS_TopicListener_T;

    template <typename DDS_TYPE>
    class DDS_Topic_T;

    template <typename DDS_TYPE>
    class DDS_ContentFilteredTopic_T;

    template <typename DDS_TYPE>
    class DDS_PublisherListener_T;

    // Class declaration
    template <typename DDS_TYPE>
    class DDS_DomainParticipant_T :
      public virtual ::DDS::DomainParticipant,
      public virtual ::CORBA::LocalObject
    {
    typedef DDS_Subscriber_T<DDS_TYPE> Subscriber_type;
    typedef DDS_SubscriberListener_T<DDS_TYPE> SubscriberListener_type;
    typedef DDS_Publisher_T<DDS_TYPE> Publisher_type;
    typedef DDS_PublisherListener_T<DDS_TYPE> PublisherListener_type;
    typedef DDS_TopicListener_T<DDS_TYPE> TopicListener_type;
    typedef DDS_Topic_T<DDS_TYPE> Topic_type;
    typedef DDS_ContentFilteredTopic_T<DDS_TYPE> ContentFilteredTopic_type;

    public:
      /// Constructor
      DDS_DomainParticipant_T (DDSDomainParticipant * dp);

      /// Destructor
      virtual ~DDS_DomainParticipant_T (void);

      virtual ::DDS::Publisher_ptr create_publisher (
        const ::DDS::PublisherQos & qos,
        ::DDS::PublisherListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::Publisher_ptr create_publisher_with_profile (
        const char* library_name,
        const char *profile_name,
        ::DDS::PublisherListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::ReturnCode_t delete_publisher (::DDS::Publisher_ptr p);

      virtual ::DDS::Subscriber_ptr create_subscriber (
        const ::DDS::SubscriberQos & qos,
        ::DDS::SubscriberListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::Subscriber_ptr create_subscriber_with_profile(
        const char* library_name,
        const char *profile_name,
        ::DDS::SubscriberListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::ReturnCode_t delete_subscriber (::DDS::Subscriber_ptr s);

      virtual ::DDS::Subscriber_ptr get_builtin_subscriber (void);

      virtual ::DDS::Topic_ptr create_topic (
        const char * impl_name,
        const char * type_name,
        const ::DDS::TopicQos & qos,
        ::DDS::TopicListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::Topic_ptr create_topic_with_profile (
        const char * impl_name,
        const char * type_name,
        const char* library_name,
        const char *profile_name,
        ::DDS::TopicListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::ReturnCode_t delete_topic (::DDS::Topic_ptr a_topic);

      virtual ::DDS::Topic_ptr find_topic (
        const char * impl_name,
        const ::DDS::Duration_t & timeout);

      virtual ::DDS::TopicDescription_ptr lookup_topicdescription (
        const char * name);

      virtual ::DDS::ContentFilteredTopic_ptr create_contentfilteredtopic (
        const char * name,
        ::DDS::Topic_ptr related_topic,
        const char * filter_expression,
        const ::DDS::StringSeq & expression_parameters);

      virtual ::DDS::ReturnCode_t delete_contentfilteredtopic (
        ::DDS::ContentFilteredTopic_ptr a_contentfilteredtopic);

      virtual ::DDS::MultiTopic_ptr create_multitopic (
        const char * name,
        const char * type_name,
        const char * subscription_expression,
        const ::DDS::StringSeq & expression_parameters);

      virtual ::DDS::ReturnCode_t delete_multitopic (
        ::DDS::MultiTopic_ptr a_multitopic);

      virtual ::DDS::ReturnCode_t delete_contained_entities (void);

      virtual ::DDS::ReturnCode_t set_qos (
        const ::DDS::DomainParticipantQos & qos);

      virtual ::DDS::ReturnCode_t get_qos (
        ::DDS::DomainParticipantQos & qos);

      virtual ::DDS::ReturnCode_t set_listener (
        ::DDS::DomainParticipantListener_ptr a_listener,
        ::DDS::StatusMask mask);

      virtual ::DDS::DomainParticipantListener_ptr get_listener (void);

      virtual ::DDS::ReturnCode_t ignore_participant (
        DDS_INSTANCE_HANDLE_T_IN handle);

      virtual ::DDS::ReturnCode_t ignore_topic (
        DDS_INSTANCE_HANDLE_T_IN handle);

      virtual ::DDS::ReturnCode_t ignore_publication (
        DDS_INSTANCE_HANDLE_T_IN handle);

      virtual ::DDS::ReturnCode_t ignore_subscription (
        DDS_INSTANCE_HANDLE_T_IN handle);

      virtual ::DDS::DomainId_t get_domain_id (void);

      virtual ::DDS::ReturnCode_t assert_liveliness (void);

      virtual ::DDS::ReturnCode_t set_default_publisher_qos (
        const ::DDS::PublisherQos & qos);

      virtual ::DDS::ReturnCode_t get_default_publisher_qos (
        ::DDS::PublisherQos & qos);

      virtual ::DDS::ReturnCode_t set_default_subscriber_qos (
        const ::DDS::SubscriberQos & qos);

      virtual ::DDS::ReturnCode_t get_default_subscriber_qos (
        ::DDS::SubscriberQos & qos);

      virtual ::DDS::ReturnCode_t set_default_topic_qos (
        const ::DDS::TopicQos & qos);

      virtual ::DDS::ReturnCode_t get_default_topic_qos (
        ::DDS::TopicQos & qos);

      virtual ::DDS::ReturnCode_t get_discovered_participants (
        ::DDS::InstanceHandleSeq & impl_handles);

      virtual ::DDS::ReturnCode_t get_discovered_participant_data (
        ::DDS::ParticipantBuiltinTopicData & impl_data,
        DDS_INSTANCE_HANDLE_T_IN impl_handle);

      virtual ::DDS::ReturnCode_t get_discovered_topics (
        ::DDS::InstanceHandleSeq & impl_handles);

      virtual ::DDS::ReturnCode_t get_discovered_topic_data (
        ::DDS::TopicBuiltinTopicData & impl_data,
        DDS_INSTANCE_HANDLE_T_IN impl_handle);

      virtual ::CORBA::Boolean contains_entity (
        DDS_INSTANCE_HANDLE_T_IN a_handle);

      virtual ::DDS::ReturnCode_t get_current_time (
        ::DDS::Time_t & current_time);

      virtual ::DDS::ReturnCode_t enable (void);

      virtual ::DDS::StatusCondition_ptr get_statuscondition (void);

      virtual ::DDS::StatusMask get_status_changes (void);

      virtual DDS_INSTANCE_HANDLE_T_RETN get_instance_handle (void);

      DDSDomainParticipant * get_impl (void);

      void set_impl (DDSDomainParticipant * dp);

    protected:
      DDSDomainParticipant *impl_;

      DDSDomainParticipant * impl (void);
    };
  }
}

#include "dds4ccm/impl/ndds/DomainParticipant_T.cpp"

#endif /* DOMAINPARTICIPANT_T_H_ */
