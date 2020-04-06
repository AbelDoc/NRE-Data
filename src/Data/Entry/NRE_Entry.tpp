    
    /**
     * @file NRE_Entry.tpp
     * @brief Implementation of Data's API's Object : Entry
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    namespace NRE {
        namespace Data {
            
            inline Entry::Entry(Utility::String const& n, Utility::String const& v) : Data(n), value(v) {
            }
            
        }
    }