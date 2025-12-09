# Base image do Dustynv (Já contém ROS Humble e OpenCV com CUDA)
FROM dustynv/ros:humble-desktop-l4t-r32.7.1

ENV DEBIAN_FRONTEND=noninteractive

# 1. Correção de Chaves e Setup de Repositórios
RUN rm -f /etc/apt/sources.list.d/ros2-latest.list /etc/apt/sources.list.d/ros2.list && \
    apt-get update || true && \
    apt-get install -y --no-install-recommends curl gnupg2 lsb-release ca-certificates && \
    curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list

# 2. Instalação de Dependências do Sistema
RUN apt-get update && apt-get install -y --no-install-recommends \
    git wget curl nano build-essential cmake pkg-config \
    python3-pip libssl-dev \
    libboost-all-dev \
    # GStreamer (Runtime e Headers Base)
    gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl \
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav \
    libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev gstreamer1.0-nice \
    # WebRTC Deps
    libnice-dev libsrtp2-dev libglib2.0-dev libjson-glib-dev \
    # UI
    libgtk-3-dev libx11-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# 3. Python e Build Tools
RUN python3 -m pip install --upgrade pip && \
    python3 -m pip install --no-cache-dir \
    numpy \
    colcon-common-extensions rosdep vcstool ntplib

# 4. Instalar Librealsense2 manualmente (Corrigindo falta no rosdep)
RUN mkdir -p /etc/apt/keyrings && \
    curl -sSf https://librealsense.intel.com/Debian/librealsense.pgp | tee /etc/apt/keyrings/librealsense.pgp > /dev/null && \
    echo "deb [signed-by=/etc/apt/keyrings/librealsense.pgp] https://librealsense.intel.com/Debian/apt-repo $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/librealsense.list && \
    apt-get update && \
    apt-get install -y --no-install-recommends librealsense2-utils librealsense2-dev && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# 5. Baixar Headers do WebRTC e GERAR o enumtypes (Correção do 404)
RUN mkdir -p /usr/include/gstreamer-1.0/gst/webrtc && \
    # Baixa os headers estáticos
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/webrtc.h -O /usr/include/gstreamer-1.0/gst/webrtc/webrtc.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/webrtc_fwd.h -O /usr/include/gstreamer-1.0/gst/webrtc/webrtc_fwd.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/dtlstransport.h -O /usr/include/gstreamer-1.0/gst/webrtc/dtlstransport.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/icetransport.h -O /usr/include/gstreamer-1.0/gst/webrtc/icetransport.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtpreceiver.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtpreceiver.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtpsender.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtpsender.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtptransceiver.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtptransceiver.h && \
    # GERA o webrtc-enumtypes.h usando glib-mkenums
    glib-mkenums \
      --fhead "#ifndef __GST_WEBRTC_ENUM_TYPES_H__\n#define __GST_WEBRTC_ENUM_TYPES_H__\n\n#include <glib-object.h>\n\nG_BEGIN_DECLS\n" \
      --fprod "\n/* enumerations from \"@filename@\" */\n" \
      --vhead "GType @enum_name@_get_type (void);\n#define GST_TYPE_@ENUMSHORT@ (@enum_name@_get_type())\n" \
      --ftail "G_END_DECLS\n\n#endif /* __GST_WEBRTC_ENUM_TYPES_H__ */" \
      /usr/include/gstreamer-1.0/gst/webrtc/dtlstransport.h \
      /usr/include/gstreamer-1.0/gst/webrtc/icetransport.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtptransceiver.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtpreceiver.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtpsender.h \
      > /usr/include/gstreamer-1.0/gst/webrtc/webrtc-enumtypes.h

# 6. Criar Link Simbólico (Mantido igual)
RUN LIB_PATH=$(find /usr/lib -name "libgstwebrtc-1.0.so.0" | head -n 1) && \
    if [ -n "$LIB_PATH" ]; then \
        ln -s "$LIB_PATH" "${LIB_PATH%.0}"; \
    fi

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]