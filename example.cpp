// example.cpp
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

// 声明 CUDA 函数
void add(int* a, int* b, int* c, int size);

PYBIND11_MODULE(example, m) {
    m.def("add", [](pybind11::array_t<int> a, pybind11::array_t<int> b) {
        auto buf_a = a.request();
        auto buf_b = b.request();
        int size = buf_a.size;
        pybind11::array_t<int> result(size);

        int* a_ptr = static_cast<int*>(buf_a.ptr);
        int* b_ptr = static_cast<int*>(buf_b.ptr);
        int* c_ptr = static_cast<int*>(result.request().ptr);

        add(a_ptr, b_ptr, c_ptr, size);

        return result;
    });
}

