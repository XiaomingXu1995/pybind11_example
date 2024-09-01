mkdir -p build
cd build && cmake -Dpybind11_DIR=/home/user_home/xiaomingxu/mambaforge/envs/ccdl/lib/python3.10/site-packages/pybind11/share/cmake/pybind11 -DPython3_EXECUTABLE=/home/user_home/xiaomingxu/mambaforge/envs/ccdl/bin/python3 ..
make 

