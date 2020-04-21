    
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
            
            inline typename DataBatch::SizeType DataBatch::getSize() const {
                return datas.getSize();
            }
            
            inline typename DataBatch::Iterator DataBatch::begin() {
                return datas.begin();
            }
    
            inline typename DataBatch::ConstIterator DataBatch::begin() const {
                return datas.begin();
            }
    
            inline typename DataBatch::ConstIterator DataBatch::cbegin() const {
                return datas.cbegin();
            }
    
            inline typename DataBatch::Iterator DataBatch::end() {
                return datas.end();
            }
    
            inline typename DataBatch::ConstIterator DataBatch::end() const {
                return datas.end();
            }
    
            inline typename DataBatch::ConstIterator DataBatch::cend() const {
                return datas.cend();
            }
    
            inline void DataBatch::addData(MappedType data) {
                datas.emplace(ValueType(data->getName(), data));
            }
            
        }
    }