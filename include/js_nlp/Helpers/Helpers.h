#pragma once

#include <emscripten/bind.h>
#include <emscripten/val.h>

#include <nlpp/Helpers/Helpers.h>

namespace js_nlp
{

nlpp::Vec makeVec (emscripten::val);


} // namespace js_nlp