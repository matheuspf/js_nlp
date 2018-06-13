#include "GradientDescent/GradientDescent.h"


namespace js_nlp
{

GD::GD ()
{
}

GD::GD(emscripten::val js_out) : Base(nlpp::params::GradientDescent<nlpp::DynamicLineSearch<JS_Function>, js_nlp::out::Optimizer>
                                      (nlpp::DynamicLineSearch<JS_Function>{}, js_nlp::out::Optimizer(js_out)))
{
}

GD::GD(std::string ls, emscripten::val js_out) : Base(nlpp::params::GradientDescent<nlpp::DynamicLineSearch<JS_Function>, js_nlp::out::Optimizer>
                                                (nlpp::DynamicLineSearch<JS_Function>(ls), js_nlp::out::Optimizer(js_out)))
{
}


} // namespace js_nlp


EMSCRIPTEN_BINDINGS(GradientDescent) {
    emscripten::class_<js_nlp::GD>("GD")
        .constructor<>()
        .constructor<emscripten::val>()
        .constructor<std::string, emscripten::val>()
        .function("optimize", static_cast<emscripten::val (js_nlp::GD::*)(emscripten::val, emscripten::val)>
                              (&js_nlp::GD::optimize))
        .property("lineSearch", &js_nlp::GD::getLineSearch, &js_nlp::GD::setLineSearch)
        .property("maxIterations", &js_nlp::GD::getMaxIterations, &js_nlp::GD::setMaxIterations)
        .property("fTol", &js_nlp::GD::getFTol, &js_nlp::GD::setFTol)
        .property("gTol", &js_nlp::GD::getGTol, &js_nlp::GD::setGTol)
        .property("xTol", &js_nlp::GD::getXTol, &js_nlp::GD::setXTol);
}