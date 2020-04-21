    
    /**
     * @file NRE_Data.hpp
     * @brief Declaration of Data's API's Object : Data
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include <Header/NRE_Utility.hpp>
    
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
             * @class Data
             * @brief Represent an abstract data
             */
            class Data {
                protected : // Fields
                    Utility::String name;   /**< The entry name */

                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct a data
                         * @param n the data's name
                         */
                        Data(Utility::String const& n);
    
                    //## Deconstructor ##//
                        /**
                         * Data Deconstructor
                         */
                        virtual ~Data() = default;
    
                    //## Getter ##//
                        /**
                         * @return the data's name
                         */
                        Utility::String const& getName() const;
            };
        
        }
    }

    #include "NRE_Data.tpp"