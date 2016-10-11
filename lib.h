
#pragma once

#include <memory>

class Foo
{
public:
    class Handler
    {
    public:
        constexpr static int CurrentVersion = 1;
        template<class T>
        Handler(T t)
            : interface(std::make_unique<Iface<T>>(std::move(t)))
            , version(CurrentVersion) {}

        void bar() { interface->bar(); }
        void pippo() { if (version > 0) interface->pippo(); }

    private:
        struct IfaceBase {
            virtual ~IfaceBase() = default;
            virtual void bar() = 0;
            virtual void pippo() = 0;
        };
        template<class T>
        struct Iface : public IfaceBase {
            Iface(T t) : data(std::move(t)) {}

            virtual void bar() { data.bar(); }
            virtual void pippo() { data.pippo(); }

            T data;
        };

        std::unique_ptr<IfaceBase> interface;
        int version;
    };

    Foo(Handler h) : handler(std::move(h)) {}

    void bar();
    void pippo();

    Handler handler;
};
