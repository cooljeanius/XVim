//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark Blocks

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark Named Structures

struct DTXMachMessage {
    struct {
        struct {
            unsigned int _field1;
            unsigned int _field2;
            unsigned int _field3;
            unsigned int _field4;
            unsigned int _field5;
            int _field6;
        } _field1;
        unsigned int _field2;
    } _field1;
    char _field2[32672];
    char _field3[68];
};

struct DTXMessageRoutingInfo {
    unsigned int _field1;
    unsigned int _field2;
    unsigned int _field3;
    unsigned int :1;
    unsigned int :31;
};

struct DTXSharedMemory {
    unsigned long long _field1;
    unsigned long long _field2;
    unsigned long long _field3;
    unsigned int _field4;
    unsigned int _field5;
    unsigned int _field6;
    unsigned int _field7;
    int _field8;
    int _field9;
    unsigned int _field10;
    unsigned int _field11;
    unsigned int _field12;
    unsigned int _field13;
    unsigned int _field14;
    unsigned int _field15;
    unsigned int _field16;
    unsigned int _field17;
    char _field18[0];
};

struct __va_list_tag {
    unsigned int _field1;
    unsigned int _field2;
    void *_field3;
    void *_field4;
};

struct mach_timebase_info {
    unsigned int numer;
    unsigned int denom;
};

#pragma mark -

//
// File: /Applications/Xcode-7GM.app/Contents/SharedFrameworks/DTXConnectionServices.framework/Versions/A/DTXConnectionServices
// UUID: 5AD0517D-7C7F-3367-9C76-A9D36B93FA7B
//
//                           Arch: x86_64
//                Current version: 58118.0.0
//          Compatibility version: 1.0.0
//                 Source version: 58118.0.0.0.0
//       Minimum Mac OS X version: 10.10.0
//                    SDK version: 10.11.0
//
// Objective-C Garbage Collection: Unsupported
//

@protocol DTXAllowedRPC <NSObject>
@end

@protocol DTXBlockCompressor <NSObject>
- (_Bool)uncompressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 withKnownUncompressedLength:(unsigned long long)arg4 usingCompressionType:(int)arg5;
- (unsigned long long)compressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 ofLength:(unsigned long long)arg4 usingCompressionType:(int)arg5 withFinalCompressionType:(int *)arg6;
@end

@protocol DTXConnectionRemoteReceiveQueueCalls <DTXAllowedRPC>
- (void)_notifyCompressionHint:(unsigned int)arg1 forChannelCode:(unsigned int)arg2;
- (void)_setTracerState:(unsigned int)arg1;
- (void)_channelCanceled:(unsigned int)arg1;
- (void)_notifyOfPublishedCapabilities:(NSDictionary *)arg1;
- (void)_requestChannelWithCode:(unsigned int)arg1 identifier:(NSString *)arg2;
@end

@protocol DTXMessenger <NSObject>
- (void)sendMessageSync:(DTXMessage *)arg1 replyHandler:(void (^)(DTXMessage *))arg2;
- (BOOL)sendMessageAsync:(DTXMessage *)arg1 replyHandler:(void (^)(DTXMessage *))arg2;
- (void)sendMessage:(DTXMessage *)arg1 replyHandler:(void (^)(DTXMessage *))arg2;
- (void)sendControlSync:(DTXMessage *)arg1 replyHandler:(void (^)(DTXMessage *))arg2;
- (void)sendControlAsync:(DTXMessage *)arg1 replyHandler:(void (^)(DTXMessage *))arg2;
- (void)cancel;
- (void)registerDisconnectHandler:(void (^)(void))arg1;
- (void)setDispatchTarget:(id <DTXAllowedRPC>)arg1;
- (void)setMessageHandler:(void (^)(DTXMessage *))arg1;
@end

@protocol DTXRateLimiter <NSObject>
- (void)notifyCompressedData:(unsigned long long)arg1 withUncompressedSize:(unsigned long long)arg2 nanosToCompress:(unsigned long long)arg3 usingCompressionType:(int)arg4;
- (void)spendUnits:(unsigned long long)arg1 onAction:(void (^)(void))arg2;
@end

@protocol NSCoding
- (id)initWithCoder:(NSCoder *)arg1;
- (void)encodeWithCoder:(NSCoder *)arg1;
@end

@protocol NSObject
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@property(readonly) unsigned long long hash;
- (struct _NSZone *)zone;
- (unsigned long long)retainCount;
- (id)autorelease;
- (oneway void)release;
- (id)retain;
- (BOOL)respondsToSelector:(SEL)arg1;
- (BOOL)conformsToProtocol:(Protocol *)arg1;
- (BOOL)isMemberOfClass:(Class)arg1;
- (BOOL)isKindOfClass:(Class)arg1;
- (BOOL)isProxy;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2 withObject:(id)arg3;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2;
- (id)performSelector:(SEL)arg1;
- (id)self;
- (Class)class;
- (BOOL)isEqual:(id)arg1;

@optional
@property(readonly, copy) NSString *debugDescription;
@end

@protocol NSSecureCoding <NSCoding>
+ (BOOL)supportsSecureCoding;
@end

@protocol NSURLSessionDelegate <NSObject>

@optional
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)arg1;
- (void)URLSession:(NSURLSession *)arg1 didReceiveChallenge:(NSURLAuthenticationChallenge *)arg2 completionHandler:(void (^)(long long, NSURLCredential *))arg3;
- (void)URLSession:(NSURLSession *)arg1 didBecomeInvalidWithError:(NSError *)arg2;
@end

@interface DTXBlockCompressorFactory : NSObject
{
}

+ (id)createLibCompressionBlockCompressor;
+ (id)createLibFastCompressionBlockCompressor;
+ (id)createBlockCompressor;

@end

@interface DTXBlockCompressorLibCompression : NSObject <DTXBlockCompressor>
{
    void *_lzfseScratchBuffer;
    void *_lz4ScratchBuffer;
}

- (_Bool)uncompressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 withKnownUncompressedLength:(unsigned long long)arg4 usingCompressionType:(int)arg5;
- (unsigned long long)compressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 ofLength:(unsigned long long)arg4 usingCompressionType:(int)arg5 withFinalCompressionType:(int *)arg6;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXBlockCompressorLibFastCompression : NSObject <DTXBlockCompressor>
{
    void *_lzfseScratchBuffer;
}

- (_Bool)uncompressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 withKnownUncompressedLength:(unsigned long long)arg4 usingCompressionType:(int)arg5;
- (unsigned long long)compressBuffer:(const char *)arg1 ofLength:(unsigned long long)arg2 toBuffer:(char *)arg3 ofLength:(unsigned long long)arg4 usingCompressionType:(int)arg5 withFinalCompressionType:(int *)arg6;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXChannel : NSObject <DTXMessenger>
{
    DTXConnection *_connection;
    NSObject<OS_dispatch_queue> *_serialQueue;
    NSObject<OS_dispatch_queue> *_atomicHandlers;
    id <DTXAllowedRPC> _dispatchTarget;
    CDUnknownBlockType _messageHandler;
    CDUnknownBlockType _dispatchValidator;
    BOOL _canceled;
    unsigned int _channelCode;
    int _compressionTypeHint;
}

@property(nonatomic) int compressionTypeHint; // @synthesize compressionTypeHint=_compressionTypeHint;
@property(readonly, retain, nonatomic) DTXConnection *connection; // @synthesize connection=_connection;
@property(readonly, nonatomic) unsigned int channelCode; // @synthesize channelCode=_channelCode;
@property BOOL isCanceled; // @synthesize isCanceled=_canceled;
- (void)sendMessageSync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendMessage:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (BOOL)sendMessageAsync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendControlSync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendControlAsync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)_setTargetQueue:(id)arg1;
- (void)resume;
- (void)suspend;
- (void)cancel;
- (void)registerDisconnectHandler:(CDUnknownBlockType)arg1;
- (void)_setDispatchValidator:(CDUnknownBlockType)arg1;
@property(retain) id <DTXAllowedRPC> dispatchTarget;
@property(copy) CDUnknownBlockType messageHandler;
- (void)_scheduleMessage:(id)arg1 tracker:(id)arg2 withHandler:(CDUnknownBlockType)arg3;
- (void)_scheduleBlock:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithConnection:(id)arg1 channelIdentifier:(unsigned int)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXConnection : NSObject <DTXConnectionRemoteReceiveQueueCalls, DTXMessenger>
{
    NSObject<OS_dispatch_queue> *_outgoing_message_queue;
    NSObject<OS_dispatch_queue> *_outgoing_control_queue;
    DTXTransport *_controlTransport;
    NSArray *_permittedBlockCompressors;
    NSObject<OS_dispatch_queue> *_receive_queue;
    NSObject<OS_dispatch_queue> *_handler_queue;
    unsigned int _nextChannelCode;
    NSMutableDictionary *_channelsByCode;
    NSMutableDictionary *_unconfiguredChannelsByCode;
    NSMutableDictionary *_capabilitiesByChannelCode;
    NSMutableDictionary *_handlersByIdentifier;
    NSMutableDictionary *_protocolHandlers;
    NSMutableDictionary *_localCapabilityVersions;
    NSMutableDictionary *_localCapabilityClasses;
    NSDictionary *_remoteCapabilityVersions;
    DTXResourceTracker *_resourceTracker;
    DTXResourceTracker *_incomingResourceTracker;
    NSObject<OS_dispatch_semaphore> *_firstMessageSem;
    DTXMessageParser *_incomingParser;
    DTXMessageTransmitter *_outgoingTransmitter;
    DTXChannel *_defaultChannel;
    BOOL _legacyMode;
    BOOL _tracer;
    BOOL _remoteTracer;
    int _connectionIndex;
    CDUnknownBlockType _channelHandler;
    id <DTXRateLimiter> _defaultRateLimiter;
    unsigned long long _logMessageCallstackSizeThreshold;
    long long _remoteCompressionCapabilityVersion;
    int _newChannelCompressionHint;
    int _compressionTypeForUnspecified;
    unsigned long long _compressionMinSizeThreshold;
    id <DTXBlockCompressor> _compressor;
}

+ (id)connectionPublishingAddress:(id)arg1;
+ (id)connectionToAddress:(id)arg1;
+ (void)registerTransport:(Class)arg1 forScheme:(id)arg2;
+ (void)initialize;
+ (void)observeDecompressionExceptionLogging:(CDUnknownBlockType)arg1;
@property(readonly, nonatomic) int atomicConnectionNumber; // @synthesize atomicConnectionNumber=_connectionIndex;
@property(copy) CDUnknownBlockType channelHandler; // @synthesize channelHandler=_channelHandler;
@property(nonatomic) BOOL remoteTracer; // @synthesize remoteTracer=_remoteTracer;
@property(nonatomic) BOOL tracer; // @synthesize tracer=_tracer;
@property(nonatomic) BOOL legacyMode; // @synthesize legacyMode=_legacyMode;
- (void)_notifyCompressionHint:(unsigned int)arg1 forChannelCode:(unsigned int)arg2;
- (void)_receiveQueueSetCompressionHint:(unsigned int)arg1 onChannel:(id)arg2;
- (void)_setTracerState:(unsigned int)arg1;
- (void)_channelCanceled:(unsigned int)arg1;
- (void)_notifyOfPublishedCapabilities:(id)arg1;
- (void)_requestChannelWithCode:(unsigned int)arg1 identifier:(id)arg2;
- (void)_unregisterChannel:(id)arg1;
- (id)makeChannelWithIdentifier:(id)arg1;
- (void)_scheduleMessage:(id)arg1 toChannel:(id)arg2;
- (void)_routeMessage:(id)arg1;
- (BOOL)_addHandler:(CDUnknownBlockType)arg1 forMessage:(unsigned int)arg2 channel:(id)arg3;
- (BOOL)sendMessage:(id)arg1 fromChannel:(id)arg2 sendMode:(int)arg3 syncWithReply:(BOOL)arg4 replyHandler:(CDUnknownBlockType)arg5;
- (void)sendMessageSync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendMessage:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (BOOL)sendMessageAsync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendControlSync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)sendControlAsync:(id)arg1 replyHandler:(CDUnknownBlockType)arg2;
- (void)cancel;
- (void)registerDisconnectHandler:(CDUnknownBlockType)arg1;
- (void)setDispatchTarget:(id)arg1;
- (void)setMessageHandler:(CDUnknownBlockType)arg1;
- (void)throttleBandwidthBytesPerSecond:(unsigned long long)arg1;
- (void)resume;
- (void)suspend;
- (long long)remoteCapabilityVersion:(id)arg1;
- (id)localCapabilities;
- (void)publishCapability:(id)arg1 withVersion:(long long)arg2 forClass:(Class)arg3;
@property(nonatomic) unsigned long long maximumEnqueueSize;
@property(readonly, copy) NSString *description;
- (id)publishedAddresses;
- (void)dealloc;
- (id)initWithTransport:(id)arg1;
- (void)_setupWireProtocols;
- (void)_handleMessageParseException:(id)arg1 forChannelCode:(unsigned int)arg2 messageID:(unsigned int)arg3 fragmentCount:(unsigned int)arg4 withPayloadBytes:(const void *)arg5 ofLength:(unsigned long long)arg6;
- (void)setCompressionHint:(int)arg1 forChannel:(id)arg2;
- (void)publishServicesInImagePath:(id)arg1;
- (id)makeProxyChannelWithRemoteInterface:(id)arg1 exportedInterface:(id)arg2;
- (void)handleProxyRequestForInterface:(id)arg1 peerInterface:(id)arg2 handler:(CDUnknownBlockType)arg3;
@property(readonly, retain, nonatomic) DTXChannel *defaultChannel;
- (void)replaceCompressorForDecompression:(id)arg1;
- (void)replaceCompressorForCompression:(id)arg1;
- (void)overridePermittedBlockCompressors:(id)arg1;
- (id)_testing_remoteCapabilityVersions;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXDecompressionException : NSException
{
}

@end

@interface DTXTransport : NSObject
{
    NSObject<OS_dispatch_queue> *_serializer;
    NSObject<OS_dispatch_queue> *_handlerGuard;
    DTXResourceTracker *_tracker;
    CDUnknownBlockType _dataReceivedHandler;
    int _status;
    NSObject<OS_dispatch_semaphore> *_waitForResume;
    BOOL _resumed;
}

+ (BOOL)recognizesURL:(id)arg1;
+ (id)schemes;
@property(readonly, nonatomic) DTXResourceTracker *resourceTracker; // @synthesize resourceTracker=_tracker;
@property int status; // @synthesize status=_status;
- (int)supportedDirections;
- (id)permittedBlockCompressionTypes;
@property(readonly) NSArray *localAddresses;
@property(copy, nonatomic) CDUnknownBlockType dataReceivedHandler;
- (void)disconnect;
- (void)received:(const char *)arg1 ofLength:(unsigned long long)arg2 destructor:(CDUnknownBlockType)arg3;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2 withRateLimiter:(id)arg3;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (id)initWithRemoteAddress:(id)arg1;
- (id)initWithLocalAddress:(id)arg1;
- (void)dealloc;
- (id)init;
- (BOOL)canTransmit;
- (BOOL)canReceive;

@end

@interface DTXFileDescriptorTransport : DTXTransport
{
    int _inFD;
    int _outFD;
    NSObject<OS_dispatch_queue> *_inputQueue;
    NSObject<OS_dispatch_queue> *_outputQueue;
    int _outputWaitKQ;
    NSObject<OS_dispatch_source> *_inputSource;
    CDUnknownBlockType _disconnectBlock;
}

- (int)supportedDirections;
- (void)disconnect;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (void)setupWithIncomingDescriptor:(int)arg1 outgoingDescriptor:(int)arg2 disconnectBlock:(CDUnknownBlockType)arg3;
- (int)_createWriteKQueue:(int)arg1;
- (id)_createReadSource:(int)arg1;
- (void)dealloc;
- (id)initWithIncomingFileDescriptor:(int)arg1 outgoingFileDescriptor:(int)arg2 disconnectBlock:(CDUnknownBlockType)arg3;
- (id)initWithIncomingFilePath:(id)arg1 outgoingFilePath:(id)arg2 error:(id *)arg3;
- (id)init;

@end

@interface DTXFoundationURLTransport : DTXTransport <NSURLSessionDelegate>
{
    NSURLSession *_session;
    NSURLSessionDataTask *_dataTask;
}

+ (id)schemes;
- (void)disconnect;
- (void)URLSession:(id)arg1 task:(id)arg2 didCompleteWithError:(id)arg3;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (void)URLSession:(id)arg1 dataTask:(id)arg2 didReceiveData:(id)arg3;
- (void)_shutDownSession;
- (id)initWithRemoteAddress:(id)arg1;
- (int)supportedDirections;
- (id)initWithLocalAddress:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXMessage : NSObject
{
    int _messageType;
    int _compressionType;
    int _status;
    CDUnknownBlockType _destructor;
    const char *_internalBuffer;
    unsigned long long _internalBufferLength;
    unsigned long long _cost;
    id <NSCoding><NSObject> _payloadObject;
    void *_auxiliary;
    BOOL _deserialized;
    BOOL _immutable;
    BOOL _expectsReply;
    unsigned int _identifier;
    unsigned int _channelCode;
    unsigned int _conversationIndex;
    NSDictionary *_auxiliaryPromoted;
}

+ (_Bool)extractSerializedCompressionInfoFromBuffer:(const char *)arg1 length:(unsigned long long)arg2 compressionType:(int *)arg3 uncompressedLength:(unsigned long long *)arg4 compressedDataOffset:(unsigned long long *)arg5;
+ (id)message;
+ (id)messageWithSelector:(SEL)arg1 objectArguments:(id)arg2;
+ (id)messageWithSelector:(SEL)arg1 typesAndArguments:(int)arg2;
+ (id)messageReferencingBuffer:(const void *)arg1 length:(unsigned long long)arg2 destructor:(CDUnknownBlockType)arg3;
+ (id)messageWithBuffer:(const void *)arg1 length:(unsigned long long)arg2;
+ (id)messageWithPrimitive:(void *)arg1;
+ (id)messageWithError:(id)arg1;
+ (id)messageWithObject:(id)arg1;
+ (void)setReportCompressionBlock:(CDUnknownBlockType)arg1;
+ (void)initialize;
@property(readonly, nonatomic) unsigned long long cost; // @synthesize cost=_cost;
@property(nonatomic) int errorStatus; // @synthesize errorStatus=_status;
@property(readonly, nonatomic) BOOL deserialized; // @synthesize deserialized=_deserialized;
@property(nonatomic) unsigned int conversationIndex; // @synthesize conversationIndex=_conversationIndex;
@property(nonatomic) BOOL expectsReply; // @synthesize expectsReply=_expectsReply;
@property(nonatomic) unsigned int channelCode; // @synthesize channelCode=_channelCode;
@property(nonatomic) int messageType; // @synthesize messageType=_messageType;
@property(nonatomic) unsigned int identifier; // @synthesize identifier=_identifier;
@property(readonly, nonatomic) unsigned long long serializedLength;
- (void)serializedFormExpectingReply:(BOOL)arg1 apply:(CDUnknownBlockType)arg2;
- (id)initWithSerializedForm:(const char *)arg1 length:(unsigned long long)arg2 destructor:(CDUnknownBlockType)arg3 compressor:(id)arg4;
- (void)invokeWithTarget:(id)arg1 replyChannel:(id)arg2 validator:(CDUnknownBlockType)arg3;
- (BOOL)shouldInvokeWithTarget:(id)arg1;
@property(readonly, nonatomic) BOOL isBarrier;
@property(readonly, nonatomic) BOOL isDispatch;
@property(nonatomic) NSError *error;
- (id)valueForMessageKey:(id)arg1;
- (void)setData:(id)arg1 forMessageKey:(id)arg2;
- (void)setInteger:(long long)arg1 forMessageKey:(id)arg2;
- (void)setString:(id)arg1 forMessageKey:(id)arg2;
- (void)setObject:(id)arg1 forMessageKey:(id)arg2;
- (id)orderedValues;
- (void)appendObject:(id)arg1;
- (void)_appendTypesAndValues:(int)arg1 withKey:(id)arg2 list:(struct __va_list_tag [1])arg3;
- (void)_willModifyAuxiliary;
- (void)_makeBarrier;
- (void)_makeDispatch;
- (void)_makeImmutable;
- (const void *)getBufferWithReturnedLength:(unsigned long long *)arg1;
- (id)object;
@property(copy, nonatomic) id <NSCoding><NSObject> payloadObject;
- (void)_setPayloadBuffer:(const char *)arg1 length:(unsigned long long)arg2 shouldCopy:(BOOL)arg3 destructor:(CDUnknownBlockType)arg4;
- (void)_clearPayloadBuffer;
- (void)dealloc;
- (id)initWithInvocation:(id)arg1;
- (id)initWithSelector:(SEL)arg1 firstArg:(id)arg2 remainingObjectArgs:(struct __va_list_tag [1])arg3;
- (id)newReplyWithError:(id)arg1;
- (id)newReplyWithObject:(id)arg1;
- (id)newReply;
- (void)compressWithCompressor:(id)arg1 usingType:(int)arg2 forCompatibilityWithVersion:(long long)arg3;
- (id)description;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

@interface DTXLegacyBufferMessage : DTXMessage
{
}

@end

@interface DTXLegacyCompactDictionaryAdapter : NSObject <NSCoding>
{
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

@interface DTXLegacyDictionaryMessage : DTXMessage
{
}

@end

@interface DTXMessageParser : NSObject
{
    const char *_parsingBuffer;
    unsigned long long _parsingBufferUsed;
    unsigned long long _parsingBufferSize;
    NSObject<OS_dispatch_queue> *_parsingQueue;
    NSMutableDictionary *_fragmentedBuffersByIdentifier;
    NSObject<OS_dispatch_semaphore> *_hasMoreDataSem;
    NSObject<OS_dispatch_semaphore> *_wantsMoreDataSem;
    unsigned long long _desiredSize;
    BOOL _eof;
    id <DTXBlockCompressor> _compressor;
}

- (void)replaceCompressor:(id)arg1;
- (void)parsingComplete;
- (void)parseIncomingBytes:(const char *)arg1 length:(unsigned long long)arg2;
- (const void *)waitForMoreData:(unsigned long long)arg1 incrementalBuffer:(const void **)arg2;
- (id)parseMessageWithExceptionHandler:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithMessageHandler:(CDUnknownBlockType)arg1 andParseExceptionHandler:(CDUnknownBlockType)arg2;

@end

@interface DTXLegacyMessageParser : DTXMessageParser
{
    NSMutableArray *_savedKeyArrays;
}

+ (void)initialize;
- (id)parseMessageWithExceptionHandler:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)initWithMessageHandler:(CDUnknownBlockType)arg1 andParseExceptionHandler:(CDUnknownBlockType)arg2;

@end

@interface DTXMessageTransmitter : NSObject
{
    unsigned int _suggestedFragmentSize;
}

@property unsigned int suggestedFragmentSize; // @synthesize suggestedFragmentSize=_suggestedFragmentSize;
- (void)transmitMessage:(id)arg1 routingInfo:(struct DTXMessageRoutingInfo)arg2 fragment:(unsigned int)arg3 transmitter:(CDUnknownBlockType)arg4;
- (unsigned int)fragmentsForLength:(unsigned long long)arg1;

@end

@interface DTXLegacyMessageTransmitter : DTXMessageTransmitter
{
}

- (void)transmitMessage:(id)arg1 routingInfo:(struct DTXMessageRoutingInfo)arg2 fragment:(unsigned int)arg3 transmitter:(CDUnknownBlockType)arg4;
- (unsigned int)fragmentsForLength:(unsigned long long)arg1;

@end

@interface DTXLegacyServiceQueueAdapter : NSObject <NSCoding>
{
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

@interface DTXMachTransport : DTXTransport
{
    unsigned int _receivePort;
    unsigned int _sendPort;
    NSURL *_connectableAddress;
    NSObject<OS_dispatch_source> *_listenSource;
    NSObject<OS_dispatch_source> *_deadPortSource;
    NSObject<OS_dispatch_queue> *_inputQueue;
    struct DTXMachMessage *_sendBuffer;
    unsigned int _bufferedLength;
}

+ (id)fileDescriptorHandshakeWithSendPort:(unsigned int)arg1;
+ (id)fileDescriptorHandshakeWithReceivePort:(unsigned int)arg1;
+ (id)addressForSendPort:(unsigned int)arg1 receivePort:(unsigned int)arg2 inProcess:(int)arg3;
+ (id)transportForCommunicationWithTask:(unsigned int)arg1;
+ (id)schemes;
- (id)localAddresses;
- (void)disconnect;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (void)dealloc;
- (id)initWithRemoteAddress:(id)arg1;
- (id)initWithLocalAddress:(id)arg1;
- (id)initWithSendPort:(unsigned int)arg1 receivePort:(unsigned int)arg2 publishedAddress:(id)arg3;
- (BOOL)_setupWithAddress:(id)arg1;
- (BOOL)_setupWithSendPort:(unsigned int)arg1 receivePort:(unsigned int)arg2 publishedAddress:(id)arg3;

@end

@interface DTXMessageParsingBuffer : NSObject
{
    void *_buffer;
    unsigned long long _filled;
    unsigned long long _size;
}

- (unsigned long long)length;
- (const void *)buffer;
- (void)clear;
- (void)appendBytes:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (void)dealloc;
- (id)initWithSize:(unsigned long long)arg1;

@end

@interface DTXProxyChannel : NSObject
{
    Protocol *_remoteInterface;
    Protocol *_exportedInterface;
    DTXChannel *_channel;
}

@property(retain, nonatomic) DTXChannel *channel; // @synthesize channel=_channel;
@property Protocol *remoteInterface; // @synthesize remoteInterface=_remoteInterface;
- (void)_sendInvocationMessage:(id)arg1;
- (void)setExportedObject:(id)arg1 queue:(id)arg2;
- (void)_validateDispatch:(id)arg1;
- (void)cancel;
@property(readonly) id remoteObjectProxy;
- (id)initWithChannel:(id)arg1 remoteProtocol:(id)arg2 localProtocol:(id)arg3;
- (void)dealloc;

@end

@interface DTXRemoteInvocationReceipt : NSObject
{
    NSObject<OS_dispatch_queue> *_guard;
    CDUnknownBlockType _completionHandler;
    id _returnValue;
    unsigned int _returnType;
}

- (void)invokeCompletionWithReturnValue:(id)arg1 error:(id)arg2;
- (void)handleCompletion:(CDUnknownBlockType)arg1;
- (void)_checkedAssign:(CDUnknownBlockType)arg1;
- (void)dealloc;
- (id)init;

@end

@interface DTXResourceTracker : NSObject
{
    unsigned long long _total;
    unsigned long long _maxChunk;
    unsigned long long _used;
    unsigned int _waiting;
    unsigned int _acquireNum;
    int _suspendCount;
    NSObject<OS_dispatch_queue> *_queue;
    NSObject<OS_dispatch_semaphore> *_acqSem;
    DTXResourceTracker *_parentTracker;
    BOOL _log;
}

@property(nonatomic) BOOL log; // @synthesize log=_log;
- (void)resumeLimits;
- (void)suspendLimits;
- (void)releaseSize:(unsigned long long)arg1;
- (void)forceAcquireSize:(unsigned long long)arg1;
- (unsigned int)acquireSize:(unsigned long long)arg1;
@property(nonatomic) unsigned long long maxChunkSize;
@property(nonatomic) unsigned long long totalSize;
- (void)dealloc;
- (id)init;

@end

@interface DTXSendAndWaitRateLimiter : NSObject <DTXRateLimiter>
{
    NSObject<OS_dispatch_queue> *_actionQueue;
    double _microsecondsPerUnit;
    struct mach_timebase_info _timeBaseInfo;
    _Bool _logSends;
    NSObject<OS_dispatch_queue> *_statsQueue;
    NSObject<OS_dispatch_source> *_timer;
    DTXSendAndWaitStats *_stats;
}

- (void)notifyCompressedData:(unsigned long long)arg1 withUncompressedSize:(unsigned long long)arg2 nanosToCompress:(unsigned long long)arg3 usingCompressionType:(int)arg4;
- (void)spendUnits:(unsigned long long)arg1 onAction:(CDUnknownBlockType)arg2;
- (void)dealloc;
- (id)initWithUnitsPerSecond:(unsigned long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXSendAndWaitStats : NSObject
{
    unsigned long long _totalSendBytes;
    unsigned long long _previousSendBytes;
    unsigned long long _lastStatTime;
    NSObject<OS_dispatch_queue> *_statsQueue;
    struct mach_timebase_info _timeBaseInfo;
    double _microsecondsPerUnit;
    unsigned long long _compressionTotalDataCompressed;
    unsigned long long _compressionTotalDataUncompressed;
    unsigned long long _compressionTotalNanosToCompress;
    NSMutableSet *_compressionTypeSet;
}

- (void)logStats:(id)arg1;
- (void)notifyCompressedData:(unsigned long long)arg1 withUncompressedSize:(unsigned long long)arg2 nanosToCompress:(unsigned long long)arg3 usingCompressionType:(int)arg4;
- (void)sentAdditionalBytes:(unsigned long long)arg1;
- (void)dealloc;
- (id)initWithQueue:(id)arg1 andMicrosPerUnit:(double)arg2;

@end

@interface DTXService : NSObject <DTXAllowedRPC>
{
    DTXChannel *_channel;
}

+ (void)registerCapabilities:(id)arg1;
+ (BOOL)automaticallyRegistersCapabilities;
+ (void)instantiateServiceWithChannel:(id)arg1;
@property(readonly, retain, nonatomic) DTXChannel *channel; // @synthesize channel=_channel;
- (void)messageReceived:(id)arg1;
- (void)dealloc;
- (id)initWithChannel:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface DTXSharedMemoryTransport : DTXTransport
{
    struct DTXSharedMemory *_shm;
    NSObject<OS_dispatch_queue> *_listenQueue;
    BOOL _creator;
}

+ (id)addressForMemory:(unsigned long long)arg1 inProcess:(int)arg2;
+ (id)addressForPosixSharedMemoryWithName:(id)arg1;
+ (id)schemes;
@property(readonly, nonatomic) struct DTXSharedMemory *sharedMemory; // @synthesize sharedMemory=_shm;
- (id)permittedBlockCompressionTypes;
- (id)localAddresses;
- (void)disconnect;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
@property(nonatomic) int remotePid;
- (void)dealloc;
- (id)initWithMappedMemory:(struct DTXSharedMemory *)arg1;
- (id)initWithMemoryAddress:(unsigned long long)arg1 inTask:(unsigned int)arg2;
- (id)initWithRemoteAddress:(id)arg1;
- (id)initWithLocalName:(id)arg1 size:(int)arg2;
- (id)initWithLocalAddress:(id)arg1;
- (BOOL)_setupCreatingSharedMemory:(id)arg1 size:(int)arg2;
- (BOOL)_setupWithShm:(struct DTXSharedMemory *)arg1 asCreator:(BOOL)arg2;
@property(readonly, nonatomic) unsigned long long totalSharedMemorySize;

@end

@interface DTXSocketTransport : DTXFileDescriptorTransport
{
    NSObject<OS_dispatch_semaphore> *_socketAcceptedSem;
    NSObject<OS_dispatch_source> *_acceptSource;
    NSArray *_addresses;
    int _port;
}

+ (id)addressForHost:(const char *)arg1 port:(int)arg2;
+ (id)schemes;
@property(readonly) int port; // @synthesize port=_port;
- (int)supportedDirections;
- (id)localAddresses;
- (void)disconnect;
- (unsigned long long)transmit:(const void *)arg1 ofLength:(unsigned long long)arg2;
- (id)initWithRemoteAddress:(id)arg1;
- (void)dealloc;
- (id)initWithLocalPort:(int)arg1;
- (id)initWithConnectedSocket:(int)arg1 disconnectAction:(CDUnknownBlockType)arg2;
- (void)_commonSocketTransportInit;
- (void)_setupChannelWithConnectedSocket:(int)arg1 assumingOwnership:(BOOL)arg2 orDisconnectBlock:(CDUnknownBlockType)arg3;
- (id)initWithLocalAddress:(id)arg1;
- (void)_setupWithLocalPort:(int)arg1;

@end

@interface _DTXProxy : NSObject
{
    DTXProxyChannel *_proxyChannel;
}

- (id)methodSignatureForSelector:(SEL)arg1;
- (void)forwardInvocation:(id)arg1;
- (void)dealloc;
- (id)initWithChannel:(id)arg1;

@end
