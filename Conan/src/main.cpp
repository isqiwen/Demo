#include <iostream>
#include <cmath>
#define EIGEN_USE_LAPACKE
#include <Eigen/Dense>
// #include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/SVD>


using Index = Eigen::Index;

template<typename Scalar>
using MatrixRowMajor        = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

template<typename Scalar>
using MatrixColMajor        = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>;

template<typename Scalar>
using Vector                = Eigen::Matrix<Scalar, Eigen::Dynamic, 1, Eigen::ColMajor>;

template<typename Scalar>
using RowVector             = Eigen::Matrix<Scalar, 1, Eigen::Dynamic, Eigen::RowMajor>;

using cx_double             = std::complex<double>;
using cx_int                = std::complex<int>;
using cx_float              = std::complex<float>;
using cx_fvec               = RowVector<cx_float>;
using fvec                  = RowVector<float>;
using cx_dvec               = RowVector<cx_double>;
using dvec                  = RowVector<double>;
using fvec                  = RowVector<float>;
using int32vec              = RowVector<int32_t>;
using vec3i                 = Eigen::Vector3i;
using vec3f                 = Eigen::Vector3f;

using cx_fmat               = MatrixRowMajor<cx_float>;
using fmat                  = MatrixRowMajor<float>;
using int32mat              = MatrixRowMajor<int32_t>;
using uint16mat             = MatrixRowMajor<uint16_t>;
using uint16matColMajor     = MatrixColMajor<uint16_t>;
using cx_dmat               = MatrixRowMajor<cx_double>;
using dmat                  = MatrixRowMajor<double>;

// template<typename Scalar, int NumIndices>
// using TensorRowMajor        = Eigen::Tensor<Scalar, NumIndices, Eigen::RowMajor>;

// template<typename Scalar>
// using Cube                  = TensorRowMajor<Scalar, 3>;

// using cx_fcube              = Cube<cx_float>;
// using fcube                 = Cube<float>;
// using cx_dcube              = Cube<cx_double>;
// using dcube                 = Cube<double>;
// using cx_icube              = Cube<cx_int>;
// using icube                 = Cube<int>;

using namespace std;

int main(){

    cx_fmat mat(3, 3);
    mat.setRandom();
    // int count = 1;
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         mat(i, j) = std::complex(count, count);
    //         count++;
    //     }
    // }

    mat <<  cx_float(0.566198,-0.211234), cx_float(0.823295,0.59688), cx_float(-0.329554,-0.604897),
            cx_float(-0.444451,0.536459), cx_float(-0.0452059,0.10794),  cx_float(-0.270431,0.257742),
            cx_float(0.904459,0.0268018),  cx_float(0.271423,0.83239),  cx_float(-0.716795,0.434594);

    mat = mat.array() * 100;

    std::cout << "####### " << std::endl;
    std::cout << mat << std::endl;
    std::cout << "####### " << std::endl;
    Eigen::JacobiSVD<cx_fmat> svd(mat, Eigen::ComputeFullU | Eigen::ComputeFullV);
    cx_fmat U = svd.matrixU();
    cx_fmat V = svd.matrixV();
    cx_fvec S = svd.singularValues();

    std::cout << U * S.asDiagonal() * V.adjoint();
    // std::cout << svd.matrixU() << std::endl;
    std::cout << "########" << std::endl;
    std::cout << U << std::endl;
    // std::cout << V << std::endl;
    std::cout << U.col(0).norm() << std::endl;

    std::cout << "sssssssssssss" << std::endl;
    std::cout << S << std::endl;
    return 0;
}
