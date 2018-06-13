#include "LineSearch/Dynamic/Dynamic.h"

namespace js_nlp
{

DynamicLineSearch::DynamicLineSearch () {}

DynamicLineSearch::DynamicLineSearch (std::string ls) : Base(ls) {}

DynamicLineSearch::DynamicLineSearch (const nlpp::DynamicLineSearch<JS_Function>& dls) : Base(dls) {}


} // namespace js_nlp


EMSCRIPTEN_BINDINGS(LineSearch) {
    emscripten::class_<js_nlp::DynamicLineSearch>("LineSearch")
        .constructor<>()
        .constructor<std::string>();
}