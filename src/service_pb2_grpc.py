# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import service_pb2 as service__pb2


class GreeterStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.fuse_access = channel.unary_unary(
        '/Greeter/fuse_access',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_readdir = channel.unary_unary(
        '/Greeter/fuse_readdir',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_getattr = channel.unary_unary(
        '/Greeter/fuse_getattr',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_read = channel.unary_unary(
        '/Greeter/fuse_read',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_fgetattr = channel.unary_unary(
        '/Greeter/fuse_fgetattr',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_mkdir = channel.unary_unary(
        '/Greeter/fuse_mkdir',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_rmdir = channel.unary_unary(
        '/Greeter/fuse_rmdir',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_rename = channel.unary_unary(
        '/Greeter/fuse_rename',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_unlink = channel.unary_unary(
        '/Greeter/fuse_unlink',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_truncate = channel.unary_unary(
        '/Greeter/fuse_truncate',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.fuse_write = channel.unary_unary(
        '/Greeter/fuse_write',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.s_replicate = channel.unary_unary(
        '/Greeter/s_replicate',
        request_serializer=service__pb2.SReplicationRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.c_replicate = channel.stream_unary(
        '/Greeter/c_replicate',
        request_serializer=service__pb2.CReplicationRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.c_empty = channel.unary_unary(
        '/Greeter/c_empty',
        request_serializer=service__pb2.CReplicationRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.get_v = channel.unary_unary(
        '/Greeter/get_v',
        request_serializer=service__pb2.MessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )


class GreeterServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def fuse_access(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_readdir(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_getattr(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_read(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_fgetattr(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_mkdir(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_rmdir(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_rename(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_unlink(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_truncate(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def fuse_write(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def s_replicate(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def c_replicate(self, request_iterator, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def c_empty(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def get_v(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_GreeterServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'fuse_access': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_access,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_readdir': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_readdir,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_getattr': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_getattr,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_read': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_read,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_fgetattr': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_fgetattr,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_mkdir': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_mkdir,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_rmdir': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_rmdir,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_rename': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_rename,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_unlink': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_unlink,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_truncate': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_truncate,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'fuse_write': grpc.unary_unary_rpc_method_handler(
          servicer.fuse_write,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      's_replicate': grpc.unary_unary_rpc_method_handler(
          servicer.s_replicate,
          request_deserializer=service__pb2.SReplicationRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'c_replicate': grpc.stream_unary_rpc_method_handler(
          servicer.c_replicate,
          request_deserializer=service__pb2.CReplicationRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'c_empty': grpc.unary_unary_rpc_method_handler(
          servicer.c_empty,
          request_deserializer=service__pb2.CReplicationRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'get_v': grpc.unary_unary_rpc_method_handler(
          servicer.get_v,
          request_deserializer=service__pb2.MessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'Greeter', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))


class CGreeterStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.c_join = channel.unary_unary(
        '/CGreeter/c_join',
        request_serializer=service__pb2.CMessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.c_getR = channel.unary_unary(
        '/CGreeter/c_getR',
        request_serializer=service__pb2.CMessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )
    self.sand_nodes = channel.unary_unary(
        '/CGreeter/sand_nodes',
        request_serializer=service__pb2.CMessageRequest.SerializeToString,
        response_deserializer=service__pb2.MessageReply.FromString,
        )


class CGreeterServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def c_join(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def c_getR(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def sand_nodes(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_CGreeterServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'c_join': grpc.unary_unary_rpc_method_handler(
          servicer.c_join,
          request_deserializer=service__pb2.CMessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'c_getR': grpc.unary_unary_rpc_method_handler(
          servicer.c_getR,
          request_deserializer=service__pb2.CMessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
      'sand_nodes': grpc.unary_unary_rpc_method_handler(
          servicer.sand_nodes,
          request_deserializer=service__pb2.CMessageRequest.FromString,
          response_serializer=service__pb2.MessageReply.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'CGreeter', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
