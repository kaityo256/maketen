#include <iostream>
#include <sstream>

enum OP{O_PLUS,O_MINUS,O_MUL,O_DIV};

const double eps = 0.001;

const std::string s_op[4] = {"+","-","*","/"};
//----------------------------------------------------------------------
double
calc(double c1,double c2, int op){
  switch(op){
    case O_PLUS:
      return (c1+c2);
    break;
    case O_MINUS:
      return (c1-c2);
    break;
    case O_MUL:
      return (c1*c2);
    break;
    case O_DIV:
      return c1/c2;
    break;
    default:
      std::cout << "Error!" << std::endl;
    break;
  }
}
//----------------------------------------------------------------------
std::string
sc(int c1,int c2,int op){
  std::stringstream s;
  s << c1 << s_op[op] << c2;
  return s.str();
}
//----------------------------------------------------------------------
std::string
sc(std::string s1,std::string s2,int op){
  std::stringstream s;
  s << "(" << s1 << ")" << s_op[op] << "(" << s2 << ")";
  return s.str();
}
//----------------------------------------------------------------------
std::string
sc(int c1 ,std::string s2,int op){
  std::stringstream s;
  s << c1 << s_op[op] << "(" << s2 << ")";
  return s.str();
}
//----------------------------------------------------------------------
std::string
sc(std::string s1 ,int c2,int op){
  std::stringstream s;
  s << "(" << s1 << ")" << s_op[op] << c2;
  return s.str();
}
//----------------------------------------------------------------------
double
calc(int c1,int c2, int op){
  return calc((double)c1,(double)c2,op);
}
//----------------------------------------------------------------------
double
calc(double c1,int c2, int op){
  return calc((double)c1,(double)c2,op);
}
//----------------------------------------------------------------------
double
calc(int c1,double c2, int op){
  return calc((double)c1,(double)c2,op);
}
//----------------------------------------------------------------------
void
checkten1(int c1, int c2, int c3, int c4,
          int op1, int op2, int op3){
  double r = calc(calc(c1,c2,op1),calc(c3,c4,op2),op3);
  if(10 - eps < r && r < 10+eps){
    std::cout <<  sc(sc(c1,c2,op1),sc(c3,c4,op2),op3) << "=10" << std::endl;
  }
}
//----------------------------------------------------------------------
void
checkten2(int c1, int c2, int c3, int c4,
          int op1, int op2, int op3){
  double r = calc(calc(calc(c1,c2,op1),c3,op2),c4,op3);
  if(10 - eps < r && r < 10+eps){
    std::cout << sc(sc(sc(c1,c2,op1),c3,op2),c4,op3) << "=10" << std::endl;
  }
}
//----------------------------------------------------------------------
void
checkten3(int c1, int c2, int c3, int c4,
          int op1, int op2, int op3){
  double r = calc(c1,calc(c2,calc(c3,c4,op3),op2),op1);
  if(10 - eps < r && r < 10+eps){
    std::cout << sc(c1,sc(c2,sc(c3,c4,op3),op2),op1) << "=10" << std::endl;
  }
}
//----------------------------------------------------------------------
void
checkten4(int c1, int c2, int c3, int c4,
          int op1, int op2, int op3){
  double r = calc(calc(c1,calc(c2,c3,op2),op1),c4,op3);
  if(10 - eps < r && r < 10+eps){
    std::cout << sc(sc(c1,sc(c2,c3,op2),op1),c4,op3) << "=10" << std::endl;
  }
}
//----------------------------------------------------------------------
void
checkten5(int c1, int c2, int c3, int c4,
          int op1, int op2, int op3){
  double r = calc(c1,calc(calc(c2,c3,op2),c4,op3),op1);
  if(10 - eps < r && r < 10+eps){
    std::cout << sc(c1,sc(sc(c2,c3,op2),c4,op3),op1) << "=10" << std::endl;
  }
}
//----------------------------------------------------------------------
void
check(int c1, int c2, int c3, int c4){
  for(int i1=0;i1<4;i1++)
  for(int i2=0;i2<4;i2++)
  for(int i3=0;i3<4;i3++){
    checkten1(c1,c2,c3,c4,i1,i2,i3);
    checkten2(c1,c2,c3,c4,i1,i2,i3);
    checkten3(c1,c2,c3,c4,i1,i2,i3);
    checkten4(c1,c2,c3,c4,i1,i2,i3);
    checkten5(c1,c2,c3,c4,i1,i2,i3);
  }
}
//----------------------------------------------------------------------
void checkall(void){
  for(int c1 = 1;c1 <=9;c1++)
  for(int c2 = 1;c2 <=9;c2++)
  for(int c3 = 1;c3 <=9;c3++)
  for(int c4 = 1;c4 <=9;c4++){
    check(c1,c2,c3,c4);
  }
}
//----------------------------------------------------------------------
int 
main(void){
  checkall();
}
//----------------------------------------------------------------------
