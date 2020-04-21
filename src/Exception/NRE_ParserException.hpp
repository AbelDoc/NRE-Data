    
    /**
     * @file NRE_ParserException.hpp
     * @brief Declaration of System's API's Object : ParserException
     * @author Louis ABEL
     * @date 21/04/2020
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
         * @namespace Exception
         * @brief Utility's API
         */
        namespace Exception {
            
            /**
             * @class ParserException
             * @brief An exception thrown by parsing operation
             */
            class ParserException : public IException {
                public:
                    /**
                     * Construct the exception with a custom log
                     * @param log the exception's log
                     */
                    ParserException(Utility::String const& log) throw() : IException(log) {
                    }
            };
        }
    }
