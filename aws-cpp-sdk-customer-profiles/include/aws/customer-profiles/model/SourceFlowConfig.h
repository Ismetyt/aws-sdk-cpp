﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/customer-profiles/CustomerProfiles_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/customer-profiles/model/SourceConnectorType.h>
#include <aws/customer-profiles/model/IncrementalPullConfig.h>
#include <aws/customer-profiles/model/SourceConnectorProperties.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace CustomerProfiles
{
namespace Model
{

  class AWS_CUSTOMERPROFILES_API SourceFlowConfig
  {
  public:
    SourceFlowConfig();
    SourceFlowConfig(Aws::Utils::Json::JsonView jsonValue);
    SourceFlowConfig& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    
    inline const Aws::String& GetConnectorProfileName() const{ return m_connectorProfileName; }

    
    inline bool ConnectorProfileNameHasBeenSet() const { return m_connectorProfileNameHasBeenSet; }

    
    inline void SetConnectorProfileName(const Aws::String& value) { m_connectorProfileNameHasBeenSet = true; m_connectorProfileName = value; }

    
    inline void SetConnectorProfileName(Aws::String&& value) { m_connectorProfileNameHasBeenSet = true; m_connectorProfileName = std::move(value); }

    
    inline void SetConnectorProfileName(const char* value) { m_connectorProfileNameHasBeenSet = true; m_connectorProfileName.assign(value); }

    
    inline SourceFlowConfig& WithConnectorProfileName(const Aws::String& value) { SetConnectorProfileName(value); return *this;}

    
    inline SourceFlowConfig& WithConnectorProfileName(Aws::String&& value) { SetConnectorProfileName(std::move(value)); return *this;}

    
    inline SourceFlowConfig& WithConnectorProfileName(const char* value) { SetConnectorProfileName(value); return *this;}


    
    inline const SourceConnectorType& GetConnectorType() const{ return m_connectorType; }

    
    inline bool ConnectorTypeHasBeenSet() const { return m_connectorTypeHasBeenSet; }

    
    inline void SetConnectorType(const SourceConnectorType& value) { m_connectorTypeHasBeenSet = true; m_connectorType = value; }

    
    inline void SetConnectorType(SourceConnectorType&& value) { m_connectorTypeHasBeenSet = true; m_connectorType = std::move(value); }

    
    inline SourceFlowConfig& WithConnectorType(const SourceConnectorType& value) { SetConnectorType(value); return *this;}

    
    inline SourceFlowConfig& WithConnectorType(SourceConnectorType&& value) { SetConnectorType(std::move(value)); return *this;}


    
    inline const IncrementalPullConfig& GetIncrementalPullConfig() const{ return m_incrementalPullConfig; }

    
    inline bool IncrementalPullConfigHasBeenSet() const { return m_incrementalPullConfigHasBeenSet; }

    
    inline void SetIncrementalPullConfig(const IncrementalPullConfig& value) { m_incrementalPullConfigHasBeenSet = true; m_incrementalPullConfig = value; }

    
    inline void SetIncrementalPullConfig(IncrementalPullConfig&& value) { m_incrementalPullConfigHasBeenSet = true; m_incrementalPullConfig = std::move(value); }

    
    inline SourceFlowConfig& WithIncrementalPullConfig(const IncrementalPullConfig& value) { SetIncrementalPullConfig(value); return *this;}

    
    inline SourceFlowConfig& WithIncrementalPullConfig(IncrementalPullConfig&& value) { SetIncrementalPullConfig(std::move(value)); return *this;}


    
    inline const SourceConnectorProperties& GetSourceConnectorProperties() const{ return m_sourceConnectorProperties; }

    
    inline bool SourceConnectorPropertiesHasBeenSet() const { return m_sourceConnectorPropertiesHasBeenSet; }

    
    inline void SetSourceConnectorProperties(const SourceConnectorProperties& value) { m_sourceConnectorPropertiesHasBeenSet = true; m_sourceConnectorProperties = value; }

    
    inline void SetSourceConnectorProperties(SourceConnectorProperties&& value) { m_sourceConnectorPropertiesHasBeenSet = true; m_sourceConnectorProperties = std::move(value); }

    
    inline SourceFlowConfig& WithSourceConnectorProperties(const SourceConnectorProperties& value) { SetSourceConnectorProperties(value); return *this;}

    
    inline SourceFlowConfig& WithSourceConnectorProperties(SourceConnectorProperties&& value) { SetSourceConnectorProperties(std::move(value)); return *this;}

  private:

    Aws::String m_connectorProfileName;
    bool m_connectorProfileNameHasBeenSet;

    SourceConnectorType m_connectorType;
    bool m_connectorTypeHasBeenSet;

    IncrementalPullConfig m_incrementalPullConfig;
    bool m_incrementalPullConfigHasBeenSet;

    SourceConnectorProperties m_sourceConnectorProperties;
    bool m_sourceConnectorPropertiesHasBeenSet;
  };

} // namespace Model
} // namespace CustomerProfiles
} // namespace Aws
