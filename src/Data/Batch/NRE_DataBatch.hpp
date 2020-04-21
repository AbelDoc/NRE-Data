    
    /**
     * @file NRE_DataBatch.hpp
     * @brief Declaration of Data's API's Object : DataBatch
     * @author Louis ABEL
     * @date 06/04/2020
     * @copyright CC-BY-NC-SA
     */
    
    #pragma once

    #include "../Data/NRE_Data.hpp"

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
                    using KeyType               = Utility::String;
                    /** The container's allocated type */
                    using ValueType             = Utility::Pair<KeyType, MappedType>;
                    /** The internal container */
                    using Container             = Utility::UnorderedMap<KeyType, MappedType>;
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
                    using ConstIterator         = typename Container::ConstPointer;
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
                        DataBatch(Utility::String const& n = "");
    
                    //## Deconstructor ##//
                        /**
                         * DataBatch Deconstructor
                         */
                        ~DataBatch();
    
                    //## Methods ##//
                        /**
                         * Add a data into the batch
                         * @param data the data to add
                         */
                        void addData(MappedType data);
            };
        }
    }

    #include "NRE_DataBatch.tpp"