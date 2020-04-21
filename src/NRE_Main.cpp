    
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
        std::cout << data.getBatch("object").getEntry("entry").getValue() << std::endl;
        data.clear();
        
        DataBatch* shaders = new DataBatch("shaders");
        data.add(shaders);
        shaders->add("SSAO", "true");
        shaders->add("Shadow", "true");
        shaders->add("Triplanar", "true");
        
        formatter.format(data, "test2.json");
        
        return 0;
    }