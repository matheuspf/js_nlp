#pragma once

#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers.h"

#include "JS_Function.h"

#include "../LineSearch/Dynamic/Dynamic.h"


namespace js_nlp
{

template <class Impl>
struct Optimizer
{
    emscripten::val optimize (emscripten::val f, emscripten::val x)
    {
        nlpp::Vec x0 = makeVec(x);

        JS_Function func(f);

        nlpp::Vec res = static_cast<Impl&>(*this).operator()(func, nlpp::fd::gradient(func), x0);

        double* buffer = new double[res.size()];

        std::copy(&res[0], &res[0]+res.size(), buffer);

        return emscripten::val(emscripten::typed_memory_view(res.size(), buffer));
    }

    DynamicLineSearch getLineSearch () const
    {
        return static_cast<const DynamicLineSearch>(static_cast<const Impl&>(*this).lineSearch);
    }

    void setLineSearch (const DynamicLineSearch& lineSearch)
    {
        static_cast<Impl&>(*this).lineSearch = lineSearch;
    }


    int getMaxIterations () const
    {
        return static_cast<const Impl&>(*this).maxIterations;
    }

    void setMaxIterations (int maxIterations)
    {
        static_cast<Impl&>(*this).maxIterations = maxIterations;
    }

    double getFTol () const
    {
        return static_cast<const Impl&>(*this).fTol;
    }

    void setFTol (double fTol)
    {
        static_cast<Impl&>(*this).fTol = fTol;
    }


    double getGTol () const
    {
        return static_cast<const Impl&>(*this).gTol;
    }

    void setGTol (double gTol)
    {
        static_cast<Impl&>(*this).gTol = gTol;
    }


    double getXTol () const
    {
        return static_cast<const Impl&>(*this).xTol;
    }

    void setXTol (double xTol)
    {
        static_cast<Impl&>(*this).xTol = xTol;
    }
};


namespace out
{

struct Optimizer
{
    Optimizer () : initialized(false), f(0)
    {
    }

    Optimizer (emscripten::val f) : f(f), initialized(true)
    {
    }

    template <class Opt>
    void init (const Opt& optimizer, double fx)
    {
        if(initialized)
            f(fx);
    }

    template <class Opt>
    void operator () (const Opt& optimizer, double fx)
    {
        if(initialized)
            f(fx);
    }

    template <class Opt>
    void finish (const Opt& optimizer, double fx)
    {
        if(initialized)
            f(fx);
    }


    emscripten::val f;

    bool initialized;
};


} // namespace out

} // namespace js_nlp
