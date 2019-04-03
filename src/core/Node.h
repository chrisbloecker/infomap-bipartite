#ifndef INFO_NODE_WITH_DATA_H_
#define INFO_NODE_WITH_DATA_H_

#include "NodeBase.h"
#include "FlowData.h"

namespace infomap {

template<typename FlowDataType>
class Node : public NodeBase
{
public:

	using NodeBaseType = Node<FlowDataType>;

	FlowDataType data;

	Node() : NodeBase() {};

	Node(const FlowDataType& flowData)
	: NodeBase(), data(flowData) {};

	// For first order nodes, physicalId equals stateId
	Node(const FlowDataType& flowData, unsigned int stateId)
	: NodeBase(stateId, stateId), data(flowData) {};

	Node(const FlowDataType& flowData, unsigned int stateId, unsigned int physicalId)
	: NodeBase(stateId, physicalId), data(flowData) {};

	Node(const FlowDataType& flowData, unsigned int stateId, unsigned int physicalId, unsigned int layerId)
	: NodeBase(stateId, physicalId, layerId), data(flowData) {};

	Node(const Node& other)
	:	NodeBase(other), data(other.data)
	{}


	virtual ~Node() {}
	
	Node& operator=(const Node& other)
	{
		NodeBase::operator=(other);
		data = other.data;
		return *this;
	}

	// ---------------------------- Data ----------------------------

	NodeBaseType& getNode(NodeBase& other) {
		return static_cast<NodeBaseType&>(other);
	}

	virtual void copyData(NodeBase& other) {
		data = getNode(other).data;
	}

	virtual void resetFlow() {
		data.resetFlow();
	}	
	virtual void setFlow(std::pair<double, double> flow) {
		data.setFlow(flow);
	}
	virtual void addFlow(std::pair<double, double> flow) {
		data.addFlow(flow);
	}
	virtual void setEnterFlow(std::pair<double, double> flow) {
		data.setEnterFlow(flow);
	}
	virtual void setExitFlow(std::pair<double, double> flow) {
		data.setExitFlow(flow);
	}
	virtual void addEnterFlow(std::pair<double, double> flow) {
		data.addEnterFlow(flow);
	}
	virtual void addExitFlow(std::pair<double, double> flow) {
		data.addExitFlow(flow);
	}
	virtual std::pair<double, double> getFlow() const {
		return data.getFlow();
	}
	virtual std::pair<double, double> getEnterFlow() const {
		return data.getEnterFlow();
	}
	virtual std::pair<double, double> getExitFlow() const {
		return data.getExitFlow();
	}

	virtual FlowData getFlowData() const {
		return data.getFlowData();
	};

};

}

#endif /* INFO_NODE_WITH_DATA_H_ */
