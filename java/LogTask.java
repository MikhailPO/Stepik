/*Требуется выставить такие настройки, чтобы:
1. Логгер с именем "org.stepic.java.logging.ClassA" принимал сообщения всех уровней.
2. Логгер с именем "org.stepic.java.logging.ClassB" принимал только сообщения уровня WARNING и серьезнее.
3. Все сообщения, пришедшие от нижестоящих логгеров на уровень "org.stepic.java", независимо от серьезности сообщения печатались в консоль в формате XML (*) и не передавались вышестоящим обработчикам на уровнях "org.stepic", "org" и "".*/
private static void configureLogging() {
    Logger LOGGER1 = Logger.getLogger("org.stepic.java.logging.ClassA"); 
    LOGGER1.setLevel(Level.ALL);
    Logger LOGGER2 = Logger.getLogger("org.stepic.java.logging.ClassB"); 
    LOGGER2.setLevel(Level.WARNING);
    Logger LOGGER3 = Logger.getLogger("org.stepic.java");
    LOGGER3.setLevel(Level.ALL); 
ConsoleHandler Hd=new ConsoleHandler();
    Hd.setFormatter(new XMLFormatter());
    Hd.setLevel(Level.ALL);
    LOGGER3.addHandler(Hd);
    LOGGER3.setUseParentHandlers(false);
 
    
    // your implementation here
}

/*Вам необходимо описать набор классов, каждый из которых является MailService:
1) UntrustworthyMailWorker – класс, моделирующий ненадежного работника почты, который вместо того, чтобы передать почтовый объект непосредственно в сервис почты, последовательно передает этот объект набору третьих лиц, а затем, в конце концов, передает получившийся объект непосредственно экземпляру RealMailService. У UntrustworthyMailWorker должен быть конструктор от массива MailService ( результат вызова processMail первого элемента массива передается на вход processMail второго элемента, и т. д.) и метод getRealMailService, который возвращает ссылку на внутренний экземпляр RealMailService.
2) Spy – шпион, который логгирует о всей почтовой переписке, которая проходит через его руки. Объект конструируется от экземпляра Logger, с помощью которого шпион будет сообщать о всех действиях. Он следит только за объектами класса MailMessage и пишет в логгер следующие сообщения (в выражениях нужно заменить части в фигурных скобках на значения полей почты):
2.1) Если в качестве отправителя или получателя указан "Austin Powers", то нужно написать в лог сообщение с уровнем WARN: Detected target mail correspondence: from {from} to {to} "{message}"
2.2) Иначе, необходимо написать в лог сообщение с уровнем INFO: Usual correspondence: from {from} to {to}
3) Thief – вор, который ворует самые ценные посылки и игнорирует все остальное. Вор принимает в конструкторе переменную int – минимальную стоимость посылки, которую он будет воровать. Также, в данном классе должен присутствовать метод getStolenValue, который возвращает суммарную стоимость всех посылок, которые он своровал. Воровство происходит следующим образом: вместо посылки, которая пришла вору, он отдает новую, такую же, только с нулевой ценностью и содержимым посылки "stones instead of {content}".
4) Inspector – Инспектор, который следит за запрещенными и украденными посылками и бьет тревогу в виде исключения, если была обнаружена подобная посылка. Если он заметил запрещенную посылку с одним из запрещенных содержимым ("weapons" и "banned substance"), то он бросает IllegalPackageException. Если он находит посылку, состоящую из камней (содержит слово "stones"), то тревога прозвучит в виде StolenPackageException. Оба исключения вы должны объявить самостоятельно в виде непроверяемых исключений.
Все классы должны быть определены как публичные и статические, так как в процессе проверки ваш код будет подставлен во внешний класс, который занимается тестированием и проверкой структуры. Для удобства во внешнем классе объявлено несколько удобных констант и импортировано все содержимое пакета java.util.logging. Для определения, посылкой или письмом является Sendable объект воспользуйтесь оператором instanceof.*/
 public static class UntrustworthyMailWorker implements MailService {

        private RealMailService realmail = new RealMailService();
        private MailService[] some;

        public UntrustworthyMailWorker()
        {
        }

        public UntrustworthyMailWorker(MailService[] people1)
        {
            this.some = people1;
        }

        public RealMailService getRealMailService()
        {
            return this.realmail;
        }
        @Override
        public Sendable processMail(Sendable mail) {

            Sendable buff = null;
            for (int i = 0; i < this.some.length; i++) {

                if (i == 0) {
                    buff = this.some[0].processMail(mail);
                    continue;
                }

                buff = this.some[i].processMail(buff);
            }
            return getRealMailService().processMail(buff);
        }
    }

    public static class Spy implements MailService {

        private Logger logger;

        public Spy()
        {
            this.logger = null;
        }

        public Spy(Logger log)
        {
            this.logger = log;
        }


        @Override
        public Sendable processMail(Sendable mail) {

            if (mail instanceof MailMessage) {
                if (mail.getFrom().contains(AUSTIN_POWERS) || mail.getTo().contains(AUSTIN_POWERS)) {
                    logger.log(Level.WARNING, "Detected target mail correspondence: from {0} to {1} \"{2}\"", new Object[] {mail.getFrom(), mail.getTo(), ((MailMessage) mail).getMessage()});
                } else {
                    logger.log(Level.INFO, "Usual correspondence: from {0} to {1}", new Object[] {mail.getFrom(), mail.getTo()});
                }
            }
            return mail;
        }
    }


    public static class IllegalPackageException extends RuntimeException
    {
        public IllegalPackageException()
        {

        }
    }

    public static class StolenPackageException extends RuntimeException
    {
        public StolenPackageException()
        {

        }
    }


    public static class Thief implements MailService {

        public int value = 0;
        public int overall = 0;
        public MailPackage mailPackage;

        public Thief(int value) {
            this.value = value;
        }

        @Override
        public Sendable processMail(Sendable mail) {

            if (mail instanceof MailPackage) {
                if (((MailPackage) mail).getContent().getPrice() >= value) {
                    overall += ((MailPackage) mail).getContent().getPrice();
                    MailPackage mailPackage = new MailPackage(mail.getFrom(), mail.getTo(), new Package("stones instead of " + (((MailPackage) mail).getContent().getContent()).toString(), 0));
                    return mailPackage;
                }
                else {return (MailPackage)mail;}
            }
            return mail;
        }

        public int getStolenValue() {
            return overall;
        }
    }

    
    public static class Inspector implements MailService {

        public Inspector()
        {
            
        }
        @Override
        public Sendable processMail(Sendable mail) //throws IllegalPackageException,StolenPackageException
        {
            // Здесь описан код настоящей системы отправки почты.

            if (mail instanceof MailPackage)
            {
                String cont = ((MailPackage) mail).getContent().getContent();
                
                if (cont.contains(WEAPONS)) {
                    throw new IllegalPackageException();
                }
                if (cont.contains(BANNED_SUBSTANCE)) {
                    throw new IllegalPackageException();
                }
                if (cont.matches(".*stones.*")){
                    throw new StolenPackageException();
                }
            }
            return mail;
        }
    }


