#include "QuasiNewton/LBFGS/LBFGS.h"


namespace js_nlp
{

LBFGS::LBFGS ()
{
}

LBFGS::LBFGS(emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>{}, 
                                      js_nlp::stop::GradientOptimizer{}, 
                                      js_nlp::out::Optimizer(js_out))
{
}

LBFGS::LBFGS(std::string ls, emscripten::val js_out) : Base(nlpp::DynamicLineSearch<JS_Function>(ls), 
                                                      js_nlp::stop::GradientOptimizer{}, 
                                                      js_nlp::out::Optimizer(js_out))
{
}


} // namespace js_nlp


EMSCRIPTEN_BINDINGS(LBFGS) {
    emscripten::class_<js_nlp::LBFGS>("LBFGS")
        .constructor<>()
        .constructor<emscripten::val>()
        .constructor<std::string, emscripten::val>()
        .function("optimize", static_cast<emscripten::val (js_nlp::LBFGS::*)(emscripten::val, emscripten::val)>
                              (&js_nlp::LBFGS::optimize))
        .property("lineSearch", &js_nlp::LBFGS::getLineSearch, &js_nlp::LBFGS::setLineSearch)
        .property("stop", &js_nlp::LBFGS::getStop, &js_nlp::LBFGS::setStop)
        .property("output", &js_nlp::LBFGS::getOutput, &js_nlp::LBFGS::setOutput);
}