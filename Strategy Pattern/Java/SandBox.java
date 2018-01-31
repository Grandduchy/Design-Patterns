
package sandBox;

public class SandBox {
	
	public static void main(String[] args) {
		Duck mallard = new MallardDuck();
		mallard.performFly();
		mallard.performQuack();
		
		Duck model = new ModelDuck();
		model.performFly();
		model.setFlyBehavior(new FlyRocketPowered());
		model.performFly();
	}

}

abstract class Duck {
	QuackBehavior quack;
	FlyBehavior fly;
	public Duck() {
	}
	public abstract void display();
	
	public void performFly() {
		fly.fly();
	}
	public void performQuack() {
		quack.quack();
	}
	public void swim() {
		System.out.println("All ducks swim, even decoys!");
	}
	public void setFlyBehavior(FlyBehavior other) {
		fly = other;
	}
	public void setQuackBehavior(QuackBehavior other) {
		quack = other;
	}
}

class MallardDuck extends Duck {
	public MallardDuck() {
		quack = new Quack();
		fly = new FlyWithWings();
	}
	@Override
	public void display() {
		System.out.println("I'm a real Mallard Duck");
	}
}

class ModelDuck extends Duck {
	public ModelDuck() {
		fly = new FlyNoWay();
		quack = new Quack();
	}
	@Override
	public void display() {
		System.out.println("I am a model duck!");
	}
}






interface QuackBehavior {
	public void quack();
}

class Quack implements QuackBehavior {
	public void quack() {
		System.out.println("Quack");
	}
}

class MuteQuack implements QuackBehavior {
	public void quack() {
		System.out.println("<<< Silence >>>");
	}
}


class Squeak implements QuackBehavior {
	public void quack() {
		System.out.println("Squeak");
	}
}





interface FlyBehavior {
	public void fly();
}

class FlyWithWings implements FlyBehavior {
	public void fly() {
		System.out.println("I'm flying!!");
	}
}

class FlyNoWay implements FlyBehavior {
	public void fly() {
		System.out.println("I can’t fly");
	}
}

class FlyRocketPowered implements FlyBehavior {
	public void fly() {
		System.out.println("I’m flying with a rocket!");
	}
}
