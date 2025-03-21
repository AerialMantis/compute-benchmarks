/*
 * Copyright (C) 2022-2025 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "framework/argument/basic_argument.h"
#include "framework/test_case/test_case.h"

struct SubmitMemcpyArguments : TestCaseArgumentContainer {
    BooleanArgument useProfiling;
    BooleanArgument inOrderQueue;
    BooleanArgument useEnqueueFunctions;
    BooleanArgument discardEvents;
    PositiveIntegerArgument numCopies;
    PositiveIntegerArgument copySize;
    BooleanArgument measureCompletionTime;

    SubmitMemcpyArguments()
        : useProfiling(*this, "Profiling", "Create the queue with the enable_profiling property"),
          inOrderQueue(*this, "Ioq", "Create the queue with the in_order property"),
          useEnqueueFunctions(*this, "EnqueueFunctions", "Use the eventless SYCL enqueue functions"),
          discardEvents(*this, "DiscardEvents", "Create the queue with the discard_events property"),
          numCopies(*this, "NumCopies", "Number of copies to submit to the queue"),
          copySize(*this, "CopySize", "Amount of memory to copy, in bytes"),
          measureCompletionTime(*this, "MeasureCompletion", "Measures time taken to complete the submission (default is to measure only submit calls)") {}
};

struct SubmitMemcpy : TestCase<SubmitMemcpyArguments> {
    using TestCase<SubmitMemcpyArguments>::TestCase;

    std::string getTestCaseName() const override {
        return "SubmitMemcpy";
    }

    std::string getHelp() const override {
        return "measures time spent in submitting a memcpy to a SYCL (or SYCL-like) queue on CPU.";
    }
};
