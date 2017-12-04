#ifndef __SALES_DATA_H__
#define __SALES_DATA_H__

#include <iostream>
#include <string>

class Sales_data
{
    // Friend function members.
    friend inline std::ostream& print(std::ostream& out, const Sales_data& data);
    friend inline std::istream& read(std::istream& in, Sales_data& data);
    friend inline Sales_data add(const Sales_data& dataOne, const Sales_data& dataTwo);

public:
    // Constructors.
    inline Sales_data() = default;
    //// Explicitly initialize data members.
    inline Sales_data(std::string &isbn, unsigned int unitsSold, double price) : bookNo(isbn), units_sold(unitsSold), revenue(price * units_sold) {}
    inline Sales_data(const Sales_data& item) {*this = item;}

    // Function members
    std::istream& fillFromStream(std::istream& in);
    Sales_data& combine(const Sales_data& item);
    bool isSameBook(const Sales_data& item);
    inline const std::string& isbn(void) { return this->bookNo; }
    inline double avg_price(void) { return (this->units_sold == 0) ? (0) : (this->revenue / this->units_sold); }

private:
    // Private data members
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

inline std::ostream& print(std::ostream& out, const Sales_data& data);
inline std::istream& read(std::istream& in, Sales_data& data);
inline Sales_data add(const Sales_data& dataOne, const Sales_data& dataTwo);

inline std::ostream& print(std::ostream& out, const Sales_data& data)
{
    out << "ISBN: " << data.bookNo << std::endl;
    out << "Units Sold: " << data.units_sold << std::endl;
    out << "Revenue: " << data.revenue << std::endl;
}

inline std::istream& read(std::istream& in, Sales_data& data)
{
    return data.fillFromStream(in);
}

inline Sales_data add(const Sales_data& dataOne, const Sales_data& dataTwo)
{
    Sales_data res = Sales_data();

    res = (const_cast<Sales_data&>(dataOne)).combine(dataTwo);

    return res;
}

#endif // __SALES_DATA_H__

