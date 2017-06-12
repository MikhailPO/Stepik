/*Реализуйте метод, вычисляющий симметрическую разность двух множеств.
Метод должен возвращать результат в виде нового множества. Изменять переданные в него множества не допускается.*/
  public static <T> Set<T> symmetricDifference(Set<? extends T> set1, Set<? extends T> set2) {
        Set<T> Set1= new HashSet<>(set1);
        Set<T> Set2= new HashSet<>(set2);
        Iterator<?> it1=Set1.iterator();
        Iterator<?> it2=Set2.iterator();
        Set<T> FinalSet= new HashSet<>();
        T one=null;
        T to;
        for(T element:Set1){
            FinalSet.add(element);
        }
        for(T element:Set2){
            FinalSet.add(element);
        }
        for(T element:Set1){
            for(T element2:Set2){
               if(element.equals(element2)){
                   FinalSet.remove(element);

                   break;
               }

            }
        }



        return FinalSet;
    }

/*Напишите программу, которая прочитает из System.in последовательность целых чисел, разделенных пробелами, затем удалит из них все числа, стоящие на четных позициях, и затем выведет получившуюся последовательность в обратном порядке в System.out.
Все числа влезают в int. Позиции чисел в последовательности нумеруются с нуля.
В этом задании надо написать программу целиком, включая import'ы, декларацию класса Main и метода main.*/
import java.io.*;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.*;


public class Main {


    public static void main(String[] args) throws IOException {
        List<String> set1 = new ArrayList<>();
        List<String> set2 = new ArrayList<>();
        String string;
        Integer f;
        int j;
        double flag = 0, i = -1;
        flag = Math.pow(-1, 2);
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            i++;
            string = scan.next();
            set2.add(string);
            flag = Math.pow(-1, i);
            if (flag == -1) {
                set1.add(string);
            }
        }

        Collections.reverse(set1);
        for(String element:set1) {
            System.out.print(element+" ");
        }
    }
}
