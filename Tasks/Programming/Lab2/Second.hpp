#pragma once

#include <iostream>
#include <vector>

namespace Programming { namespace SecondLab { namespace Second {
    
    struct Point {
        double x;
        double y;
    };
    
    class PointsManager {
    public:
        PointsManager(void) = default;
        ~PointsManager(void) = default;
        
        void AddPoint(const Point& point);
        
        std::vector<Point> GetRandomPoints(unsigned int count, double lX, double rX, double lY, double rY) const;
        inline const std::vector<Point>& GetPoints(void) const { return m_Points; }
    private:
        std::vector<Point> m_Points;
    };
    
    class Task {
    public:
        Task(void) = default;
        ~Task(void) = default;
        
        void DoWork(const std::vector<Point>& points);
    };
    
} } }
