#include <iostream>
#include <typeinfo>
#include <string>

#include <boost/assert.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <boost/thread.hpp>
//#include <boost/thread/mutex.hpp>

// back-end
#include <boost/msm/back/state_machine.hpp>
//front-end
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/back/common_types.hpp>


#ifndef _HORIZON_STATE_MACHINE_CONTEXT_H_
#define _HORIZON_STATE_MACHINE_CONTEXT_H_
namespace horizon{


    template<class TMachineType>
    class StateMachineContext{
        typedef boost::msm::back::state_machine<TMachineType> StateMachineImp;
    public:

        StateMachineContext();
        template<class TEventType>
        void operator() (const TEventType &e);

        void setDebug(bool b) {
            m_bDebug = b;
        }

        void start() {
            //int a = 10;
            m_machine->start();
        }

        void stop() {
            //StateMachineImp* a = m_machine->get();
            m_machine->stop();
            //timer_service().stop();
             //join();
        }
        template<class Ev>
        void processEvent(Ev e){
            m_machine->process_event(e);
        };

        void printState() {
            int cs = m_machine->current_state()[0];
            std::cout << "current_state: " << cs << std::endl;
        }
    private:

        boost::shared_ptr<StateMachineImp> m_machine;
        bool m_bDebug;
    };


    template<class TMachineType>
    inline
    StateMachineContext<TMachineType>::StateMachineContext() 
        : m_bDebug(false)
    {
        //m_machine = boost::shared_ptr<StateMachineImp>(new StateMachineImp());
        m_machine = boost::shared_ptr<StateMachineImp>(new StateMachineImp(boost::ref(*this)));
    }




    template<class TMachineType> template<class TEventType>
    inline void StateMachineContext<TMachineType>::operator() (const TEventType &e)
    {
        boost::mutex::scoped_lock scoped_lock(mutex);
        using namespace std;
        if (m_bDebug)
            cout << "process: " << typeid(e).name() << endl;
        m_machine->process_event(e);
        if (m_bDebug)
            print_state();
    };


    class HTest{
    public:
        HTest();
        ~HTest();
    };

};


#endif //_HORIZON_STATE_MACHINE_CONTEXT_H_