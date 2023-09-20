
#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int i, int j)
{
    return i + j;
}

PYBIND11_MODULE(example, m)
{
// optional module docstring
m.doc() = "pybind11 example plugin";
// expose add function, and add keyword arguments and default arguments
m.def("add", &add, "A function which adds two numbers", py::arg("i")=1, py::arg("j")=2);

// exporting variables
py::object theAnswer = py::cast("theAnswerShouldBe1+2=3");
m.attr("the_answer") = theAnswer;
py::object objectWorld = py::cast("World");
m.attr("what") =  objectWorld;
}