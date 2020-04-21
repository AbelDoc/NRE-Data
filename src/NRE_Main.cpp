    
    /**
     * @file NRE_Main.cpp
     * @brief Test of Data's API
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    #include "Header/NRE_Data.hpp"
    
    using namespace NRE::Data;
    using namespace NRE::Utility;
    
    int main(int, char**) {
        JSONParser parser;
        JSONFormatter formatter;
        
        DataBatch data = parser.parse("test.json");
        auto& object = data.getBatch("object");
        auto& entry = object.getEntry("entry");
        std::cout << entry.getValue() << std::endl;
        formatter.format(data, "test2.json");
        
        return 0;
    }