    
    /**
     * @file NRE_Formatter.hpp
     * @brief Declaration of Data's API's Object : Formatter
     * @author Louis ABEL
     * @date 21/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include <Header/NRE_IO.hpp>
    #include "../Batch/NRE_DataBatch.hpp"
    
    
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
             * @class Formatter
             * @brief Describe an abstract formatter
             */
            template <class T>
            class Formatter : public Utility::StaticInterface<Formatter<T>> {
                public :    // Methods
                    /**
                     * Format the given data into the given file
                     * @param data the data to format
                     * @param file the output file
                     */
                    void format(DataBatch const& data, IO::File const& file) const {
                        return this->impl().format(data, file);
                    }
            };
        }
    }