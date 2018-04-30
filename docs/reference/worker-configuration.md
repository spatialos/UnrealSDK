# Worker configuration

The Unreal SDK provides a set of configuration parameters for controlling a worker's behaviour. This page is a reference to those configuration parameters.

You can specify a worker's configuration either in [code](../configuration/worker-setup.md#creating-the-connection) or 
in the [editor](../develop/debug-and-iterate.md#setup). Please refer to those pages to find out how worker configurations are applied.

Worker configurations set in code or via the editor can be overwritten at runtime by starting a worker executable with command line arguments that
follow the format `+<command line argument> <value>`. The command line arguments are shown below. You can specify the command line arguments 
with which a worker is started in its respective [configuration file (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/shared/worker-configuration/worker-configuration#configuration-file).

### `FSOSWorkerConfigurationData` struct

**Summary**: Provides configuration parameters for controlling a worker's behaviour.

#### Fields
* `FSpatialOSDebuggingConfig Debugging` - Provides configuration parameters related to debugging a worker.
* `FSOSNetworkingConfiguration Networking` - Provides configuration parameters related to how a worker establishes a connection with a SpatialOS deployment.
* `FSpatialOSApplicationConfig SpatialOSApplication` - Provides configuration parameters related to a worker's behaviour.

### `FSpatialOSDebuggingConfig` struct

**Summary**: Provides configuration parameters related to debugging a worker.

#### Fields
* `uint32 BuiltInMetricsReportPeriodMillis (default: worker::defaults::kBuiltInMetricsReportPeriodMillis)` - 
`BuiltInMetricsReportPeriodMillis` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
This parameter controls how frequently the Connection will return a MetricsOp reporting its built-in metrics. If set to zero, this functionality is disabled. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+builtInMetricsReportPeriodMillis`.
* `uint32 LogMessageQueueCapacity (default: worker::defaults::kLogMessageQueueCapacity)` - 
`LogMessageQueueCapacity` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
Number of messages logged by the SDK that can be stored in the log message queue. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+logMessageQueueCapacity`.
* `bool ProtocolLoggingOnStartup (default: false)` - 
`EnableProtocolLoggingAtStartpup` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
Whether to enable protocol logging at startup. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+protocolLoggingOnStartup`.
* `FString ProtocolLogPrefix (default: worker::defaults::kLogPrefix)` - 
`LogPrefix` field for an underlying [`worker::ProtocolLoggingParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-protocolloggingparameters-struct) struct. 
Log file names are prefixed with this prefix, are numbered, and have the extension `.log`.
To be used when protocol logging is enabled. Command line argument for overriding this setting: `+protocolLogPrefix`.
* `uint32 ProtocolLogMaxFileBytes (default: 100U * worker::defaults::kMaxLogFileSizeBytes)` - 
`MaxLogFileSizeBytes` field for an underlying [`worker::ProtocolLoggingParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-protocolloggingparameters-struct) struct. 
Once the size of a log file reaches this size, a new log file is created. 
To be used when protocol logging is enabled. Command line argument for overriding this setting: `+protocolLogMaxFileBytes`.
* `uint32 ProtocolLogMaxFiles (default: worker::defaults::kMaxLogFiles)` - 
`MaxLogFiles` field for an underlying [`worker::ProtocolLoggingParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-protocolloggingparameters-struct) struct. 
Maximum number of log files to keep. 
To be used when protocol logging is enabled. Command line argument for overriding this setting: `+protocolLogMaxFiles`.
* **DEPRECATED** `FString InfraServiceUrl (default: https://api.spatial.improbable.io)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool LogDebugToSpatialOs (default: false)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool LogAssertToSpatialOs (default: false)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool LogWarningToSpatialOs (default: true)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool LogErrorToSpatialOs (default: true)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool ShowDebugTraces (default: false)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* **DEPRECATED** `bool UseInstrumentation (default: true)` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 

### `FSOSNetworkingConfiguration` struct

**Summary**: Provides configuration parameters related to how a worker establishes a connection with a SpatialOS deployment.

#### Fields
* `FString LocatorHost (default: locator.improbable.io)` - 
`hostname` argument for a constructor call of an underlying [`worker::Locator` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-locator-class) object. 
Target hostname for a locator. 
To be used when connecting to a SpatialOS deployment via a locator service. Command line argument for overriding this setting: `+locatorHost`.
* `FString ReceptionistHost (default: 127.0.0.1)` - 
`hostname` argument for an underlying [`worker::Connection::ConnectAsync()` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection-connect_async) function call. 
Target hostname for connecting to a deployment via receptionist.
This is the flow used to connect a managed worker running in the cloud alongside the deployment, 
and also to connect any local worker to a (local or remote) deployment via a locally-running receptionist. 
To be used when connecting to a SpatialOS deployment via a receptionist. Command line argument for overriding this setting: `+receptionistHost`.
* `worker::NetworkConnectionType LinkProtocol (default: worker::NetworkConnectionType::kRaknet)` - 
`ConnectionType` field for an underlying [`worker::NetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-network_parameters) struct. 
Type of network connection to use when connecting to SpatialOS. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+linkProtocol`.
* `uint32 ReceptionistPort (default: 7777)` - 
`port` argument for an underlying [`worker::Connection::ConnectAsync()` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection-connect_async) function call. 
Target port for connecting to a deployment via receptionist.
This is the flow used to connect a managed worker running in the cloud alongside the deployment,
and also to connect any local worker to a (local or remote) deployment via a locally-running receptionist. 
To be used when connecting to a SpatialOS deployment via a receptionist. Command line argument for overriding this setting: `+receptionistPort`.
* `uint32 RaknetHeartbeatTimeoutMillis (default: worker::defaults::kRakNetHeartbeatTimeoutMillis)` - 
`HeartbeatTimeoutMillis` field for an underlying [`worker::RakNetNetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-raknetnetworkparameters-struct) struct. 
Time (in milliseconds) that RakNet should use for its heartbeat protocol.
To be used when RakNet is chosen as the underlying network connection type/link protocol. Command line argument for overriding this setting: `+raknetHeartbeatTimeoutMs`.
* `uint32 ReceiveQueueCapacity (default: worker::defaults::kReceiveQueueCapacity)` - 
`ReceiveQueueCapacity` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
Number of messages that can be stored on the receive queue. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+receiveQueueCapacity`.
* `uint32 SendQueueCapacity (default: worker::defaults::kSendQueueCapacity)` - 
`SendQueueCapacity` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
Number of messages that can be stored on the send queue. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+sendQueueCapacity`.
* `uint32 TcpMultiplexLevel (default: worker::defaults::kTcpMultiplexLevel)` - 
`MultiplexLevel` field for an underlying [`worker::TcpNetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-tcp_network_parameters) struct. 
Number of multiplexed TCP connections. 
To be used when TCP is chosen as the underlying network connection type/link protocol. Command line argument for overriding this setting: `+tcpMultiplexLevel`.
* `bool TcpNoDelay (default: worker::defaults::kTcpNoDelay)` - 
`NoDelay` field for an underlying [`worker::TcpNetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-tcp_network_parameters) struct. 
Whether to enable TCP_NODELAY. 
To be used when TCP is chosen as the underlying network connection type/link protocol. Command line argument for overriding this setting: `+tcpNoDelay`.
* `uint32 TcpReceiveBufferSize (default: worker::defaults::kTcpReceiveBufferSize)` - 
`ReceiveBufferSize` field for an underlying [`worker::TcpNetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-tcp_network_parameters) struct. 
Size in bytes of the TCP receive buffer. 
To be used when TCP is chosen as the underlying network connection type/link protocol. Command line argument for overriding this setting: `+tcpReceiveBufferSize`.
* `uint32 TcpSendBufferSize (default: worker::defaults::kTcpSendBufferSize)` - 
`SendBufferSize` field for an underlying [`worker::TcpNetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-tcp_network_parameters) struct. 
Size in bytes of the TCP send buffer. 
To be used when TCP is chosen as the underlying network connection type/link protocol. Command line argument for overriding this setting: `+tcpSendBufferSize`.
* `bool UseExternalIp (default: worker::defaults::kUseExternalIp)` - 
`UseExternalIp` field for an underlying [`worker::NetworkParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-network_parameters) struct. 
Set this flag to connect to SpatialOS using the externally-visible IP address. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+useExternalIpForBridge`.
* `FString SteamToken (default: "")` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 

### `FSpatialOSApplicationConfig` struct

**Summary**: Provides configuration parameters related to a worker's behaviour.

#### Fields
* `FString DeploymentName (default: "")` - 
`deployment_name` argument for an underlying [`worker::Locator::ConnectAsync()` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-locator-connect_async) function call. 
The name of the deployment. 
To be used when connecting to a SpatialOS deployment via a locator service. Command line argument for overriding this setting: `+deploymentName`.
* `FString ProjectName (default: "")` - 
`ProjectName` field for an underlying [`worker::LocatorParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-locator_parameters) struct. 
The name of the SpatialOS project. 
To be used when connecting to a SpatialOS deployment via a locator service. Command line argument for overriding this setting: `+projectName`.
* `FString WorkerPlatform (default: "UnrealClient")` - 
`WorkerType` field for an underlying [`worker::ConnectionParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection_parameters) struct. 
A string that specifies the type of a worker. 
Used when establishing a connection with a SpatialOS deployment. Command line argument for overriding this setting: `+workerType`.
* `FString WorkerId (default: "")` - 
`worker_id` argument for an underlying [`worker::Connection::ConnectAsync()` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-connection-connect_async) function call. 
Self assigned worker id of the connecting worker. 
To be used when connecting to a SpatialOS deployment via a receptionist. Command line argument for overriding this setting: `+workerId`.
* `FString LoginToken (default: "")` - 
`LoginToken` field for an underlying [`worker::LocatorParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-locator_parameters) struct. 
Authentication token allowing a worker to connect to a SpatialOS deployment. 
To be used when connecting to a SpatialOS deployment via a locator service. Command line argument for overriding this setting: `+loginToken`.
* **DEPRECATED** `FString AppName (default: "")` - 
`ProjectName` field for an underlying [`worker::LocatorParameters` (SpatialOS documentation)](https://docs.improbable.io/reference/12.2/cppsdk/api-reference#worker-locator_parameters) struct. 
To be used when connecting to a SpatialOS deployment via a locator service. This field is deprecated. Please use ProjectName instead. 
* **DEPRECATED** `FString AssemblyName (default: "")` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
* `FString DeploymentTag (default: "prod")` - 
This field is not in use. Setting this field will not affect a worker's behaviour. 
