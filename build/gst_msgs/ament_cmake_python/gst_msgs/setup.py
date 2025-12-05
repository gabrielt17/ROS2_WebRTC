from setuptools import find_packages
from setuptools import setup

setup(
    name='gst_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('gst_msgs', 'gst_msgs.*')),
)
