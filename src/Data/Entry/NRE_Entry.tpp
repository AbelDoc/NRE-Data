    
    /**
     * @file NRE_Entry.tpp
     * @brief Implementation of Data's API's Object : Entry
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    namespace NRE {
        namespace Data {
            
            inline Entry::Entry(Core::String const& n, Core::String const& v) : Data(n), value(v) {
            }
            
            inline Core::String const& Entry::getValue() const {
                return value;
            }
            
            inline bool Entry::isEntry() const {
                return true;
            }
            
            template <>
            inline short int Entry::get() const {
                std::stringstream parser;
                parser << value;
                short int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline int Entry::get() const {
                std::stringstream parser;
                parser << value;
                int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline long int Entry::get() const {
                std::stringstream parser;
                parser << value;
                long int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline long long int Entry::get() const {
                std::stringstream parser;
                parser << value;
                long long int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline unsigned short int Entry::get() const {
                std::stringstream parser;
                parser << value;
                unsigned short int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline unsigned int Entry::get() const {
                std::stringstream parser;
                parser << value;
                unsigned int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline unsigned long int Entry::get() const {
                std::stringstream parser;
                parser << value;
                unsigned long int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline unsigned long long int Entry::get() const {
                std::stringstream parser;
                parser << value;
                unsigned long long int res;
                parser >> res;
                return res;
            }
    
            template <>
            inline float Entry::get() const {
                std::stringstream parser;
                parser << value;
                float res;
                parser >> res;
                return res;
            }
    
            template <>
            inline double Entry::get() const {
                std::stringstream parser;
                parser << value;
                double res;
                parser >> res;
                return res;
            }
    
            template <>
            inline long double Entry::get() const {
                std::stringstream parser;
                parser << value;
                long double res;
                parser >> res;
                return res;
            }
            
            template <>
            inline bool Entry::get() const {
                return value != "false" || value != "0";
                
            }
            
            template <class T>
            inline T Entry::get() const {
                return T(value);
            }
            
        }
    }