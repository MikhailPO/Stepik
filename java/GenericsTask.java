/*Реализуйте generic-класс Pair, похожий на Optional, но содержащий пару элементов разных типов и не запрещающий элементам принимать значение null.
Реализуйте методы getFirst(), getSecond(), equals() и hashCode(), а также статический фабричный метод of(). Конструктор должен быть закрытым (private).
С корректно реализованным классом Pair должен компилироваться и успешно работать следующий код:
Pair<Integer, String> pair = Pair.of(1, "hello");
Integer i = pair.getFirst(); // 1
String s = pair.getSecond(); // "hello"
Pair<Integer, String> pair2 = Pair.of(1, "hello");
boolean mustBeTrue = pair.equals(pair2); // true!
boolean mustAlsoBeTrue = pair.hashCode() == pair2.hashCode(); // true!

Пожалуйста, не меняйте модификатор доступа класса Pair. Для корректной проверки класс должен иметь пакетную видимость.
*/
class Pair <X,T>{
    X First;
    T Second;
    private Pair (X First,T Second){
    this.First= First;
         this.Second= Second;
    }
    static Pair of(Object one, Object to){
    Pair p= new Pair(one,to);
        return p;
    }
    public X getFirst(){
    return this.First;
    }
    
    public T getSecond(){
    return this.Second;
    }
   @Override
    public boolean equals(Object obj) {
        if(obj==null)
            return false;
        else
        if (obj instanceof Pair){
            if((this.Second==null)||(((Pair)obj).getSecond()==null)||(((this.First==null)||(((Pair)obj).getFirst()==null)))){
                if((this.Second==null)&&(((Pair)obj).getSecond()==null)&&(((this.First==null)&&(((Pair)obj).getFirst()==null)))){
                    return true;
                }else if((this.Second==null)&&(((Pair)obj).getSecond()==null)&&(this.First!=null)&&(((Pair)obj).getFirst()!=null)){
                    return this.First.equals(((Pair)obj).getFirst());
                }else if((this.First==null)&&(((Pair)obj).getFirst()==null)&&(this.Second!=null)&&(((Pair)obj).getSecond()!=null)){
                    return this.Second.equals(((Pair)obj).getSecond());
                }else return false;
            } if(this.Second.equals(((Pair)obj).getSecond())&&(this.First.equals(((Pair)obj).getFirst()))){return true;}
            else return false;
        }
else return this.equals(obj);

    }
     @Override
    public int hashCode() {
    int  i,y;
        if((this.First==null)||(this.Second==null))
        {return 0;}
        i= this.First.hashCode();
        y=this.Second.hashCode();
        
        return i+y ;
         
    }

}
