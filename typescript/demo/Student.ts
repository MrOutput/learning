import { Person } from "./Person";

export class Student {
    private p: Person;
    private id: string;

    constructor(p: Person, id: string) {
        this.p = p;
        this.id = id;
    }

    toString(): string {
        return `NAME:\t${this.p.Name().toUpperCase()}\nID:\t${this.id}\nAGE:\t${this.p.Age()}`
    }
}

