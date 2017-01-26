export class Person {
    private first: string
    private last: string;
    private full: string;
    private age: number;

    constructor(first: string, last: string, age: number) {
        this.full = `${first} ${last}`;
        this.age = age;
    }

    Name(): string {
        return this.full;
    }

    Age(): number {
        this.smile();
        return this.age;
    }

    private smile(): void {
        console.log("I like to smile!");
    }
}

