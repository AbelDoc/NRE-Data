    
    /**
     * @file NRE_DataBatch.tpp
     * @brief Implementation of Data's API's Object : DataBatch
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    namespace NRE {
        namespace Data {
            
            inline Data::Data(Utility::String const& n) : name(n) {
            }
            
            inline Utility::String const& Data::getName() const {
                return name;
            }
            
        }
    }