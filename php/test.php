<?php

interface Drivable {
    public function steer($deg);
}

class Person {
    private $first;
    private $last;


    public function __construct($first, $last) {
        $this->first = $first;
        $this->last = $last;
    }

    public function __toString() {
        return "hello my name is " . $this->first . " " . $this->last . "\n";
    }
}

class Vehicle {
    private $isStarted = false;
    private $make;
    private $year;
    private $model;
            

    public function __construct($year, $make, $model) {
        $this->make = $make;
        $this->year = $year;
        $this->model = $model;
    }

    public function start() {
        if ($this->isStarted == true) {
            $this->_displayWarning();
        } else {
            $this->isStarted = true;
        }
    }

    public function turnOff() {
        if ($this->isStarted == false) {
            $this->_displayWarning();
        } else {
            $this->isStarted = false;
        }
    }

    private function _displayWarning() {
        if ($this->isStarted == true) {
            echo "The " . $this->model . " is already running.\n";
        } else {
            echo "The " . $this->model . " is already off.\n";
        }
    }

    public function __toString() {
        return $this->year . " " .
               $this->make . " " .
               $this->model . "\n";
    }
}

class Car extends Vehicle implements Drivable {
    private $isStarted = false;

    public function steer($deg) {
        if ($this->isStarted == false) {
            echo "only if the car was started, this would be so much easier to steer!\n";
        }

        if ($deg > 0) {
            echo "steering right\n";
        } else {
            echo "steering left\n";
        }

        printf("steering left %d degrees!\n", $deg);
    }
}

$person = new Person("rafael", "cepeda");
echo $person;

$car = new Car(1994, "Acura", "Integra");
$car->start();
$car->steer(-12);
$car->turnOff();
$car->turnOff();

echo $car;
