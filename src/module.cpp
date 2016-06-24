#include <boost/python/module.hpp>
#include <boost/python/register_ptr_to_python.hpp>

//------------------------------------------------------------------------------
// Class to be exported
// It needs to be abstract to demonstrate the bug
//------------------------------------------------------------------------------
class Base {
public:
  Base() {}
  virtual ~Base() {}
  virtual const int id() const = 0;
};

//------------------------------------------------------------------------------
// Module
//------------------------------------------------------------------------------

BOOST_PYTHON_MODULE(helloworld23) {
  using namespace boost::python;

  // Including this line with VS2015 (x64) & update 3 gives a linker error:
  // module.obj : error LNK2019: unresolved external symbol "class Base const volatile * __cdecl boost::get_pointer<class Base const volatile >(class Base const volatile *)" (??$get_pointer@$$CDVBase@@@boost@@YAPEDVBase@@PEDV1@@Z) referenced in function "public: static struct _object * __cdecl boost::python::objects::make_instance_impl<class Base,struct boost::python::objects::pointer_holder<class boost::shared_ptr<class Base>,class Base>,struct boost::python::objects::make_ptr_instance<class Base,struct boost::python::objects::pointer_holder<class boost::shared_ptr<class Base>,class Base> > >::execute<class boost::shared_ptr<class Base> >(class boost::shared_ptr<class Base> &)" (??$execute@V?$shared_ptr@VBase@@@boost@@@?$make_instance_impl@VBase@@U?$pointer_holder@V?$shared_ptr@VBase@@@boost@@VBase@@@objects@python@boost@@U?$make_ptr_instance@VBase@@U?$pointer_holder@V?$shared_ptr@VBase@@@boost@@VBase@@@objects@python@boost@@@345@@objects@python@boost@@SAPEAU_object@@AEAV?$shared_ptr@VBase@@@3@@Z)
  register_ptr_to_python<Base*>();
}


