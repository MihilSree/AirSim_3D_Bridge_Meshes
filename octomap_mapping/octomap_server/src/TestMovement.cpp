#include <iostream>
#include "/home/mihil/AirSim/Unreal/Environments/Blocks/Plugins/AirSim/Source/AirLib/include/vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include "rpc/rpc_error.h"
int main() 
{
  using namespace std;
  msr::airlib::MultirotorRpcLibClient client;
  client.enableApiControl(true);
  client.armDisarm(true);
  cout << "Press Enter To Get Position" << endl; cin.get();
  auto position = client.getMultirotorState().getPosition();
  client.takeoffAsync(5)->waitOnLastTask();

  try {
  cout << "Press Enter to move to (0,-1,3, 2) with 2 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 0, position.y() + -1, position.z() - 3, 2)->waitOnLastTask();

  cout << "Press Enter to move to (0,-1,6, 2) with 2 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 0, position.y() + -1, position.z() - 6, 2)->waitOnLastTask();
  
  cout << "Press Enter to move to (0,-15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 0, position.y() + -15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (15,-15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 15, position.y() + -15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (15,15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 15, position.y() + 15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (-45,15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + -45, position.y() + 15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (-45,-15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + -45, position.y() + -15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (-45,-15,6, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + -45, position.y() + -15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to move to (-45,-15,-5, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + -45, position.y() + -15, position.z() + 5, 3)->waitOnLastTask();

  cout << "Press Enter to move to (45,-15,-5, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 45, position.y() + -15, position.z() + 5, 3)->waitOnLastTask();

  cout << "Press Enter to move to (45,15,-5, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 45, position.y() + 15, position.z() + 5, 3)->waitOnLastTask();

  cout << "Press Enter to move to (-45,15,-5, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + -45, position.y() + 15, position.z() + 5, 3)->waitOnLastTask();

  cout << "Press Enter to move to (45,15,-5, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 45, position.y() + 15, position.z() + 5, 3)->waitOnLastTask();

  cout << "Press Enter to move to (45,15,9, 3) with 3 m/s velocity" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 45, position.y() + 15, position.z() - 6, 3)->waitOnLastTask();

  cout << "Press Enter to Move to Origin" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.moveToPositionAsync(position.x() + 0, position.y() + 0, position.z() - 6, 1)->waitOnLastTask();

  cout << "Press Enter to Move to Land" << endl; cin.get();
  client.enableApiControl(true);
  client.armDisarm(true);
  client.landAsync()->waitOnLastTask();

  }

  catch (rpc::rpc_error& e) {
       std::string msg = e.get_error().as<std::string>();
       std::cout << "Exception raised by the API, something went wrong." << std::endl
                 << msg << std::endl;
  }
  return 0;
}
