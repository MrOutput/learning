package hello;

import org.joda.time.LocalTime;

public class HelloWorld {
    public static void main(String[] args) {
        LocalTime curtime = new LocalTime();
        System.out.println("The current time is: " + curtime);

        Greeter g = new Greeter();
        System.out.println(g.sayHello());
    }
}
