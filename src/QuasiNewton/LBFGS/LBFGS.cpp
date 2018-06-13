#include "QuasiNewton/LBFGS/LBFGS.h"


namespace js_nlp
{

LBFGS::LBFGS ()
{
}

LBFGS::LBFGS(emscripten::val js_out) : 
Base(nlpp::params::LBFGS<nlpp::BFGS_Diagonal, nlpp::DynamicLineSearch<JS_Function>, js_nlp::out::Optimizer>
     (nlpp::DynamicLineSearch<JS_Function>{}, js_nlp::out::Optimizer(js_out)))
{
}

LBFGS::LBFGS(std::string ls, emscripten::val js_out) : 
Base(nlpp::params::LBFGS<nlpp::BFGS_Diagonal, nlpp::DynamicLineSearch<JS_Function>, js_nlp::out::Optimizer>
     (nlpp::DynamicLineSearch<JS_Function>(ls), js_nlp::out::Optimizer(js_out)))
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
        .property("maxIterations", &js_nlp::LBFGS::getMaxIterations, &js_nlp::LBFGS::setMaxIterations)
        .property("fTol", &js_nlp::LBFGS::getFTol, &js_nlp::LBFGS::setFTol)
        .property("gTol", &js_nlp::LBFGS::getGTol, &js_nlp::LBFGS::setGTol)
        .property("xTol", &js_nlp::LBFGS::getXTol, &js_nlp::LBFGS::setXTol);
}