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
    # --- ADICIONADO: ZLIB para ixwebsocket ---
    zlib1g-dev \
    # GStreamer (Runtime e Headers Base)
    gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl \
    gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav \
    libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev gstreamer1.0-nice \
    # WebRTC Deps
    libgnutls28-dev libsrtp2-dev libglib2.0-dev libjson-glib-dev \
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

RUN apt-get update && apt-get install -y --no-install-recommends \
    python3-setuptools python3-wheel ninja-build git chrony \
    && python3 -m pip install meson==0.61.5

RUN echo    "server 0.br.pool.ntp.org iburst \
            server 1.br.pool.ntp.org iburst \
            server 2.br.pool.ntp.org iburst \
            server 3.br.pool.ntp.org iburst" >> tee -a /etc/chrony.conf

# 2. Baixar, Compilar e Instalar Libnice 0.1.18
RUN cd /tmp && \
    git clone --branch 0.1.18 https://gitlab.freedesktop.org/libnice/libnice.git && \
    cd libnice && \
    # Compilação limpa
    meson build --prefix=/usr --libdir=lib/aarch64-linux-gnu -Dexamples=disabled -Dtests=disabled && \
    ninja -C build && \
    ninja -C build install && \
    cd / && rm -rf /tmp/libnice && \
    ldconfig

# 5. CORREÇÃO CRÍTICA DO GSTREAMER 1.14: Headers faltantes e Enumtypes
# Baixa headers, gera enumtypes e cria manualmente o rtcsessiondescription.h
RUN mkdir -p /usr/include/gstreamer-1.0/gst/webrtc && \
    # A. Baixa os headers oficiais do 1.14
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/webrtc.h -O /usr/include/gstreamer-1.0/gst/webrtc/webrtc.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/webrtc_fwd.h -O /usr/include/gstreamer-1.0/gst/webrtc/webrtc_fwd.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/dtlstransport.h -O /usr/include/gstreamer-1.0/gst/webrtc/dtlstransport.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/icetransport.h -O /usr/include/gstreamer-1.0/gst/webrtc/icetransport.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtpreceiver.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtpreceiver.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtpsender.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtpsender.h && \
    wget https://raw.githubusercontent.com/GStreamer/gst-plugins-bad/1.14/gst-libs/gst/webrtc/rtptransceiver.h -O /usr/include/gstreamer-1.0/gst/webrtc/rtptransceiver.h && \
    # B. Gera webrtc-enumtypes.h
    glib-mkenums \
      --fhead "#ifndef _GST_WEBRTC_ENUM_TYPES_H\n#define __GST_WEBRTC_ENUM_TYPES_H_\n\n#include <glib-object.h>\n\nG_BEGIN_DECLS\n" \
      --fprod "\n/* enumerations from \"@filename@\" */\n" \
      --vhead "GType @enum_name@get_type (void);\n#define GST_TYPE@ENUMSHORT@ (@enum_name@_get_type())\n" \
      --ftail "G_END_DECLS\n\n#endif /* _GST_WEBRTC_ENUM_TYPES_H_ */" \
      /usr/include/gstreamer-1.0/gst/webrtc/dtlstransport.h \
      /usr/include/gstreamer-1.0/gst/webrtc/icetransport.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtptransceiver.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtpreceiver.h \
      /usr/include/gstreamer-1.0/gst/webrtc/rtpsender.h \
      > /usr/include/gstreamer-1.0/gst/webrtc/webrtc-enumtypes.h && \
    # C. Cria rtcsessiondescription.h (O Fix Final)
    echo '#ifndef _GST_WEBRTC_SESSION_DESCRIPTION_H_' > /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#define _GST_WEBRTC_SESSION_DESCRIPTION_H_' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#include <gst/gst.h>' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#include <gst/sdp/sdp.h>' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#include <gst/webrtc/webrtc_fwd.h>' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'G_BEGIN_DECLS' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#define GST_TYPE_WEBRTC_SESSION_DESCRIPTION (gst_webrtc_session_description_get_type())' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'typedef struct _GstWebRTCSessionDescription GstWebRTCSessionDescription;' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'struct _GstWebRTCSessionDescription {' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '  GstWebRTCSDPType type;' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '  GstSDPMessage *sdp;' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '};' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'GType gst_webrtc_session_description_get_type (void);' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'GstWebRTCSessionDescription * gst_webrtc_session_description_new (GstWebRTCSDPType type, GstSDPMessage * sdp);' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'GstWebRTCSessionDescription * gst_webrtc_session_description_copy (const GstWebRTCSessionDescription * src);' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'void gst_webrtc_session_description_free (GstWebRTCSessionDescription * desc);' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo 'G_END_DECLS' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h && \
    echo '#endif /* _GST_WEBRTC_SESSION_DESCRIPTION_H_ */' >> /usr/include/gstreamer-1.0/gst/webrtc/rtcsessiondescription.h

# 6. Criar Link Simbólico
RUN LIB_PATH=$(find /usr/lib -name "libgstwebrtc-1.0.so.0" | head -n 1) && \
    if [ -n "$LIB_PATH" ]; then \
        ln -s "$LIB_PATH" "${LIB_PATH%.0}"; \
    fi

WORKDIR /root/Workspaces

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]