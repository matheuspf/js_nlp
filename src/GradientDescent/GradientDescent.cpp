#include "GradientDescent/GradientDescent.h"


namespace js_nlp
{

GD::GD ()
{
}

GD::GD(emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>{}, 
                                      js_nlp::stop::GradientOptimizer{}, 
                                      js_nlp::out::Optimizer(js_out))
{
}

GD::GD(std::string ls, emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>(ls), 
                                                      js_nlp::stop::GradientOptimizer{}, 
                                                      js_nlp::out::Optimizer(js_out))
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
        .property("stop", &js_nlp::GD::getStop, &js_nlp::GD::setStop)
        .property("output", &js_nlp::GD::getOutput, &js_nlp::GD::setOutput);
}