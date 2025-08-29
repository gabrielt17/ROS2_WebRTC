# Dockerfile (Baseado na imagem oficial ROS2 Humble + dependências)
FROM osrf/ros:humble-desktop-full

ENV DEBIAN_FRONTEND=noninteractive

# Argumentos para criar um usuário com o mesmo UID/GID do host
ARG USER_UID=1000
ARG USER_GID=1000
ARG USERNAME=devuser

# Instala pacotes adicionais (GStreamer, WebRTC, PipeWire, ferramentas)
RUN apt-get update && apt-get install -y --no-install-recommends \
    # Utilitários de compilação e debug
    sudo git wget curl nano bash-completion build-essential cmake pkg-config gdb \
    cppcheck valgrind \
    \
    # Python + WebSockets para sinalização
    python3 python3-pip python3-websockets \
    \
    # SSL
    ca-certificates \
    libssl-dev \
    \
    # GStreamer + Plugins
    gstreamer1.0-tools libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    gstreamer1.0-nice \
    gstreamer1.0-gl \
    gstreamer1.0-vaapi mesa-va-drivers \
    libgtk-3-dev libx11-dev libwayland-dev x11-apps \
    \
    # PipeWire (áudio)
    pipewire libspa-0.2-modules gstreamer1.0-pipewire \
    \
    # WebRTC
    libgstreamer-plugins-bad1.0-dev \
    libnice-dev \
    libsrtp2-dev \
    libglib2.0-dev \
    \
    # Ferramentas ROS2
    python3-colcon-common-extensions \
    python3-rosdep \
    python3-rosinstall-generator \
    python3-vcstool \
    ros-humble-ros-core \
    ros-humble-gazebo-msgs \
    ros-humble-gazebo-plugins \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Inicializa rosdep
RUN rosdep update

# Script para criar usuário com UID/GID igual ao host
RUN set -x && \
    if getent passwd ${USER_UID} >/dev/null 2>&1; then deluser --remove-home $(getent passwd ${USER_UID} | cut -d: -f1); fi && \
    if getent group ${USER_GID} >/dev/null 2>&1; then delgroup $(getent group ${USER_GID} | cut -d: -f1); fi && \
    groupadd --gid ${USER_GID} ${USERNAME} && \
    useradd --uid ${USER_UID} --gid ${USER_GID} -m -s /bin/bash ${USERNAME} && \
    usermod -aG sudo ${USERNAME} && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/${USERNAME}

RUN groupadd --gid 985 dri && groupadd --gid 989 render && \
    usermod -aG dri,render,video ${USERNAME}

# Volta ao seu workspace original
WORKDIR ${HOME}/${USERNAME}/Workspaces

USER ${USERNAME}

# Garante o ambiente ROS em shells interativos
RUN echo "source /opt/ros/humble/setup.bash" \
    >> /home/${USERNAME}/.bashrc \
    && echo "source /home/${USERNAME}/Workspaces/ros2_ws/install/setup.bash" \
    >> /home/${USERNAME}/.bashrc


CMD ["/bin/bash"]
