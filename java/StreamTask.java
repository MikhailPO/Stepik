/*Напишите метод, читающий входной поток и вычисляющий контрольную сумму прочитанных данных.
Контрольная сумма данных вычисляется по следующему алгоритму:
1. Контрольная сумма представляет собой число типа int. Контрольная сумма пустого набора данных равна нулю.
2. Контрольная сумма непустого набора данных вычисляется по следующей рекуррентной формуле: Cn+1=rotateLeft(Cn) xor bn+1 , где Cn — контрольная сумма первых n байт данных, rotateLeft — циклический сдвиг бит числа на один бит влево (чтобы не изобретать велосипед, используйте Integer.rotateLeft), bn — n-ный байт данных.
Поскольку метод не открывал данный InputStream, то и закрывать его он не должен. Выброшенное из методов InputStream исключение должно выбрасываться из метода.*/
public static int checkSumOfStream(InputStream inputStream) throws IOException {
  int cn,b;
    byte bt=0;
    cn=0;
     InputStream is= inputStream;
    for (;;){
        b=is.read();
                        if(b<0)
                            return cn;
                        else{ bt=(byte) b;
                            cn=Integer.rotateLeft(cn,1)^b;}
    }
   
   
      
    // your implementation here
}

/*По историческим причинам на разных платформах принят разный способ обозначения конца строки в текстовом файле. На Unix-системах конец строки обозначается символом с кодом 10 ('\n'), на Windows — двумя последовательными символами с кодами 13 и 10 ('\r' '\n').
Напишите программу, которая будет преобразовывать переводы строк из формата Windows в формат Unix. Данные в формате Windows подаются программе в System.in, преобразованные данные должны выводиться в System.out. На этот раз вам надо написать программу полностью, т.е. объявить класс (с именем Main — таково ограничение проверяющей системы), метод main, прописать все import'ы.
Требуется заменить все вхождения пары символов '\r' и '\n' на один символ '\n'. Если на входе встречается одиночный символ '\r', за которым не следует '\n', то символ '\r' выводится без изменения.
Кодировка входных данных такова, что символ '\n' представляется байтом 10, а символ '\r' — байтом 13. Поэтому программа может осуществлять фильтрацию на уровне двоичных данных, не преобразуя байты в символы.
Из-за буферизации данных в System.out в конце вашей программы надо явно вызвать System.out.flush(). Иначе часть выведенных вами данных не будет видна проверяющей системе.
*/


import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        int Stream=1,next=1,next2=1;
        while(Stream >= 0) {
            Stream = System.in.read();
            if(Stream<0){
                break;
            }

            next = System.in.read();

            if (next < 0) {
                System.out.write(Stream);
                break;
            }
            else if(next == 13){
                next2=System.in.read();
                if(next2==10){
                    System.out.write(Stream);
                    System.out.write(next2);
                    continue;
                }
                else{if (next2 < 0) {
                    System.out.write(Stream);
                    System.out.write(next);
                    break;
                }else{}
                    System.out.write(Stream);
                    System.out.write(next);
                    System.out.write(next2);
                    continue;
                }
            }
            else if (Stream == 13) {
                if (next == 10) {
                    System.out.write(next);
                } else {
                    System.out.write(Stream);
                    System.out.write(next);
                }
            } else {
                System.out.write(Stream);
                System.out.write(next);

            }
            
        }
        System.out.flush();
    }

}

/*Реализуйте метод, который зачитает данные из InputStream и преобразует их в строку, используя заданную кодировку.*/
public static String readAsString(InputStream inputStream, Charset charset) throws IOException {
     String string,Sum="";
    int i=0;
    char code;
        Reader in= new InputStreamReader(inputStream,charset);
    while((i=in.read())!=-1){
    code = (char)i;
        Sum+=code;         
    }
    return Sum;
        
}
/*Напишите программу, читающую текст из System.in и выводящую в System.out сумму всех встреченных в тексте вещественных чисел с точностью до шестого знака после запятой. Числом считается последовательность символов, отделенная от окружающего текста пробелами или переводами строк и успешно разбираемая методом Double.parseDouble.
На этот раз вам надо написать программу полностью, т.е. объявить класс (с именем Main — таково ограничение проверяющей системы), метод main, прописать все import'ы.
*/
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        double sum=0;
        try (Scanner scan = new Scanner(System.in)){
            while(scan.hasNext()){
                if(scan.hasNextDouble()){
                sum+=Double.parseDouble(scan.next());
                } else {
                    scan.next();
                }
            }
            System.out.printf("%.6f", sum);
        } catch(Exception e){
        System.out.printf("%.6f", 0);
                }
        }
}
/*Дан сериализуемый класс Animal:
class Animal implements Serializable {
    private final String name;
    public Animal(String name) {
        this.name = name;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Animal) {
            return Objects.equals(name, ((Animal) obj).name);
        }
        return false;
    }
}
Реализуйте метод, который из переданного массива байт восстановит массив объектов Animal. Массив байт устроен следующим образом. Сначала идет число типа int, записанное при помощи ObjectOutputStream.writeInt(size). Далее подряд записано указанное количество объектов типа Animal, сериализованных при помощи ObjectOutputStream.writeObject(animal).
Если вдруг массив байт не является корректным представлением массива экземпляров Animal, то метод должен бросить исключение java.lang.IllegalArgumentException.
Причины некорректности могут быть разные. Попробуйте подать на вход методу разные некорректные данные и посмотрите, какие исключения будут возникать. Вот их-то и нужно превратить в IllegalArgumentException и выбросить. Если что-то забудете, то проверяющая система подскажет. Главное не глотать никаких исключений, т.е. не оставлять нигде пустой catch.
*/
public static Animal[] deserializeAnimalArray(byte[] data) {
    try{ ByteArrayInputStream bS = new ByteArrayInputStream(data);
        ObjectInputStream ois= new ObjectInputStream( bS);
            int size =  ois.readInt();
        Animal[] anim = new Animal[size];
        for(int i=0;i<size;i++){
            anim[i] = (Animal) ois.readObject();
        }
        return anim;
    }
    catch (Exception e){
         throw new IllegalArgumentException(e);
    }// your implementation here
}

