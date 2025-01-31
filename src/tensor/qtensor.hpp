/****************************************************************************
  PackageName  [ tensor ]
  Synopsis     [ Define class QTensor structure ]
  Author       [ Design Verification Lab ]
  Copyright    [ Copyright(c) 2023 DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#pragma once

#include <fmt/core.h>
#include <fmt/ostream.h>

#include <fstream>
#include <gsl/narrow>

#include "./tensor.hpp"
#include "util/phase.hpp"
#include "util/util.hpp"

namespace qsyn::tensor {

template <typename T>
class QTensor : public Tensor<std::complex<T>> {
protected:
    using DataType     = typename Tensor<std::complex<T>>::DataType;
    using InternalType = typename Tensor<std::complex<T>>::InternalType;

public:
    QTensor() : Tensor<DataType>(std::complex<T>(1, 0)) {}
    QTensor(Tensor<DataType> const& t) : Tensor<DataType>(t) {}
    QTensor(Tensor<DataType>&& t) : Tensor<DataType>(t) {}

    QTensor(xt::nested_initializer_list_t<DataType, 0> il) : Tensor<DataType>(il) {}
    QTensor(xt::nested_initializer_list_t<DataType, 1> il) : Tensor<DataType>(il) {}
    QTensor(xt::nested_initializer_list_t<DataType, 2> il) : Tensor<DataType>(il) {}
    QTensor(xt::nested_initializer_list_t<DataType, 3> il) : Tensor<DataType>(il) {}
    QTensor(xt::nested_initializer_list_t<DataType, 4> il) : Tensor<DataType>(il) {}
    QTensor(xt::nested_initializer_list_t<DataType, 5> il) : Tensor<DataType>(il) {}

    ~QTensor() override = default;

    QTensor(TensorShape const& shape) : Tensor<DataType>(shape) {}
    QTensor(TensorShape&& shape) : Tensor<DataType>(shape) {}
    template <typename From>
    requires std::convertible_to<From, InternalType>
    QTensor(From const& internal) : Tensor<DataType>(internal) {}
    template <typename From>
    requires std::convertible_to<From, InternalType>
    QTensor(From&& internal) : Tensor<DataType>(internal) {}

    static QTensor<T> identity(size_t const& n_qubits);
    static QTensor<T> zspider(size_t const& arity, dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> xspider(size_t const& arity, dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> hbox(size_t const& arity, DataType const& a = -1.);
    static QTensor<T> xgate() {
        using namespace std::literals;
        return {{0. + 0.i, 1. + 0.i}, {1. + 0.i, 0. + 0.i}};
    }
    static QTensor<T> ygate() {
        using namespace std::literals;
        return {{0. + 0.i, 0. - 1.i}, {0. + 1.i, 0. + 0.i}};
    }
    static QTensor<T> zgate() {
        using namespace std::literals;
        return {{1. + 0.i, 0. + 0.i}, {0. + 0.i, -1. + 0.i}};
    }
    static QTensor<T> rxgate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> rygate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> rzgate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> pxgate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> pygate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> pzgate(dvlab::Phase const& phase = dvlab::Phase(0));
    static QTensor<T> control(QTensor<T> const& gate, size_t n_ctrls = 1);

    QTensor<T> self_tensor_dot(TensorAxisList const& ax1 = {}, TensorAxisList const& ax2 = {});

    QTensor<T> to_qtensor() const;

    template <typename U>
    friend std::complex<U> global_scalar_factor(QTensor<U> const& t1, QTensor<U> const& t2);

    template <typename U>
    friend U global_norm(QTensor<U> const& t1, QTensor<U> const& t2);

    template <typename U>
    friend dvlab::Phase global_phase(QTensor<U> const& t1, QTensor<U> const& t2);

    template <typename U>
    friend bool is_equivalent(QTensor<U> const& t1, QTensor<U> const& t2, double eps /* = 1e-6*/);

    void set_filename(std::string const& f) { _filename = f; }
    void add_procedures(std::vector<std::string> const& ps) { _procedures.insert(_procedures.end(), ps.begin(), ps.end()); }
    void add_procedure(std::string_view p) { _procedures.emplace_back(p); }

    std::string get_filename() const { return _filename; }
    std::vector<std::string> const& get_procedures() const { return _procedures; }

    // decomposition function
    // friend struct TwoLevelMatrix;

    template <typename U>
    void decompose(QTensor<U>& t, std::string& filename);
    template <typename U>
    auto get_2level(QTensor<U>& t);
    // template <typename U>
    // int graycode(TwoLevelMatrix const& t, int qreq);

private:
    friend struct fmt::formatter<QTensor>;
    static DataType _nu_pow(int n);

    std::string _filename;
    std::vector<std::string> _procedures;
};

//------------------------------
// tensor builders functions
//------------------------------

/**
 * @brief Generate an tensor that corresponds to a n-qubit identity gate.
 *
 * @tparam T floating-point type
 * @param numQubits number of qubits
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::identity(size_t const& n_qubits) {
    using dvlab::utils::int_pow;
    QTensor<T> t(xt::eye<DataType>(int_pow(2, n_qubits)));
    t.reshape(TensorShape(2 * n_qubits, 2));
    TensorAxisList ax;
    for (size_t i = 0; i < n_qubits; ++i) {
        ax.emplace_back(i);
        ax.emplace_back(i + n_qubits);
    }
    return t.transpose(ax);
}

/**
 * @brief Generate an tensor that corresponds to a n-ary Z-spider.
 *
 * @tparam T
 * @param arity the dimension of the tensor
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::zspider(size_t const& arity, dvlab::Phase const& phase) {
    using namespace std::literals;
    QTensor<T> t = xt::zeros<DataType>(TensorShape(arity, 2));
    if (arity == 0) {
        t() = 1. + std::exp(1.0i * dvlab::Phase::phase_to_floating_point<T>(phase));
    } else {
        t[TensorIndex(arity, 0)] = 1.;
        t[TensorIndex(arity, 1)] = std::exp(1.0i * dvlab::Phase::phase_to_floating_point<T>(phase));
    }
    t._tensor *= _nu_pow(2 - arity);
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a n-ary X-spider.
 *
 * @tparam T
 * @param arity the dimension of the tensor
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::xspider(size_t const& arity, dvlab::Phase const& phase) {
    using namespace std::literals;
    QTensor<T> t = xt::ones<QTensor<T>::DataType>(TensorShape(arity, 2));
    QTensor<T> const ket_minus({1. + 0.i, -1. + 0.i});
    QTensor<T> const tmp = tensor_product_pow(ket_minus, arity);
    t._tensor += tmp._tensor * std::exp(1.0i * dvlab::Phase::phase_to_floating_point<T>(phase));
    t._tensor /= std::pow(std::sqrt(2), arity);
    t._tensor *= _nu_pow(2 - arity);
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a n-ary H-box.
 *
 * @tparam T
 * @param arity
 * @param a t(1, ..., 1) (default to -1)
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::hbox(size_t const& arity, QTensor<T>::DataType const& a) {
    QTensor<T> t = xt::ones<QTensor<T>::DataType>(TensorShape(arity, 2));
    if (arity == 0) {
        t() = a;
    } else {
        t[TensorIndex(arity, 1)] = a;
    }
    t._tensor *= _nu_pow(arity);
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a Rx gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::rxgate(dvlab::Phase const& phase) {
    using namespace std::literals;
    auto t = QTensor<T>::pxgate(phase);
    t._tensor *= std::exp(-0.5i * dvlab::Phase::phase_to_floating_point<T>(phase));
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a Ry gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::rygate(dvlab::Phase const& phase) {
    using namespace std::literals;
    auto t = QTensor<T>::pygate(phase);
    t._tensor *= std::exp(-0.5i * dvlab::Phase::phase_to_floating_point<T>(phase));
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a Rz gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::rzgate(dvlab::Phase const& phase) {
    using namespace std::literals;
    auto t = QTensor<T>::pzgate(phase);
    t._tensor *= std::exp(-0.5i * dvlab::Phase::phase_to_floating_point<T>(phase));
    return t;
}

/**
 * @brief Generate an tensor that corresponds to a Px gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::pxgate(dvlab::Phase const& phase) {
    return QTensor<T>::xspider(2, phase);
}

/**
 * @brief Generate an tensor that corresponds to a Py gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::pygate(dvlab::Phase const& phase) {
    auto sdg = QTensor<T>::pzgate(dvlab::Phase(-1, 2));
    auto px  = QTensor<T>::pxgate(phase);
    auto s   = QTensor<T>::pzgate(dvlab::Phase(1, 2));
    return tensordot(s, tensordot(px, sdg, {1}, {0}), {1}, {0});
}

/**
 * @brief Generate an tensor that corresponds to a Pz gate. Axis order: <in, out>
 *
 * @tparam T
 * @param phase
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::pzgate(dvlab::Phase const& phase) {
    return QTensor<T>::zspider(2, phase);
}

//------------------------------
// tensor manipulation functions
//------------------------------

/**
 * @brief Tensor-dot a tensor between pairs of axes
 *
 * @tparam T
 * @param ax1 the first set of axes
 * @param ax2 the second set of axes
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::self_tensor_dot(TensorAxisList const& ax1, TensorAxisList const& ax2) {
    if (ax1.size() != ax2.size()) {
        throw std::invalid_argument("The two index orders should contain the same number of indices.");
    }
    if (!is_disjoint(ax1, ax2)) {
        throw std::invalid_argument("The two index orders should be disjoint.");
    }
    if (ax1.empty()) return *this;
    auto tmp       = QTensor<T>::identity(ax1.size());
    auto tmp_order = TensorAxisList(ax1.size() + ax2.size(), 0);
    std::iota(tmp_order.begin(), tmp_order.end(), 0);
    QTensor<T> u = tensordot(*this, tmp, concat_axis_list(ax1, ax2), tmp_order);
    u._tensor *= _nu_pow(2 * ax1.size());
    return u;
}

/**
 * @brief Generate QTensor
 *
 * @tparam T
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::to_qtensor() const {
    assert(this->dimension() == 2);
    auto dim = gsl::narrow<size_t>(std::log2(this->shape()[0]) + std::log2(this->shape()[1]));

    assert(dim % 2 == 0);

    TensorAxisList ax;
    for (size_t i = 0; i < dim / 2; ++i) {
        ax.emplace_back(i);
        ax.emplace_back(i + dim / 2);
    }
    auto result = *this;
    result.reshape(TensorAxisList(dim, 2));

    return result.transpose(ax);
}

/**
 * @brief Generate the corresponding tensor of a controlled gate.
 *
 * @tparam T
 * @param gate base gate type. e.g., rxgate, pgate, etc.
 * @param numControls number of controls
 * @return QTensor<T>
 */
template <typename T>
QTensor<T> QTensor<T>::control(QTensor<T> const& gate, size_t n_ctrls) {
    using dvlab::utils::int_pow;
    if (n_ctrls == 0) return gate;

    auto const dim = gate.dimension();

    assert(dim % 2 == 0);

    TensorAxisList ax;

    for (size_t i = 0; i < dim / 2; ++i) {
        ax.emplace_back(2 * i);
    }
    for (size_t i = 0; i < dim / 2; ++i) {
        ax.emplace_back(2 * i + 1);
    }

    auto const gate_size     = int_pow(2, dim / 2);
    auto const identity_size = gate_size * (int_pow(2, n_ctrls) - 1);

    QTensor<T> const identity = xt::eye({identity_size, identity_size});
    QTensor<T> gate_matrix    = gate.transpose(ax);
    gate_matrix.reshape({gate_size, gate_size});

    QTensor<T> const result = direct_sum(identity, gate_matrix);
    return result.to_qtensor();
}

/**
 * @brief Get the global scalar factor between two QTensors. This function is only well defined when the cosine similarity is high between two QTensors
 *
 * @tparam U
 * @param t1 the first tensor
 * @param t2 the second tensor
 * @return std::complex<U>
 */
template <typename U>
std::complex<U> global_scalar_factor(QTensor<U> const& t1, QTensor<U> const& t2) {
    return (xt::sum(t2._tensor) / xt::sum(t1._tensor))();
}

/**
 * @brief Get the global norm between two QTensors. This function is only well defined when the cosine similarity is high between two QTensors
 *
 * @tparam U
 * @param t1 the first tensor
 * @param t2 the second tensor
 * @return U
 */
template <typename U>
U global_norm(QTensor<U> const& t1, QTensor<U> const& t2) {
    return std::abs(global_scalar_factor(t1, t2));
}

/**
 * @brief Get the global phase between two QTensors. This function is only well defined when the cosine similarity is high between two QTensors
 *
 * @tparam U
 * @param t1 the first tensor
 * @param t2 the second tensor
 * @return U
 */
template <typename U>
dvlab::Phase global_phase(QTensor<U> const& t1, QTensor<U> const& t2) {
    return dvlab::Phase(std::arg(global_scalar_factor(t1, t2)));
}

template <typename U>
bool is_equivalent(QTensor<U> const& t1, QTensor<U> const& t2, double eps = 1e-6) {
    if (t1.shape() != t2.shape()) return false;
    return cosine_similarity(t1, t2) >= (1 - eps);
}

//------------------------------
// Private member functions
//------------------------------

/**
 * @brief Calculate (2^(1/4))^n
 *
 * @tparam T
 * @param n
 * @return QTensor<T>::DataType
 */
template <typename T>
typename QTensor<T>::DataType QTensor<T>::_nu_pow(int n) {
    return std::pow(2., -0.25 * n);
}

// decomposition function
template <typename U>
int graycode(Tensor<U> const& t, int I, int J, int qreq, std::fstream& fout) {
    // fmt::println("in graycode function");
    // do pabbing
    std::vector<std::string> cnot_list;
    int cnot_length = 0;
    // int qreq = int(log2(t.shape()[0]));
    // qreq = 4;
    // std::cout << "qreq: " << qreq << std::endl;
    // std::cout << "index: " << I << ", " << J << std::endl;

    // get the 0 & 1 diff position
    int get_diff = I ^ J;
    int diff_pos = 0;
    for (int i = 0; i < qreq; i++) {
        if (((get_diff >> i) & 1) && (J >> i & 1)) {
            diff_pos = i;
            break;
        }
    }
    // std::cout << "diff position: " << diff_pos << std::endl;
    bool x_given = 0;

    if ((I + std::pow(2, diff_pos)) != (std::pow(2, qreq) - 1)) {
        if (((I >> diff_pos) & 1) == 0) {
            cnot_list.emplace_back(fmt::format("x q[{}];\n", diff_pos));
            fout << cnot_list[cnot_length];
            cnot_length++;
            x_given = 1;
        }
        for (int i = 0; i < qreq; i++) {
            if (i == diff_pos) {
                continue;
            }
            if (((I >> i) & 1) == 0) {
                cnot_list.emplace_back(fmt::format("cx q[{}], q[{}];\n", diff_pos, i));
                fout << cnot_list[cnot_length];
                cnot_length++;
                // std::cout << "cx on ctrl: " << diff_pos << " targ: " << i << std::endl;
            }
        }
        if (x_given) {
            cnot_list.emplace_back(fmt::format("x q[{}];\n", diff_pos));
            fout << cnot_list[cnot_length];
            cnot_length++;
            // std::cout << "x on " << diff_pos << std::endl;
            x_given = 0;
        }
    }
    if (((J >> diff_pos) & 1) == 0) {
        cnot_list.emplace_back(fmt::format("x q[{}];\n", diff_pos));
        fout << cnot_list[cnot_length];
        cnot_length++;
        // std::cout << "x on " << diff_pos << std::endl;
        x_given = 1;
    }
    for (int i = 0; i < qreq; i++) {
        if (i == diff_pos) {
            continue;
        }
        if (((J >> i) & 1) == 0) {
            cnot_list.emplace_back(fmt::format("cx q[{}], q[{}];\n", diff_pos, i));
            fout << cnot_list[cnot_length];
            cnot_length++;
            // std::cout << "cx on ctrl: " << diff_pos << " targ: " << i << std::endl;
        }
    }
    if (x_given) {
        cnot_list.emplace_back(fmt::format("x q[{}];\n", diff_pos));
        fout << cnot_list[cnot_length];
        cnot_length++;
        // std::cout << "x on " << diff_pos << std::endl;
        x_given = 0;
    }
    // decompose CnU
    int ctrl_index = 0;
    for (int i = 0; i < qreq; i++) {
        if (i != diff_pos) {
            ctrl_index += int(pow(2, i));
        }
    }
    decompose_CnU(t, diff_pos, ctrl_index, qreq - 1, qreq, fout);

    // do unpabbing
    for (int i = cnot_length - 1; i >= 0; i--) {
        fout << cnot_list[i];
    }
    return diff_pos;
}

template <typename U>
auto get_2level(QTensor<U> t) {
    std::vector<TwoLevelMatrix> two_level_chain;
    // fmt::println("start decomposing...");

    using namespace std::literals;
    size_t num = 0;

    // t = {
    //     {0.353553 + 0.i, 0. + 0.i, -0.612372 + 0.i, 0.707107 + 0.i},
    //     {0. + -0.866025i, 0. + 0.i, 0. - 0.5i, 0. + 0.i},
    //     {0. + 0.i, 0. + 1.i, 0. + 0.i, 0. + 0.i}, // test
    //     {-0.353553 + 0.i, 0. + 0.i, 0.612372 + 0.i, 0.707107 + 0.i},
    // };
    // t = {
    //     {0.707107+ 0.i, -0.707107 + 0.i, 0.0 + 0.i, 0.0+ 0.i},
    //     {0.707107 + 0.0i, 0.707107 + 0.i, 0. - 0.0i, 0. + 0.i},
    //     {0. + 0.i, 0. + 0.i, 0.707107 + 0.i, -0.707107 + 0.i}, // test
    //     {0.0 + 0.i, 0. + 0.i, 0.707107 + 0.i, 0.707107 + 0.i},
    // };
    // fmt::println("今天拆解的矩陣是:");
    // fmt::println("{}", t);

    int s = int(t.shape()[0]);
    // fmt::println("shape : {} * {}", s, s);

    QTensor<double>
        XU = QTensor<double>::identity((int)round(std::log2(s)));
    // QTensor<double> I = QTensor<double>::identity(1);
    // QTensor<double> U = tensor_product_pow(I, (int)round(std::log2(s)));
    XU.reshape({t.shape()[0], t.shape()[0]});

    QTensor<double>
        FU = QTensor<double>::identity(1);

    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            // check 2-level
            bool is_two_level = false;
            int d = 0, Up = 0, L = 0;
            int d1 = 0, Ui = 0, Li = 0;
            int d2 = 0, Uj = 0, Lj = 0;
            int c_i = 0, c_j = 0;
            std::complex one(1.0, 0.);

            for (int x = 0; x < s; x++) {  // check all
                for (int y = 0; y < s; y++) {
                    if (x == y) {
                        if (std::abs(t(y, x) - one) > 1e-6) {
                            d++;
                            if (d == 1) {
                                d1 = x;
                            }
                            if (d == 2) {
                                d2 = x;
                            }
                        }
                    } else if (x > y) {
                        if (std::abs(t(y, x)) > 1e-6) {
                            Up++;
                            Ui = y;
                            Uj = x;
                        }
                    } else {
                        if (std::abs(t(y, x)) > 1e-6) {
                            L++;
                            Li = y;
                            Lj = x;
                        }
                    }
                }
            }

            if ((Up == 1 && L == 1) && (Ui == Lj && Uj == Li)) {
                if (d == 2 && d1 == Ui && d2 == Li) {
                    is_two_level = true;
                    c_i          = d1;
                    c_j          = d2;
                }
                if (d == 1 && (d1 == Ui || d1 == Uj)) {
                    is_two_level = true;
                    if (d1 != s - 1) {
                        c_i = d1;
                        c_j = d1 + 1;
                    } else {
                        c_i = d1 - 1;
                        c_j = d1;
                    }
                }
                if (d == 0) {
                    is_two_level = true;
                    c_i          = Ui;
                    c_j          = Uj;
                }
            }

            if (Up == 0 && L == 0) {
                if (d == 2) {
                    is_two_level = true;
                    c_i          = d1;
                    c_j          = d2;
                }
                if (d == 1) {
                    is_two_level = true;
                    if (d1 != s - 1) {
                        c_i = d1;
                        c_j = d1 + 1;
                    } else {
                        c_i = d1 - 1;
                        c_j = d1;
                    }
                }
                if (d == 0) {  // identity
                    // fmt::println("U become I, ended");
                    return two_level_chain;
                }
            }

            if (is_two_level == true) {
                FU(0, 0) = t(c_i, c_i);
                FU(0, 1) = t(c_i, c_j);
                FU(1, 0) = t(c_j, c_i);
                FU(1, 1) = t(c_j, c_j);
                TwoLevelMatrix m(FU);
                m.i = c_i;
                m.j = c_j;
                two_level_chain.push_back(m);
                // fmt::println("find t has been 2 level matrix, put it in the chain");
                // fmt::println("{}", FU);
                // fmt::println("in the chain");

                return two_level_chain;
            }

            if (std::abs(t(i, i).real() - 1) < 1e-6 && std::abs(t(i, i).imag()) < 1e-6) {  // maybe use e-6 approx.
                if (std::abs(t(j, i).real()) < 1e-6 && std::abs(t(j, i).imag()) < 1e-6) {
                    // fmt::println("skip cuz (1,0) {},{}", i, j);
                    continue;
                }
            }
            if (std::abs(t(i, i).real()) < 1e-6 && std::abs(t(i, i).imag()) < 1e-6) {  // maybe use e-6 approx.
                if (std::abs(t(j, i).real()) < 1e-6 && std::abs(t(j, i).imag()) < 1e-6) {
                    // fmt::println("skip cuz (0,0) {},{}", i, j);
                    continue;
                }
            }

            // if (std::abs(t(j, i).real()) < 1e-6 && std::abs(t(j, i).imag()) < 1e-6)
            // {
            //     fmt::println("skip cuz U({},{}) = 0", j, i);
            //     continue;
            // }

            // fmt::println("拆! i = {}, j = {}", i, j);
            num++;

            double u = std::sqrt(std::norm(t(i, i)) + std::norm(t(j, i)));
            // fmt::println("u = {}", u);

            using namespace std::literals;

            for (int x = 0; x < s; x++) {
                for (int y = 0; y < s; y++) {
                    if (x == y) {
                        if (x == i) {
                            XU(x, y) = (std::conj(t(i, i))) / u;
                        } else if (x == j) {
                            XU(x, y) = t(i, i) / u;
                        } else {
                            XU(x, y) = 1.0 + 0.i;
                        }
                    } else if (x == j && y == i) {
                        XU(x, y) = (-1. + 0.i) * t(j, i) / u;
                    } else if (x == i && y == j) {
                        XU(x, y) = (std::conj(t(j, i))) / u;
                    } else {
                        XU(x, y) = 0. + 0.i;
                    }
                }
            }

            t = tensordot(XU, t, {1}, {0});
            // fmt::println("after U, t =:");
            // fmt::println("{}", t);

            // U(ii/ij/ji/jj) adjust
            QTensor<double>
                CU = QTensor<double>::identity(1);

            CU(0, 0) = std::conj(XU(i, i));
            CU(0, 1) = std::conj(XU(j, i));
            CU(1, 0) = std::conj(XU(i, j));
            CU(1, 1) = std::conj(XU(j, j));

            TwoLevelMatrix m(CU);
            m.i = i;
            m.j = j;
            two_level_chain.push_back(m);

            // fmt::println("CU{}", num);
            // fmt::println("{}", two_level_chain[num - 1].given);
        }
    }

    return two_level_chain;
}

template <typename U>
void decompose(QTensor<U>& t, std::string& filepath) {
    // fmt::println("matrix: {}", t);
    // fmt::println("in decompose function QTensor");
    // fmt::println("in decomposition main function");
    std::fstream fs;
    std::string filename = fmt::format("{}{}", filepath, ".qasm");
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::vector<TwoLevelMatrix> two_level_chain = get_2level(t);
    // fmt::println("two level chain: {}", two_level_chain[0].given);
    int qreq = int(log2(t.shape()[0]));
    fs << "OPENQASM 2.0;\ninclude \"qelib1.inc\";\n";
    fs << fmt::format("qreg q[{}];\n", qreq);
    // qreq = 2;
    int end = two_level_chain.size();
    // for(int i=end-1; i >= 0; i--){
    //     fmt::println("{} {}", two_level_chain[i].i, two_level_chain[i].j);
    //     fmt::println("{}", two_level_chain[i].given);
    // }
    // for(int i=0 ; i< end; i++){
    //     int i_tmp = 0, j_tmp = 0;
    //     std::cout << two_level_chain[i].i << " " << two_level_chain[i].j <<std::endl;
    //     for(int j=0; j<qreq; j++){
    //         i_tmp = i_tmp*2+((two_level_chain[i].i >> j) & 1);
    //         j_tmp = j_tmp*2+((two_level_chain[i].j >> j) & 1);
    //     }
    //     two_level_chain[i].i =  i_tmp;
    //     two_level_chain[i].j = j_tmp ;
    //     std::cout << two_level_chain[i].i << " " << two_level_chain[i].j <<std::endl;
    // }
    for (int i = end - 1; i >= 0; i--) {
        int i_idx = 0, j_idx = 0;
        for (int j = 0; j < qreq; j++) {
            i_idx = i_idx * 2 + (two_level_chain[i].i >> j & 1);
            j_idx = j_idx * 2 + (two_level_chain[i].j >> j & 1);
        }
        if (i_idx > j_idx) {
            std::swap(i_idx, j_idx);
            std::swap(two_level_chain[i].given(0, 0), two_level_chain[i].given(1, 1));
            std::swap(two_level_chain[i].given(0, 1), two_level_chain[i].given(1, 0));
        }
        // fmt::println("original: {}, {}; after: {}, {}", two_level_chain[i].i, two_level_chain[i].j, i_idx, j_idx);

        graycode(two_level_chain[i].given, i_idx, j_idx, qreq, fs);
        // graycode(two_level_chain[i].given, two_level_chain[i].i, two_level_chain[i].j, qreq, fs);
    }
}

}  // namespace qsyn::tensor

template <typename T>
struct fmt::formatter<qsyn::tensor::QTensor<T>> : fmt::ostream_formatter {};
