#include "GradientDescent/GradientDescent.h"


namespace js_nlp
{

GD::GD() {}

} // namespace js_nlp


EMSCRIPTEN_BINDINGS(Optimization) {
    emscripten::class_<js_nlp::GD>("GD")
        .constructor<>()
        .function("optimize", static_cast<emscripten::val (js_nlp::GD::*)(emscripten::val, emscripten::val)>(&js_nlp::GD::optimize));
}