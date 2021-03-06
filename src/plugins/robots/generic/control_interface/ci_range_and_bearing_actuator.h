/**
 * @file <argos3/plugins/robots/generic/control_interface/ci_range_and_bearing_actuator.h>
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 */

#ifndef CI_RANGE_AND_BEARING_ACTUATOR_H
#define CI_RANGE_AND_BEARING_ACTUATOR_H

namespace argos {
   class CCI_RangeAndBearingActuator;
}

#include <argos3/core/control_interface/ci_actuator.h>
#include <argos3/core/utility/datatypes/byte_array.h>

namespace argos {

   class CCI_RangeAndBearingActuator : public CCI_Actuator {

   public:

      virtual ~CCI_RangeAndBearingActuator() {}

      inline size_t GetSize() const {
         return m_cData.Size();
      }

      void SetData(const CByteArray& c_data);

      inline void SetData(size_t un_idx,
                          UInt8 un_value) {
         m_cData[un_idx] = un_value;
      }

      inline void ClearData() {
         m_cData.Zero();
      }

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);
#endif

   protected:

      CByteArray m_cData;

   };

}

#endif
