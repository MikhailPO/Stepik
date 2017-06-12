/*Реализуйте метод, который возвращает букву, стоящую в таблице UNICODE после символа "\" (обратный слэш) на расстоянии a.*/
public static char charExpression(int a) {
   int b=0x5c;
    b= (b+a);
    char y=(char)b;
   
    return y;
}
 
/*Реализуйте метод, проверяющий, является ли заданное число по абсолютной величине степенью двойки.*/
public static boolean isPowerOfTwo(int value) {
    int v=Math.abs(value);
    if(value==0)
         return false;
    else
    {
   int a= (int)(Math.log(v)/Math.log(2));
    if(v==Math.pow(2,a))
    return true; // you implementation here
else
{
     return false;
}
}
}

/*Реализуйте метод, проверяющий, является ли заданная строка палиндромом. Палиндромом называется строка, которая читается одинаково слева направо и справа налево (в том числе пустая). При определении "палиндромности" строки должны учитываться только буквы и цифры. А пробелы, знаки препинания, а также регистр символов должны игнорироваться. Гарантируется, что в метод попадают только строки, состоящие из символов ASCII (цифры, латинские буквы, знаки препинания). Т.е. русских, китайских и прочих экзотических символов в строке не будет.*/
public static boolean isPalindrome(String text) {
        String str= text.replaceAll("[^A-Za-z1-9]+", "");
        StringBuilder str1 = new StringBuilder(str);
        StringBuilder str2= str1.reverse();
        String a = new String (str2);
        return a.equalsIgnoreCase(str);
    }

