/*Реализуйте метод, вычисляющий факториал заданного натурального числа.*/
public static BigInteger factorial(int value) {
        BigInteger a = new BigInteger("1");
        BigInteger int2;
        for(int i=1;i<= value;i++){
            int2=BigInteger.valueOf(i);
            a = a.multiply(int2);
        }
        return a; // your implementation here
    }
/*Реализуйте метод, сливающий два отсортированных по неубыванию массива чисел в один отсортированный в том же порядке массив. Массивы могут быть любой длины, в том числе нулевой.
*/
public static int[] mergeArrays(int[] a1, int[] a2) {
        int lA1=a1.length;
        int lA2=a2.length;
        int lSum = lA1+lA2;
        int[] aa =new int [lSum];
        if(lA1>lA2){ int max=lA1;
            int min=lA2;
        }
        else{int max=lA2;
            int min=lA1;
        }
        int j=0;
        int jj=0;
        for(int i=0;(i<lSum);i++){
            if(a1[jj]<=a2[j]){
                aa[i]=a1[jj];
                jj++;
            }else{
                aa[i]=a2[j];
                j++;
            }
            if(jj>lA1-1){jj=lA1-1;
                for(int jjj=i+1;jjj<lSum;jjj++){
                    aa[jjj]=a2[j];
                    j++;
                } break;

            }
            if(j>lA2-1){j=lA2-1;
                for(int jjj=i+1;jjj<lSum;jjj++){
                    aa[jjj]=a1[jj];
                    jj++;
                } break;
            }

        }
        return aa; 
    }
/*Вам дан список ролей и сценарий пьесы в виде массива строчек. 
Каждая строчка сценария пьесы дана в следующем виде: 
Роль: текст
Текст может содержать любые символы.
Напишите метод, который будет группировать строчки по ролям, пронумеровывать их и возвращать результат в виде готового текста (см. пример). Каждая группа распечатывается в следующем виде:
Роль:
i) текст
j) текст2
...
==перевод строки==
*/

private String printTextPerRole(String[] roles, String[] textLines) {
     StringBuilder res2 = new StringBuilder();
        int i = 0, k = 0, j = 0;

        StringBuilder[] role = new StringBuilder[roles.length];
        StringBuilder[] text = new StringBuilder[textLines.length];

        for (i =0;i<text.length;i++){text[i] = new StringBuilder();}
        for (i =0;i<role.length;i++){role[i] = new StringBuilder();}


        for (i = 0, j = 0; i < roles.length; i++, j++)
            {
                //res[j] = roles[i];
                res2.append(roles[i] + ":\n");
                String repl = roles[i] + ":";
                for(k = 1; k <= textLines.length; k++)
                {
                    if (textLines[k-1].startsWith(repl)) {
                        //repl = roles[i] + ":";
                        j++;
                        //res[j] = k + ")" + textLines[k-1].toString().replace(repl, "");
                        if (!textLines[k-1].contains(repl))
                            repl = roles[i];
                        res2.append(k + ")" + textLines[k-1].toString().replaceFirst(repl, "")+ "\n");

                    }
                }
                res2.append("\n");
            }
        return res2.toString();
}


