#include<iostream>
#include"datamodel.h"
#include<vector>
// using namespace std;
vector<Product> allproducts = {
    Product(1,"apple",26),
    Product(2,"mango",26),
    Product(3,"guava",26),
    Product(4,"banana",26),
    Product(5,"strawberry",26),
    Product(6,"pineapple",26),
};



Product* chooseProduct()
{
    string ProductList;
    cout<<"Available Products "<<endl;

    for(auto product : allproducts)
    {
        ProductList.append(product.displayName());
    }
    cout<<ProductList<<endl;
    cout<<"----------------"<<endl;
    string choice;
    cin>>choice;
    for(int i=0;i<allproducts.size();i++)
    {
        if(allproducts[i].getShortName()==choice)
        {
            return &allproducts[i];
        }
    }
    cout<<"Product not found";
    return NULL;
}

bool checkout(Cart &cart)
{
    if(cart.Isempty())
    {
        return false;
    }

    int total = cart.getTotal();

    cout<<"Pay in Cash ";

    int paid;
    cin>>paid;
    if(paid>total)
    {
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thanks for shopping with us!";
        return true;
    }

    else
    {
        cout<<"Not enough cash";
        return false;
    }
}
int main()
{
    Cart cart;
    char action;
    while(true)
    {
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
        cin>>action;
        if(action=='a')
        {
            Product *product = chooseProduct();
            cout<<"Added to the cart "<<product->displayName()<<endl;
            cart.addProduct(*product);
        }

        else if(action=='v')
        {
            cout<<"---------------"<<endl;
            cout<<cart.viewCart();
            cout<<"---------------"<<endl;
        }
        else
        {
            cart.viewCart();
            if(checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}