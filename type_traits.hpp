#include<type_traits>
#include<<utility>

template<class r_val, class T, class... Args>
constexpr T somes(r_val(T::* ptr)(Args...));

template<class Ptr>
struct remove_fun_member_pointer
{
    using type = std::remove_cv_t< decltype(somes(std::declval<Ptr>()))>;
};

template<class Ptr>
using remove_fun_member_pointer_t = typename remove_fun_member_pointer<Ptr>::type;
