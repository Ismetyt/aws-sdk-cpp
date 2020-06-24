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

#pragma once
#include <aws/amplify/Amplify_EXPORTS.h>
#include <aws/amplify/AmplifyRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace Http
{
    class URI;
} //namespace Http
namespace Amplify
{
namespace Model
{

  /**
   * <p> The request structure for the list webhooks request. </p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/amplify-2017-07-25/ListWebhooksRequest">AWS
   * API Reference</a></p>
   */
  class AWS_AMPLIFY_API ListWebhooksRequest : public AmplifyRequest
  {
  public:
    ListWebhooksRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "ListWebhooks"; }

    Aws::String SerializePayload() const override;

    void AddQueryStringParameters(Aws::Http::URI& uri) const override;


    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline const Aws::String& GetAppId() const{ return m_appId; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline bool AppIdHasBeenSet() const { return m_appIdHasBeenSet; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(const Aws::String& value) { m_appIdHasBeenSet = true; m_appId = value; }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(Aws::String&& value) { m_appIdHasBeenSet = true; m_appId = std::move(value); }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline void SetAppId(const char* value) { m_appIdHasBeenSet = true; m_appId.assign(value); }

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline ListWebhooksRequest& WithAppId(const Aws::String& value) { SetAppId(value); return *this;}

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline ListWebhooksRequest& WithAppId(Aws::String&& value) { SetAppId(std::move(value)); return *this;}

    /**
     * <p> The unique ID for an Amplify app. </p>
     */
    inline ListWebhooksRequest& WithAppId(const char* value) { SetAppId(value); return *this;}


    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline const Aws::String& GetNextToken() const{ return m_nextToken; }

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline bool NextTokenHasBeenSet() const { return m_nextTokenHasBeenSet; }

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline void SetNextToken(const Aws::String& value) { m_nextTokenHasBeenSet = true; m_nextToken = value; }

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline void SetNextToken(Aws::String&& value) { m_nextTokenHasBeenSet = true; m_nextToken = std::move(value); }

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline void SetNextToken(const char* value) { m_nextTokenHasBeenSet = true; m_nextToken.assign(value); }

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline ListWebhooksRequest& WithNextToken(const Aws::String& value) { SetNextToken(value); return *this;}

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline ListWebhooksRequest& WithNextToken(Aws::String&& value) { SetNextToken(std::move(value)); return *this;}

    /**
     * <p> A pagination token. Set to null to start listing webhooks from the start. If
     * non-null,the pagination token is returned in a result. Pass its value in here to
     * list more webhooks. </p>
     */
    inline ListWebhooksRequest& WithNextToken(const char* value) { SetNextToken(value); return *this;}


    /**
     * <p> The maximum number of records to list in a single response. </p>
     */
    inline int GetMaxResults() const{ return m_maxResults; }

    /**
     * <p> The maximum number of records to list in a single response. </p>
     */
    inline bool MaxResultsHasBeenSet() const { return m_maxResultsHasBeenSet; }

    /**
     * <p> The maximum number of records to list in a single response. </p>
     */
    inline void SetMaxResults(int value) { m_maxResultsHasBeenSet = true; m_maxResults = value; }

    /**
     * <p> The maximum number of records to list in a single response. </p>
     */
    inline ListWebhooksRequest& WithMaxResults(int value) { SetMaxResults(value); return *this;}

  private:

    Aws::String m_appId;
    bool m_appIdHasBeenSet;

    Aws::String m_nextToken;
    bool m_nextTokenHasBeenSet;

    int m_maxResults;
    bool m_maxResultsHasBeenSet;
  };

} // namespace Model
} // namespace Amplify
} // namespace Aws
