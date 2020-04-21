    
    /**
     * @file NRE_Entry.hpp
     * @brief Declaration of Data's API's Object : Entry
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include <sstream>
    #include "../Data/NRE_Data.hpp"
    
    /**
     * @namespace NRE
     * @brief The NearlyRealEngine's global namespace
     */
    namespace NRE {
        /**
         * @namespace Data
         * @brief Data's API
         */
        namespace Data {
        
            /**
             * @class Entry
             * @brief Manage one data value
             */
            class Entry : public Data {
                private :    // Fields
                    Utility::String value;  /**< The entry value */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct an entry
                         * @param n the entry's name
                         * @param v the entry's value
                         */
                        Entry(Utility::String const& n, Utility::String const& v);
    
                    //## Getter ##//
                        /**
                         * @return the entry's value
                         */
                        Utility::String const& getValue() const;
                        /**
                         * @return if the data is an entry
                         */
                        bool isEntry() const override;
                        /**
                         * @return a new variable created from the entry value
                         */
                        template <class T>
                        T get() const;
            };
        
        }
    }
    
    #include "NRE_Entry.tpp"