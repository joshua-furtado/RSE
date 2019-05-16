#include <gazebo/gazebo.hh>

namespace gazebo
{
  class WorldPluginUW : public WorldPlugin
  {
    public: WorldPluginUW() : WorldPlugin()
            {
              printf("Welcome to Joshua's World!\n");
            }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };
  GZ_REGISTER_WORLD_PLUGIN(WorldPluginUW)
}
