    
    /**
     * @file NRE_DataBatch.tpp
     * @brief Implementation of Data's API's Object : DataBatch
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
     
    namespace NRE {
        namespace Data {
            
            inline DataBatch::DataBatch(Utility::String const& n) : Data(n) {
            }
            
            inline DataBatch::~DataBatch() {
                for (auto& it : datas) {
                    delete it.second;
                }
            }
            
            inline void DataBatch::addData(MappedType data) {
                datas.emplace(ValueType(data->getName(), data));
            }
            
        }
    }