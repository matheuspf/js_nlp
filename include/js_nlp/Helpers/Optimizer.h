#pragma once

#include <nlpp/LineSearch/Dynamic/Dynamic.h>

#include "Helpers.h"

#include "JS_Function.h"

#include "../LineSearch/Dynamic/Dynamic.h"


namespace js_nlp
{

namespace stop
{

struct GradientOptimizer : public nlpp::stop::GradientOptimizer
{
    using Base = nlpp::stop::GradientOptimizer;
    using Base::Base;


    int getMaxIterations () const
    {
        return Base::maxIterations;
    }

    void setMaxIterations (int maxIterations)
    {
        Base::maxIterations = maxIterations;
    }

    double getFTol () const
    {
        return Base::fTol;
    }

    void setFTol (double fTol)
    {
        Base::fTol = fTol;
    }


    double getGTol () const
    {
        return Base::gTol;
    }

    void setGTol (double gTol)
    {
        Base::gTol = gTol;
    }


    double getXTol () const
    {
        return Base::xTol;
    }

    void setXTol (double xTol)
    {
        Base::xTol = xTol;
    }
};


} // namespace stop



namespace out
{

struct Optimizer
{
    Optimizer () : init_(emscripten::val::null()), op_(emscripten::val::null()), finish_(emscripten::val::null())
    {
    }

    Optimizer (emscripten::val op_) : init_(emscripten::val::null()), op_(op_), finish_(emscripten::val::null())
    {
    }

    Optimizer (emscripten::val op_, emscripten::val finish_) : init_(emscripten::val::null()), op_(op_), finish_(finish_)
    {
    }

    Optimizer (emscripten::val init_, emscripten::val op_, emscripten::val finish_) : init_(init_), op_(op_), finish_(finish_)
    {
    }


    template <class Opt, class Vec, typename Float>
    void init (const Opt& optimizer, const Eigen::MatrixBase<Vec>& x, Float fx, const Eigen::MatrixBase<Vec>& gx)
    {
        if(init_.isNull())
            return;

        emscripten::val valX(emscripten::typed_memory_view(x.size(), &x[0]));
        emscripten::val valGx(emscripten::typed_memory_view(gx.size(), &gx[0]));

        init_(valX, fx, valGx);
    }

    template <class Opt, class Vec, typename Float>
    void operator () (const Opt& optimizer, const Eigen::MatrixBase<Vec>& x, Float fx, const Eigen::MatrixBase<Vec>& gx)
    {
        if(op_.isNull())
            return;

        emscripten::val valX(emscripten::typed_memory_view(x.size(), &x[0]));
        emscripten::val valGx(emscripten::typed_memory_view(gx.size(), &gx[0]));

        op_(valX, fx, valGx);
    }

    template <class Opt, class Vec, typename Float>
    void finish (const Opt& optimizer, const Eigen::MatrixBase<Vec>& x, Float fx, const Eigen::MatrixBase<Vec>& gx)
    {
        if(finish_.isNull())
            return;

        emscripten::val valX(emscripten::typed_memory_view(x.size(), &x[0]));
        emscripten::val valGx(emscripten::typed_memory_view(gx.size(), &gx[0]));

        finish_(valX, fx, valGx);
    }


    emscripten::val getInit () const { return init_; }

    void setInit (emscripten::val init__) { init_ = init__; }


    emscripten::val getOp () const { return op_; }

    void setOp (emscripten::val op__) { op_ = op__; }


    emscripten::val getFinish () const { return finish_; }

    void setFinish (emscripten::val finish__) { finish_ = finish__; }


    emscripten::val init_;
    emscripten::val op_;
    emscripten::val finish_;
};


} // namespace out



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


    stop::GradientOptimizer getStop () const
    {
        return static_cast<const stop::GradientOptimizer>(static_cast<const Impl&>(*this).stop);
    }

    void setStop (const stop::GradientOptimizer& stop)
    {
        static_cast<Impl&>(*this).stop = stop;
    }


    out::Optimizer getOutput () const
    {
        return static_cast<const out::Optimizer>(static_cast<const Impl&>(*this).output);
    }

    void setOutput (const out::Optimizer& output)
    {
        static_cast<Impl&>(*this).output = output;
    }
};

} // namespace js_nlp
