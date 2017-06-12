/*Реализуйте метод sqrt(), вычисляющий квадратный корень числа. В отличие от Math.sqrt(), это метод при передаче отрицательного параметра должен бросать исключение java.lang.IllegalArgumentException с сообщением "Expected non-negative number, got ?", где вместо вопросика будет подставлено фактически переданное в метод число.*/
public static double sqrt(double x) {
    if (x<0){
        throw new java.lang.IllegalArgumentException("Expected non-negative number, got "+x);
    }
    else    
    return Math.sqrt(x); // your implementation here
}
/*Реализуйте метод, позволяющий другим методам узнать, откуда их вызвали.
Метод getCallerClassAndMethodName() должен возвращать имя класса и метода, откуда вызван метод, вызвавший данный утилитный метод. Или null (нулевую ссылку, а не строку "null"), если метод, вызвавший getCallerClassAndMethodName() является точкой входа в программу, т.е. его никто не вызывал.
Это актуально, например, в библиотеках логирования, где для каждого сообщения в логе надо выводить класс и метод, откуда сообщение было залогировано.*/
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
/*Ваша задача — реализовать метод который устанавливает соединение с роботом, отдает ему команду на перемещение в заданную точку и затем закрывает соединение, выполняя при необходимости повтор этой последовательности до трех раз.*/
public static void moveRobot(RobotConnectionManager robotConnectionManager, int toX, int toY)
    {
        RobotConnection robot = null;
        for(int i = 0; i < 3; i++)
        {
            try
            {
                robot = robotConnectionManager.getConnection();
                robot.moveRobotTo(toX, toY);
                return;
            }
            catch(RobotConnectionException er)
            {
                if ( i == 2)
                {
                    throw er;//new RobotConnectionException("error");
                }
                else
                {
                    continue;
                }
            } catch(RuntimeException e){
                throw e;
            }
            finally
            {
                if(robot != null)
                {
                    try
                    {
                    robot.close();
                    }
                    catch (RuntimeException e){
                        
                    }
                }
            }
        }
    }

