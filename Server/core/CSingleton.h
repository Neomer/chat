#ifndef CSINGLETON_H
#define CSINGLETON_H

namespace noncopyable_  // protection from unintended ADL
{
  class noncopyable
  {
   protected:
      noncopyable() {}
      ~noncopyable() {}
   private:  // emphasize the following members are private
      noncopyable( const noncopyable& );
      const noncopyable& operator=( const noncopyable& );
  };
}

typedef noncopyable_::noncopyable noncopyable;


template<typename T>
class CSingleton : private noncopyable
{
public:
    ///Возвращает статический экземпляр нужного класса
    static T& getInstance()
    {
        static T tmp;
        return tmp;
    }
};

#endif // CSINGLETON_H
