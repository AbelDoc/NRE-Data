    
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
        DataBatch data = parser.parse("test.json");
        
        return 0;
    }