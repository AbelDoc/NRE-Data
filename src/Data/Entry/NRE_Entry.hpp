    
    /**
     * @file NRE_Entry.hpp
     * @brief Declaration of Data's API's Object : Entry
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once

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
            };
        
        }
    }
    
    #include "NRE_Entry.tpp"