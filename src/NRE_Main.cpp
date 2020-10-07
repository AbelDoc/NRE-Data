    
    /**
     * @file NRE_Main.cpp
     * @brief Test of Data's API
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    #include "Header/NRE_Data.hpp"
    
    using namespace NRE::Data;
    using namespace NRE::Core;
    
    int main(int, char**) {
        JSONParser parser;
        JSONFormatter formatter;
        
        DataBatch data = parser.parse("input.json");
        std::cout << data.getBatch("object").getEntry("entry").getValue() << std::endl;
        data.clear();
        
        DataBatch* shaders = new DataBatch("shaders");
        DataBatch* ssao = new DataBatch("SSAO");
        data.add(shaders);
        shaders->add(ssao);
        ssao->add("enable", "true");
        ssao->add("samples", "16");
        ssao->add("kernel size", "64");
        shaders->add("Shadow", "true");
        shaders->add("Triplanar", "true");
        
        auto enable = shaders->getBatch("SSAO").getEntry("enable").get<bool>();
        auto samples = shaders->getBatch("SSAO").getEntry("samples").get<int>();
        auto kernelSize = shaders->getBatch("SSAO").getEntry("kernel size").get<int>();
        std::cout << "Enabled : " << enable << std::endl;
        std::cout << "Samples : " << samples << std::endl;
        std::cout << "Kernel Size : " << kernelSize << std::endl;
        
        formatter.format(data, "output.json");
        
        return 0;
    }