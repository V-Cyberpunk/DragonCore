// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: api/common/v1/event_view_types.proto

#ifndef PROTOBUF_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto__INCLUDED
#define PROTOBUF_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "Define.h" // for TC_PROTO_API
// @@protoc_insertion_point(includes)

namespace bgs {
namespace protocol {

// Internal implementation detail -- do not call these.
void TC_PROTO_API protobuf_AddDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
void protobuf_AssignDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
void protobuf_ShutdownFile_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();

class GetEventOptions;
class ViewMarker;

enum EventOrder {
  EVENT_DESCENDING = 0,
  EVENT_ASCENDING = 1
};
TC_PROTO_API bool EventOrder_IsValid(int value);
const EventOrder EventOrder_MIN = EVENT_DESCENDING;
const EventOrder EventOrder_MAX = EVENT_ASCENDING;
const int EventOrder_ARRAYSIZE = EventOrder_MAX + 1;

TC_PROTO_API const ::google::protobuf::EnumDescriptor* EventOrder_descriptor();
inline const ::std::string& EventOrder_Name(EventOrder value) {
  return ::google::protobuf::internal::NameOfEnum(
    EventOrder_descriptor(), value);
}
inline bool EventOrder_Parse(
    const ::std::string& name, EventOrder* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EventOrder>(
    EventOrder_descriptor(), name, value);
}
// ===================================================================

class TC_PROTO_API GetEventOptions : public ::google::protobuf::Message {
 public:
  GetEventOptions();
  virtual ~GetEventOptions();

  GetEventOptions(const GetEventOptions& from);

  inline GetEventOptions& operator=(const GetEventOptions& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetEventOptions& default_instance();

  void Swap(GetEventOptions* other);

  // implements Message ----------------------------------------------

  GetEventOptions* New() const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 fetch_from = 1;
  inline bool has_fetch_from() const;
  inline void clear_fetch_from();
  static const int kFetchFromFieldNumber = 1;
  inline ::google::protobuf::uint64 fetch_from() const;
  inline void set_fetch_from(::google::protobuf::uint64 value);

  // optional uint64 fetch_until = 2;
  inline bool has_fetch_until() const;
  inline void clear_fetch_until();
  static const int kFetchUntilFieldNumber = 2;
  inline ::google::protobuf::uint64 fetch_until() const;
  inline void set_fetch_until(::google::protobuf::uint64 value);

  // optional uint32 max_events = 3;
  inline bool has_max_events() const;
  inline void clear_max_events();
  static const int kMaxEventsFieldNumber = 3;
  inline ::google::protobuf::uint32 max_events() const;
  inline void set_max_events(::google::protobuf::uint32 value);

  // optional .bgs.protocol.EventOrder order = 4;
  inline bool has_order() const;
  inline void clear_order();
  static const int kOrderFieldNumber = 4;
  inline ::bgs::protocol::EventOrder order() const;
  inline void set_order(::bgs::protocol::EventOrder value);

  // @@protoc_insertion_point(class_scope:bgs.protocol.GetEventOptions)
 private:
  inline void set_has_fetch_from();
  inline void clear_has_fetch_from();
  inline void set_has_fetch_until();
  inline void clear_has_fetch_until();
  inline void set_has_max_events();
  inline void clear_has_max_events();
  inline void set_has_order();
  inline void clear_has_order();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 fetch_from_;
  ::google::protobuf::uint64 fetch_until_;
  ::google::protobuf::uint32 max_events_;
  int order_;
  friend void TC_PROTO_API protobuf_AddDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
  friend void protobuf_AssignDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
  friend void protobuf_ShutdownFile_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();

  void InitAsDefaultInstance();
  static GetEventOptions* default_instance_;
};
// -------------------------------------------------------------------

class TC_PROTO_API ViewMarker : public ::google::protobuf::Message {
 public:
  ViewMarker();
  virtual ~ViewMarker();

  ViewMarker(const ViewMarker& from);

  inline ViewMarker& operator=(const ViewMarker& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ViewMarker& default_instance();

  void Swap(ViewMarker* other);

  // implements Message ----------------------------------------------

  ViewMarker* New() const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint64 last_read_time = 1;
  inline bool has_last_read_time() const;
  inline void clear_last_read_time();
  static const int kLastReadTimeFieldNumber = 1;
  inline ::google::protobuf::uint64 last_read_time() const;
  inline void set_last_read_time(::google::protobuf::uint64 value);

  // optional uint64 last_message_time = 2;
  inline bool has_last_message_time() const;
  inline void clear_last_message_time();
  static const int kLastMessageTimeFieldNumber = 2;
  inline ::google::protobuf::uint64 last_message_time() const;
  inline void set_last_message_time(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:bgs.protocol.ViewMarker)
 private:
  inline void set_has_last_read_time();
  inline void clear_has_last_read_time();
  inline void set_has_last_message_time();
  inline void clear_has_last_message_time();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint64 last_read_time_;
  ::google::protobuf::uint64 last_message_time_;
  friend void TC_PROTO_API protobuf_AddDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
  friend void protobuf_AssignDesc_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();
  friend void protobuf_ShutdownFile_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto();

  void InitAsDefaultInstance();
  static ViewMarker* default_instance_;
};
// ===================================================================

// ===================================================================

// ===================================================================

// GetEventOptions

// optional uint64 fetch_from = 1;
inline bool GetEventOptions::has_fetch_from() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetEventOptions::set_has_fetch_from() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetEventOptions::clear_has_fetch_from() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetEventOptions::clear_fetch_from() {
  fetch_from_ = GOOGLE_ULONGLONG(0);
  clear_has_fetch_from();
}
inline ::google::protobuf::uint64 GetEventOptions::fetch_from() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.GetEventOptions.fetch_from)
  return fetch_from_;
}
inline void GetEventOptions::set_fetch_from(::google::protobuf::uint64 value) {
  set_has_fetch_from();
  fetch_from_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.GetEventOptions.fetch_from)
}

// optional uint64 fetch_until = 2;
inline bool GetEventOptions::has_fetch_until() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GetEventOptions::set_has_fetch_until() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GetEventOptions::clear_has_fetch_until() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GetEventOptions::clear_fetch_until() {
  fetch_until_ = GOOGLE_ULONGLONG(0);
  clear_has_fetch_until();
}
inline ::google::protobuf::uint64 GetEventOptions::fetch_until() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.GetEventOptions.fetch_until)
  return fetch_until_;
}
inline void GetEventOptions::set_fetch_until(::google::protobuf::uint64 value) {
  set_has_fetch_until();
  fetch_until_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.GetEventOptions.fetch_until)
}

// optional uint32 max_events = 3;
inline bool GetEventOptions::has_max_events() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GetEventOptions::set_has_max_events() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GetEventOptions::clear_has_max_events() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GetEventOptions::clear_max_events() {
  max_events_ = 0u;
  clear_has_max_events();
}
inline ::google::protobuf::uint32 GetEventOptions::max_events() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.GetEventOptions.max_events)
  return max_events_;
}
inline void GetEventOptions::set_max_events(::google::protobuf::uint32 value) {
  set_has_max_events();
  max_events_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.GetEventOptions.max_events)
}

// optional .bgs.protocol.EventOrder order = 4;
inline bool GetEventOptions::has_order() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void GetEventOptions::set_has_order() {
  _has_bits_[0] |= 0x00000008u;
}
inline void GetEventOptions::clear_has_order() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void GetEventOptions::clear_order() {
  order_ = 0;
  clear_has_order();
}
inline ::bgs::protocol::EventOrder GetEventOptions::order() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.GetEventOptions.order)
  return static_cast< ::bgs::protocol::EventOrder >(order_);
}
inline void GetEventOptions::set_order(::bgs::protocol::EventOrder value) {
  assert(::bgs::protocol::EventOrder_IsValid(value));
  set_has_order();
  order_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.GetEventOptions.order)
}

// -------------------------------------------------------------------

// ViewMarker

// optional uint64 last_read_time = 1;
inline bool ViewMarker::has_last_read_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ViewMarker::set_has_last_read_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ViewMarker::clear_has_last_read_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ViewMarker::clear_last_read_time() {
  last_read_time_ = GOOGLE_ULONGLONG(0);
  clear_has_last_read_time();
}
inline ::google::protobuf::uint64 ViewMarker::last_read_time() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.ViewMarker.last_read_time)
  return last_read_time_;
}
inline void ViewMarker::set_last_read_time(::google::protobuf::uint64 value) {
  set_has_last_read_time();
  last_read_time_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.ViewMarker.last_read_time)
}

// optional uint64 last_message_time = 2;
inline bool ViewMarker::has_last_message_time() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ViewMarker::set_has_last_message_time() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ViewMarker::clear_has_last_message_time() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ViewMarker::clear_last_message_time() {
  last_message_time_ = GOOGLE_ULONGLONG(0);
  clear_has_last_message_time();
}
inline ::google::protobuf::uint64 ViewMarker::last_message_time() const {
  // @@protoc_insertion_point(field_get:bgs.protocol.ViewMarker.last_message_time)
  return last_message_time_;
}
inline void ViewMarker::set_last_message_time(::google::protobuf::uint64 value) {
  set_has_last_message_time();
  last_message_time_ = value;
  // @@protoc_insertion_point(field_set:bgs.protocol.ViewMarker.last_message_time)
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace bgs

#ifndef SWIG
namespace google {
namespace protobuf {
template <> struct is_proto_enum< ::bgs::protocol::EventOrder> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::bgs::protocol::EventOrder>() {
  return ::bgs::protocol::EventOrder_descriptor();
}
}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_api_2fcommon_2fv1_2fevent_5fview_5ftypes_2eproto__INCLUDED
