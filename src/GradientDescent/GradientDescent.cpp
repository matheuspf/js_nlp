#include "GradientDescent/GradientDescent.h"


namespace js_nlp
{

GD::GD ()
{
}

GD::GD(emscripten::val js_out) : Base(nlpp::params::GradientDescent<nlpp::Goldstein, js_nlp::out::Optimizer>
                                      (nlpp::Goldstein{}, js_nlp::out::Optimizer(js_out)))
{
}


} // namespace js_nlp


EMSCRIPTEN_BINDINGS(Optimization) {
    emscripten::class_<js_nlp::GD>("GD")
        .constructor<>()
        .constructor<emscripten::val>()
        .function("optimize", static_cast<emscripten::val (js_nlp::GD::*)(emscripten::val, emscripten::val)>
                              (&js_nlp::GD::optimize))
        .property("maxIterations", &js_nlp::GD::getMaxIterations, &js_nlp::GD::setMaxIterations)
        .property("fTol", &js_nlp::GD::getFTol, &js_nlp::GD::setFTol)
        .property("gTol", &js_nlp::GD::getGTol, &js_nlp::GD::setGTol)
        .property("xTol", &js_nlp::GD::getXTol, &js_nlp::GD::setXTol);
}