#include "ants.h"
#include <chrono>

// Add room
void AntHill::addRoom(std::string name, int capacity) {
    rooms.emplace(std::move(name), std::make_shared<Room>(name, capacity));
}

// Add tunnel
void AntHill::addTunnel(std::string from, std::string to) {
    tunnels.push_back(std::make_shared<Tunnel>(rooms[std::move(from)], rooms[std::move(to)]));
}

// Use the last added ant
void AntHill::addAnt(std::shared_ptr<Ant> ant) {
    ants.push_back(std::move(ant));
    ants.back()->current_room->arrive();
}

// To move ants
void AntHill::simulateMovement() {
    //chrono start
    auto start = std::chrono::high_resolution_clock::now();
    int steps = 0;

    while (!ants.empty()) {
        std::vector<std::string> movements;
        for (const auto& ant : ants) {
            if (ant->current_room->name == "Sd") continue;

            std::shared_ptr<Tunnel> chosenTunnel = nullptr;

            // Evaluate all valid tunnels
            for (const auto& tunnel : tunnels) {
                if (tunnel->from_room == ant->current_room && tunnel->to_room->canAcceptAnt(1)) {
                    // Check if this move leads directly to Sd
                    if (tunnel->to_room->name == "Sd") {
                        chosenTunnel = tunnel;
                        break;
                    }

                    // Check if moving to this room can reach Sd
                    if (canReachSd(tunnel->to_room)) {
                        chosenTunnel = tunnel;
                        break;
                    }
                }
            }

            // Move the ant if a tunnel was chosen
            if (chosenTunnel) {
                movements.push_back("f" + std::to_string(ant->id) + " -- " + ant->current_room->name + " -> " + chosenTunnel->to_room->name);
                ant->current_room->depart();
                ant->current_room = chosenTunnel->to_room;
                ant->current_room->arrive();
            }
        }

        if (!movements.empty()) {
            steps++;
            std::cout << "+++ E" << steps << " +++\n";
            for (const auto& move : movements) {
                std::cout << move << std::endl;
            }
        }

        // Remove ants that have reached the dormitory
        ants.erase(std::remove_if(ants.begin(), ants.end(), [](const std::shared_ptr<Ant>& ant) {
            return ant->current_room->name == "Sd";
        }), ants.end());
    }

    //chrono end
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "=== Total steps: " << steps << " ===" << std::endl;
    std::cout << "Duration: " << duration.count() << " seconds" << std::endl;
}