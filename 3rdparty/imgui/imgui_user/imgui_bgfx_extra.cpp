// Copyright 2021 mnesarco
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "dear-imgui/imgui.h"
#include "dear-imgui/imgui_internal.h"

namespace ImGui
{

float RoundScalarWithFormatFloat(const char* format, ImGuiDataType data_type, float v)
{
    return RoundScalarWithFormatT<float, float>(format, data_type, v);
}

float SliderCalcRatioFromValueFloat(ImGuiDataType data_type, float v, float v_min, float v_max, float power, float linear_zero_pos)
{
    return ScaleRatioFromValueT<float, float, float>(data_type, v, v_min, v_max, false, power, linear_zero_pos);
}

} // namespace ImGui
