/*На игровом поле находится робот. Позиция робота на поле описывается двумя целочисленным координатами: X и Y. Ось X смотрит слева направо, ось Y — снизу вверх. (Помните, как рисовали графики функций в школе?)
В начальный момент робот находится в некоторой позиции на поле. Также известно, куда робот смотрит: вверх, вниз, направо или налево. Ваша задача — привести робота в заданную точку игрового поля.
Робот описывается классом Robot. Вы можете пользоваться следующими его методами (реализация вам неизвестна):*/
public static void moveRobot(Robot robot, int toX, int toY) {
    if (robot.getX() == toX){
    } 
    else { 
        if(robot.getX() > toX) { 
            for(;robot.getDirection() != Direction.LEFT;){
            robot.turnLeft();
            }
            for(;robot.getX() != toX;){
            robot.stepForward();
            }
        } 
        else {
                for(;robot.getDirection() != Direction.RIGHT;){
                    robot.turnLeft();
                }
                for(;robot.getX() != toX;){
                    robot.stepForward();
                }
        }
    }
     if (robot.getY() == toY){
    } 
    else { 
        if(robot.getY() > toY) { 
            for(;robot.getDirection() != Direction.DOWN;){
            robot.turnLeft();
            }
            for(;robot.getY() != toY;){
            robot.stepForward();
            }
        } 
        else {
                for(;robot.getDirection() != Direction.UP;){
                    robot.turnLeft();
                }
                for(;robot.getY() != toY;){
                    robot.stepForward();
                }
        }
    }
}
