// RUN: %clangxx -fsycl -D_FORTIFY_SOURCE=2 %s -o %t.out
#include <CL/sycl.hpp>
#include <iostream>

int main() {
  using res_vec_type = cl::sycl::vec<cl::sycl::cl_ushort, 4>;
  res_vec_type res;

  cl::sycl::vec<cl::sycl::cl_uchar, 8> RefData(1, 2, 3, 4, 5, 6, 7, 8);
  {
    cl::sycl::buffer<res_vec_type, 1> OutBuf(&res, cl::sycl::range<1>(1));
    cl::sycl::buffer<decltype(RefData), 1> InBuf(&RefData,
                                                 cl::sycl::range<1>(1));
    cl::sycl::queue Queue;
    Queue.submit([&](cl::sycl::handler &cgh) {
      auto In = InBuf.get_access<cl::sycl::access::mode::write>(cgh);
      auto Out = OutBuf.get_access<cl::sycl::access::mode::read>(cgh);
      cgh.single_task<class as_op>(
          [=]() { Out[0] = In[0].as<res_vec_type>(); });
    });
  }
  std::cout << res.s0() << " " << res.s1() << " " << res.s2() << " " << res.s3()
            << std::endl;
  return 0;
}
