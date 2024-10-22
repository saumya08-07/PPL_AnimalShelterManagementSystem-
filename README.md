# PPL_AnimalShelterManagementSystem-
#Animal Shelter Management System
The goal of this project is to create a management system for an animal shelter that facilitates the tracking and administration of animals within the shelter. The system will allow users to add new animals, remove animals when adopted, search for animals by ID, and filter animals by species and gender. The data will be stored in a CSV file, which the program will read upon startup.
Objectives
•	To create an intuitive console application that’s easy for shelter staff to use.
•	To build a flexible system that can grow with the needs of the shelter, potentially adding features like advanced search options or database integration in the future.
•	To provide a clear and maintainable codebase that adheres to good programming practices.


#Brief Explanation:
Animal shelters play a crucial role in caring for and rehoming abandoned and stray animals. An efficient management system is essential for organizing animal information, tracking adoptions, and maintaining overall operational effectiveness.
How We Built It
We used two important programming concepts: inheritance and polymorphism. These concepts allow us to create a flexible and efficient framework that can easily adapt to the needs of different animal species.
Key Features
1.	Inheritance:
o	The system uses a base class, Animal, which contains common attributes and methods relevant to all animals (e.g., id, intakeDate, intakeReason, and methods for displaying information).
o	Derived classes (Dog, Cat, Rabbit, Hamster, Tortoise) inherit from the Animal class, allowing them to utilize shared properties while adding specific details unique to each species (e.g., breed for dogs and cats).
2.	Polymorphism:
o	The displayInfo method is declared virtual in the Animal class, enabling each derived class to implement its own version of this method if needed.
o	This allows the system to treat different animal types uniformly while still providing species-specific behavior when required.
3.	Sample Dataset:
o	To enhance the system’s functionality during testing and demonstration, a sample dataset of 200 animals has been incorporated. This dataset includes a variety of species such as:
	Dogs: Various breeds and ages, each with distinct care requirements.
	Cats: A range of breeds and temperaments to accommodate different adopter preferences.
	Rabbits: Information about their unique care needs and adoption criteria.
	Hamsters: Details about their habitat requirements and social behavior.
	Tortoises: Specifics about their longevity and dietary needs.
o	This dataset facilitates realistic testing of the system, ensuring that all functionalities—like filtering, searching, and displaying animal information—work seamlessly across different species.
Conclusion
By employing inheritance and polymorphism, the Animal Shelter Management System not only achieves code reusability and flexibility but also simplifies future enhancements. As new species are introduced or additional features are needed, the system can adapt with minimal disruption, thereby supporting the vital mission of animal shelters in providing care and finding homes for animals in need.

