// Copyright 2017 Yahoo Holdings. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#include "integerbucketresultnode.h"
#include <vespa/vespalib/objects/visit.h>

namespace search {
namespace expression {

IMPLEMENT_RESULTNODE(IntegerBucketResultNode, BucketResultNode);

IntegerBucketResultNode IntegerBucketResultNode::_nullResult;

size_t
IntegerBucketResultNode::hash() const
{
    return _from;
}

int
IntegerBucketResultNode::onCmp(const Identifiable & b) const
{
    int64_t f1(_from);
    int64_t f2(static_cast<const IntegerBucketResultNode &>(b)._from);
    if (f1 < f2) {
        return -1;
    } else if (f1 > f2) {
        return 1;
    } else {
        int64_t t1(_to);
        int64_t t2(static_cast<const IntegerBucketResultNode &>(b)._to);
        if (t1 < t2) {
            return -1;
        } else if (t1 > t2) {
            return 1;
        }
    }
    return 0;
}

int IntegerBucketResultNode::contains(const IntegerBucketResultNode & b) const
{
    int64_t diff(_from - b._from);
    if (diff < 0) {
        return (_to < b._to) ? -1 : 0;
    } else {
        return (_to > b._to) ? 1 : 0;
    }
}

void
IntegerBucketResultNode::visitMembers(vespalib::ObjectVisitor &visitor) const
{
    visit(visitor, _fromField.getName(), _from);
    visit(visitor, _toField.getName(), _to);
}

vespalib::Serializer &
IntegerBucketResultNode::onSerialize(vespalib::Serializer & os) const
{
    return os.put(_fromField, _from).put(_toField, _to);
}

vespalib::Deserializer &
IntegerBucketResultNode::onDeserialize(vespalib::Deserializer & is)
{
    return is.get(_fromField, _from).get(_toField, _to);
}

}
}

// this function was added by ../../forcelink.sh
void forcelink_file_searchlib_expression_integerbucketresultnode() {}
