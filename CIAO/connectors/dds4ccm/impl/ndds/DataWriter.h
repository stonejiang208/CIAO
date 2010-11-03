/**
 * @author Johnny Willemsen <jwillemsen@remedy.nl>
 *
 * $Id$
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_DATAWRITER_H
#define DDS4CCM_DATAWRITER_H

#include "dds4ccm/idl/dds_rtf2_dcpsC.h"

#include "dds4ccm/impl/ndds/dds4ccm_ndds_export.h"

#include "tao/LocalObject.h"

#include "ndds/ndds_cpp.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    class DDS4CCM_NDDS_Export DDS_DataWriter_Base
      : public virtual ::DDS::DataWriter,
        public virtual ::CORBA::LocalObject
    {
    public:
      /// Constructor
      explicit DDS_DataWriter_Base (DDSDataWriter * dw);

      DDSDataWriter * get_impl (void);

      void set_impl (DDSDataWriter * dw);

    protected:
      DDSDataWriter * impl (void);

    private:
      DDSDataWriter * impl_;
    };
  }
}

#endif /* DDS4CCM_DATAWRITER_H */
