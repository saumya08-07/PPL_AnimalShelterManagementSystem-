#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Base class
class Animal {
protected:
    int id;
    string intakeDate;
    string intakeReason;
    string shelterCode;
    string animalName;
    string breedName;
    string speciesName;
    string animalAge;
    string gender;
    string movementDate;
    string typeOfMovement;
    string returnDate;
    string returnReason;

public:
    Animal(int id, const string& intakeDate, const string& intakeReason,
           const string& shelterCode, const string& animalName, const string& breedName,
           const string& speciesName, const string& animalAge, const string& gender,
           const string& movementDate, const string& typeOfMovement, const string& returnDate,
           const string& returnReason)
        : id(id), intakeDate(intakeDate), intakeReason(intakeReason), shelterCode(shelterCode),
          animalName(animalName), breedName(breedName), speciesName(speciesName),
          animalAge(animalAge), gender(gender), movementDate(movementDate),
          typeOfMovement(typeOfMovement), returnDate(returnDate), returnReason(returnReason) {}

    int getId() const {
        return id;
    }

    string getSpecies() const {
        return speciesName;
    }

    string getGender() const {
        return gender;
    }

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Intake Date: " << intakeDate 
             << ", Reason: " << intakeReason << ", Shelter Code: " << shelterCode 
             << ", Animal Name: " << animalName << ", Breed: " << breedName 
             << ", Species: " << speciesName << ", Age: " << animalAge 
             << ", Gender: " << gender << ", Movement Date: " << movementDate 
             << ", Type of Movement: " << typeOfMovement 
             << ", Return Date: " << returnDate << ", Return Reason: " << returnReason << endl;
    }

    virtual ~Animal() {}
};

// Derived classes for Dog, Cat, Rabbit, Hamster, and Tortoise
class Dog : public Animal {
public:
    Dog(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
        const string& animalName, const string& breedName, const string& animalAge,
        const string& gender, const string& movementDate, const string& typeOfMovement,
        const string& returnDate, const string& returnReason)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Dog", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason) {}
};
class Cat : public Animal {
public:
    Cat(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
        const string& animalName, const string& breedName, const string& animalAge,
        const string& gender, const string& movementDate, const string& typeOfMovement,
        const string& returnDate, const string& returnReason)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Cat", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason) {}
};

class Rabbit : public Animal {
public:
    Rabbit(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
           const string& animalName, const string& breedName, const string& animalAge,
           const string& gender, const string& movementDate, const string& typeOfMovement,
           const string& returnDate, const string& returnReason)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Rabbit", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason) {}
};

class Hamster : public Animal {
public:
    Hamster(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
            const string& animalName, const string& breedName, const string& animalAge,
            const string& gender, const string& movementDate, const string& typeOfMovement,
            const string& returnDate, const string& returnReason)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Hamster", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason) {}
};

class Tortoise : public Animal {
public:
    Tortoise(int id, const string& intakeDate, const string& intakeReason, const string& shelterCode,
             const string& animalName, const string& breedName, const string& animalAge,
             const string& gender, const string& movementDate, const string& typeOfMovement,
             const string& returnDate, const string& returnReason)
        : Animal(id, intakeDate, intakeReason, shelterCode, animalName, breedName, "Tortoise", animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason) {}
};

// Function to read animals from the CSV file
void readAnimalsFromCSV(const string& filename, vector<Animal*>& shelterAnimals) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the CSV file!" << endl;
        return;
    }

    string line;
    // Skip header
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        int id;
        string intakeDate, intakeReason, shelterCode, animalName, breedName, speciesName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason;

        getline(ss, token, ',');
        if (token.empty()) continue; // Skip empty lines
        id = stoi(token); // Convert string to integer
        getline(ss, intakeDate, ',');
        getline(ss, intakeReason, ',');
        getline(ss, shelterCode, ',');
        getline(ss, animalName, ',');
        getline(ss, breedName, ',');
        getline(ss, speciesName, ',');
        getline(ss, animalAge, ',');
        getline(ss, gender, ',');
        getline(ss, movementDate, ',');
        getline(ss, typeOfMovement, ',');
        getline(ss, returnDate, ',');
        getline(ss, returnReason, ',');

        // Create Animal objects based on species
        if (speciesName == "Dog") {
            shelterAnimals.push_back(new Dog(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
        } else if (speciesName == "Cat") {
            shelterAnimals.push_back(new Cat(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
        } else if (speciesName == "Rabbit") {
            shelterAnimals.push_back(new Rabbit(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
        } else if (speciesName == "Hamster") {
            shelterAnimals.push_back(new Hamster(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
        } else if (speciesName == "Tortoise") {
            shelterAnimals.push_back(new Tortoise(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
        }
    }

    file.close();
}

// Function to display all animals
void displayAllAnimals(const vector<Animal*>& shelterAnimals) {
    for (const auto& animal : shelterAnimals) {
        animal->displayInfo();
    }
}

// Function to find an animal by ID
void findAnimalByID(const vector<Animal*>& shelterAnimals, int id) {
    for (const auto& animal : shelterAnimals) {
        if (animal->getId() == id) {
            animal->displayInfo();
            return;
        }
    }
    cout << "Animal with ID " << id << " not found." << endl;
}

// Function to filter animals by species
void filterBySpecies(const vector<Animal*>& shelterAnimals, const string& species) {
    cout << "Animals of species: " << species << endl;
    bool found = false;
    for (const auto& animal : shelterAnimals) {
        if (animal->getSpecies() == species) {
            animal->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No animals found of species: " << species << endl;
    }
}

// Function to filter animals by gender
void filterByGender(const vector<Animal*>& shelterAnimals, const string& gender) {
    cout << "Animals of gender: " << gender << endl;
    bool found = false;
    for (const auto& animal : shelterAnimals) {
        if (animal->getGender() == gender) {
            animal->displayInfo();
            found = true;
        }
    }
    if (!found) {
        cout << "No animals found of gender: " << gender << endl;
    }
}

// Function to add a new animal
void addAnimal(vector<Animal*>& shelterAnimals) {
    int id;
    string intakeDate, intakeReason, shelterCode, animalName, breedName, speciesName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(); // Ignore the newline character after the ID
    cout << "Enter intake date: ";
    getline(cin, intakeDate);
    cout << "Enter intake reason: ";
    getline(cin, intakeReason);
    cout << "Enter shelter code: ";
    getline(cin, shelterCode);
    cout << "Enter animal name: ";
    getline(cin, animalName);
    cout << "Enter breed name: ";
    getline(cin, breedName);
    cout << "Enter species name (Dog, Cat, Rabbit, Hamster, Tortoise): ";
    getline(cin, speciesName);
    cout << "Enter animal age: ";
    getline(cin, animalAge);
    cout << "Enter gender (Male, Female): ";
    getline(cin, gender);
    cout << "Enter movement date: ";
    getline(cin, movementDate);
    cout << "Enter type of movement: ";
    getline(cin, typeOfMovement);
    cout << "Enter return date (if applicable, else leave empty): ";
    getline(cin, returnDate);
    cout << "Enter return reason (if applicable, else leave empty): ";
    getline(cin, returnReason);

    // Create and add new animal based on species
    if (speciesName == "Dog") {
        shelterAnimals.push_back(new Dog(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
    } else if (speciesName == "Cat") {
        shelterAnimals.push_back(new Cat(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
    } else if (speciesName == "Rabbit") {
        shelterAnimals.push_back(new Rabbit(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
    } else if (speciesName == "Hamster") {
        shelterAnimals.push_back(new Hamster(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
    } else if (speciesName == "Tortoise") {
        shelterAnimals.push_back(new Tortoise(id, intakeDate, intakeReason, shelterCode, animalName, breedName, animalAge, gender, movementDate, typeOfMovement, returnDate, returnReason));
    } else {
        cout << "Invalid species!" << endl;
    }
}

// Function to remove an animal by ID
void removeAnimalByID(vector<Animal*>& shelterAnimals, int id) {
    for (auto it = shelterAnimals.begin(); it != shelterAnimals.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it; // Free the memory
            shelterAnimals.erase(it); // Remove the pointer from the vector
            cout << "Animal with ID " << id << " has been adopted and removed." << endl;
            return;
        }
    }
    cout << "Animal with ID " << id << " not found." << endl;
}

int main() {
    vector<Animal*> shelterAnimals;
    string filename = "C:/Users/kumar/OneDrive/Desktop/animal_shelter_data.csv"; 
    readAnimalsFromCSV(filename, shelterAnimals);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all animals\n";
        cout << "2. Find animal by ID\n";
        cout << "3. Filter animals by species\n";
        cout << "4. Filter animals by gender\n";
        cout << "5. Add a new animal\n";
        cout << "6. Adopt an animal (remove by ID)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllAnimals(shelterAnimals);
                break;
            case 2: {
                int id;
                cout << "Enter animal ID to search: ";
                cin >> id;
                findAnimalByID(shelterAnimals, id);
                break;
            }
            case 3: {
                string species;
                cout << "Enter species to filter (Dog, Cat, Rabbit, Hamster, Tortoise): ";
                cin >> species;
                filterBySpecies(shelterAnimals, species);
                break;
            }
            case 4: {
                string gender;
                cout << "Enter gender to filter (Male, Female): ";
                cin >> gender;
                filterByGender(shelterAnimals, gender);
                break;
            }
            case 5:
                addAnimal(shelterAnimals);
                break;
            case 6: {
                int id;
                cout << "Enter animal ID to adopt: ";
                cin >> id;
                removeAnimalByID(shelterAnimals, id);
                break;
            }
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    // Clean up dynamically allocated memory
    for (auto animal : shelterAnimals) {
        delete animal;
    }

    return 0;
}
