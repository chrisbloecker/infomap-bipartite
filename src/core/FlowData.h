/*
 * FlowData.h
 */

#ifndef SRC_CLUSTERING_FLOWDATA_H_
#define SRC_CLUSTERING_FLOWDATA_H_

#include <ostream>
#include "Pair.h"

namespace infomap {


struct FlowData
{
	std::pair<double, double> flow;
	std::pair<double, double> enterFlow;
	std::pair<double, double> exitFlow;

	FlowData(std::pair<double, double> flow = { 1.0, 1.0 }, std::pair<double, double> enterFlow = { 0.0, 0.0 }, std::pair<double, double> exitFlow = { 0.0, 0.0 }) :
		flow(flow),
		enterFlow(enterFlow),
		exitFlow(exitFlow)
	{}
	FlowData(const FlowData& other) :
		flow(other.flow),
		enterFlow(other.enterFlow),
		exitFlow(other.exitFlow)
	{}
	FlowData& operator=(const FlowData& other)
	{
		flow = other.flow;
		enterFlow = other.enterFlow;
		exitFlow = other.exitFlow;
		return *this;
	}

	FlowData& operator+=(const FlowData& other)
	{
		flow += other.flow;
		enterFlow += other.enterFlow;
		exitFlow += other.exitFlow;
		return *this;
	}

	FlowData& operator-=(const FlowData& other)
	{
		flow -= other.flow;
		enterFlow -= other.enterFlow;
		exitFlow -= other.exitFlow;
		return *this;
	}

	void resetFlow() { flow = { 0.0, 0.0 }; }
	void setFlow(std::pair<double, double> f) { flow = f; }
	void addFlow(std::pair<double, double> f) { flow += f; }
	void setEnterFlow(std::pair<double, double> f) { enterFlow = f; }
	void setExitFlow(std::pair<double, double> f) { exitFlow = f; }
	void addEnterFlow(std::pair<double, double> f) { enterFlow += f; }
	void addExitFlow(std::pair<double, double> f) { exitFlow += f; }
	std::pair<double, double> getFlow() const { return flow; }
	std::pair<double, double> getEnterFlow() const { return enterFlow; }
	std::pair<double, double> getExitFlow() const { return exitFlow; }
	FlowData getFlowData() const { return *this; }

	friend std::ostream& operator<<(std::ostream& out, const FlowData& data)
	{
		return out << "flow: (" << data.flow.first << ", " << data.flow.second << "), enter: (" << data.enterFlow.first << ", " << data.enterFlow.second << "), exit: (" << data.exitFlow.first << ", " << data.exitFlow.second << ")";
	}
};


struct DeltaFlow
{
	unsigned int module = 0;
	std::pair<double, double> deltaExit = { 0.0, 0.0 };
	std::pair<double, double> deltaEnter = { 0.0, 0.0 };
	unsigned int count = 0;

	virtual ~DeltaFlow() = default;

	DeltaFlow() {}

	explicit DeltaFlow(unsigned int module, std::pair<double, double> deltaExit, std::pair<double, double> deltaEnter)
	:	module(module),
		deltaExit(deltaExit),
		deltaEnter(deltaEnter),
		count(0) {}

	DeltaFlow(const DeltaFlow&) = default;
    DeltaFlow& operator=(const DeltaFlow&) = default;
    DeltaFlow(DeltaFlow&&) = default;
    DeltaFlow& operator=(DeltaFlow&&) = default;

	DeltaFlow& operator+=(const DeltaFlow& other)
	{
		module = other.module;
		deltaExit += other.deltaExit;
		deltaEnter += other.deltaEnter;
		++count;
		return *this;
	}

	void reset()
	{
		module = 0;
		deltaExit = { 0.0, 0.0 };
		deltaEnter = { 0.0, 0.0 };
		count = 0;
	}

	friend void swap(DeltaFlow& first, DeltaFlow& second)
	{
		std::swap(first.module, second.module);
		std::swap(first.deltaExit, second.deltaExit);
		std::swap(first.deltaEnter, second.deltaEnter);
		std::swap(first.count, second.count);
	}

	friend std::ostream& operator<<(std::ostream& out, const DeltaFlow& data)
	{
		return out << "module: " << data.module << ", deltaEnter: (" << data.deltaEnter.first << ", " << data.deltaEnter.second << "), deltaExit: (" << data.deltaExit.first << ", " << data.deltaExit.second << "), count: " << data.count;
	}
};


struct MemDeltaFlow : DeltaFlow
{
	std::pair<double, double> sumDeltaPlogpPhysFlow = { 0.0, 0.0 };
	std::pair<double, double> sumPlogpPhysFlow = { 0.0, 0.0 };
	
	MemDeltaFlow() : DeltaFlow() {}

	explicit MemDeltaFlow(unsigned int module, std::pair<double, double> deltaExit, std::pair<double, double> deltaEnter, std::pair<double, double> sumDeltaPlogpPhysFlow = { 0.0, 0.0 }, std::pair<double, double> sumPlogpPhysFlow = { 0.0, 0.0 })
	:	DeltaFlow(module, deltaExit, deltaEnter),
		sumDeltaPlogpPhysFlow(sumDeltaPlogpPhysFlow),
		sumPlogpPhysFlow(sumPlogpPhysFlow) {}

	MemDeltaFlow& operator+=(const MemDeltaFlow& other)
	{
		DeltaFlow::operator+=(other);
		sumDeltaPlogpPhysFlow += other.sumDeltaPlogpPhysFlow;
		sumPlogpPhysFlow += other.sumPlogpPhysFlow;
		return *this;
	}

	void reset()
	{
		DeltaFlow::reset();
		sumDeltaPlogpPhysFlow = { 0.0, 0.0 };
		sumPlogpPhysFlow = { 0.0, 0.0 };
	}

	friend void swap(MemDeltaFlow& first, MemDeltaFlow& second)
	{
        swap(static_cast<DeltaFlow&>(first), static_cast<DeltaFlow&>(second));
		std::swap(first.sumDeltaPlogpPhysFlow, second.sumDeltaPlogpPhysFlow);
		std::swap(first.sumPlogpPhysFlow, second.sumPlogpPhysFlow);
	}

	friend std::ostream& operator<<(std::ostream& out, const MemDeltaFlow& data)
	{
		return out << "module: " << data.module << ", deltaEnter: (" << data.deltaEnter.first << ", " << data.deltaEnter.second <<
		"), deltaExit: (" << data.deltaExit.first << ", " << data.deltaExit.second << "), count: " << data.count <<
		", sumDeltaPlogpPhysFlow: (" << data.sumDeltaPlogpPhysFlow.first << ", " << data.sumDeltaPlogpPhysFlow.second <<
		"), sumPlogpPhysFlow: (" << data.sumPlogpPhysFlow.first << ", " << data.sumPlogpPhysFlow.second << ")";
	}
};


struct PhysData
{
	PhysData(unsigned int physNodeIndex, std::pair<double, double> sumFlowFromM2Node = { 0.0, 0.0 })
	: physNodeIndex(physNodeIndex), sumFlowFromM2Node(sumFlowFromM2Node)
	{}
	PhysData(const PhysData& other) : physNodeIndex(other.physNodeIndex), sumFlowFromM2Node(other.sumFlowFromM2Node) {}
	unsigned int physNodeIndex;
	std::pair<double, double> sumFlowFromM2Node; // The amount of flow from the memory node in this physical node
	
	friend std::ostream& operator<<(std::ostream& out, const PhysData& data)
	{
		return out << "physNodeIndex: " << data.physNodeIndex <<
		", sumFlowFromM2Node: (" << data.sumFlowFromM2Node.first << ", " << data.sumFlowFromM2Node.second << ")";
	}
};


}



#endif /* SRC_CLUSTERING_FLOWDATA_H_ */
