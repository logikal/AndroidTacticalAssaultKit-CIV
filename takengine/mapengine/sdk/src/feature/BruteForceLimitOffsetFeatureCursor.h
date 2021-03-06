#ifndef TAK_ENGINE_FEATURE_BRUTEFORCELIMITOFFSETFEATURECURSOR_H_INCLUDED
#define TAK_ENGINE_FEATURE_BRUTEFORCELIMITOFFSETFEATURECURSOR_H_INCLUDED

#include <set>

#include "feature/FeatureCursor2.h"
#include "feature/FeatureDataStore2.h"

namespace TAK {
    namespace Engine {
        namespace Feature {
            class ENGINE_API BruteForceLimitOffsetFeatureCursor : public FeatureCursor2
            {
            public:
                BruteForceLimitOffsetFeatureCursor(FeatureCursorPtr &&filter, std::size_t limit, std::size_t offset) NOTHROWS;
            public: // FeatureCursor2
                virtual Util::TAKErr getId(int64_t *value) NOTHROWS;
                virtual Util::TAKErr getFeatureSetId(int64_t *value) NOTHROWS;
                virtual Util::TAKErr getVersion(int64_t *value) NOTHROWS;
            public: // FeatureDefinition2
                virtual Util::TAKErr getRawGeometry(FeatureDefinition2::RawData *value) NOTHROWS;
                virtual FeatureDefinition2::GeometryEncoding getGeomCoding() NOTHROWS;
                virtual Util::TAKErr getName(const char **value) NOTHROWS;
                virtual FeatureDefinition2::StyleEncoding getStyleCoding() NOTHROWS;
                virtual Util::TAKErr getRawStyle(FeatureDefinition2::RawData *value) NOTHROWS;
                virtual Util::TAKErr getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS;
                virtual Util::TAKErr get(const Feature2 **feature) NOTHROWS;
            public: // RowIterator
                virtual Util::TAKErr moveToNext() NOTHROWS;
            private:
                FeatureCursorPtr filter;
                std::size_t limit;
                std::size_t offset;
                std::size_t pos;
            };
        }
    }
}

#endif
