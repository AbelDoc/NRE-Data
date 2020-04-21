    
    /**
     * @file NRE_JSONParser.hpp
     * @brief Declaration of Data's API's Object : JSONParser
     * @author Louis ABEL
     * @date 21/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include "../NRE_Parser.hpp"
    
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
             * @class JSONParser
             * @brief Describe a JSON parser
             */
            class JSONParser : public Parser<JSONParser> {
                public :    // Methods
                    /**
                     * Parse the given file and return a data batch from it
                     * @param file the file to parse
                     * @return     the parsed data batch
                     */
                    DataBatch parse(IO::File const& file) const {
                        IO::InputFile input(file);
                        if (input.isOpen()) {
                            // Parse
                        } else {
                            throw Exception::ParserException("File can't be opened : " + file.getPath());
                        }
                    }
            };
        }
    }