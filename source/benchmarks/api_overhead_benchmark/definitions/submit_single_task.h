/*
 * Copyright (C) 2022-2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "framework/argument/basic_argument.h"
#include "framework/test_case/test_case.h"

struct SubmitSingleTaskArguments : TestCaseArgumentContainer {
    BooleanArgument useProfiling;
    BooleanArgument inOrderQueue;
    BooleanArgument useEnqueueFunctions;
    BooleanArgument discardEvents;
    PositiveIntegerArgument numKernels;
    PositiveIntegerArgument kernelExecutionTime;
    BooleanArgument measureCompletionTime;

    SubmitSingleTaskArguments()
        : useProfiling(*this, "Profiling", "Create the queue with the enable_profiling property"),
          inOrderQueue(*this, "Ioq", "Create the queue with the in_order property"),
          useEnqueueFunctions(*this, "EnqueueFunctions", "Use the eventless SYCL enqueue functions"),
          discardEvents(*this, "DiscardEvents", "Create the queue with the discard_events property"),
          numKernels(*this, "NumKernels", "Number of kernels to submit to the queue"),
          kernelExecutionTime(*this, "KernelExecTime", "Approximately how long a single kernel executes, in us"),
          measureCompletionTime(*this, "MeasureCompletion", "Measures time taken to complete the submission (default is to measure only submit calls)") {}
};

struct SubmitSingleTask : TestCase<SubmitSingleTaskArguments> {
    using TestCase<SubmitSingleTaskArguments>::TestCase;

    std::string getTestCaseName() const override {
        return "SubmitSingleTask";
    }

    std::string getHelp() const override {
        return "measures time spent in submitting a single task to a SYCL (or SYCL-like) queue on CPU.";
    }
};
