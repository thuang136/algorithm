#include "people.h"
#include <dlfcn.h>

class callPlugin
{
typedef BasePeople* ObjectPtr;

typedef ObjectPtr (*createObjectPtr)(const string& , const int);

typedef void (*deleteObjectPtr)(ObjectPtr);

public:
    callPlugin(const string& soPath, const int openMode = RTLD_LAZY) :soPath_(soPath),openMode_(openMode)
    {
        cout << "callPlugin constructor invoked" << endl;
    }

    ~callPlugin()
    {
        cout << "callPlugin deconstructor invoked" << endl;
    }

    int execute()
    {
        void* pluginHandler = openPlugin();

        if(pluginHandler)
        {
            createObjectPtr createFunc = (createObjectPtr)dlsym(pluginHandler,_CREATE_OBJECT_.c_str());

            /*
               ���ݶ�̬���ӿ�Ĳ����������ţ����ط��Ŷ�Ӧ�ĵ�ַ
            */

            ObjectPtr people = NULL;

            if(createFunc)
            {
                people = createFunc("huangtao",29);
                people->speak();
                people->test();

            }
            else
            {
                cout << "execute error" << endl;
            }

            deleteObjectPtr deleteFunc = (deleteObjectPtr)dlsym(pluginHandler,_DELETE_OBJECT_.c_str());

            if(deleteFunc)
            {
                deleteFunc(people);
            }
            else
            {
                cout << "deleteFunc error" << dlerror() << endl;
            }

            dlclose(pluginHandler);

            pluginHandler = NULL;

        }


    }


private:
    string soPath_;
    int openMode_;

    void* openPlugin()
    {
        if(soPath_.size() < 1)
        {
            cout << "plugin file[soPath = " << soPath_ << "] cannot be empty!" << endl;
            return NULL;
        }

        /*

           ��һ����̬���ӿ⣬�����ض�̬���ӿ�ľ��

           RTLD_NOW  ��Ҫ��dlopen����ǰ��������δ����ķ��ţ��������������������NULL


        */


        if(openMode_ == RTLD_NOW || openMode_ == RTLD_LAZY)
        {
            return dlopen(soPath_.c_str(),openMode_);
        }
        else
        {
            return dlopen(soPath_.c_str(),RTLD_LAZY);
        }

    }

};

int main(int argc, char** argv)
{
    callPlugin cp1("liblibstudent.so");

    cp1.execute();

}

