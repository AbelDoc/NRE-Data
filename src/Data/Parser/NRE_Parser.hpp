    
    /**
     * @file NRE_Parser.hpp
     * @brief Declaration of Data's API's Object : Parser
     * @author Louis ABEL
     * @date 21/04/2020
     * @copyright CC-BY-NC-SA
     */

    #pragma once

    #include <Header/NRE_IO.hpp>
    #include "../Batch/NRE_DataBatch.hpp"
    #include "../../Header/NRE_Exception.hpp"


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
             * @class Parser
             * @brief Describe an abstract parser
             */
            template <class T>
            class Parser : public Utility::StaticInterface<Parser<T>> {
                public :    // Methods
                    /**
                     * Parse the given file and return a data batch from it
                     * @param file the file to parse
                     * @return     the parsed data batch
                     */
                    DataBatch parse(IO::File const& file) const {
                        return this->impl().parse(file);
                    }
            };
        }
    }