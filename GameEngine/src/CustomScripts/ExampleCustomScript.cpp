#include <iostream> 
#include <entityx/entityx.h> 
#include "../CScript.h" 
#include "../Components/Components.h" 

#define EXPORT extern "C" __declspec(dllexport) 

class ExampleCustomScript : public CScript 
{ 
private: 
   typedef CScript super; 
public: 
   ExampleCustomScript(entityx::Entity* ex) : super(ex) {} 
   void update(); 
}; 

void ExampleCustomScript::update() 
{ 
   entityx::ComponentHandle<Transform> transform = entity->component<Transform>(); 
   transform.get()->x = 2; 
   // std::cout << entity->component<Transform>().get()->x << std::endl; 

   //Input::getInstance().isKeyPressed(45);
} 

EXPORT CScript* CreateCustomScriptObject(entityx::Entity* ex) 
{ 
   return new ExampleCustomScript(ex); 
} 
