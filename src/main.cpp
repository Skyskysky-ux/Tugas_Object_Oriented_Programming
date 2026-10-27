#include <iostream>     //Header files untuk memanggil library - Digunakan untuk operasi input dan output
#include <string>       //Digunakan untuk operasi string
#include <stdexcept>    //Digunakan untuk operasi exception
#include <vector>       //Digunakan untuk operasi vector

class Product0002 {     // Class Product0002 untuk menyimpan informasi produk
    private: // access modifier private untuk menyembunyikan atribut dari class Product0002
        std::string name;  // Nama produk (Atribut private)
        std::string category;  // Kategori produk (Atribut private)
        double price;  // Harga produk (Atribut private)

    public: // access modifier public untuk mengakses atribut dari class Product0002
    // Constructor
        Product0002(const std::string name, const std::string category, double productPrice) {    // Constructor untuk menginisialisasi atribut name, category, dan price
            setName(name); // Memanggil setter untuk mengatur nama produk
            setCategory(category); // Memanggil setter untuk mengatur kategori produk
            setPrice(productPrice); // Memanggil setter untuk mengatur harga produk
        }

        // setter dan getter dari attribute name
        std::string getName() const {       // Getter untuk mendapatkan nama produk
            return name;                    // Mengembalikan nilai dari atribut name
        }
        void setName(const std::string name) {      // Setter untuk mengatur nama produk dengan parameter name
            if (name.empty()) {                     // Pengkondisian Mengecek apakah nama produk kosong
                throw std::invalid_argument("Name cannot be empty"); // Jika nama produk kosong, maka akan melemparkan exception dengan pesan "Name cannot be empty"
            }
            this->name = name;      // Mengatur nilai dari atribut name dengan nilai yang diberikan
        }

        // setter dan getter dari attribute category
        std::string getCategory() const {       // Getter untuk mendapatkan kategori produk 
            return category;                    // Mengembalikan nilai dari atribut category
        }
        void setCategory(const std::string category) {      // Setter untuk mengatur kategori produk dengan parameter category
            if (category.empty()) {                        // Pengkondisian Mengecek apakah kategori produk kosong
                throw std::invalid_argument("Category cannot be empty");    // Jika kategori produk kosong, maka akan melemparkan exception dengan pesan "Category cannot be empty"
            }
            this->category = category;  // Mengatur nilai dari atribut category dengan nilai yang diberikan
        }
        // setter dan getter dari attribute price
        double getPrice() const {      // Getter untuk mendapatkan harga produk
            return price;              // Mengembalikan nilai dari atribut price
        }
        
        void setPrice(double productPrice) {      // Setter untuk mengatur harga produk dengan parameter productPrice 
            if (productPrice <= 0) {             // Pengkondisian Mengecek apakah harga produk kurang dari atau sama dengan 0
                throw std::invalid_argument("Price cannot be less than or equal to 0");    // Jika harga produk kurang dari atau sama dengan 0, maka akan melemparkan exception dengan pesan "Price cannot be less than or equal to 0"
            }
            this->price = productPrice;  // Mengatur nilai dari atribut price dengan nilai yang diberikan
        };
    };

class Store {       // Class store untuk menyimpan informasi toko
    private:        // access modifier private untuk menyembunyikan atribut dari class store
        std::string name;   // Nama toko (Atribut private)
        std::vector<Product0002> products;      //

    public:     // access modifier public untuk mengakses atribut dari class store
        // Constructor
        Store(const std::string storeName) {        // Constructor untuk menginisialisasi atribut name dengan parameter storeName
            setName(storeName);                     // Memanggil setter untuk mengatur nama toko
        }

    // setter dan getter dari attribute name
        std::string getName() const {           // Getter untuk mendapatkan nama toko
            return name;                        // Mengembalikan nilai dari atribut name
        }
        void setName(const std::string storeName) {     // Setter untuk mengatur nama toko dengan parameter storeName
            if (storeName.empty()) {                    // Pengkondisian Mengecek apakah nama toko kosong
                throw std::invalid_argument("Store name cannot be empty");      // Jika nama toko kosong, maka akan melemparkan exception dengan pesan "Store name cannot be empty"
            }
            this->name = storeName; // Mengatur nilai dari atribut name dengan nilai yang diberikan
        }
};
        
int main() {        // Fungsi utama untuk menjalankan program

        Store myStore("Toko Madura 24 Jam");        // Membuat objek myStore dari class store dengan nama toko serta Argument "Toko Madura 24 Jam"
        Product0002 product("Chitato", "Snack", 12000);     // Membuat objek product dari class Product0002 dengan Argument nama produk "Chitato", kategori "Snack", dan harga 12000
        
        std::cout << "Store Name: " << myStore.getName() << std::endl;      // Menampilkan nama toko dengan memanggil getter getName() dari objek myStore
        std::cout << "Product Name: " << product.getName() << std::endl;    // Menampilkan nama produk dengan memanggil getter getName() dari objek product
        std::cout << "Product Category: " << product.getCategory() << std::endl;  // Menampilkan kategori produk dengan memanggil getter getCategory() dari objek product
        std::cout << "Product Price: " << product.getPrice() << std::endl;    // Menampilkan harga produk dengan memanggil getter getPrice() dari objek product
        std::cout << "\nUji Validasi: " << "\n";


// Test 1: Nama toko kosong
try {   // Pengkondisian untuk menguji validasi nama toko kosong
    Store myStore(""); // Membuat objek myStore dari class store dengan nama toko kosong
}
catch (const std::invalid_argument& e) {        // Menangkap exception yang dilemparkan oleh setter setName() dari class store
    std::cout << "Test 1: " << e.what() << '\n';    // Menampilkan pesan exception yang dilemparkan
}

// Test 2: Nama produk kosong
try {       // Pengkondisian untuk menguji validasi nama produk kosong
    Product0002 product("", "Snack", 12000);        // Membuat objek product dari class Product0002 dengan nama produk kosong
}
catch (const std::invalid_argument& e) {        // Menangkap exception yang dilemparkan oleh setter setName() dari class Product0002
    std::cout << "Test 2: " << e.what() << '\n';        // Menampilkan pesan exception yang dilemparkan
}

// Test 3: Kategori kosong
try {       // Pengkondisian untuk menguji validasi kategori produk kosong
    Product0002 product("Chitato", "", 12000);  // Membuat objek product dari class Product0002 dengan kategori produk kosong
}
catch (const std::invalid_argument& e) {        // Menangkap exception yang dilemparkan oleh setter setCategory() dari class Product0002
    std::cout << "Test 3: " << e.what() << '\n';   // Menampilkan pesan exception yang dilemparkan
}

// Test 4: Harga negatif
try {    // Pengkondisian untuk menguji validasi harga produk negatif
    Product0002 product("Chitato", "Snack", -12000);    // Membuat objek product dari class Product0002 dengan harga produk negatif
}
catch (const std::invalid_argument& e) {        // Menangkap exception yang dilemparkan oleh setter setPrice() dari class Product0002
    std::cout << "Test 4: " << e.what() << '\n';        // Menampilkan pesan exception yang dilemparkan
} 
   
    return 0;   // Mengembalikan nilai 0 untuk menandakan program berjalan dengan sukses
};

