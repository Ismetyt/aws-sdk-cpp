﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/honeycode/model/ResultSet.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Honeycode
{
namespace Model
{

ResultSet::ResultSet() : 
    m_headersHasBeenSet(false),
    m_rowsHasBeenSet(false)
{
}

ResultSet::ResultSet(JsonView jsonValue) : 
    m_headersHasBeenSet(false),
    m_rowsHasBeenSet(false)
{
  *this = jsonValue;
}

ResultSet& ResultSet::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("headers"))
  {
    Array<JsonView> headersJsonList = jsonValue.GetArray("headers");
    for(unsigned headersIndex = 0; headersIndex < headersJsonList.GetLength(); ++headersIndex)
    {
      m_headers.push_back(headersJsonList[headersIndex].AsObject());
    }
    m_headersHasBeenSet = true;
  }

  if(jsonValue.ValueExists("rows"))
  {
    Array<JsonView> rowsJsonList = jsonValue.GetArray("rows");
    for(unsigned rowsIndex = 0; rowsIndex < rowsJsonList.GetLength(); ++rowsIndex)
    {
      m_rows.push_back(rowsJsonList[rowsIndex].AsObject());
    }
    m_rowsHasBeenSet = true;
  }

  return *this;
}

JsonValue ResultSet::Jsonize() const
{
  JsonValue payload;

  if(m_headersHasBeenSet)
  {
   Array<JsonValue> headersJsonList(m_headers.size());
   for(unsigned headersIndex = 0; headersIndex < headersJsonList.GetLength(); ++headersIndex)
   {
     headersJsonList[headersIndex].AsObject(m_headers[headersIndex].Jsonize());
   }
   payload.WithArray("headers", std::move(headersJsonList));

  }

  if(m_rowsHasBeenSet)
  {
   Array<JsonValue> rowsJsonList(m_rows.size());
   for(unsigned rowsIndex = 0; rowsIndex < rowsJsonList.GetLength(); ++rowsIndex)
   {
     rowsJsonList[rowsIndex].AsObject(m_rows[rowsIndex].Jsonize());
   }
   payload.WithArray("rows", std::move(rowsJsonList));

  }

  return payload;
}

} // namespace Model
} // namespace Honeycode
} // namespace Aws
