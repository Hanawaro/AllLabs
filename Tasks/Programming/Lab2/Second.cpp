#include "Second.hpp"

#include "../../../glm/glm.hpp"

struct Data {
    double x4 = 0;
    double x3 = 0;
    double x2 = 0;
    double x1 = 0;
    double x0 = 0;
    
    double yx2 = 0;
    double yx1 = 0;
    double yx0 = 0;
};

namespace Programming { namespace SecondLab { namespace Second {
    
    void PointsManager::AddPoint(const Point& point) {
        m_Points.push_back(point);
    }
    
    std::vector<Point> PointsManager::GetRandomPoints(unsigned int count, double lX, double rX, double lY, double rY) const {
        std::vector<Point> points;
        for (int i = 0; i < count; i++) {
            double x = (rX - lX)*rand()/RAND_MAX + lX;
            double y = (rY - lY)*rand()/RAND_MAX + lY;
            points.push_back({x, y});
        }
        return points;
    }
    
    void Task::DoWork(const std::vector<Point>& points) {
        Data data;
        for (const auto& point : points) {
            data.x1 += point.x;
            data.x2 += point.x * point.x;
            data.x3 += point.x * point.x * point.x;
            data.x4 += point.x * point.x * point.x * point.x;
            
            data.yx0 += point.y;
            data.yx1 += point.y * point.x;
            data.yx2 += point.y * point.x * point.x;
        }
        data.x0 = points.size();
        
        glm::dmat3 values = {
            data.x4, data.x3, data.x2,
            data.x3, data.x2, data.x1,
            data.x2, data.x1, data.x0
        };
        
        if (glm::determinant(values) == 0)
            throw "bad values";
        
        values = glm::inverse(values);
        glm::dvec3 vecValues = { data.yx2, data.yx1, data.yx0 };
        glm::vec3 parameters = vecValues * values;
        
        std::cout << std::fixed << "  Итоговое уравнение: " << parameters[0] << "*(x^2) + " << parameters[1] << "*(x) + " << parameters[2] << std::endl;
        
    }
    
} } }
