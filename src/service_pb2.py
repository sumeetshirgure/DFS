# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: service.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='service.proto',
  package='',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=_b('\n\rservice.proto\"h\n\x0eMessageRequest\x12\x0b\n\x03mpt\x18\x01 \x01(\t\x12\x0c\n\x04path\x18\x02 \x01(\t\x12\x0c\n\x04mode\x18\x03 \x01(\x05\x12\x0e\n\x06length\x18\x04 \x01(\x05\x12\x0e\n\x06offset\x18\x05 \x01(\x05\x12\r\n\x05\x66lags\x18\x06 \x01(\x05\"\x1c\n\x0cMessageReply\x12\x0c\n\x04pstr\x18\x01 \x01(\x0c\x32\x80\x02\n\x07Greeter\x12/\n\x0b\x66use_access\x12\x0f.MessageRequest\x1a\r.MessageReply\"\x00\x12\x30\n\x0c\x66use_readdir\x12\x0f.MessageRequest\x1a\r.MessageReply\"\x00\x12\x30\n\x0c\x66use_getattr\x12\x0f.MessageRequest\x1a\r.MessageReply\"\x00\x12-\n\tfuse_read\x12\x0f.MessageRequest\x1a\r.MessageReply\"\x00\x12\x31\n\rfuse_fgetattr\x12\x0f.MessageRequest\x1a\r.MessageReply\"\x00')
)




_MESSAGEREQUEST = _descriptor.Descriptor(
  name='MessageRequest',
  full_name='MessageRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='mpt', full_name='MessageRequest.mpt', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='path', full_name='MessageRequest.path', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mode', full_name='MessageRequest.mode', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='length', full_name='MessageRequest.length', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='offset', full_name='MessageRequest.offset', index=4,
      number=5, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='flags', full_name='MessageRequest.flags', index=5,
      number=6, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=17,
  serialized_end=121,
)


_MESSAGEREPLY = _descriptor.Descriptor(
  name='MessageReply',
  full_name='MessageReply',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='pstr', full_name='MessageReply.pstr', index=0,
      number=1, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=_b(""),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=123,
  serialized_end=151,
)

DESCRIPTOR.message_types_by_name['MessageRequest'] = _MESSAGEREQUEST
DESCRIPTOR.message_types_by_name['MessageReply'] = _MESSAGEREPLY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

MessageRequest = _reflection.GeneratedProtocolMessageType('MessageRequest', (_message.Message,), dict(
  DESCRIPTOR = _MESSAGEREQUEST,
  __module__ = 'service_pb2'
  # @@protoc_insertion_point(class_scope:MessageRequest)
  ))
_sym_db.RegisterMessage(MessageRequest)

MessageReply = _reflection.GeneratedProtocolMessageType('MessageReply', (_message.Message,), dict(
  DESCRIPTOR = _MESSAGEREPLY,
  __module__ = 'service_pb2'
  # @@protoc_insertion_point(class_scope:MessageReply)
  ))
_sym_db.RegisterMessage(MessageReply)



_GREETER = _descriptor.ServiceDescriptor(
  name='Greeter',
  full_name='Greeter',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=154,
  serialized_end=410,
  methods=[
  _descriptor.MethodDescriptor(
    name='fuse_access',
    full_name='Greeter.fuse_access',
    index=0,
    containing_service=None,
    input_type=_MESSAGEREQUEST,
    output_type=_MESSAGEREPLY,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='fuse_readdir',
    full_name='Greeter.fuse_readdir',
    index=1,
    containing_service=None,
    input_type=_MESSAGEREQUEST,
    output_type=_MESSAGEREPLY,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='fuse_getattr',
    full_name='Greeter.fuse_getattr',
    index=2,
    containing_service=None,
    input_type=_MESSAGEREQUEST,
    output_type=_MESSAGEREPLY,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='fuse_read',
    full_name='Greeter.fuse_read',
    index=3,
    containing_service=None,
    input_type=_MESSAGEREQUEST,
    output_type=_MESSAGEREPLY,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='fuse_fgetattr',
    full_name='Greeter.fuse_fgetattr',
    index=4,
    containing_service=None,
    input_type=_MESSAGEREQUEST,
    output_type=_MESSAGEREPLY,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_GREETER)

DESCRIPTOR.services_by_name['Greeter'] = _GREETER

# @@protoc_insertion_point(module_scope)
