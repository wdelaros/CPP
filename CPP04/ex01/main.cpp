#include "Cat.hpp"
#include "Dog.hpp"

# define NBANIMAL 50

int main(void){
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	{
		const Animal *meta[NBANIMAL];

		for (int i = 0; i < NBANIMAL / 2; i++) {
			meta[i] = new Cat();
		}
		for (int i = NBANIMAL / 2; i < NBANIMAL; i++) {
			meta[i] = new Dog();
		}

		for (int i = 0; i < NBANIMAL; i++) {
			std::cout << i + 1 << ":	" << meta[i]->getType() << std::endl;
		}

		for (int i = 0; i < NBANIMAL; i++) {
			delete meta[i];
		}
	}
	{
		Cat *cat = new Cat();
		Cat *ca = new Cat(*cat);

		cat->createIdea("1");
		cat->createIdea("2");
		cat->createIdea("3");
		cat->createIdea("4");
		cat->createIdea("5");
		cat->createIdea("6");
		cat->createIdea("7");
		cat->createIdea("8");
		cat->createIdea("9");
		cat->createIdea("10");
		cat->createIdea("11");
		cat->createIdea("12");
		cat->createIdea("13");
		cat->createIdea("14");
		cat->createIdea("15");
		cat->createIdea("16");
		cat->createIdea("17");
		cat->createIdea("18");
		cat->createIdea("19");
		cat->createIdea("20");
		cat->createIdea("21");
		cat->createIdea("22");
		cat->createIdea("23");
		cat->createIdea("24");
		cat->createIdea("25");
		cat->createIdea("26");
		cat->createIdea("27");
		cat->createIdea("28");
		cat->createIdea("29");
		cat->createIdea("30");
		cat->createIdea("31");
		cat->createIdea("32");
		cat->createIdea("33");
		cat->createIdea("34");
		cat->createIdea("35");
		cat->createIdea("36");
		cat->createIdea("37");
		cat->createIdea("38");
		cat->createIdea("39");
		cat->createIdea("40");
		cat->createIdea("41");
		cat->createIdea("42");
		cat->createIdea("43");
		cat->createIdea("44");
		cat->createIdea("45");
		cat->createIdea("46");
		cat->createIdea("47");
		cat->createIdea("48");
		cat->createIdea("49");
		cat->createIdea("50");
		cat->createIdea("51");
		cat->createIdea("52");
		cat->createIdea("53");
		cat->createIdea("54");
		cat->createIdea("55");
		cat->createIdea("56");
		cat->createIdea("57");
		cat->createIdea("58");
		cat->createIdea("59");
		cat->createIdea("60");
		cat->createIdea("61");
		cat->createIdea("62");
		cat->createIdea("63");
		cat->createIdea("64");
		cat->createIdea("65");
		cat->createIdea("66");
		cat->createIdea("67");
		cat->createIdea("68");
		cat->createIdea("69");
		cat->createIdea("70");
		cat->createIdea("71");
		cat->createIdea("72");
		cat->createIdea("73");
		cat->createIdea("74");
		cat->createIdea("75");
		cat->createIdea("76");
		cat->createIdea("77");
		cat->createIdea("78");
		cat->createIdea("79");
		cat->createIdea("80");
		cat->createIdea("81");
		cat->createIdea("82");
		cat->createIdea("83");
		cat->createIdea("84");
		cat->createIdea("85");
		cat->createIdea("86");
		cat->createIdea("87");
		cat->createIdea("88");
		cat->createIdea("89");
		cat->createIdea("90");
		cat->createIdea("91");
		cat->createIdea("92");
		cat->createIdea("93");
		cat->createIdea("94");
		cat->createIdea("95");
		cat->createIdea("96");
		cat->createIdea("97");
		cat->createIdea("98");
		cat->createIdea("99");
		cat->createIdea("100");
		cat->createIdea("101");

		for (int i = 0; i < 100; i++) {
			ca->printIdea(i);
		}

		for (int i = 0; i < 100; i++) {
			cat->printIdea(i);
		}

		delete ca;
		delete cat;
	}
	return 0;
}