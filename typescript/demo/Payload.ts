export class Payload {
    private id: number;

    constructor(id: number) {
        this.id = id;
    }

    toString(): string {
        return this.id.toString();
    }
}
