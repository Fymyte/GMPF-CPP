///
/// @file logger.hh
/// @author Pierrick Guillaume
/// @date 30/09/2020.
///

#pragma once

#include <fstream>
#include <optional>
#include <ostream>
#include <variant>

#include "misc/singleton.hh"

/**
 * @def D_PRINT()
 * @brief write logs in debug mode.
 *
 * This macro should be used to write debug logs instead of the standard
 * \a Logger::debug() function. It provide additional file, line and function
 * information to help user know from were logs come from. \line
 *
 * Furthermore, when build type is release, it automatically remove those logs
 * from code.
 */
#ifdef GMPF_DEBUG_LOG
#  define D_PRINT(_msg)                                                        \
    GMPF::Logger::debug() << "[" << __FILENAME__ << "::" << __LINE__ << " "    \
                          << __func__ << "] " << _msg << std::endl;
#else
#   define D_PRINT(_msg)
#endif

namespace GMPF {
  /**
   * @class Logger
   * @brief A logging helper class
   *
   * A simple logger for all logging operation in the app.
   * It allows logging on output stream as well as file and use the \b <<
   * operator
   */
  class Logger : public Singleton<Logger> {
  public:
    /// @name Ctor.
    /// @{
    Logger& operator=(const Logger&) = delete;
    Logger(const Logger&) = delete;
    /// @}

    /// @name Logging functions.
    /// @{
    /** Display Debug before logging the message. */
    static Logger& debug();
    /** Display Info before logging the message. */
    static Logger& info();
    /** Display Warning before logging the message. */
    static Logger& warn();
    /** Display Error before logging the message. */
    static Logger& error();
    /// @}

    /// @name Setters.
    /// @{
    /**
     * @brief Set output stream to the given already opened \a ostream.
     * @param ostream the new output stream.
     */
    static void setOutputStream(std::ostream& ostream);
    /**
     * @brief Open a file and set logs output to this file.
     * @param filename the file's name to open.
     */
    static void setOutputStream(const std::string& filename);
    /// @}

    /**
     * @brief Append text to logs.
     * @param logger The logger instance on which we want to write logs.
     * @param msg the message to write in logs.
     * @return the output stream of the logger so you can write in it using
     * standard \b << stream operator
     */
    friend std::ostream& operator<<(const Logger& logger,
                                    const std::string& msg);

  private:
    friend Logger& Singleton<Logger>::instance();
    Logger();
    enum logLevel { DEBUG, INFO, WARN, ERROR };
    logLevel logLevel_;
    std::ostream& ostream_;
    std::ofstream fileStream_;
  };

}  // namespace GMPF
