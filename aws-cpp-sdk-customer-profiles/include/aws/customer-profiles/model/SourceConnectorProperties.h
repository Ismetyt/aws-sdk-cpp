﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/customer-profiles/CustomerProfiles_EXPORTS.h>
#include <aws/customer-profiles/model/MarketoSourceProperties.h>
#include <aws/customer-profiles/model/S3SourceProperties.h>
#include <aws/customer-profiles/model/SalesforceSourceProperties.h>
#include <aws/customer-profiles/model/ServiceNowSourceProperties.h>
#include <aws/customer-profiles/model/ZendeskSourceProperties.h>
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

  class AWS_CUSTOMERPROFILES_API SourceConnectorProperties
  {
  public:
    SourceConnectorProperties();
    SourceConnectorProperties(Aws::Utils::Json::JsonView jsonValue);
    SourceConnectorProperties& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    
    inline const MarketoSourceProperties& GetMarketo() const{ return m_marketo; }

    
    inline bool MarketoHasBeenSet() const { return m_marketoHasBeenSet; }

    
    inline void SetMarketo(const MarketoSourceProperties& value) { m_marketoHasBeenSet = true; m_marketo = value; }

    
    inline void SetMarketo(MarketoSourceProperties&& value) { m_marketoHasBeenSet = true; m_marketo = std::move(value); }

    
    inline SourceConnectorProperties& WithMarketo(const MarketoSourceProperties& value) { SetMarketo(value); return *this;}

    
    inline SourceConnectorProperties& WithMarketo(MarketoSourceProperties&& value) { SetMarketo(std::move(value)); return *this;}


    
    inline const S3SourceProperties& GetS3() const{ return m_s3; }

    
    inline bool S3HasBeenSet() const { return m_s3HasBeenSet; }

    
    inline void SetS3(const S3SourceProperties& value) { m_s3HasBeenSet = true; m_s3 = value; }

    
    inline void SetS3(S3SourceProperties&& value) { m_s3HasBeenSet = true; m_s3 = std::move(value); }

    
    inline SourceConnectorProperties& WithS3(const S3SourceProperties& value) { SetS3(value); return *this;}

    
    inline SourceConnectorProperties& WithS3(S3SourceProperties&& value) { SetS3(std::move(value)); return *this;}


    
    inline const SalesforceSourceProperties& GetSalesforce() const{ return m_salesforce; }

    
    inline bool SalesforceHasBeenSet() const { return m_salesforceHasBeenSet; }

    
    inline void SetSalesforce(const SalesforceSourceProperties& value) { m_salesforceHasBeenSet = true; m_salesforce = value; }

    
    inline void SetSalesforce(SalesforceSourceProperties&& value) { m_salesforceHasBeenSet = true; m_salesforce = std::move(value); }

    
    inline SourceConnectorProperties& WithSalesforce(const SalesforceSourceProperties& value) { SetSalesforce(value); return *this;}

    
    inline SourceConnectorProperties& WithSalesforce(SalesforceSourceProperties&& value) { SetSalesforce(std::move(value)); return *this;}


    
    inline const ServiceNowSourceProperties& GetServiceNow() const{ return m_serviceNow; }

    
    inline bool ServiceNowHasBeenSet() const { return m_serviceNowHasBeenSet; }

    
    inline void SetServiceNow(const ServiceNowSourceProperties& value) { m_serviceNowHasBeenSet = true; m_serviceNow = value; }

    
    inline void SetServiceNow(ServiceNowSourceProperties&& value) { m_serviceNowHasBeenSet = true; m_serviceNow = std::move(value); }

    
    inline SourceConnectorProperties& WithServiceNow(const ServiceNowSourceProperties& value) { SetServiceNow(value); return *this;}

    
    inline SourceConnectorProperties& WithServiceNow(ServiceNowSourceProperties&& value) { SetServiceNow(std::move(value)); return *this;}


    
    inline const ZendeskSourceProperties& GetZendesk() const{ return m_zendesk; }

    
    inline bool ZendeskHasBeenSet() const { return m_zendeskHasBeenSet; }

    
    inline void SetZendesk(const ZendeskSourceProperties& value) { m_zendeskHasBeenSet = true; m_zendesk = value; }

    
    inline void SetZendesk(ZendeskSourceProperties&& value) { m_zendeskHasBeenSet = true; m_zendesk = std::move(value); }

    
    inline SourceConnectorProperties& WithZendesk(const ZendeskSourceProperties& value) { SetZendesk(value); return *this;}

    
    inline SourceConnectorProperties& WithZendesk(ZendeskSourceProperties&& value) { SetZendesk(std::move(value)); return *this;}

  private:

    MarketoSourceProperties m_marketo;
    bool m_marketoHasBeenSet;

    S3SourceProperties m_s3;
    bool m_s3HasBeenSet;

    SalesforceSourceProperties m_salesforce;
    bool m_salesforceHasBeenSet;

    ServiceNowSourceProperties m_serviceNow;
    bool m_serviceNowHasBeenSet;

    ZendeskSourceProperties m_zendesk;
    bool m_zendeskHasBeenSet;
  };

} // namespace Model
} // namespace CustomerProfiles
} // namespace Aws
