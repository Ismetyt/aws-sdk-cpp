﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/Outcome.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/client/CoreErrors.h>
#include <aws/core/client/RetryStrategy.h>
#include <aws/core/http/HttpClient.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/HttpClientFactory.h>
#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>
#include <aws/core/utils/threading/Executor.h>
#include <aws/core/utils/DNS.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <aws/iotevents/IoTEventsClient.h>
#include <aws/iotevents/IoTEventsEndpoint.h>
#include <aws/iotevents/IoTEventsErrorMarshaller.h>
#include <aws/iotevents/model/CreateDetectorModelRequest.h>
#include <aws/iotevents/model/CreateInputRequest.h>
#include <aws/iotevents/model/DeleteDetectorModelRequest.h>
#include <aws/iotevents/model/DeleteInputRequest.h>
#include <aws/iotevents/model/DescribeDetectorModelRequest.h>
#include <aws/iotevents/model/DescribeDetectorModelAnalysisRequest.h>
#include <aws/iotevents/model/DescribeInputRequest.h>
#include <aws/iotevents/model/DescribeLoggingOptionsRequest.h>
#include <aws/iotevents/model/GetDetectorModelAnalysisResultsRequest.h>
#include <aws/iotevents/model/ListDetectorModelVersionsRequest.h>
#include <aws/iotevents/model/ListDetectorModelsRequest.h>
#include <aws/iotevents/model/ListInputsRequest.h>
#include <aws/iotevents/model/ListTagsForResourceRequest.h>
#include <aws/iotevents/model/PutLoggingOptionsRequest.h>
#include <aws/iotevents/model/StartDetectorModelAnalysisRequest.h>
#include <aws/iotevents/model/TagResourceRequest.h>
#include <aws/iotevents/model/UntagResourceRequest.h>
#include <aws/iotevents/model/UpdateDetectorModelRequest.h>
#include <aws/iotevents/model/UpdateInputRequest.h>

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Client;
using namespace Aws::IoTEvents;
using namespace Aws::IoTEvents::Model;
using namespace Aws::Http;
using namespace Aws::Utils::Json;

static const char* SERVICE_NAME = "iotevents";
static const char* ALLOCATION_TAG = "IoTEventsClient";


IoTEventsClient::IoTEventsClient(const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<DefaultAWSCredentialsProviderChain>(ALLOCATION_TAG),
        SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<IoTEventsErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

IoTEventsClient::IoTEventsClient(const AWSCredentials& credentials, const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, Aws::MakeShared<SimpleAWSCredentialsProvider>(ALLOCATION_TAG, credentials),
         SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<IoTEventsErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

IoTEventsClient::IoTEventsClient(const std::shared_ptr<AWSCredentialsProvider>& credentialsProvider,
  const Client::ClientConfiguration& clientConfiguration) :
  BASECLASS(clientConfiguration,
    Aws::MakeShared<AWSAuthV4Signer>(ALLOCATION_TAG, credentialsProvider,
         SERVICE_NAME, Aws::Region::ComputeSignerRegion(clientConfiguration.region)),
    Aws::MakeShared<IoTEventsErrorMarshaller>(ALLOCATION_TAG)),
    m_executor(clientConfiguration.executor)
{
  init(clientConfiguration);
}

IoTEventsClient::~IoTEventsClient()
{
}

void IoTEventsClient::init(const ClientConfiguration& config)
{
  SetServiceClientName("IoT Events");
  m_configScheme = SchemeMapper::ToString(config.scheme);
  if (config.endpointOverride.empty())
  {
      m_uri = m_configScheme + "://" + IoTEventsEndpoint::ForRegion(config.region, config.useDualStack);
  }
  else
  {
      OverrideEndpoint(config.endpointOverride);
  }
}

void IoTEventsClient::OverrideEndpoint(const Aws::String& endpoint)
{
  if (endpoint.compare(0, 7, "http://") == 0 || endpoint.compare(0, 8, "https://") == 0)
  {
      m_uri = endpoint;
  }
  else
  {
      m_uri = m_configScheme + "://" + endpoint;
  }
}

CreateDetectorModelOutcome IoTEventsClient::CreateDetectorModel(const CreateDetectorModelRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models";
  uri.SetPath(uri.GetPath() + ss.str());
  return CreateDetectorModelOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateDetectorModelOutcomeCallable IoTEventsClient::CreateDetectorModelCallable(const CreateDetectorModelRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateDetectorModelOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateDetectorModel(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::CreateDetectorModelAsync(const CreateDetectorModelRequest& request, const CreateDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreateDetectorModelAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::CreateDetectorModelAsyncHelper(const CreateDetectorModelRequest& request, const CreateDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreateDetectorModel(request), context);
}

CreateInputOutcome IoTEventsClient::CreateInput(const CreateInputRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/inputs";
  uri.SetPath(uri.GetPath() + ss.str());
  return CreateInputOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

CreateInputOutcomeCallable IoTEventsClient::CreateInputCallable(const CreateInputRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< CreateInputOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->CreateInput(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::CreateInputAsync(const CreateInputRequest& request, const CreateInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->CreateInputAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::CreateInputAsyncHelper(const CreateInputRequest& request, const CreateInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, CreateInput(request), context);
}

DeleteDetectorModelOutcome IoTEventsClient::DeleteDetectorModel(const DeleteDetectorModelRequest& request) const
{
  if (!request.DetectorModelNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DeleteDetectorModel", "Required field: DetectorModelName, is not set");
    return DeleteDetectorModelOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [DetectorModelName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models/";
  ss << request.GetDetectorModelName();
  uri.SetPath(uri.GetPath() + ss.str());
  return DeleteDetectorModelOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_DELETE, Aws::Auth::SIGV4_SIGNER));
}

DeleteDetectorModelOutcomeCallable IoTEventsClient::DeleteDetectorModelCallable(const DeleteDetectorModelRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteDetectorModelOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteDetectorModel(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DeleteDetectorModelAsync(const DeleteDetectorModelRequest& request, const DeleteDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteDetectorModelAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DeleteDetectorModelAsyncHelper(const DeleteDetectorModelRequest& request, const DeleteDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteDetectorModel(request), context);
}

DeleteInputOutcome IoTEventsClient::DeleteInput(const DeleteInputRequest& request) const
{
  if (!request.InputNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DeleteInput", "Required field: InputName, is not set");
    return DeleteInputOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [InputName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/inputs/";
  ss << request.GetInputName();
  uri.SetPath(uri.GetPath() + ss.str());
  return DeleteInputOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_DELETE, Aws::Auth::SIGV4_SIGNER));
}

DeleteInputOutcomeCallable IoTEventsClient::DeleteInputCallable(const DeleteInputRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DeleteInputOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DeleteInput(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DeleteInputAsync(const DeleteInputRequest& request, const DeleteInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DeleteInputAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DeleteInputAsyncHelper(const DeleteInputRequest& request, const DeleteInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DeleteInput(request), context);
}

DescribeDetectorModelOutcome IoTEventsClient::DescribeDetectorModel(const DescribeDetectorModelRequest& request) const
{
  if (!request.DetectorModelNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DescribeDetectorModel", "Required field: DetectorModelName, is not set");
    return DescribeDetectorModelOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [DetectorModelName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models/";
  ss << request.GetDetectorModelName();
  uri.SetPath(uri.GetPath() + ss.str());
  return DescribeDetectorModelOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

DescribeDetectorModelOutcomeCallable IoTEventsClient::DescribeDetectorModelCallable(const DescribeDetectorModelRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeDetectorModelOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeDetectorModel(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DescribeDetectorModelAsync(const DescribeDetectorModelRequest& request, const DescribeDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeDetectorModelAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DescribeDetectorModelAsyncHelper(const DescribeDetectorModelRequest& request, const DescribeDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeDetectorModel(request), context);
}

DescribeDetectorModelAnalysisOutcome IoTEventsClient::DescribeDetectorModelAnalysis(const DescribeDetectorModelAnalysisRequest& request) const
{
  if (!request.AnalysisIdHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DescribeDetectorModelAnalysis", "Required field: AnalysisId, is not set");
    return DescribeDetectorModelAnalysisOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [AnalysisId]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/analysis/detector-models/";
  ss << request.GetAnalysisId();
  uri.SetPath(uri.GetPath() + ss.str());
  return DescribeDetectorModelAnalysisOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

DescribeDetectorModelAnalysisOutcomeCallable IoTEventsClient::DescribeDetectorModelAnalysisCallable(const DescribeDetectorModelAnalysisRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeDetectorModelAnalysisOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeDetectorModelAnalysis(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DescribeDetectorModelAnalysisAsync(const DescribeDetectorModelAnalysisRequest& request, const DescribeDetectorModelAnalysisResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeDetectorModelAnalysisAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DescribeDetectorModelAnalysisAsyncHelper(const DescribeDetectorModelAnalysisRequest& request, const DescribeDetectorModelAnalysisResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeDetectorModelAnalysis(request), context);
}

DescribeInputOutcome IoTEventsClient::DescribeInput(const DescribeInputRequest& request) const
{
  if (!request.InputNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("DescribeInput", "Required field: InputName, is not set");
    return DescribeInputOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [InputName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/inputs/";
  ss << request.GetInputName();
  uri.SetPath(uri.GetPath() + ss.str());
  return DescribeInputOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

DescribeInputOutcomeCallable IoTEventsClient::DescribeInputCallable(const DescribeInputRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeInputOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeInput(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DescribeInputAsync(const DescribeInputRequest& request, const DescribeInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeInputAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DescribeInputAsyncHelper(const DescribeInputRequest& request, const DescribeInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeInput(request), context);
}

DescribeLoggingOptionsOutcome IoTEventsClient::DescribeLoggingOptions(const DescribeLoggingOptionsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/logging";
  uri.SetPath(uri.GetPath() + ss.str());
  return DescribeLoggingOptionsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

DescribeLoggingOptionsOutcomeCallable IoTEventsClient::DescribeLoggingOptionsCallable(const DescribeLoggingOptionsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< DescribeLoggingOptionsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->DescribeLoggingOptions(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::DescribeLoggingOptionsAsync(const DescribeLoggingOptionsRequest& request, const DescribeLoggingOptionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->DescribeLoggingOptionsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::DescribeLoggingOptionsAsyncHelper(const DescribeLoggingOptionsRequest& request, const DescribeLoggingOptionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, DescribeLoggingOptions(request), context);
}

GetDetectorModelAnalysisResultsOutcome IoTEventsClient::GetDetectorModelAnalysisResults(const GetDetectorModelAnalysisResultsRequest& request) const
{
  if (!request.AnalysisIdHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("GetDetectorModelAnalysisResults", "Required field: AnalysisId, is not set");
    return GetDetectorModelAnalysisResultsOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [AnalysisId]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/analysis/detector-models/";
  ss << request.GetAnalysisId();
  ss << "/results";
  uri.SetPath(uri.GetPath() + ss.str());
  return GetDetectorModelAnalysisResultsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

GetDetectorModelAnalysisResultsOutcomeCallable IoTEventsClient::GetDetectorModelAnalysisResultsCallable(const GetDetectorModelAnalysisResultsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< GetDetectorModelAnalysisResultsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->GetDetectorModelAnalysisResults(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::GetDetectorModelAnalysisResultsAsync(const GetDetectorModelAnalysisResultsRequest& request, const GetDetectorModelAnalysisResultsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->GetDetectorModelAnalysisResultsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::GetDetectorModelAnalysisResultsAsyncHelper(const GetDetectorModelAnalysisResultsRequest& request, const GetDetectorModelAnalysisResultsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, GetDetectorModelAnalysisResults(request), context);
}

ListDetectorModelVersionsOutcome IoTEventsClient::ListDetectorModelVersions(const ListDetectorModelVersionsRequest& request) const
{
  if (!request.DetectorModelNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("ListDetectorModelVersions", "Required field: DetectorModelName, is not set");
    return ListDetectorModelVersionsOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [DetectorModelName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models/";
  ss << request.GetDetectorModelName();
  ss << "/versions";
  uri.SetPath(uri.GetPath() + ss.str());
  return ListDetectorModelVersionsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListDetectorModelVersionsOutcomeCallable IoTEventsClient::ListDetectorModelVersionsCallable(const ListDetectorModelVersionsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListDetectorModelVersionsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListDetectorModelVersions(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::ListDetectorModelVersionsAsync(const ListDetectorModelVersionsRequest& request, const ListDetectorModelVersionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListDetectorModelVersionsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::ListDetectorModelVersionsAsyncHelper(const ListDetectorModelVersionsRequest& request, const ListDetectorModelVersionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListDetectorModelVersions(request), context);
}

ListDetectorModelsOutcome IoTEventsClient::ListDetectorModels(const ListDetectorModelsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models";
  uri.SetPath(uri.GetPath() + ss.str());
  return ListDetectorModelsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListDetectorModelsOutcomeCallable IoTEventsClient::ListDetectorModelsCallable(const ListDetectorModelsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListDetectorModelsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListDetectorModels(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::ListDetectorModelsAsync(const ListDetectorModelsRequest& request, const ListDetectorModelsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListDetectorModelsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::ListDetectorModelsAsyncHelper(const ListDetectorModelsRequest& request, const ListDetectorModelsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListDetectorModels(request), context);
}

ListInputsOutcome IoTEventsClient::ListInputs(const ListInputsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/inputs";
  uri.SetPath(uri.GetPath() + ss.str());
  return ListInputsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListInputsOutcomeCallable IoTEventsClient::ListInputsCallable(const ListInputsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListInputsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListInputs(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::ListInputsAsync(const ListInputsRequest& request, const ListInputsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListInputsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::ListInputsAsyncHelper(const ListInputsRequest& request, const ListInputsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListInputs(request), context);
}

ListTagsForResourceOutcome IoTEventsClient::ListTagsForResource(const ListTagsForResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("ListTagsForResource", "Required field: ResourceArn, is not set");
    return ListTagsForResourceOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/tags";
  uri.SetPath(uri.GetPath() + ss.str());
  return ListTagsForResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_GET, Aws::Auth::SIGV4_SIGNER));
}

ListTagsForResourceOutcomeCallable IoTEventsClient::ListTagsForResourceCallable(const ListTagsForResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< ListTagsForResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->ListTagsForResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::ListTagsForResourceAsync(const ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->ListTagsForResourceAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::ListTagsForResourceAsyncHelper(const ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, ListTagsForResource(request), context);
}

PutLoggingOptionsOutcome IoTEventsClient::PutLoggingOptions(const PutLoggingOptionsRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/logging";
  uri.SetPath(uri.GetPath() + ss.str());
  return PutLoggingOptionsOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_PUT, Aws::Auth::SIGV4_SIGNER));
}

PutLoggingOptionsOutcomeCallable IoTEventsClient::PutLoggingOptionsCallable(const PutLoggingOptionsRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< PutLoggingOptionsOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->PutLoggingOptions(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::PutLoggingOptionsAsync(const PutLoggingOptionsRequest& request, const PutLoggingOptionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->PutLoggingOptionsAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::PutLoggingOptionsAsyncHelper(const PutLoggingOptionsRequest& request, const PutLoggingOptionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, PutLoggingOptions(request), context);
}

StartDetectorModelAnalysisOutcome IoTEventsClient::StartDetectorModelAnalysis(const StartDetectorModelAnalysisRequest& request) const
{
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/analysis/detector-models/";
  uri.SetPath(uri.GetPath() + ss.str());
  return StartDetectorModelAnalysisOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

StartDetectorModelAnalysisOutcomeCallable IoTEventsClient::StartDetectorModelAnalysisCallable(const StartDetectorModelAnalysisRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< StartDetectorModelAnalysisOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->StartDetectorModelAnalysis(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::StartDetectorModelAnalysisAsync(const StartDetectorModelAnalysisRequest& request, const StartDetectorModelAnalysisResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->StartDetectorModelAnalysisAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::StartDetectorModelAnalysisAsyncHelper(const StartDetectorModelAnalysisRequest& request, const StartDetectorModelAnalysisResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, StartDetectorModelAnalysis(request), context);
}

TagResourceOutcome IoTEventsClient::TagResource(const TagResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("TagResource", "Required field: ResourceArn, is not set");
    return TagResourceOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/tags";
  uri.SetPath(uri.GetPath() + ss.str());
  return TagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

TagResourceOutcomeCallable IoTEventsClient::TagResourceCallable(const TagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< TagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->TagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::TagResourceAsync(const TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->TagResourceAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::TagResourceAsyncHelper(const TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, TagResource(request), context);
}

UntagResourceOutcome IoTEventsClient::UntagResource(const UntagResourceRequest& request) const
{
  if (!request.ResourceArnHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UntagResource", "Required field: ResourceArn, is not set");
    return UntagResourceOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [ResourceArn]", false));
  }
  if (!request.TagKeysHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UntagResource", "Required field: TagKeys, is not set");
    return UntagResourceOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [TagKeys]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/tags";
  uri.SetPath(uri.GetPath() + ss.str());
  return UntagResourceOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_DELETE, Aws::Auth::SIGV4_SIGNER));
}

UntagResourceOutcomeCallable IoTEventsClient::UntagResourceCallable(const UntagResourceRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UntagResourceOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UntagResource(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::UntagResourceAsync(const UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->UntagResourceAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::UntagResourceAsyncHelper(const UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, UntagResource(request), context);
}

UpdateDetectorModelOutcome IoTEventsClient::UpdateDetectorModel(const UpdateDetectorModelRequest& request) const
{
  if (!request.DetectorModelNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UpdateDetectorModel", "Required field: DetectorModelName, is not set");
    return UpdateDetectorModelOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [DetectorModelName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/detector-models/";
  ss << request.GetDetectorModelName();
  uri.SetPath(uri.GetPath() + ss.str());
  return UpdateDetectorModelOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_POST, Aws::Auth::SIGV4_SIGNER));
}

UpdateDetectorModelOutcomeCallable IoTEventsClient::UpdateDetectorModelCallable(const UpdateDetectorModelRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateDetectorModelOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateDetectorModel(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::UpdateDetectorModelAsync(const UpdateDetectorModelRequest& request, const UpdateDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->UpdateDetectorModelAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::UpdateDetectorModelAsyncHelper(const UpdateDetectorModelRequest& request, const UpdateDetectorModelResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, UpdateDetectorModel(request), context);
}

UpdateInputOutcome IoTEventsClient::UpdateInput(const UpdateInputRequest& request) const
{
  if (!request.InputNameHasBeenSet())
  {
    AWS_LOGSTREAM_ERROR("UpdateInput", "Required field: InputName, is not set");
    return UpdateInputOutcome(Aws::Client::AWSError<IoTEventsErrors>(IoTEventsErrors::MISSING_PARAMETER, "MISSING_PARAMETER", "Missing required field [InputName]", false));
  }
  Aws::Http::URI uri = m_uri;
  Aws::StringStream ss;
  ss << "/inputs/";
  ss << request.GetInputName();
  uri.SetPath(uri.GetPath() + ss.str());
  return UpdateInputOutcome(MakeRequest(uri, request, Aws::Http::HttpMethod::HTTP_PUT, Aws::Auth::SIGV4_SIGNER));
}

UpdateInputOutcomeCallable IoTEventsClient::UpdateInputCallable(const UpdateInputRequest& request) const
{
  auto task = Aws::MakeShared< std::packaged_task< UpdateInputOutcome() > >(ALLOCATION_TAG, [this, request](){ return this->UpdateInput(request); } );
  auto packagedFunction = [task]() { (*task)(); };
  m_executor->Submit(packagedFunction);
  return task->get_future();
}

void IoTEventsClient::UpdateInputAsync(const UpdateInputRequest& request, const UpdateInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  m_executor->Submit( [this, request, handler, context](){ this->UpdateInputAsyncHelper( request, handler, context ); } );
}

void IoTEventsClient::UpdateInputAsyncHelper(const UpdateInputRequest& request, const UpdateInputResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const
{
  handler(this, request, UpdateInput(request), context);
}

