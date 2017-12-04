#include "Sales_data.h"

std::istream& Sales_data::fillFromStream(std::istream& in)
{
    double price = 0.0;

    in >> this->bookNo >> this->units_sold >> price;

    if (in)
    {
        // All went well.
        this->revenue = this->units_sold * price;
    }
    else
    {
        // Something went bad, restart object.
        *this = Sales_data();
    }

    return in;
}

Sales_data& Sales_data::combine(const Sales_data& item)
{
    this->units_sold += item.units_sold;
    this->revenue += item.revenue;

    return *this;
}

bool Sales_data::isSameBook(const Sales_data& item)
{
    bool isSameBook = false;

    if (item.bookNo == this->bookNo)
    {
        isSameBook = true;
    }

    return isSameBook;
}

