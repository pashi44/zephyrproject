#include  <iostream>
#include <memory>


#ifdef __cplusplus
extern "C" {
#endif



using namespace std;


int main(){
  
  

  std::shared_ptr<void>  voisptr = 
  
  
   std::make_shared<std::string>("asds");
  cout <<  "from here " << endl;
  
return   0;

}


#ifdef __cplusplus
}
#endif


