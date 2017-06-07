package server;

public class User {
    private final String name;
    private final int age;

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return "My name is " + this.name + " and I am " + this.age + " years old.";
    }
}
