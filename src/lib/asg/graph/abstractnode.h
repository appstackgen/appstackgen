/*
 * This file is part of Project 'appstackgen'.
 *
 * Copyright (c) 2015, Johannes Lochmann
 *
 * All rights reserved.
 */

#pragma once

#include <asg/graph/graphfragment.h>

#include <asg/graph/abstractnode.h>

namespace asg {
namespace graph {

class AbstractGraph;
class abstract_edge;

using abstract_edge_sptr = std::shared_ptr<abstract_edge>;
using AbstractEdgeSPtrVector = std::vector<abstract_edge_sptr>;

class abstract_node: public GraphFragment
{
public:
    using GraphFragment::GraphFragment;

    string nodeTypeName() const { return implNodeTypeName(); }
    object_name name() const { return implName(); }

    void registerOutEdge(abstract_edge_sptr e) { implRegisterOutEdge(e); }
    void registerInEdge(abstract_edge_sptr e) { implRegisterInEdge(e); }

    template<typename T=abstract_edge>
    size countInEdges() const {
        return typedInEdges<T>().size();
    }

    template<typename T=abstract_edge>
    size countOutEdges() const {
        return typedOutEdges<T>().size();
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    bool hasUniqueInEdgeFrom() const {
        return ((size)1 == typedInEdgesFrom<EdgeT, NodeT>().size());
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    std::shared_ptr<NodeT> startNodeOfUniqueInEdgeFrom() const {
        return *(typedInEdgesFrom<EdgeT, NodeT>().begin());
    }

    template<typename T>
    bool hasUniqueInEdge() const {
        return ((size)1 == typedInEdges<T>().size());
    }

    template<typename T>
    std::shared_ptr<T> uniqueInEdge() const {
        assert(hasUniqueInEdge<T>());
        return *(typedInEdges<T>().begin());
    }

    template<typename EdgeT, typename NodeT=abstract_node>
    std::shared_ptr<NodeT> startNodeOfUniqueInEdge() const {
        assert(hasUniqueInEdge<EdgeT>());

        auto n = uniqueInEdge<EdgeT>()->template start<NodeT>();

        assert(std::shared_ptr<NodeT>() != n);

        return n;
    }

    template<typename T=abstract_edge>
    std::vector<std::shared_ptr<T>> typedOutEdges() const {
        std::vector<std::shared_ptr<T>> buf;

        for (auto e : outEdges()) {
            auto ee = std::dynamic_pointer_cast<T>(e);

            if (ee) {
                buf.push_back(ee);
            }
        }

        return buf;
    }

    template<typename T=abstract_edge>
    std::vector<std::shared_ptr<T>> typedInEdges() const {
        std::vector<std::shared_ptr<T>> buf;

        for (auto e : inEdges()) {
            auto ee = std::dynamic_pointer_cast<T>(e);

            if (ee) {
                buf.push_back(ee);
            }
        }

        return buf;
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    std::vector<std::shared_ptr<EdgeT>> typedOutEdgesTo() const {
        std::vector<std::shared_ptr<EdgeT>> buf;

        for (auto e : typedOutEdges<EdgeT>()) {
            auto n = std::dynamic_pointer_cast<NodeT>(e->end());

            if (n) {
                buf.push_back(e);
            }
        }

        return buf;
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    std::vector<std::shared_ptr<EdgeT>> typedInEdgesFrom() const {
        std::vector<std::shared_ptr<EdgeT>> buf;

        for (auto e : typedInEdges<EdgeT>()) {
            auto n = std::dynamic_pointer_cast<NodeT>(e->start());

            if (n) {
                buf.push_back(e);
            }
        }

        return buf;
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    std::vector<std::shared_ptr<NodeT>> endNodesOfTypedOutEdgesTo() const {
        std::vector<std::shared_ptr<NodeT>> buf;

        for (auto e : typedOutEdgesTo<EdgeT, NodeT>()) {
            buf.push_back(std::dynamic_pointer_cast<NodeT>(e->end()));
        }

        return buf;
    }

    template<typename EdgeT=abstract_edge, typename NodeT=abstract_node>
    std::vector<std::shared_ptr<NodeT>> startNodesOfTypedInEdgesFrom() const {
        std::vector<std::shared_ptr<NodeT>> buf;

        for (auto e : typedInEdgesFrom<EdgeT, NodeT>()) {
            buf.push_back(std::dynamic_pointer_cast<NodeT>(e->start()));
        }

        return buf;
    }

    AbstractEdgeSPtrVector outEdges() const { return implOutEdges(); }
    AbstractEdgeSPtrVector inEdges() const { return implInEdges(); }

    AbstractEdgeSPtrVector edges() const { return implEdges(); }

    size outEdgeCount() const { return implOutEdgeCount(); }
    size inEdgeCount() const { return implInEdgeCount(); }
    size edgeCount() { return edgeCount(); }

protected:
    virtual void implRegisterOutEdge(abstract_edge_sptr e) = 0;
    virtual void implRegisterInEdge(abstract_edge_sptr e) = 0;

    virtual AbstractEdgeSPtrVector implOutEdges() const = 0;
    virtual AbstractEdgeSPtrVector implInEdges() const = 0;
    virtual AbstractEdgeSPtrVector implEdges() const = 0;

    virtual size implOutEdgeCount() const = 0;
    virtual size implInEdgeCount() const = 0;
    virtual size implEdgeCount() const = 0;

    virtual string implNodeTypeName() const = 0;
    virtual object_name implName() const = 0;

    string impl_to_string() const override;
};

}
}
