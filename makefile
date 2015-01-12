# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
TARGET = bin/SimCoffeeShop
CFLAGS  = -g -Wall -Weffc++
LFLAGS  = -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lPocoUtil -lPocoFoundation


# All Targets
all: $(TARGET)

# Tool invocations
# Executable “SimCoffeeShop” depends on the files *.o
$(TARGET): bin/Main.o bin/CoffeeShop.o bin/VipCustomer.o bin/Suppliers.o bin/Supplier.o bin/RegularCustomer.o bin/Products.o bin/Product.o bin/LoggerParams.o bin/Ingredients.o bin/Ingredient.o bin/Customers.o bin/Customer.o bin/CAppLogger.o bin/ImgProc.o
	@echo 'Building target: SimCoffeeShop'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/SimCoffeeShop bin/Main.o bin/CoffeeShop.o bin/VipCustomer.o bin/Suppliers.o bin/Supplier.o bin/RegularCustomer.o bin/Products.o bin/Product.o bin/LoggerParams.o bin/Ingredients.o bin/Ingredient.o bin/Customers.o bin/Customer.o bin/CAppLogger.o bin/ImgProc.o $(LFLAGS)
	@echo 'Finished building target: SimCoffeeShop'
	@echo ' '

# Depends on the source and header files
bin/Main.o: src/Main.cpp
	$(CC) $(CFLAGS) -c -o bin/Main.o src/Main.cpp

# Depends on the source and header files 
bin/CoffeeShop.o: src/CoffeeShop.cpp
	$(CC) $(CFLAGS) -c -o bin/CoffeeShop.o src/CoffeeShop.cpp

# Depends on the source and header files 
bin/VipCustomer.o: src/VipCustomer.cpp
	$(CC) $(CFLAGS) -c -o bin/VipCustomer.o src/VipCustomer.cpp

# Depends on the source and header files 
bin/Suppliers.o: src/Suppliers.cpp
	$(CC) $(CFLAGS) -c -o bin/Suppliers.o src/Suppliers.cpp

# Depends on the source and header files 
bin/Supplier.o: src/Supplier.cpp
	$(CC) $(CFLAGS) -c -o bin/Supplier.o src/Supplier.cpp

# Depends on the source and header files 
bin/RegularCustomer.o: src/RegularCustomer.cpp
	$(CC) $(CFLAGS) -c -o bin/RegularCustomer.o src/RegularCustomer.cpp

# Depends on the source and header files 
bin/Products.o: src/Products.cpp
	$(CC) $(CFLAGS) -c -o bin/Products.o src/Products.cpp

# Depends on the source and header files 
bin/Product.o: src/Product.cpp
	$(CC) $(CFLAGS) -c -o bin/Product.o src/Product.cpp

# Depends on the source and header files 
bin/LoggerParams.o: src/LoggerParams.cpp
	$(CC) $(CFLAGS) -c -o bin/LoggerParams.o src/LoggerParams.cpp

# Depends on the source and header files 
bin/Ingredients.o: src/Ingredients.cpp
	$(CC) $(CFLAGS) -c -o bin/Ingredients.o src/Ingredients.cpp

# Depends on the source and header files 
bin/Ingredient.o: src/Ingredient.cpp
	$(CC) $(CFLAGS) -c -o bin/Ingredient.o src/Ingredient.cpp

# Depends on the source and header files 
bin/Customers.o: src/Customers.cpp
	$(CC) $(CFLAGS) -c -o bin/Customers.o src/Customers.cpp

# Depends on the source and header files 
bin/Customer.o: src/Customer.cpp
	$(CC) $(CFLAGS) -c -o bin/Customer.o src/Customer.cpp

# Depends on the source and header files 
bin/CAppLogger.o: src/CAppLogger.cpp
	$(CC) $(CFLAGS) -c -o bin/CAppLogger.o src/CAppLogger.cpp

# Depends on the source and header files 
bin/ImgProc.o: src/ImgProc.cpp
	$(CC) $(CFLAGS) -c -I/usr/include/opencv -o bin/ImgProc.o src/ImgProc.cpp


#Clean the build directory
clean: 
	rm -f bin/*
