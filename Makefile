SOURCES = main.cpp read_goods_file.cpp generate_random_customers.cpp arrange_line.cpp trace_line.cpp write_cashier_arrangement.cpp
OBJECTS = main.o read_goods_file.o generate_random_customers.o arrange_line.o trace_line.o write_cashier_arrangement.o
HEADERS = main.h read_goods_file.h generate_random_customers.h arrange_line.h trace_line.h write_cashier_arrangement.h customer.h
PROGRAM = Cash_Register_System

$(PROGRAM) : $(OBJECTS)
        g++ $^ -o $@

main.o: main.cpp $(HEADERS)
        g++ -c $<

read_goods_file.o: read_goods_file.cpp $(HEADERS)
        g++ -c $<
      
generate_random_customer.o: generate_random_customer.cpp $(HEADERS)
        g++ -c $<
      
arrange_line.o: arrange_line.cpp $(HEADERS)
        g++ -c $<
        
trace_line.o: trace_line.cpp $(HEADERS)
        g++ -c $<
        vi 
write_cashier_arrangement.o: write_cashier_arrangement.cpp $(HEADERS)
        g++ -c $<
      

clean:
        rm $(PROGRAM) $(OBJECTS)
tar:
        tar Cash_Register_System -czvf .tgz *.cpp *.h
.PHONY: 
        clean tar
