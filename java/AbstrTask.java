/*Реализуйте метод, выполняющий численное интегрирование заданной функции на заданном интервале по формуле левых прямоугольников.
Функция задана объектом, реализующим интерфейс java.util.function.DoubleUnaryOperator. Его метод applyAsDouble() принимает значение аргумента и возвращает значение функции в заданной точке.
Интервал интегрирования задается его конечными точками a и b, причем a<=b. Для получения достаточно точного результата используйте шаг сетки не больше 10−6.*/
public static double integrate(DoubleUnaryOperator f, double a, double b) {
double Sum=0;
    for(double i=a;i<b;i=i+0.000001){
    Sum=Sum+f.applyAsDouble(i)*0.000001;
    }    
    return Sum;
}
/*Напишите класс AsciiCharSequence, реализующий компактное хранение последовательности ASCII-символов (их коды влезают в один байт) в массиве байт. По сравнению с классом String, хранящим каждый символ как char, AsciiCharSequence будет занимать в два раза меньше памяти.
Класс AsciiCharSequence должен:
реализовывать интерфейс java.lang.CharSequence;
иметь конструктор, принимающий массив байт;
определять методы length(), charAt(), subSequence() и toString()
Сигнатуры методов и ожидания по их поведению смотрите в описании интерфейса java.lang.CharSequence (JavaDoc или исходники).
В данном задании методам charAt() и subSequence() всегда будут подаваться корректные входные параметры, поэтому их проверкой и обработкой ошибок заниматься не нужно. Тем более мы еще не проходили исключения.
*/
public class AsciiCharSequence implements CharSequence
{
    byte[] str;

    public AsciiCharSequence(byte[] b) 
    {
        this.str = b;
    }

    public int length() {
        return str.length;
    }

    public char charAt(int index) 
    {
        return (char)(str[index] & 0xff);
    }

    public CharSequence subSequence(int start, int end) 
    {
        int length = end - start;
        byte[] bytes = new byte[length];
        for (int i = 0, j = start; i < length; i++, j++) {
            bytes[i] = str[j];
        }
        return new AsciiCharSequence(bytes);
    }

    public String toString() {
        return new String(str);
    }
}
/*вам необходимо реализовать три класса, которые реализуют данный интерфейс: SpamAnalyzer, NegativeTextAnalyzer и TooLongTextAnalyzer.
1. SpamAnalyzer должен конструироваться от массива строк с ключевыми словами. Объект этого класса должен сохранять в своем состоянии этот массив строк в приватном поле keywords.
2. NegativeTextAnalyzer должен конструироваться конструктором по-умолчанию.
3. TooLongTextAnalyzer должен конструироваться от int'а с максимальной допустимой длиной комментария. Объект этого класса должен сохранять в своем состоянии это число в приватном поле maxLength.
*/
public abstract class KeywordAnalyzer implements TextAnalyzer
    {
        protected abstract String[] getKeywords();
        protected abstract Label getLabel();

        public Label processText(String text)
        {
            String[] str = getKeywords();
            int i = 0;

            for (i = 0; i < str.length; i++) {
                if (text.indexOf(str[i]) != -1)
                    return getLabel();
            }
            return Label.OK;
        }
    }

    public class SpamAnalyzer extends KeywordAnalyzer
    {
        private String[] keywords;

        SpamAnalyzer(String[] _key)
        {
            this.keywords = _key;
        }

        protected String[] getKeywords()
        {
            return this.keywords;
        }
        protected Label getLabel()
        {
            return Label.SPAM;
        }
    }

    public class NegativeTextAnalyzer extends KeywordAnalyzer
    {
        private String[] keywords;

        NegativeTextAnalyzer()
        {
            this.keywords = new String[3];
            this.keywords[0] = ":(";
            this.keywords[1] = "=(";
            this.keywords[2] = ":|";
        }

        protected String[] getKeywords()
        {
            return this.keywords;
        }

        protected Label getLabel()
        {
            return Label.NEGATIVE_TEXT;
        }
    }

    public class TooLongTextAnalyzer implements TextAnalyzer
    {
        private int maxLength;

        public TooLongTextAnalyzer(int maxLength)
        {
            this.maxLength = maxLength;
        }

        public Label processText(String text)
        {
            if (text.length() > maxLength)
                return Label.TOO_LONG;
            else
                return Label.OK;
        }
    }

 public Label checkLabels(TextAnalyzer[] analyzers, String text) {
        
        for (int i = 0; i < analyzers.length; i++)
        {
            Label res = analyzers[i].processText(text);
            if (res != Label.OK)
                return res; 
        }
        return Label.OK;
    }

	
	
	public static String getCallerClassAndMethodName() {
   StackTraceElement[] stackTraceElements = Thread.currentThread().getStackTrace();
        String message = "";
        if(stackTraceElements.length >= 4) {
            StackTraceElement element = stackTraceElements[3];
            String className = element.getClassName();
            String methodName = element.getMethodName();
            if (methodName == "invoke0")
                return null;
            message = className + "#" + methodName;
        }
        else
            return null;
        return message;
}
