/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "ngraph/runtime/backend.hpp"
#include "ngraph/runtime/cpu/cpu_tensor_view.hpp"
#include "ngraph/runtime/manager.hpp"

using namespace std;
using namespace ngraph;

std::shared_ptr<runtime::Backend> runtime::Backend::create_backend(const std::string& type)
{
    std::shared_ptr<Manager> manager = runtime::Manager::get(type);
    return manager->allocate_backend();
}

shared_ptr<runtime::TensorView>
    runtime::Backend::create_host_tensor(const element::Type& element_type, const Shape& shape)
{
    auto rc = make_shared<runtime::cpu::CPUTensorView>(element_type, shape);
    return dynamic_pointer_cast<runtime::TensorView>(rc);
}

shared_ptr<runtime::TensorView>
    runtime::Backend::create_device_tensor(const element::Type& element_type, const Shape& shape)
{
    return create_host_tensor(element_type, shape);
}
