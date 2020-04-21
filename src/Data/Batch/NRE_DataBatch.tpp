    
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
                clear();
            }
            
            inline typename DataBatch::MappedType& DataBatch::get(KeyType const& k) {
                return datas.get(k);
            }
    
            inline typename DataBatch::MappedType const& DataBatch::get(KeyType const& k) const {
                return datas.get(k);
            }
    
            inline DataBatch& DataBatch::getBatch(KeyType const& k) {
                return *static_cast <DataBatch*> (datas.get(k));
            }
    
            inline DataBatch const& DataBatch::getBatch(KeyType const& k) const {
                return *static_cast <const DataBatch*> (datas.get(k));
            }
            
            inline Entry& DataBatch::getEntry(KeyType const& k) {
                return *static_cast <Entry*> (datas.get(k));
            }
    
            inline Entry const& DataBatch::getEntry(KeyType const& k) const {
                return *static_cast <const Entry*> (datas.get(k));
            }
            
            inline bool DataBatch::isEmpty() const {
                return datas.isEmpty();
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
    
            inline void DataBatch::emplaceEntry(Utility::String const& eName, Utility::String const& eValue) {
                datas.emplace(ValueType(eName, new Entry(eName, eValue)));
            }
            
            inline void DataBatch::clear() {
                for (auto& it : datas) {
                    delete it.second;
                }
                datas.clear();
            }
            
            inline DataBatch& DataBatch::operator=(DataBatch const& batch) {
                if (this != &batch) {
                    clear();
                    datas = batch.datas;
                }
                return *this;
            }
            
            inline DataBatch& DataBatch::operator=(DataBatch && batch) {
                if (this != &batch) {
                    clear();
                    datas = std::move(batch.datas);
                }
                return *this;
            }
    
            inline typename DataBatch::MappedType& DataBatch::operator[](KeyType const& k) {
                return datas[k];
            }
    
            inline typename DataBatch::MappedType& DataBatch::operator[](KeyType && k) {
                return datas[std::move(k)];
            }
            
        }
    }