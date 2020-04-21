    
    /**
     * @file NRE_JSONFormatter.hpp
     * @brief Declaration of Data's API's Object : JSONFormatter
     * @author Louis ABEL
     * @date 21/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once
    
    #include "../NRE_Formatter.hpp"
    
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
             * @class JSONFormatter
             * @brief Describe a JSON formatter
             */
            class JSONFormatter : public Formatter<JSONFormatter> {
                public :    // Methods
                    /**
                     * Format the given data into the given file
                     * @param data the data to format
                     * @param file the output file
                     */
                    void format(DataBatch const& data, IO::File const& file) const {
                        using namespace NRE::IO;
                        
                        OutputFile output(file);
                        output.openEmpty();
                        
                        formatBatch(data, output, "");
                    }
                    /**
                     * Format a given batch and output it into the file
                     * @param batch the batch to format
                     * @param file  the output file
                     * @param tab   improve readability with recursive output
                     */
                    void formatBatch(DataBatch const& batch, IO::OutputFile& file, Utility::String const& tab) const {
                        Utility::String nextTab(tab + "\t");
                        file.write("{\n" + nextTab + "\"");
                        auto toFormat = batch.getSize();
                        for (auto& it : batch) {
                            Data* data = it.second;
                            file.write(data->getName() + "\" : ");
                            if (data->isEntry()) {
                                Entry* entry = static_cast <Entry*> (data);
                                file.write("\"" + entry->getValue() + "\"");
                            } else {
                                DataBatch* subBatch = static_cast <DataBatch*> (data);
                                formatBatch(*subBatch, file, nextTab);
                            }
                            if (toFormat > 1) {
                                file.write(",\n" + nextTab + "\"");
                            } else {
                                file.write("\n" + tab);
                            }
                            toFormat--;
                        }
                        file.write("}");
                    }
            };
        }
    }