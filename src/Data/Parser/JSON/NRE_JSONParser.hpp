    
    /**
     * @file NRE_JSONParser.hpp
     * @brief Declaration of Data's API's Object : JSONParser
     * @author Louis ABEL
     * @date 21/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include <sstream>
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
                        using namespace NRE::IO;
                        using namespace NRE::Utility;
                        using namespace NRE::Exception;
                        DataBatch batch;
    
                        String txt(readFile(file));
                        txt.erase(std::remove_if(txt.begin(), txt.end(), isspace), txt.end());
    
                        if (txt[0] != '{' || txt[txt.getSize() - 1] != '}') {
                            throw ParserException("JSON Format not respected : Main object not contained in braces");
                        }
                        parseObject(txt.substr(1, txt.getSize() - 2), batch);
                        
                        return batch;
                    }
                    /**
                     * Read a whole file and return its content
                     * @param file the file to read
                     * @return     the file's content
                     */
                    Utility::String readFile(IO::File const& file) const {
                        IO::InputFile input(file);
                        input.open();
                        
                        std::stringstream content;
                        content << input.getStream().rdbuf();
                        auto tmp = content.str();
                        return Utility::String(tmp.size(), tmp.data());
                    }
                    /**
                     * Parse a JSON object from the given text
                     * @param txt   the text to parse
                     * @param batch the data to fill
                     */
                    void parseObject(Utility::String const& txt, DataBatch& batch) const {
                        using namespace NRE::Utility;
                        using namespace NRE::Exception;

                        bool stop = false;
                        Utility::String current = txt;
                        
                        while (!stop) {
                            auto size = current.getSize();
                            auto colon = current.find(':', 1);
                            auto name = current.substr(1, colon - 2);
                            auto next = current.substr(colon + 1, size - (colon + 1));
    
                            
                            String::SizeType comma;
                            if (next[0] == '{') {
                                DataBatch* object = new DataBatch(name);
                                auto rBrace = next.find("},");
                                if (rBrace == String::NOT_FOUND) {
                                    rBrace = next.rfind('}', next.getSize() - 1);
                                    if (rBrace == String::NOT_FOUND) {
                                        throw ParserException("JSON Format not respected : Object :" + name + ", not contained in braces");
                                    } else {
                                        comma = next.find(',', rBrace);
                                        if (comma == String::NOT_FOUND) {
                                            stop = true;
                                        }
                                    }
                                } else {
                                    comma = rBrace + 1;
                                }
                                batch.add(object);
                                parseObject(next.substr(1, rBrace - 1), *object);
                            } else {
                                comma = next.find(',');
                                if (comma == String::NOT_FOUND) {
                                    stop = true;
                                    comma = next.getSize();
                                }
                                auto value = next.substr(1, comma - 2);
                                batch.add(name, value);
                            }
                            if (!stop) {
                                current = next.substr(comma + 1, next.getSize() - (comma + 1));
                            }
                        }
                    }
            };
        }
    }