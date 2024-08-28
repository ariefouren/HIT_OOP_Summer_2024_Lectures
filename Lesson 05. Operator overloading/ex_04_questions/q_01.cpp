class Record {
public:
    ~Record() {};
    Record(const Record& that) { *this = that; }
    Record operator = (const Record& that){
        name = that.name;
        return *this;
    }
private:
    char name[100];
    long id;
};
void main()
{
Record r1;
Record r2 = r1;
Record r3;
r3 = r2 = r1;
}
