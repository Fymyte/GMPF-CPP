
namespace GMPF {
  struct GlobalData {
    GtkBuilder *builder;
    gpointer user_data;
  }

  GlobalData globalDataGet() {
    static GlobalData globalData = new GlobalData();
    return globalData;
  }
}
