#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

#define INVOICE_FILE "faktura.txt"
#define DELIMITER ';'
#define TAX_CONST 1.2

typedef struct {
	int id;
	int number;
	double price;
	string name;
} article;

/* Return number of articles in invoice */
int get_articles_count(ifstream &invoice)
{
	int count = 0;

	invoice.clear();
	invoice.seekg(ios::beg);

	string tmp;
	while (getline(invoice, tmp))
		count++;

	return count;
}

article *allocate_articles_list(int articles_count)
{
	return (new article[articles_count]);
}

void parse_articles(ifstream &invoice, article *articles)
{
	invoice.clear();
	invoice.seekg(ios::beg);

	int article_ptr = 0;

	string article_entry;
	while (getline(invoice, article_entry)) {		
		vector<string> article_entry_data;
		istringstream article_entry_stream(article_entry);
		
		string data;    
		while (getline(article_entry_stream, data, DELIMITER))
			article_entry_data.push_back(data);

		articles[article_ptr].id = atoi(article_entry_data[1].c_str());
		articles[article_ptr].number = atoi(article_entry_data[2].c_str());
		articles[article_ptr].price = atof(article_entry_data[4].c_str());
		articles[article_ptr].name = article_entry_data[5];

		article_ptr++;
	}	
}

float get_invoce_price(article *articles, int articles_count)
{
	float sum = 0.0;

	for (int i = 0; i < articles_count; i++) {
		sum += articles[i].price * articles[i].number;
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	ifstream invoice(INVOICE_FILE);

	if(!invoice.is_open()) {
		cout << "Unable to open invoice file" << endl;
		return 1;
	}

	int articles_count = get_articles_count(invoice);
	article *articles = allocate_articles_list(articles_count);

	parse_articles(invoice, articles);

	/* Print out invoce summary */

	cout << "názov tovaru\t\t\tcena za 1ks\tpočet" << endl;
	

	for (int i = 0; i < articles_count; ++i) {
		cout << (articles[i].name).substr(0, 20) << "\t\t";
		cout << setprecision(2) << fixed << articles[i].price << "€" << "\t\t";
		cout << articles[i].number << endl;
	}

	float invoce_price = get_invoce_price(articles, articles_count);

	cout << "----------------------------------------------" << endl;
	cout << "Spolu:\t\t" << setprecision(2) << fixed << invoce_price << " Eur bez DPH";
	cout << "\t" << setprecision(2) << fixed << invoce_price * TAX_CONST  << " Eur s DPH" << endl;

	invoice.close();

	return 0;
}