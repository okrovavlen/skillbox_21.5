#include <iostream>
#include <vector>
#include <string>

enum BuildingType {
    HOUSE,
    GARAGE,
    SHED,
    BATHHOUSE
};

enum RoomType {
    BEDROOM,
    KITCHEN,
    BATHROOM,
    CHILDREN,
    LIVING_ROOM
};

struct Room {
    RoomType type;
    double area;
};

struct Floor {
    int room_count;
    double ceiling_height;
    std::vector<Room> rooms;
};

struct Building {
    BuildingType type;
    double area;
    std::vector<Floor> floors;  // Only relevant for houses and maybe bathhouses
    bool has_stove = false; // For house and bathhouse
};

struct Plot {
    int plot_number;
    std::vector<Building> buildings;
};

struct Settlement {
    std::vector<Plot> plots;
    double total_area = 0; //  We'll assume each plot has the same area for simplicity
};


int main() {
    int plot_count;

    std::cout << "Enter the number of plots: ";
    std::cin >> plot_count;

    Settlement settlement;
    settlement.plots.resize(plot_count); // Allocate space for plots

    for (int i = 0; i < plot_count; ++i) {
        settlement.plots[i].plot_number = i + 1;

        int building_count;
        std::cout << "Enter the number of buildings on plot " << i + 1 << ": ";
        std::cin >> building_count;

        for (int j = 0; j < building_count; ++j) {
            Building building;
            int building_type;

            std::cout << "Enter building type (0-House, 1-Garage, 2-Shed, 3-Bathhouse): ";
            std::cin >> building_type;
            building.type = static_cast<BuildingType>(building_type);


            std::cout << "Enter building area: ";
            std::cin >> building.area;

            if (building.type == HOUSE) {
                int floor_count;
                std::cout << "Enter the number of floors: ";
                std::cin >> floor_count;
                building.floors.resize(floor_count);

                for (int k = 0; k < floor_count; ++k) {
                    std::cout << "Enter the number of rooms on floor " << k + 1 << ": ";
                    std::cin >> building.floors[k].room_count;
                    std::cout << "Enter the ceiling height on floor " << k + 1 << ": ";
                    std::cin >> building.floors[k].ceiling_height;
                    building.floors[k].rooms.resize(building.floors[k].room_count);


                    for (int l = 0; l < building.floors[k].room_count; ++l) {
                        int room_type;
                        std::cout << "Enter room type (0-Bedroom, 1-Kitchen, 2-Bathroom, 3-Children, 4-Living room): ";
                        std::cin >> room_type;
                        building.floors[k].rooms[l].type = static_cast<RoomType>(room_type);
                        std::cout << "Enter room area: ";
                        std::cin >> building.floors[k].rooms[l].area;
                    }
                }
                std::cout << "Does the house have a stove (0-No, 1-Yes): ";
                std::cin >> building.has_stove;

            } else if (building.type == BATHHOUSE) {
                std::cout << "Does the bathhouse have a stove (0-No, 1-Yes): ";
                std::cin >> building.has_stove;
            }


            settlement.plots[i].buildings.push_back(building);
        }

    }




    return 0;
}