/*Дан класс ComplexNumber. Переопределите в нем методы equals() и hashCode() так, чтобы equals() сравнивал экземпляры ComplexNumber по содержимому полей re и im, а hashCode() был бы согласованным с реализацией equals().
Реализация hashCode(), возвращающая константу или не учитывающая дробную часть re и im, засчитана не будет
*/
public final class ComplexNumber {
    private final double re;
    private final double im;

    public ComplexNumber(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public double getRe() {
        return re;
    }

    public double getIm() {
        return im;
    }
   @Override
    public boolean equals(Object obj) {
        if( obj instanceof ComplexNumber){
        if(this.getRe() == ((ComplexNumber)obj).getRe()){
            return ( this.getIm() == ((ComplexNumber)obj).getIm());
        }
        else{
            return false;
        }
        }
        return this==obj;
    }
 @Override
public int hashCode() { 
       int result;
           int Re;
           int Im;
           double dRe;
           double dIm;
           dRe = this.getRe();
           dIm = this.getIm();
           Re = (int)this.getRe();
           Im = (int)this.getIm();
           dRe=(dRe-Re)*1000000;
           dIm=(dIm-Im)*1000000;
           Re=Re+(int)dRe;
           Im=Im+(int)dIm;
           result = (Re+Im);
           return result;
}}


