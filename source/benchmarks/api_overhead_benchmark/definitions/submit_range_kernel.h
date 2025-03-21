/*
 * Copyright (C) 2022-2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "framework/argument/basic_argument.h"
#include "framework/test_case/test_case.h"

struct SubmitRangeKernelArguments : TestCaseArgumentContainer {
    BooleanArgument useProfiling;
    BooleanArgument inOrderQueue;
    BooleanArgument useEnqueueFunctions;
    BooleanArgument discardEvents;
    PositiveIntegerArgument numKernels;
    PositiveIntegerArgument kernelExecutionTime;
    BooleanArgument measureCompletionTime;

    SubmitRangeKernelArguments()
        : useProfiling(*this, "Profiling", "Create the queue with the enable_profiling property"),
          inOrderQueue(*this, "Ioq", "Create the queue with the in_order property"),
          useEnqueueFunctions(*this, "EnqueueFunctions", "Use the eventless SYCL enqueue functions"),
          discardEvents(*this, "DiscardEvents", "Create the queue with the discard_events property"),
          numKernels(*this, "NumKernels", "Number of kernels to submit to the queue"),
          kernelExecutionTime(*this, "KernelExecTime", "Approximately how long a single kernel executes, in us"),
          measureCompletionTime(*this, "MeasureCompletion", "Measures time taken to complete the submission (default is to measure only submit calls)") {}
};

struct SubmitRangeKernel : TestCase<SubmitRangeKernelArguments> {
    using TestCase<SubmitRangeKernelArguments>::TestCase;

    std::string getTestCaseName() const override {
        return "SubmitRangeKernel";
    }

    std::string getHelp() const override {
        return "measures time spent in submitting a kernel using a range to a SYCL (or SYCL-like) queue on CPU.";
    }
};
