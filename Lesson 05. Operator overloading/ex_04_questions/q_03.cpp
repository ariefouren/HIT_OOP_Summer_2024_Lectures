class Record {
public:
    Record(const Record& that) { *this = that; } // Line 3
    Record operator = (const Record& that){     // Line 4
        this->id = that.id;                     // Line 5
        return *this;                           // Line 6
    }
private:
    long id;
};
void main()
{
    Record r1;              // Line 14
    Record r2(r1);          // Line 15
    Record r3 = r2 = r1;    // Line 16
    r1 = r2 = r3;           // Line 17
}
