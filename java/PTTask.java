/*Реализуйте метод, возвращающий true, если среди четырех его аргументов ровно два истинны (любые). Во всех остальных случаях метод должен возвращать false.*/
public static boolean booleanExpression(boolean a, boolean b, boolean c, boolean d) {
    return !(a^b^d^c)&!((a == d)&(c == d));
}

/*Реализуйте метод, вычисляющий количество високосных лет с начала нашей эры (первого года) до заданного года включительно. На самом деле Григорианский календарь был введен значительно позже, но здесь для упрощения мы распространяем его действие на всю нашу эру.*/
public static int leapYearCount(int year) {
    return (year/4)-(year/100)+(year/400);
}

/*Реализуйте метод, возвращающий ответ на вопрос: правда ли, что a + b = c?
Допустимая погрешность – 0.0001 (1E-4)*/
public static boolean doubleExpression(double a, double b, double c) {
    return (Math.abs((a + b)-c)<= 1e-4);
}

/*Реализуйте метод flipBit, изменяющий значение одного бита заданного целого числа на противоположное. Данная задача актуальна, например, при работе с битовыми полями.*/
public static int flipBit(int value, int bitIndex) {
    return value^(1<< (bitIndex-1)); // put your implementation here
}

