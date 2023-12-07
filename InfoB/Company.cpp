//
// Created by asus on 11/13/2023.
//

#include "company.h"
#include <fstream>
#include <algorithm>

void Company::addProject(const Project& project) {
    projects.push_back(project);
}

void Company::addDeveloper(const Developer& developer) {
    developers.push_back(developer);
}

void Company::readProjectsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    int id, startYear, endYear;
    std::string name;
    while (file >> id >> name >> startYear >> endYear) {
        Project project(name, startYear, endYear);
        project.addDeveloper(nullptr);  // Placeholder
        addProject(project);
    }

    file.close();
}

void Company::readDevelopersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    std::string name;
    int salary, levelInt;
    while (file >> name >> salary >> levelInt) {
        Level level = static_cast<Level>(levelInt);
        Developer developer(name, salary, level);
        addDeveloper(developer);
    }

    file.close();
}

void Company::readProjectsDevelopersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    int projectId, developerId;
    while (file >> projectId >> developerId) {
        Project& project = projects.at(projectId - 1);
        Developer* developer = &developers.at(developerId - 1);
        project.addDeveloper(developer);
    }

    file.close();
}

void Company::printDevelopers() const {
    for (const auto& developer : developers) {
        std::cout << developer << std::endl;
    }
}

void Company::printProjects() const {
    for (const auto& project : projects) {
        std::cout << project << std::endl;
    }
}

void Company::printActiveProjects() const {
    for (const auto& project : projects) {
        if (project.getEndYear() == 0) {
            std::cout << project << std::endl;
        }
    }
}

void Company::printDevelopersOrderedBySalary() {
    std::sort(developers.begin(), developers.end(), [](const Developer& a, const Developer& b) {
        return a.getSalary() < b.getSalary();
    });
    printDevelopers();
}

void Company::printDevelopersOrderedByName() {
    std::sort(developers.begin(), developers.end(), [](const Developer& a, const Developer& b) {
        return a.getName() < b.getName();
    });
    printDevelopers();
}

void Company::printProjectsOrderedByStartYearAndName() {
    std::sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) {
        if (a.getStartYear() == b.getStartYear()) {
            return a.getName() < b.getName();
        }
        return a.getStartYear() < b.getStartYear();
    });
    printProjects();
}

//Developer* Company::getDeveloperWithMaxProjects() const {
//    auto maxDeveloper = std::max_element(developers.begin(), developers.end(), [](const Developer& a, const Developer& b) {
//        return a.getProjectsCount() < b.getProjectsCount();
//    });
//    return &(*maxDeveloper);
}
