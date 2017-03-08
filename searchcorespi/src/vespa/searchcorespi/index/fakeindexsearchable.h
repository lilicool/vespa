// Copyright 2016 Yahoo Inc. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include "indexsearchable.h"
#include <vespa/searchlib/queryeval/fake_searchable.h>

namespace searchcorespi {

/**
 * A fake index searchable used for unit testing.
 */
class FakeIndexSearchable : public IndexSearchable {
private:
    search::queryeval::FakeSearchable _fake;

public:
    FakeIndexSearchable() : _fake() { }

    search::queryeval::FakeSearchable &getFake() { return _fake; }
    
    /**
     * Implements IndexSearchable
     */
    Blueprint::UP
    createBlueprint(const IRequestContext & requestContext,
                    const FieldSpec &field,
                    const Node &term,
                    const IAttributeContext &) override
    {
        return _fake.createBlueprint(requestContext, field, term);
    }

    search::SearchableStats getSearchableStats() const override {
        return search::SearchableStats();
    }

    virtual search::SerialNum getSerialNum() const override { return 0; }
    virtual void accept(IndexSearchableVisitor &visitor) const override {
        (void) visitor;
    }

};

}  // namespace searchcorespi

