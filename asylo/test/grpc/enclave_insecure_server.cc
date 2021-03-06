/*
 *
 * Copyright 2017 Asylo authors
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
 *
 */

#include <memory>

#include "grpcpp/security/server_credentials.h"
#include "absl/memory/memory.h"
#include "asylo/grpc/util/enclave_server.h"
#include "asylo/test/grpc/messenger_server_impl.h"

namespace asylo {

// Creates an enclave application hosting a simple gRPC server with insecure
// credentials.
TrustedApplication *BuildTrustedApplication() {
  return new EnclaveServer<test::MessengerServer1>(
      absl::make_unique<test::MessengerServer1>(),
      ::grpc::InsecureServerCredentials());
}

}  // namespace asylo
