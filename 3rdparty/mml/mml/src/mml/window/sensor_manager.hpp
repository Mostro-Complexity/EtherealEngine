#ifndef MML_SENSORMANAGER_HPP
#define MML_SENSORMANAGER_HPP

#include <mml/window/sensor.hpp>
#include <mml/window/sensor_impl.hpp>
#include <mml/system/non_copyable.hpp>

namespace mml {
  namespace priv {
    /// \brief Global sensor manager
    ///
    class sensor_manager : non_copyable {
    public:
      /// \brief Get the global unique instance of the manager
      ///
      /// \return Unique instance of the sensor manager
      ///
      static sensor_manager& get_instance();

      /// \brief Check if a sensor is available on the underlying platform
      ///
      /// \param sensor sensor to check
      ///
      /// \return True if the sensor is available, false otherwise
      ///
      bool is_available(sensor::type sensor);

      /// \brief Enable or disable a sensor
      ///
      /// \param sensor  sensor to modify
      /// \param enabled Whether it should be enabled or not
      ///
      void set_enabled(sensor::type sensor, bool enabled);

      /// \brief Check if a sensor is enabled
      ///
      /// \param sensor sensor to check
      ///
      /// \return True if the sensor is enabled, false otherwise
      ///
      bool is_enabled(sensor::type sensor) const;

      /// \brief Get the current value of a sensor
      ///
      /// \param sensor sensor to read
      ///
      /// \return Current value of the sensor
      ///
      std::array<float, 3> get_value(sensor::type sensor) const;

      /// \brief Update the state of all the sensors
      ///
      void update();

    private:
      /// \brief Default constructor
      ///
      sensor_manager();

      /// \brief Destructor
      ///
      ~sensor_manager();

      /// \brief sensor information and state
      ///
      struct item {
        bool available;              ///< Is the sensor available on this device?
        bool enabled;                ///< Current enable state of the sensor
        sensor_impl sensor;          ///< sensor implementation
        std::array<float, 3> value;  ///< The current sensor value
      };

      item m_sensors[sensor::count];  ///< Sensors information and state
    };

  }  // namespace priv

}  // namespace mml

#endif  // MML_SENSORMANAGER_HPP
