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

#include "ngraph/op/negative.hpp"

using namespace std;
using namespace ngraph;

op::Negative::Negative(const shared_ptr<Node>& arg)
    : UnaryElementwiseArithmetic("Negative", arg)
{
}

shared_ptr<Node> op::Negative::copy_with_new_args(const NodeVector& new_args) const
{
    if (new_args.size() != 1)
    {
        throw ngraph_error("Incorrect number of new arguments");
    }
    return make_shared<Negative>(new_args.at(0));
}

void op::Negative::generate_adjoints(autodiff::Adjoints& adjoints, const shared_ptr<Node>& delta)
{
    auto x = get_input_op(0);

    adjoints.add_delta(x, -delta);
}

shared_ptr<Node> ngraph::operator-(const shared_ptr<Node> arg0)
{
    return make_shared<op::Negative>(arg0);
}
