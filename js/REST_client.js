"use strict";

function Resource(endpoint) {
    this.endpoint = endpoint;

    this.save = function () {
        console.log("PUT: %s", this.endpoint);
    };
    this.delete = function (id) {
        console.log("DELETE: %s/%s", this.endpoint, this.getID());
    };

    this.getID = function () {
        throw new Error();
    };

    Resource.get = function (id, endpoint) {
        if (id === undefined) {
            Resource._getAll(endpoint);
        } else {
            Resource._getOne(id, endpoint);
        }
    };

    Resource._getOne = function (id, endpoint) {
        console.log("GET: %s/%s", endpoint, id);
    };

    Resource._getAll = function (endpoint) {
        console.log("get everything from %s", endpoint);
    };
}

function Car(vin, make) {
    Car.endpoint = "/car";
    Resource.call(this, Car.endpoint);

    this.vin = vin;
    this.make = make;
    this.toString = function () {
        console.log("I am a %s, with VIN: %s", this.make, this.vin);
    };

    this.getID = function () {
        return this.vin;
    };
}
Car.prototype = Object.create(Resource.prototype)
Car.prototype.constructor = Car;

function Customer(ssn) {
    Customer.endpoint = "/customer";
    Resource.call(this, Customer.endpoint);

    this.ssn = ssn;
    this.toString = function () {
        console.log("I am a Customer: %s", this.getID());
    };

    this.getID = function () {
        return this.ssn;
    };
}
Customer.prototype = Object.create(Resource.prototype)
Customer.prototype.constructor = Customer;

function Transaction(id) {
    Transaction.endpoint = "/transaction";
    Resource.call(this, Transaction.endpoint);

    this.id = id;

    this.getID = function () {
        return this.id;
    };

    this.toString = function () {
        console.log("I am a Transaction: %s", this.getID());
    };
}
Transaction.prototype = Object.create(Resource.prototype)
Transaction.prototype.constructor = Transaction;


















var a = new Car("003", "Honda");
a.delete();
var b = Resource.get("005", Car.endpoint);
var u = new Customer("440-03-2389");
u.delete();




var t = new Transaction("0001");
t.save();
