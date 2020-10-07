    
    /**
     * @file NRE_DataBatch.hpp
     * @brief Declaration of Data's API's Object : DataBatch
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once

    #include "../Entry/NRE_Entry.hpp"

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
             * @class DataBatch
             * @brief Manage a group of data
             */
            class DataBatch : public Data {
                public :    // Traits
                    /** The container's mapped type */
                    using MappedType            = Data*;
                    /** The container's key type */
                    using KeyType               = Core::String;
                    /** The container's allocated type */
                    using ValueType             = Core::Pair<KeyType, MappedType>;
                    /** The internal container */
                    using Container             = Core::UnorderedMap<KeyType, MappedType>;
                    /** The object's size type */
                    using SizeType              = std::size_t;
                    /** The object's difference type */
                    using DifferenceType        = std::ptrdiff_t;
                    /** The allocated type reference */
                    using Reference             = ValueType&;
                    /** The allocated type const reference */
                    using ConstReference        = ValueType const&;
                    /** The allocated type pointer */
                    using Pointer               = ValueType*;
                    /** The allocated type const pointer */
                    using ConstPointer          = const ValueType*;
                    /** Mutable random access iterator */
                    using Iterator              = typename Container::Iterator;
                    /** Immuable random access iterator */
                    using ConstIterator         = typename Container::ConstIterator;
                    /** STL compatibility */
                    using value_type            = ValueType;
                    /** STL compatibility */
                    using size_type             = SizeType;
                    /** STL compatibility */
                    using difference_type       = DifferenceType;
                    /** STL compatibility */
                    using reference             = Reference;
                    /** STL compatibility */
                    using const_reference       = ConstReference;
                    /** STL compatibility */
                    using pointer               = Pointer;
                    /** STL compatibility */
                    using const_pointer         = ConstPointer;
                    /** STL compatibility */
                    using iterator              = Iterator;
                    /** STL compatibility */
                    using const_iterator        = ConstIterator;
                    
                private :   // Fields
                    Container datas;        /**< The internal data batch */
                    
                public :    // Methods
                    //## Constructor ##//
                        /**
                         * Construct an empty data batch
                         * @param n the batch's name
                         */
                        DataBatch(Core::String const& n = "");
                        
                    //## Copy Constructor ##//
                        /**
                         * Copy batch into this
                         * @param batch the data batch to copy
                         */
                        DataBatch(DataBatch const& batch) = default;
        
                    //## Move Constructor ##//
                        /**
                         * Move batch into this
                         * @param batch the data batch to move
                         */
                        DataBatch(DataBatch && batch) = default;
    
                    //## Deconstructor ##//
                        /**
                         * DataBatch Deconstructor
                         */
                        ~DataBatch();
    
                    //## Getter ##//
                        /**
                         * Access a particular element with bound checking
                         * @param  k the element key
                         * @return   the corresponding element
                         */
                        MappedType& get(KeyType const& k);
                        /**
                         * Access a particular element with bound checking
                         * @param  k the element key
                         * @return   the corresponding element
                         */
                        MappedType const& get(KeyType const& k) const;
                        /**
                         * Access a particular batch with bound checking (and try a cast on it)
                         * @param k the element key
                         * @return  the casted data batch
                         */
                        DataBatch& getBatch(KeyType const& k);
                        /**
                         * Access a particular batch with bound checking (and try a cast on it)
                         * @param k the element key
                         * @return  the casted data batch
                         */
                        DataBatch const& getBatch(KeyType const& k) const;
                        /**
                         * Access a particular entry with bound checking (and try a cast on it)
                         * @param k the element key
                         * @return  the casted data entry
                         */
                        Entry& getEntry(KeyType const& k);
                        /**
                         * Access a particular entry with bound checking (and try a cast on it)
                         * @param k the element key
                         * @return  the casted data entry
                         */
                        Entry const& getEntry(KeyType const& k) const;
                        /**
                         * @return if the batch is empty
                         */
                        bool isEmpty() const;
                        /**
                         * @return the number of entry in the batch
                         */
                        SizeType getSize() const;
    
                    //## Iterator Access ##//
                        /**
                         * @return an iterator on the first element
                         */
                        Iterator begin();
                        /**
                         * @return a const iterator on the first element
                         */
                        ConstIterator begin() const;
                        /**
                         * @return a const iterator on the first element
                         */
                        ConstIterator cbegin() const;
                        /**
                         * @return an iterator on the end of the container
                         */
                        Iterator end();
                        /**
                         * @return a const iterator on the end of the container
                         */
                        ConstIterator end() const;
                        /**
                         * @return a const iterator on the end of the container
                         */
                        ConstIterator cend() const;
    
                    //## Methods ##//
                        /**
                         * Add a data into the batch
                         * @param data the data to add
                         */
                        void add(MappedType data);
                        /**
                         * Create and add an entry to the data batch
                         * @param eName  the entry's name
                         * @param eValue the entry's value
                         */
                        void add(Core::String const& eName, Core::String const& eValue);
                        /**
                         * Clear the data batch
                         */
                        void clear();
    
                    //## Assignment Operator ##//
                        /**
                         * Copy batch into this
                         * @param batch the data batch to copy into this
                         * @return      the reference of himself
                         */
                        DataBatch& operator =(DataBatch const& batch);
                        /**
                         * Move batch into this
                         * @param batch the data batch to move into this
                         * @return      the reference of himself
                         */
                        DataBatch& operator =(DataBatch && batch);
            
                    //## Access Operator ##//
                        /**
                         * Try to access the element designed by the given key, if not found insert a default one
                         * @param  k the key used for access
                         * @return   the found/inserted element
                         */
                        MappedType& operator[](KeyType const& k);
                        /**
                         * Try to access the element designed by the given key, if not found insert a default one
                         * @param  k the key used for access
                         * @return   the found/inserted element
                         */
                        MappedType& operator[](KeyType && k);
            };
        }
    }

    #include "NRE_DataBatch.tpp"