#include "apctainer.h"

ApCtainer::ApCtainer(ApStruct *ctainer, size_t size)
{
    m_ctainer = new Apartments[size];
    m_size = size;

    for (size_t i = 0; i < m_size; ++i)
    {
        m_ctainer[i].set_address(ctainer[i].address);
        m_ctainer[i].set_area(ctainer[i].area);
        m_ctainer[i].set_floor(ctainer[i].floor);
        m_ctainer[i].set_quantity_of_rooms(ctainer[i].quantity_of_rooms);
    }
}

void ApCtainer::print_apps_by_rooms(size_t quantity_of_rooms) const
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_ctainer[i].get_quantity_of_rooms() == quantity_of_rooms)
        {
            std::cout << "------------------------------------\n";
            m_ctainer[i].printout();
            std::cout << "------------------------------------\n";
        }
    }
}

void ApCtainer::print_apps_between_floors(int floor_a, int floor_b) const
{
    if (floor_a > floor_b)
    {
        floor_a = floor_b + floor_a;
        floor_b = floor_a - floor_b;
        floor_a -= floor_b;
    }
    for (size_t i = 0; i < m_size; ++i)
    {
        if (floor_a <= m_ctainer[i].get_floor() && floor_b >= m_ctainer[i].get_floor())
        {
            std::cout << "------------------------------------\n";
            m_ctainer[i].printout();
            std::cout << "------------------------------------\n";
        }
    }
}

void ApCtainer::print_apps_ofless_area(double area) const
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_ctainer[i].get_area() < area)
        {
            std::cout << "------------------------------------\n";
            m_ctainer[i].printout();
            std::cout << "------------------------------------\n";
        }
    }
}

ApCtainer::~ApCtainer()
{
    delete[] m_ctainer;
}

