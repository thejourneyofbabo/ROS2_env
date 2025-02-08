202501092125
## To Begin - F1Tenth_Gym_ROS
[F1Tenth Simulator](https://github.com/f1tenth/f1tenth_gym_ros)

## Without an NVIDIA gpu:
(https://github.com/f1tenth/f1tenth_gym_ros#without-an-nvidia-gpu)

**Install the following dependencies:**
If your system does not support nvidia-docker2, noVNC will have to be used to forward the display.
- Again you'll need **Docker**. Follow the instruction from above.
- Additionally you'll need **docker-compose**. Follow the instruction [here](https://docs.docker.com/compose/install/) to install docker-compose.

**Installing the simulation:**
1. Clone this repo
2. Bringup the novnc container and the sim container with docker-compose:

```shell
docker-compose up
```

3. In a separate terminal, run the following, and you'll have the a bash session in the simulation container. `tmux` is available for convenience.

`docker ps` 명령어로 파일 확인후 실행

```shell
docker exec -it f1tenth_gym_ros-sim-1 /bin/bash

docker exec -it -w / f1tenth_gym_ros-sim-1 /bin/bash

docker exec -it -w / f1tenth_docker-sim-1 /bin/zsh

```

4. In your browser, navigate to [http://loctygalhost:8080/vnc.html](http://localhost:8080/vnc.html), you should see the noVNC logo with the connect button. Click the connect button to connect to the session.


# Launching the Simulation
(https://github.com/f1tenth/f1tenth_gym_ros#launching-the-simulation)

1. `tmux` is included in the contianer, so you can create multiple bash sessions in the same terminal.
2. To launch the simulation, make sure you source both the ROS2 setup script and the local workspace setup script. Run the following in the bash session from the container:

```shell
$ source /opt/ros/foxy/setup.bash
$ source install/local_setup.bash
$ ros2 launch f1tenth_gym_ros gym_bridge_launch.py
```

A rviz window should pop up showing the simulation either on your host system or in the browser window depending on the display forwarding you chose.

You can then run another node by creating another bash session in `tmux`.


# Keyboard Teleop

The keyboard teleop node from `teleop_twist_keyboard` is also installed as part of the simulation's dependency. To enable keyboard teleop, set `kb_teleop` to `True` in `sim.yaml`. After launching the simulation, in another terminal, run:

```shell
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

Then, press `i` to move forward, `u` and `o` to move forward and turn, `,` to move backwards, `m` and `.` to move backwards and turn, and `k` to stop in the terminal window running the teleop node.
---
### Reference

