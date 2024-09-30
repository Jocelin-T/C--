#include <vector>
#include <iostream>
#include <memory>

// Forward Declaration
class Customer;
class BankAccount;
class Bank;

class BankAccount
{
public:
    // Need to be a pointer, cause of circular independencies
    // (Bank and BankAccount need each others) => Beacause it's C++
    std::unique_ptr<Bank> m_p_bank = std::make_unique<Bank>();

    int m_account_id{0};

    // Amount is added to the balance
    bool credit(float amount)
    {
        m_balance += amount;
        return true;
    }

    // Amout is removed from the balance
    bool debit(float amount)
    {
        if (m_balance - amount >= 0)
        {

            m_balance -= amount;
            std::cout << "Debit OK\n";

            return true;
        }

        std::cout << "Balance too low: " << m_balance << " CHF\n";
        return false;
    }

        private : float m_balance{0.0f};
};

class Bank
{
public:
    void createNewAccount(Customer cust);
    void createNewCustomer(std::string first_name, std::string last_name){
        Customer c;
        c.setFullName(first_name, last_name);
        m_list_customers.push_back(c);
    }

    Customer getCustomer(int index){
        return m_list_customers[index];
    }

    bool Transfer(BankAccount &ba_debit, BankAccount &ba_credit, float amount)
    {

        if (!ba_credit.credit(amount))
        {
            std::cout << "Transfer failed\n";
            return false;
        }
        if (!ba_debit.debit(amount))
        {
            std::cout << "Transfer failed\n";
            return false;
        }

        return true;
    }

private:
    std::vector<Customer> m_list_customers;
};

class Customer
{
public:
    void setFullName(std::string fn, std::string ln)
    {
        m_first_name = fn;
        m_last_name = ln;
    }

    std::string getFullName()
    {
        return m_first_name + " " + m_last_name;
    }

private:
    std::string m_first_name{""};
    std::string m_last_name{""};
};

int main()
{
    BankAccount ba;
    BankAccount bb;

    Bank a;
    Bank b;

    a.createNewCustomer("Ciao", "Bella");

    std::cout << a.getCustomer(0) << "\n";

    ba.credit(600);


    a.Transfer(ba, bb, 500);
    a.Transfer(ba, bb, 500);

    return 0;
}
