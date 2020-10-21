///
/// @file global_data.hh
/// @author Pierrick Guillaume
/// @date 22/09/2020.
///

#pragma once

#include <gtkmm/builder.h>
#include <gtkmm/application.h>

#include "misc/singleton.hh"

namespace GMPF {
  /**
   * @class GlobalData
   * @brief Hold information which have to be shared between the whole project.
   */
  struct GlobalData: public Singleton<GlobalData> {
  private:
    Glib::RefPtr<Gtk::Builder> builder_;
    Glib::RefPtr<Gtk::Application> app_;

  public:
    /**
     * @brief Singleton constructor.
     *
     * Cannot be called since we need an instance of
     * `Singleton<GlobalData>::SingletonToken`.
     * This constructor is used by the \b Singleton to instantiate the unique
     * Logger.
     */
    explicit GlobalData(SingletonToken);
    /// @name Getters.
    /// @{
    /** Retrieve the \a builder from the unique instance of \a data */
    static const Glib::RefPtr<Gtk::Builder> getBuilder();
    /** Retrieve the \a app from the unique instance of \a data */
    static const Glib::RefPtr<Gtk::Application> getApp();
    /// @}

    /// @name Setters
    /// @{
    /**
     * @brief Set the \a builder from the instance of \a data to \a builder.
     * @param builder the builder to set to.
     */
    static void setBuilder(Glib::RefPtr<Gtk::Builder> builder);
    /**
     * @brief Set the \a app from the instance of \a data to \a app.
     * @param app the \a app to set to.
     */
    static void setApp(Glib::RefPtr<Gtk::Application> app);
    /// @}
  };
}  // namespace GMPF
